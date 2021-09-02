/*! @file : iot_sdk_irq_lptimer0.c
 * @author  Ernesto Andres Rincon Cruz
 * @version 1.0.0
 * @date    1 sept. 2021
 * @brief   IRQ ejecutado cada que ocurre interrupción por timer 0
 * @details
 *
*/
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "peripherals.h"
#include <iot_sdk_peripherals_leds.h>
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


/*******************************************************************************
 * Private Source Code
 ******************************************************************************/


/*******************************************************************************
 * Public Source Code
 ******************************************************************************/
 /* LPTMR0_IRQn interrupt handler */
void LPTMR0_IRQHANDLER(void) {
  uint32_t intStatus;
  /* Reading all interrupt flags of status register */
  intStatus = LPTMR_GetStatusFlags(LPTMR0_PERIPHERAL);
  LPTMR_ClearStatusFlags(LPTMR0_PERIPHERAL, intStatus);

  /* Place your code here */
  toggleLedVerde();
  /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
     Store immediate overlapping exception return operation might vector to incorrect interrupt. */
  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}
