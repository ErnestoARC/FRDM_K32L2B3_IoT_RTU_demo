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
#include "iot_sdk_ irq_lptimer0.h"
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
volatile uint32_t lptmr0_ticks=0;

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
  lptmr0_ticks++;

  /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
     Store immediate overlapping exception return operation might vector to incorrect interrupt. */
  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}
