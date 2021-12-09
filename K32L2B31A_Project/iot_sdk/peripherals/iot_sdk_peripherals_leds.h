/*! @file : sdk_mdlw_leds.h
 * @author  Ernesto Andres Rincon Cruz
 * @version 1.0.0
 * @date    17/01/2021
 * @brief   Driver para LEDS
 * @details
 *
 */
#ifndef SDK_MDLW_LEDS_H_
#define SDK_MDLW_LEDS_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iot_sdk_hal_gpio.h>
#include "peripherals.h"
/*!
 * @addtogroup PERIPHERALS
 * @{
 */
/*!
 * @addtogroup LEDS
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/
#define LED_VERDE_PIN	KPTD5
#define LED_ROJO_PIN	KPTE31

/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Public vars
 ******************************************************************************/

/*******************************************************************************
 * Public Prototypes
 ******************************************************************************/

static inline void encenderLedRojo(void) {
	gpioPutValue(LED_ROJO_PIN, 0);
}

static inline void apagarLedRojo(void) {
	gpioPutValue(LED_ROJO_PIN, 1);
}

static inline void toggleLedRojo(void){
	gpioPutToggle(LED_ROJO_PIN);
}

static inline void encenderLedVerde(void) {
	gpioPutValue(LED_VERDE_PIN, 0);
}

static inline void apagarLedVerde(void) {
	gpioPutValue(LED_VERDE_PIN, 1);
}

static inline void toggleLedVerde(void){
	gpioPutToggle(LED_VERDE_PIN);
}

/** @} */ // end of LEDS group
/** @} */ // end of MIDDLEWARE group

#endif /* SDK_MDLW_LEDS_H_ */
