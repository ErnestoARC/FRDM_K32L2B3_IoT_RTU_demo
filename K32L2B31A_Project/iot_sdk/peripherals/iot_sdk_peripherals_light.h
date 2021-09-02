/*! @file : iot_sdk_peripherals_light.h
 * @author  Ernesto Andres Rincon Cruz
 * @version 1.0.0
 * @date    1 sept. 2021
 * @brief   Driver para 
 * @details
 *
 */
#ifndef PERIPHERALS_IOT_SDK_PERIPHERALS_LIGHT_H_
#define PERIPHERALS_IOT_SDK_PERIPHERALS_LIGHT_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "K32L2B31A.h"
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

/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Public vars
 ******************************************************************************/

/*******************************************************************************
 * Public Prototypes
 ******************************************************************************/
uint32_t get_light_value(void);

/** @} */ // end of LIGHT group
/** @} */ // end of PERIPHERALS group

#endif /* PERIPHERALS_IOT_SDK_PERIPHERALS_LIGHT_H_ */
