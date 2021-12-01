/*! @file : K32L2B31A_Project.c
 * @author  Ernesto Andres Rincon Cruz
 * @version 0.0.000
 * @date    23/08/2021
 * @brief   Funcion principal main
 * @details
 *			v0.0.000	Proyecto base creado usando MCUXpresso
 *
 *
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "K32L2B31A.h"
#include "fsl_debug_console.h"
#include <limits.h>
#include <float.h>

#include <iot_sdk_peripherals_leds.h>
#include <iot_sdk_peripherals_light.h>
#include "iot_sdk_peripherals_buttons.h"
#include "iot_sdk_peripheral_temperature.h"

#include "iot_sdk_ irq_lptimer0.h"
#include "iot_sdk_irq_lpuart0.h"
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
int main(void) {
	uint32_t adc_light_value;
	float temperature_value;
	status_t status;
	uint8_t nuevo_byte_uart;

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    /* Activa LPTMR0 para que iniciar contador y posterior IRQ cada 1 segundo*/
    LPTMR_StartTimer(LPTMR0);

    while(1) {
    	if(lptmr0_ticks!=0){
    		lptmr0_ticks=0;
        	toggleLedRojo();
        	toggleLedVerde();

    		//Busca si llegaron nuevos datos desde modem mientras esperaba
    		if (lpUart0CuantosDatosHayEnBuffer() > 0) {
    			status = lpUart0LeerByteDesdeBuffer(&nuevo_byte_uart);
    			if (status == kStatus_Success) {
    				adc_light_value=getLightADC();
    				temperature_value=getTemperatureValue();

    				printf("Nuevo byte:%c - 0x%2x\r\n",nuevo_byte_uart,nuevo_byte_uart);
    	        	printf("ADC Light: %d\r\n", adc_light_value);
    	        	printf("Temperature: %f\r\n", temperature_value);
    	            printf("boton1:%d\r\n",leerBoton1());
    	            printf("boton2:%d\r\n",leerBoton2());
    	            printf("\r\n");
    			}
    		}


    	}
    }
    return 0 ;
}
