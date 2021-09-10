/*! @file : iot_sdk_peripheral_temperature.h
 * @author  Ernesto Andres Rincon Cruz
 * @version 1.0.0
 * @date    8 sept. 2021
 * @brief   Driver para lectura de sensor de temperatura interna del microcontrolador
 * @details
 *
 */
#ifndef PERIPHERALS_IOT_SDK_PERIPHERAL_TEMPERATURE_H_
#define PERIPHERALS_IOT_SDK_PERIPHERAL_TEMPERATURE_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "peripherals.h"

/*!
 * @addtogroup PERIPHERAL
 * @{
 */
/*!
 * @addtogroup TEMPERATURE
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/
#define MAX_ADC			(float)65535
#define VDD_MAX			(float)(3.3)
#define VTEMP25			(float)(0.716)


#define ADC_VTEMP25		14219//(VTEMP25 * MAX_ADC)/(VDD_MAX)
#define ADC_VSLOPE		32//(float)(VTEMP25 * MAX_ADC)/(VDD_MAX)


/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Public vars
 ******************************************************************************/

/*******************************************************************************
 * Public Prototypes
 ******************************************************************************/

 float getTemperatureValue(void);

/** @} */ // end of TEMPERATURE group
/** @} */ // end of PERIPHERAL group

#endif /* PERIPHERALS_IOT_SDK_PERIPHERAL_TEMPERATURE_H_ */
