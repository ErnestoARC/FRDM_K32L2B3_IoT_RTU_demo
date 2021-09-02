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
void waitTime(void) {
	uint32_t tiempo = 0x1FFFFF;
	do {
		tiempo--;
	} while (tiempo != 0x0000);
}


int main(void) {
	uint32_t adc_light_value;
    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    /* Activa LPTMR0 para que iniciar contador y posterior IRQ cáda 1 segundo*/
    LPTMR_StartTimer(LPTMR0);

    while(1) {
    	waitTime();
    	toggleLedRojo();
    	adc_light_value=get_light_value();
        PRINTF("ADC Value: %d\r\n", adc_light_value);
    }
    return 0 ;
}
