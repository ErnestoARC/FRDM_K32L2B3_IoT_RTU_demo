/*! @file : iot_sdk_irq_lpuart0.h
 * @author  Ernesto Andres Rincon Cruz
 * @version 1.0.0
 * @date    9 sept. 2021
 * @brief   Driver para 
 * @details
 *
 */
#ifndef IRQ_IOT_SDK_IRQ_LPUART0_H_
#define IRQ_IOT_SDK_IRQ_LPUART0_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "peripherals.h"
#include "fsl_lpuart.h"

/*!
 * @addtogroup IRQ
 * @{
 */
/*!
 * @addtogroup LPUART0
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/
/*! @brief Tamaño de buffer circular para recibir datos por UART (Unit: Byte). */
#define LONGITUD_BUFFER_CIRCULAR 	100

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
 * @brief Calcula el numero de datos nuevos que hay en el buffer circular
 *
 * @return	numero de bytes que estan pendientes por ser procesados
 * @endcode
 */
uint16_t lpUart0CuantosDatosHayEnBuffer(void);
/*--------------------------------------------*/
/*!
 * @brief Obtiene 1 byte desde buffer circular
 *
 * @param nuevo_byte	apuntador de memoria donde almacenar nuevo byte
 * @return	estado de la ejecución
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t lpUart0LeerByteDesdeBuffer(uint8_t *nuevo_byte);
/** @} */ // end of LPUART0 group
/** @} */ // end of IRQ group

#endif /* IRQ_IOT_SDK_IRQ_LPUART0_H_ */
