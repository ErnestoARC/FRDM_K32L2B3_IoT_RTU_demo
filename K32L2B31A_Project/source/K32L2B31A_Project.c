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
    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    printf("============================================================\r\n");
	printf("Size of C data types:\r\n");
	printf("Type               Bytes\r\n");
	printf("--------------------------------\r\n");
	printf("char                 %lu\r\n", sizeof(char));
	printf("int8_t               %lu\r\n", sizeof(int8_t));
	printf("unsigned char        %lu\r\n", sizeof(unsigned char));
	printf("uint8_t              %lu\r\n", sizeof(uint8_t));
	printf("short                %lu\r\n", sizeof(short));
	printf("int16_t              %lu\r\n", sizeof(int16_t));
	printf("uint16t              %lu\r\n", sizeof(uint16_t));
	printf("int                  %lu\r\n", sizeof(int));
	printf("unsigned             %lu\r\n", sizeof(unsigned));
	printf("long                 %lu\r\n", sizeof(long));
	printf("unsigned long        %lu\r\n", sizeof(unsigned long));
	printf("int32_t              %lu\r\n", sizeof(int32_t));
	printf("uint32_t             %lu\r\n", sizeof(uint32_t));
	printf("long long            %lu\r\n", sizeof(long long));
	printf("int64_t              %lu\r\n", sizeof(int64_t));
	printf("unsigned long long   %lu\r\n", sizeof(unsigned long long));
	printf("uint64_t             %lu\r\n", sizeof(uint64_t));
	printf("float                %lu\r\n", sizeof(float));
	printf("double               %lu\r\n", sizeof(double));
	printf("long double          %lu\r\n", sizeof(long double));
	printf("_Bool                %lu\r\n", sizeof(_Bool));
	printf("============================================================\r\n");
	printf("Ranges for integer data types in C\r\n");
	printf("------------------------------------------------------------\r\n");
	printf("int8_t    %20d  %20d\r\n", SCHAR_MIN, SCHAR_MAX);
	printf("int16_t   %20d  %20d\r\n", SHRT_MIN, SHRT_MAX);
	printf("int32_t   %20d  %20d\r\n", INT_MIN, INT_MAX);
	printf("int64_t   %20lld  %20lld\r\n", LLONG_MIN, LLONG_MAX);
	printf("uint8_t   %20d  %20d\r\n", 0, UCHAR_MAX);
	printf("uint16_t  %20d  %20d\r\n", 0, USHRT_MAX);
	printf("uint32_t  %20d  %20u\r\n", 0, UINT_MAX);
	printf("uint64_t  %20d  %20llu\r\n", 0, ULLONG_MAX);
	printf("\r\n");
	printf("============================================================\r\n");
	printf("Ranges for real number data types in C\r\n\r\n");
	printf("------------------------------------------------------------\r\n");
	printf("float        %14.7g  %14.7g\r\n", FLT_MIN, FLT_MAX);
	printf("double       %14.7g  %14.7g\r\n", DBL_MIN, DBL_MAX);
	printf("long double  %14.7Lg  %14.7Lg\r\n", LDBL_MIN, LDBL_MAX);
	printf("\r\n");

    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        i++ ;
        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
    }
    return 0 ;
}
