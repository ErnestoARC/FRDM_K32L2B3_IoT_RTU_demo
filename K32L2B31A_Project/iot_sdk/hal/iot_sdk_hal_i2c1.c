/*! @file : sdk_hal_i2c1.c
 * @author  Ernesto Andres Rincon Cruz
 * @version 1.0.0
 * @date    11/02/2021
 * @brief   Driver for I2C1
 * @details
 *
*/
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "iot_sdk_hal_i2c1.h"
#include "fsl_i2c.h"
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
status_t i2c1MasterInit(uint32_t baud_rate) {
	i2c_master_config_t masterConfig;

	I2C_MasterGetDefaultConfig(&masterConfig);
    masterConfig.baudRate_Bps = baud_rate;

    I2C_MasterInit(I2C1, &masterConfig, CLOCK_GetFreq(I2C1_CLK_SRC));
	return(kStatus_Success);
}
/*--------------------------------------------*/
status_t i2c1MasterReadByte(uint8_t *data, uint8_t bytes_to_read, uint8_t device_address, uint32_t memory_address, uint8_t address_size) {
	i2c_master_transfer_t masterXfer;
	status_t status;

    masterXfer.slaveAddress = device_address;
    masterXfer.direction = kI2C_Read;
    masterXfer.subaddress = memory_address;
    masterXfer.subaddressSize = address_size;
    masterXfer.data = data;
    masterXfer.dataSize = bytes_to_read;
    masterXfer.flags = kI2C_TransferDefaultFlag;

    status=I2C_MasterTransferBlocking(I2C1, &masterXfer);

    return(status);
}
/*--------------------------------------------*/
status_t i2c1MasterWriteByte(uint8_t *data, uint8_t bytes_to_write, uint8_t device_address, uint32_t memory_address, uint8_t address_size) {
	i2c_master_transfer_t masterXfer;
	status_t status;

    masterXfer.slaveAddress = device_address;
    masterXfer.direction = kI2C_Write;
    masterXfer.subaddress = memory_address;
    masterXfer.subaddressSize = address_size;
    masterXfer.data = data;
    masterXfer.dataSize = bytes_to_write;
    masterXfer.flags = kI2C_TransferDefaultFlag;

    status=I2C_MasterTransferBlocking(I2C1, &masterXfer);

    return(status);
}
