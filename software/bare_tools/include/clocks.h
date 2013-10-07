//**********************************************************************
//                                                                      
// Filename: clocks.h 
//                                                                      
// Description: Header file for the clocks.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Use of this source code is subject to the terms of the Cirrus end-user
// license agreement (EULA) under which you licensed this SOFTWARE PRODUCT.
// If you did not accept the terms of the EULA, you are not authorized to 
// use this source code. For a copy of the EULA, please see the 
// EULA.RTF on your install media.
//
// Copyright(c) Cirrus Logic Corporation 2005, All Rights Reserved                       
//                                                                      
//**********************************************************************
#ifndef _H_CLOCKS
#define _H_CLOCKS

#if (EP93XX_PLATFORM_TYPE== EDB9307) ||  (EP93XX_PLATFORM_TYPE== EDB9312)  || (EP93XX_PLATFORM_TYPE== EDB9315) 

	#define     FCLOCK                  200

#elif	EP93XX_PLATFORM_TYPE == EDB9301

	#define     FCLOCK                  166

#elif	EP93XX_PLATFORM_TYPE == EDB9302

	#define     FCLOCK                  200

#elif	EP93XX_PLATFORM_TYPE == EDB9315A

//	#define     FCLOCK                  200
	#define     FCLOCK                  166

#elif	EP93XX_PLATFORM_TYPE==EDB9307A

	#define     FCLOCK                  200

#elif	EP93XX_PLATFORM_TYPE ==EDB9302A

	#define     FCLOCK                  200

#elif	EP93XX_PLATFORM_TYPE ==EDB9301A

	#define     FCLOCK                  166

#endif      // FCLOCK


//**********************************************************************
//
// PLL1 Clock =400  Mhz
// FClock    = 200  Mhz
// HCLock    = 100   Mhz
// PClock    = 50   Mhz
//
//
//**********************************************************************
#if (FCLOCK == 200)
#define     FDIV                    1
#define     HDIV                    2
#define     PDIV                    1
#define     PRE_CLKSET1_VALUE       0x0080a3d7
#define     PLL1_CLOCK              399974400
#endif // (FCLOCK == 200)



//**********************************************************************
//
// PLL1 Clock =368  Mhz
// FClock    = 184  Mhz
// HCLock    = 73   Mhz
// PClock    = 46   Mhz
//
//
//**********************************************************************
#if (FCLOCK == 184)
#define     FDIV                    1
#define     HDIV                    2
#define     PDIV                    1
#define     PRE_CLKSET1_VALUE       0x0080ab15
#define     PLL1_CLOCK              368640000
#endif // (FCLOCK == 184)              
#if (FCLOCK == 166)
#define     FDIV                    1
#define     HDIV                    3
#define     PDIV                    1
//#define     PRE_CLKSET1_VALUE       0x0080fa5a
//#define     PLL1_CLOCK              332049054
#define     PRE_CLKSET1_VALUE        0x00809907
#define     PLL1_CLOCK              331776000
#endif // (FCLOCK == 166)              



#define     REAL_HDIV           ((1  * (HDIV == 0))  + \
                                 (2  * (HDIV == 1))  + \
                                 (4  * (HDIV == 2))  + \
                                 (5  * (HDIV == 3))  + \
                                 (6  * (HDIV == 4))  + \
                                 (8  * (HDIV == 5))  + \
                                 (16 * (HDIV == 6))  + \
                                 (32 * (HDIV == 7)))

#define     REAL_FCLOCK         (PLL1_CLOCK / (1<<FDIV))
#define     REAL_HCLOCK         (PLL1_CLOCK / REAL_HDIV)
#define     REAL_PCLOCK         (REAL_HCLOCK/ (1<<PDIV))
#define     CLKSET1_VALUE       (PRE_CLKSET1_VALUE |                \
                                (PDIV <<CLKSET1_PCLK_DIV_SHIFT)|    \
                                (HDIV <<CLKSET1_HCLK_DIV_SHIFT)|    \
                                (FDIV <<CLKSET1_FCLK_DIV_SHIFT))
//
// Value for the PLL 2 register.
// 
//#define     CLKSET2_VALUE           0x100ec317
//#define     PLL2_CLOCK              96000000

//
// For lower power use this setting.
//
#define     CLKSET2_VALUE           0x300dc317
#define     PLL2_CLOCK              192000000

//
// For USB requires an exact clock of 48Mhz multiple.
//
// For I2S audio requires a clock of an approx multiple
// of 11.2896MHz.  384Mhz/34 = 11.2944Mhz 
// 
//
//#define     CLKSET2_VALUE           0x700cc317
//#define     PLL2_CLOCK              384000000
                

//
//
// Ex Clock
//
#define     EX_CLOCK                14745600


//**********************************************************************
//
// Divisors to get the other clocks to come out right.
//
//**********************************************************************
#define     TIMER_508KHZ_FREQ       (EX_CLOCK / 29)
#define     TIMER_2KHZ_FREQ         (EX_CLOCK / 7373)
#define     TIMER_DEBUG_FREQ        (EX_CLOCK / 15)

//
// The timer frequency is based off of EX_CLOCK
//
#define     OEM_CLOCK_FREQ          TIMER_508KHZ_FREQ

//
// Timer count for 1 ms
//
#define     OEM_COUNT_1MS           (OEM_CLOCK_FREQ/1000)

//
// Reschedule period in ms
//
#define     RESCHED_PERIOD          1

//
// Timer count value for rescheduler period for 1 ms system tick.
//
//              
//
#define     RESCHED_INCREMENT       (OEM_COUNT_1MS*RESCHED_PERIOD)

//
// Maximum time that we can idle in milliseconds
//
#define     IDLE_MAX_MS             ((0x10000 /OEM_COUNT_1MS) - 1)

//****************************************************************************
// SDRAM refresh calculation
//****************************************************************************
// This is the time in uS between refreshes.
//
//
//
#define     SDRAM_REFRESH_TIME          8
#define     SDRAM_REFRESH_VALUE         ((REAL_HCLOCK / 1000000) * SDRAM_REFRESH_TIME)
#define     SDRAM_14MHZ_REFRESH_VALUE   ((EX_CLOCK / 1000000) * SDRAM_REFRESH_TIME)


//****************************************************************************
// Serial port Divisors.
//****************************************************************************
// 
//
// Current UART Divisor.
//
#define     UART_CLOCK              (EX_CLOCK/2)
#define     UART_DIVISOR(BAUDRATE)  ((UART_CLOCK/(16 * BAUDRATE)) -1)


//****************************************************************************
// Calculate Flash and SMC wait states
//****************************************************************************
//#define WAIT_STATES_150NS       (1 + ((REAL_HCLOCK / 1000000) * 150 ) / 1000 )
#define WAIT_STATES(NanoSeconds)  ((((REAL_HCLOCK / 1000000) * NanoSeconds  + 999) / 1000)  - 1)  
//#define WAIT_STATES_150NS       (1 + ((REAL_HCLOCK / 1000000) * 200 ) / 1000 )
//#define WAIT_STATES_75NS        (1 + ((REAL_HCLOCK / 1000000) * 75  ) / 1000 )


#endif // _H_CLOCKS







                                              
