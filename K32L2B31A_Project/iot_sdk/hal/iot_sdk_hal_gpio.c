/*! @file : iot_sdk_hal_gpio.c
 * @author  Ernesto Andres Rincon Cruz
 * @version 1.0.0
 * @date    10/01/2021
 * @brief   Driver para control de GPIO
 * @details
 *
*/
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iot_sdk_hal_gpio.h>
#include "fsl_gpio.h"
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
/*--------------------------------------------*/
status_t gpioPutHigh(uint16_t pin_to_change) {

	uint16_t gpio_port_name;
	uint32_t gpio_pin_number;

	//Take 8MSB bits of pin_name for GPIOx PORT NAME
	gpio_port_name = pin_to_change & 0xFF00;
	gpio_port_name >>= 8;

	//Take 8LSB bits of pin_name for GPIOx PIN NUMBER
	gpio_pin_number = pin_to_change & 0x00FF;

	//only is available numbers for range (0-31)
	if (gpio_pin_number > 31)
		return (kStatus_Fail);

	//pin mask is calculated
	gpio_pin_number = 1 << (gpio_pin_number);

	//Call NXP_SDK_STACK to perform pin change
	switch (gpio_port_name) {
	case KGPIOA:
		GPIO_PortSet(GPIOA, gpio_pin_number);
		break;

	case KGPIOB:
		GPIO_PortSet(GPIOB, gpio_pin_number);
		break;

	case KGPIOC:
		GPIO_PortSet(GPIOC, gpio_pin_number);
		break;

	case KGPIOD:
		GPIO_PortSet(GPIOD, gpio_pin_number);
		break;

	case KGPIOE:
		GPIO_PortSet(GPIOE, gpio_pin_number);
		break;

	default:
		return (kStatus_Fail);
		break;
	}

	return (kStatus_Success);
}
 /*--------------------------------------------*/
status_t gpioPutLow(uint16_t pin_to_change) {
	uint16_t gpio_port_name;
	uint32_t gpio_pin_number;

	//Take 8MSB bits of pin_name for GPIOx PORT NAME
	gpio_port_name = pin_to_change & 0xFF00;
	gpio_port_name >>= 8;

	//Take 8LSB bits of pin_name for GPIOx PIN NUMBER
	gpio_pin_number = pin_to_change & 0x00FF;

	//only is available numbers for range (0-31)
	if (gpio_pin_number > 31)
		return (kStatus_Fail);

	//pin mask is calculated
	gpio_pin_number = 1 << (gpio_pin_number);

	//Call NXP_SDK_STACK to perform pin change
	switch (gpio_port_name) {
	case KGPIOA:
		GPIO_PortClear(GPIOA, gpio_pin_number);
		break;

	case KGPIOB:
		GPIO_PortClear(GPIOB, gpio_pin_number);
		break;

	case KGPIOC:
		GPIO_PortClear(GPIOC, gpio_pin_number);
		break;

	case KGPIOD:
		GPIO_PortClear(GPIOD, gpio_pin_number);
		break;

	case KGPIOE:
		GPIO_PortClear(GPIOE, gpio_pin_number);
		break;

	default:
		return (kStatus_Fail);
		break;
	}

	return (kStatus_Success);
}
 /*--------------------------------------------*/
status_t gpioPutValue(uint16_t pin_to_change, uint8_t new_value) {
	uint16_t gpio_port_name;
	uint32_t gpio_pin_number;

	//Take 8MSB bits of pin_name for GPIOx PORT NAME
	gpio_port_name = pin_to_change & 0xFF00;
	gpio_port_name >>= 8;

	//Take 8LSB bits of pin_name for GPIOx PIN NUMBER
	gpio_pin_number = pin_to_change & 0x00FF;

	//only is available numbers for range (0-31)
	if (gpio_pin_number > 31)
		return (kStatus_Fail);

	//Call NXP_SDK_STACK to perform pin change
	switch (gpio_port_name) {
	case KGPIOA:
		GPIO_PinWrite(GPIOA, gpio_pin_number,new_value);
		break;

	case KGPIOB:
		GPIO_PinWrite(GPIOB, gpio_pin_number,new_value);
		break;

	case KGPIOC:
		GPIO_PinWrite(GPIOC, gpio_pin_number,new_value);
		break;

	case KGPIOD:
		GPIO_PinWrite(GPIOD, gpio_pin_number,new_value);
		break;

	case KGPIOE:
		GPIO_PinWrite(GPIOE, gpio_pin_number,new_value);
		break;

	default:
		return (kStatus_Fail);
		break;
	}

	return (kStatus_Success);
}
 /*--------------------------------------------*/
status_t gpioPutToggle(uint16_t pin_to_change) {
	uint16_t gpio_port_name;
	uint32_t gpio_pin_number;

	//Take 8MSB bits of pin_name for GPIOx PORT NAME
	gpio_port_name = pin_to_change & 0xFF00;
	gpio_port_name >>= 8;

	//Take 8LSB bits of pin_name for GPIOx PIN NUMBER
	gpio_pin_number = pin_to_change & 0x00FF;

	//only is available numbers for range (0-31)
	if (gpio_pin_number > 31)
		return (kStatus_Fail);

	//pin mask is calculated
	gpio_pin_number = 0x01 << (gpio_pin_number);

	//Call NXP_SDK_STACK to perform pin change
	switch (gpio_port_name) {
	case KGPIOA:
		GPIO_PortToggle(GPIOA, gpio_pin_number);
		break;

	case KGPIOB:
		GPIO_PortToggle(GPIOB, gpio_pin_number);
		break;

	case KGPIOC:
		GPIO_PortToggle(GPIOC, gpio_pin_number);
		break;

	case KGPIOD:
		GPIO_PortToggle(GPIOD, gpio_pin_number);
		break;

	case KGPIOE:
		GPIO_PortToggle(GPIOE, gpio_pin_number);
		break;

	default:
		return (kStatus_Fail);
		break;
	}

	return (kStatus_Success);
}
/*--------------------------------------------*/
status_t gpioReadValue(uint16_t pin_to_read, uint32_t *pin_value){
	uint16_t gpio_port_name;
	uint32_t gpio_pin_number;
	uint32_t gpio_pin_value;
	//Take 8MSB bits of pin_name for GPIOx PORT NAME
	gpio_port_name = pin_to_read & 0xFF00;
	gpio_port_name >>= 8;

	//Take 8LSB bits of pin_name for GPIOx PIN NUMBER
	gpio_pin_number = pin_to_read & 0x00FF;

	//only is available numbers for range (0-31)
	if (gpio_pin_number > 31)
		return (kStatus_Fail);

	//Call NXP_SDK_STACK to perform pin read
	switch (gpio_port_name) {
	case KGPIOA:
		gpio_pin_value=GPIO_PinRead(GPIOA, gpio_pin_number);
		break;

	case KGPIOB:
		gpio_pin_value=GPIO_PinRead(GPIOB, gpio_pin_number);
		break;

	case KGPIOC:
		gpio_pin_value=GPIO_PinRead(GPIOC, gpio_pin_number);
		break;

	case KGPIOD:
		gpio_pin_value=GPIO_PinRead(GPIOD, gpio_pin_number);
		break;

	case KGPIOE:
		gpio_pin_value=GPIO_PinRead(GPIOE, gpio_pin_number);
		break;

	default:
		return (kStatus_Fail);
		break;
	}

	*pin_value=gpio_pin_value;

	return (kStatus_Success);
}
