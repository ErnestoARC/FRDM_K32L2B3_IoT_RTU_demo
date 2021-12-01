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

#include "iot_sdk_hal_i2c1.h"

#include <iot_sdk_peripherals_leds.h>
#include <iot_sdk_peripherals_light.h>
#include "iot_sdk_peripherals_buttons.h"
#include "iot_sdk_peripheral_temperature.h"
#include "iot_sdk_peripherals_bme280.h"
#include "iot_sdk_peripherals_sht3x.h"

#include "iot_sdk_ irq_lptimer0.h"
#include "iot_sdk_irq_lpuart0.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define HABILITAR_SENSOR_BME280		1
#define HABILITAR_SENSOR_SHT3X		1

#define HABILITAR_TLPTMR0			1
#define HABILITAR_I2C1				1

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

	bme280_data_t bme280_datos;
	uint8_t bme280_detectado=0;
	uint8_t bme280_base_de_tiempo=0;

	sht3x_data_t sht3x_datos;
	uint8_t sht3x_detectado=0;
	uint8_t sht3x_base_de_tiempo=0;


    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

#if HABILITAR_TLPTMR0
    /* Activa LPTMR0 para que iniciar contador y posterior IRQ cada 1 segundo*/
    printf("Inicializa LPTMR0:");
    LPTMR_StartTimer(LPTMR0);
    printf("OK\r\n");
#endif

#if HABILITAR_I2C1
    /* Inicializa I2C1 para lectura de sensores SHT31 y BME280*/
    //Solo avanza si es exitoso el proceso
    printf("Inicializa I2C1:");
    if(i2c1MasterInit(100000)!=kStatus_Success){	//100kbps
    	printf("Error");
    	return 0 ;
    }
    printf("OK\r\n");
#endif

#if HABILITAR_SENSOR_SHT3X
    printf("Detectando SHT3X:");
    //LLamado a funcion que identifica sensor SHT3X
    if(sht3xInit()== kStatus_Success){
    	sht3x_detectado=1;
    	printf("OK\r\n");
    }
#endif

#if HABILITAR_SENSOR_BME280
    printf("Detectando BME280:");
    //LLamado a funcion que identifica sensor BME280
    if (bme280WhoAmI() == kStatus_Success){
    	printf("OK\r\n");
    	(void)bme280Init();	//inicializa sensor bme280
    	bme280_detectado=1;	//activa bandera que indica (SI HAY BME280)
    }
#endif

    while(1) {
    	if(lptmr0_ticks!=0){
    		lptmr0_ticks=0;
        	toggleLedRojo();
        	toggleLedVerde();

    		//Busca si llegaron nuevos datos desde modem mientras esperaba
    		if (lpUart0CuantosDatosHayEnBuffer() > 0) {
    			status = lpUart0LeerByteDesdeBuffer(&nuevo_byte_uart);
    			if (status == kStatus_Success) {
    				/* Imprime byte recibido por opuerto LPUART0*/
    				printf("Nuevo byte:%c - 0x%2x\r\n",nuevo_byte_uart,nuevo_byte_uart);

    				/* Toma lectura del sensor de luz*/
    				adc_light_value=getLightADC();
    				printf("ADC Light: %d\r\n", adc_light_value);

    				/* Toma lectura de temperatura*/
    				temperature_value=getTemperatureValue();
    				printf("Temperature: %f\r\n", temperature_value);

#if HABILITAR_SENSOR_BME280
					if(bme280_detectado==1){
						bme280_base_de_tiempo++;	//incrementa base de tiempo para tomar dato bme280
						if(bme280_base_de_tiempo>10){	//	>10 equivale aproximadamente a 2s
							bme280_base_de_tiempo=0; //reinicia contador de tiempo
							if(bme280ReadData(&bme280_datos)==kStatus_Success){	//toma lectura humedad, presion, temperatura
								printf("BME280 ->");
								printf("temperatura:0x%X ",bme280_datos.temperatura);	//imprime temperatura sin procesar
								printf("humedad:0x%X ",bme280_datos.humedad);	//imprime humedad sin procesar
								printf("presion:0x%X ",bme280_datos.presion);	//imprime presion sin procesar
								printf("\r\n");	//Imprime cambio de linea
							}
						}
					}
#endif

#if HABILITAR_SENSOR_SHT3X
					if(sht3x_detectado==1){
						sht3x_base_de_tiempo++; //incrementa base de tiempo para tomar dato sensor SHT3X
						if(sht3x_base_de_tiempo>10){//	>10 equivale aproximadamente a 2s
							sht3x_base_de_tiempo=0; //reinicia contador de tiempo
							if (sht3xReadData(&sht3x_datos) == kStatus_Success) {//toma lectura humedad, temperatura
								printf("SHT3X ->");
								printf("temperatura:0x%X ",sht3x_datos.temperatura);	//imprime temperatura sin procesar
								printf("CRC8_t:0x%X ",sht3x_datos.crc_temperatura);	//imprime CRC8 de temperatura
								printf("humedad:0x%X ",sht3x_datos.humedad);	//imprime humedad sin procesar
								printf("CRC8_h:0x%X ",sht3x_datos.crc_humedad);	//imprime CRC8 de temperatura
								printf("\r\n");	//Imprime cambio de linea
							}
						}
					}
#endif

    	            printf("boton1:%d\r\n",leerBoton1());
    	            printf("boton2:%d\r\n",leerBoton2());
    	            printf("\r\n");
    			}
    		}


    	}
    }
    return 0 ;
}
