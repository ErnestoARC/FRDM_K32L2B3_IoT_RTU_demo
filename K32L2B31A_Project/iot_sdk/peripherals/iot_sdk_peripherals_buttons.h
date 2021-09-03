/*! @file : iot_sdk_peripherals_buttons.h
 * @author  Ernesto Andres Rincon Cruz
 * @version 1.0.0
 * @date    2 sept. 2021
 * @brief   Driver para 
 * @details
 *
 */
#ifndef PERIPHERALS_IOT_SDK_PERIPHERALS_BUTTONS_H_
#define PERIPHERALS_IOT_SDK_PERIPHERALS_BUTTONS_H_
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
 * @addtogroup BUTTONS
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/
#define BOTON1_PIN	KPTC3
#define BOTON2_PIN	KPTA4
/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Public vars
 ******************************************************************************/

/*******************************************************************************
 * Public Prototypes
 ******************************************************************************/
bool leerBoton1(void);
bool leerBoton2(void);

/** @} */ // end of X group
/** @} */ // end of X group

#endif /* PERIPHERALS_IOT_SDK_PERIPHERALS_BUTTONS_H_ */
