/*! @file : iot_sdk_irq_lpuart0.c
 * @author  Ernesto Andres Rincon Cruz
 * @version 1.0.0
 * @date    9 sept. 2021
 * @brief   Driver para 
 * @details
 *
*/
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "iot_sdk_irq_lpuart0.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Private Prototypes
 ******************************************************************************/


/*******************************************************************************
 * External vars
 ******************************************************************************/


/*******************************************************************************
 * Local vars
 ******************************************************************************/
volatile uint8_t 	lpuart0_buffer_circular[LONGITUD_BUFFER_CIRCULAR];
volatile uint16_t 	txIndex; /* Index of the data to send out. */
volatile uint16_t 	rxIndex; /* Index of the memory to save new arrived data. */

/*******************************************************************************
 * Private Source Code
 ******************************************************************************/


/*******************************************************************************
 * Public Source Code
 ******************************************************************************/
 /* LPUART0_IRQn interrupt handler */
void LPUART0_SERIAL_RX_TX_IRQHANDLER(void) {
  uint32_t intStatus;
  /* Reading all interrupt flags of status registers */
  intStatus = LPUART_GetStatusFlags(LPUART0_PERIPHERAL);

  /* Flags can be cleared by reading the status register and reading/writing data registers.
    See the reference manual for details of each flag.
    The LPUART_ClearStatusFlags() function can be also used for clearing of flags in case the content of data/FIFO regsiter is not used.
    For example:
        status_t status;
        status = LPUART_ClearStatusFlags(LPUART0_PERIPHERAL, intStatus);
  */

  /* Place your code here */
  uint8_t data;

  if ((kLPUART_RxDataRegFullFlag)&intStatus)
  {
      data = LPUART_ReadByte(LPUART0);

      if (((rxIndex + 1) % LONGITUD_BUFFER_CIRCULAR) != txIndex)
      {
          lpuart0_buffer_circular[rxIndex] = data;
          rxIndex++;
          rxIndex %= LONGITUD_BUFFER_CIRCULAR;
      }
  }

  /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
     Store immediate overlapping exception return operation might vector to incorrect interrupt. */
  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}
/*--------------------------------------------*/
uint16_t lpUart0CuantosDatosHayEnBuffer(void) {
	return ((uint16_t) (rxIndex - txIndex));
}
/*--------------------------------------------*/
status_t lpUart0LeerByteDesdeBuffer(uint8_t *nuevo_byte) {
	if (rxIndex != txIndex) {
		*nuevo_byte = lpuart0_buffer_circular[txIndex];
		txIndex++;
		txIndex %= LONGITUD_BUFFER_CIRCULAR;
		return (kStatus_Success);
	} else {
		return (kStatus_Fail);
	}
}
