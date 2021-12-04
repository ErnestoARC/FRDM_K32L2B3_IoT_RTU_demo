/*! @file : iot_sdk_peripherals_sensor_ana.h
 * @author  Ernesto Andres Rincon Cruz
 * @version 1.0.0
 * @date    1 sept. 2021
 * @brief   Driver para
 * @details
 *
 */
#ifndef PERIPHERALS_IOT_SDK_PERIPHERALS_SENSOR_ANA_H_
#define PERIPHERALS_IOT_SDK_PERIPHERALS_SENSOR_ANA_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "peripherals.h"

/*!
 * @addtogroup PERIPHERALS
 * @{
 */
/*!
 * @addtogroup LIGHT
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/
#define INDEX_SENSOR_ANA	3
/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Public vars
 ******************************************************************************/

/*******************************************************************************
 * Public Prototypes
 ******************************************************************************/
uint32_t getSensorADC(void);

/** @} */ // end of SENSOR_ADC group
/** @} */ // end of PERIPHERALS group

#endif /* PERIPHERALS_IOT_SDK_PERIPHERALS_SENSOR_ANA_H_ */
