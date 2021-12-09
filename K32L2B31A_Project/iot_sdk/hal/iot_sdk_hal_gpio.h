/*! @file : iot_sdk_hal_gpio.h
 * @author  Ernesto Andres Rincon Cruz
 * @version 1.0.0
 * @date    10/01/2021
 * @brief   Driver for GPIO
 * @details
 *
 */
#ifndef SDK_HAL_GPIO_H_
#define SDK_HAL_GPIO_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fsl_common.h"

/*!
 * @addtogroup HAL
 * @{
 */
/*!
 * @addtogroup GPIO
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/
/*!
 * @brief Lista de puertos GPIO disponibles en microcontrolador
 */
enum _gpio_port_list_available
{
	KGPIOA=0X00,
	KGPIOB,
	KGPIOC,
	KGPIOD,
	KGPIOE
};

/*!
 * @brief Lista de pines GPIO disponibles en microcontrolador
 */
enum _gpio_pin_list_available
{
	/*!< GPIOA*/
	KPTA0 = 0x0000,
	KPTA1,
	KPTA2,
	KPTA3,
	KPTA4,
	KPTA5,
	KPTA6,
	KPTA7,
	KPTA8,
	KPTA9,
	KPTA10,
	KPTA11,
	KPTA12,
	KPTA13,
	KPTA14,
	KPTA15,
	KPTA16,
	KPTA17,
	KPTA18,
	KPTA19,
	KPTA20,
	KPTA21,
	KPTA22,
	KPTA23,
	KPTA24,
	KPTA25,
	KPTA26,
	KPTA27,
	KPTA28,
	KPTA29,
	KPTA30,
	KPTA31,

	/*!< GPIOB*/
	KPTB0 = 0x0100,
	KPTB1,
	KPTB2,
	KPTB3,
	KPTB4,
	KPTB5,
	KPTB6,
	KPTB7,
	KPTB8,
	KPTB9,
	KPTB10,
	KPTB11,
	KPTB12,
	KPTB13,
	KPTB14,
	KPTB15,
	KPTB16,
	KPTB17,
	KPTB18,
	KPTB19,
	KPTB20,
	KPTB21,
	KPTB22,
	KPTB23,
	KPTB24,
	KPTB25,
	KPTB26,
	KPTB27,
	KPTB28,
	KPTB29,
	KPTB30,
	KPTB31,
	/*!< GPIOC*/
	KPTC0 = 0x0200,
	KPTC1,
	KPTC2,
	KPTC3,
	KPTC4,
	KPTC5,
	KPTC6,
	KPTC7,
	KPTC8,
	KPTC9,
	KPTC10,
	KPTC11,
	KPTC12,
	KPTC13,
	KPTC14,
	KPTC15,
	KPTC16,
	KPTC17,
	KPTC18,
	KPTC19,
	KPTC20,
	KPTC21,
	KPTC22,
	KPTC23,
	KPTC24,
	KPTC25,
	KPTC26,
	KPTC27,
	KPTC28,
	KPTC29,
	KPTC30,
	KPTC31,
	/*!< GPIOD*/
	KPTD0 = 0x0300,
	KPTD1,
	KPTD2,
	KPTD3,
	KPTD4,
	KPTD5,
	KPTD6,
	KPTD7,
	KPTD8,
	KPTD9,
	KPTD10,
	KPTD11,
	KPTD12,
	KPTD13,
	KPTD14,
	KPTD15,
	KPTD16,
	KPTD17,
	KPTD18,
	KPTD19,
	KPTD20,
	KPTD21,
	KPTD22,
	KPTD23,
	KPTD24,
	KPTD25,
	KPTD26,
	KPTD27,
	KPTD28,
	KPTD29,
	KPTD30,
	KPTD31,
	/*!< GPIOE*/
	KPTE0 = 0x0400,
	KPTE1,
	KPTE2,
	KPTE3,
	KPTE4,
	KPTE5,
	KPTE6,
	KPTE7,
	KPTE8,
	KPTE9,
	KPTE10,
	KPTE11,
	KPTE12,
	KPTE13,
	KPTE14,
	KPTE15,
	KPTE16,
	KPTE17,
	KPTE18,
	KPTE19,
	KPTE20,
	KPTE21,
	KPTE22,
	KPTE23,
	KPTE24,
	KPTE25,
	KPTE26,
	KPTE27,
	KPTE28,
	KPTE29,
	KPTE30,
	KPTE31,
};
/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Public vars
 ******************************************************************************/

/*******************************************************************************
 * Public Prototypes
 ******************************************************************************/
/*!
 * @brief Set specific pin to high value
 *
 * @param pin_to_change	pin name code
 * @see	_gpio_pin_list_available
 * @return	execution error code
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t gpioPutHigh(uint16_t pin_to_change);
/*!
 * @brief Set specific pin to low value
 *
 * @param pin_to_change	pin name code
 * @see	_gpio_pin_list_available
 * @return	execution error code
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t gpioPutLow(uint16_t pin_to_change);
/*!
 * @brief Set specific pin to new specific value
 *
 * @param pin_to_change	pin name code
 * @see	_gpio_pin_list_available
 * @param new_value new value to be pushed on specific pin
 * @return	execution error code
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t gpioPutValue(uint16_t pin_to_change, uint8_t new_value);
/*!
 * @brief Set toggle on specific pin
 *
 * @param pin_to_change	pin name code
 * @see	_gpio_pin_list_available
 * @return	execution error code
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t gpioPutToggle(uint16_t pin_to_change);

/*!
 * @brief Get value from specific pin
 *
 * @param pin_to_read	pin name code
 * @param *pin_value
 * @see	_gpio_pin_list_available
 * @return	execution error code
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t gpioReadValue(uint16_t pin_to_read, uint32_t *pin_value);

/** @} */ // end of GPIO group
/** @} */ // end of HAL group

#endif /* SDK_HAL_GPIO_H_ */
