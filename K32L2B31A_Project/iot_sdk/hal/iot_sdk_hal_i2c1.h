/*! @file : sdk_hal_i2c1.h
 * @author  Ernesto Andres Rincon Cruz
 * @version 1.0.0
 * @date    11/02/2021
 * @brief   Driver for I2C1
 * @details
 *
 */
#ifndef SDK_HAL_I2C1_H_
#define SDK_HAL_I2C1_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fsl_common.h"


/*!
 * @addtogroup HAL
 * @{
 */
/*!
 * @addtogroup I2C1
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
/*--------------------------------------------*/
/*!
 * @brief Perform a I2C1 initialization
 *
 * @param baud_rate   baudrate (bps) for I2C module
 * @return            status for process
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t i2c1MasterInit(uint32_t baud_rate);
/*--------------------------------------------*/
/*!
 * @brief Read byte from I2C1 devide
 *
 * @param data				memory adderess pointer
 * @param bytes_to_read		number of byte to read form i2c device
 * @param device_address	I2C address
 * @return            		status for process
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t i2c1MasterReadByte(uint8_t *data, uint8_t bytes_to_read, uint8_t device_address, uint32_t memory_address, uint8_t address_size);
/*--------------------------------------------*/
/*!
 * @brief Write byte to I2C1 devide
 *
 * @param data				memory adderess pointer
 * @param bytes_to_read		number of byte to write on i2c device
 * @param device_address	I2C address
 * @return            		status for process
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t i2c1MasterWriteByte(uint8_t *data, uint8_t bytes_to_write, uint8_t device_address, uint32_t memory_address, uint8_t address_size);



/** @} */ // end of I2C0 group
/** @} */ // end of HAL group

#endif /* SDK_HAL_I2C0_H_ */
