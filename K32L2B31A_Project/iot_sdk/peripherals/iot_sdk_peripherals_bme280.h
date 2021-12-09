/*! @file : sdk_pph_bme280.h
 * @author  Ernesto Andres Rincon Cruz
 * @version 1.0.0
 * @date    9/02/2021
 * @brief   Driver para sensor de temperatura BME280
 * @details
 *
 */
#ifndef SDK_PPH_BME280_H_
#define SDK_PPH_BME280_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "iot_sdk_hal_i2c1.h"

/*!
 * @addtogroup PERIPHERAL
 * @{
 */
/*!
 * @addtogroup BME280
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/
#define BME280_ADDRESS  (0x76) //!< BME280 Dirección I2C.

/*! @brief Listado de registros del sensor BME280 */
enum _bme280_registers{
	BME280_REG_ID=0xD0,
	BME280_REG_CTRL_HUM=0XF2,
	BME280_REG_STATUS,
	BME280_REG_CTRL_MEAS,
	BME280_REG_CONFIG,
	BME280_REG_PRESS_MSB=0XF7,
	BME280_REG_PRESS_lSB,
	BME280_REG_PRESS_XlSB,
	BME280_REG_TEMP_MSB,
	BME280_REG_TEMP_lSB,
	BME280_REG_TEMP_XlSB,
	BME280_REG_HUM_MSB,
	BME280_REG_HUM_lSB,
};

/*!
 * @brief Define tipo de datos estructura que permite organizar los datos del sensor BM280
 */
typedef struct _bme280_data{
	uint32_t temperatura;
	uint32_t humedad;
	uint32_t presion;
}bme280_data_t;


//Define interconexión entre capa de firmware Peripherals (PPH) y HardwareAbstractionLayer (HAl)
#define bme280WriteByte	i2c1MasterWriteByte
#define bme280ReadByte	i2c1MasterReadByte

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
 * @brief Lee registro de identificacion sensor BME280
 *
 * @return	resultado ejecución
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t bme280WhoAmI(void);

/*!
 * @brief Lee temperatura, humedad y presión del sensor BME280
 * @param data	apuntador de memoria  a estructura donde almacenar los  datos
 * @return	resultado ejecución
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t	bme280ReadData(bme280_data_t *data );

/*!
 * @brief Inicialización de registros en sensor BME280
 * @return	resultado ejecución
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t bme280Init(void);

/** @} */ // end of X group
/** @} */ // end of X group

#endif /* SDK_PPH_BME280_H_ */
