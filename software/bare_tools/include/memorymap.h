//**********************************************************************
//                                                                      
// Filename: memorymap.h
//                                                                      
// Description: Memory map for the edb93xx emulation and bringup board.
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

// Default Chip Selects.  Assume asyncronous boot mode.
//
#define PHYSICAL_ADDR_SYNC_CS0              0xC0000000
#define PHYSICAL_ADDR_SYNC_CS1              0xD0000000
#define PHYSICAL_ADDR_SYNC_CS2              0xE0000000
#define PHYSICAL_ADDR_SYNC_CS3              0x00000000
#define PHYSICAL_ADDR_ASYNC_CS0             0xF0000000
#define PHYSICAL_ADDR_ASYNC_CS1             0x10000000
#define PHYSICAL_ADDR_ASYNC_CS2             0x20000000
#define PHYSICAL_ADDR_ASYNC_CS3             0x30000000
#define PHYSICAL_ADDR_ASYNC_CS6             0x60000000
#define PHYSICAL_ADDR_ASYNC_CS7             0x70000000
#define PHYSICAL_ADDR_PCMCIA1               0x40000000
#define PHYSICAL_ADDR_PCMCIA2               0x50000000
#define PHYSICAL_SYSTEM_ASIC_REG_BASE       0x80000000


//
// Conversion between chips selects and memory.

// For the emulation platform, memory is at CS0.
#if (EP93XX_PLATFORM_TYPE== EDB9307) ||  (EP93XX_PLATFORM_TYPE== EDB9312)  || (EP93XX_PLATFORM_TYPE== EDB9315) 
	#ifndef EP93XX_FLASH_WIDTH
	#define EP93XX_FLASH_WIDTH 32
	#endif

	#include "memorymap-1215.h"
#elif ( EP93XX_PLATFORM_TYPE == EDB9301 ) ||(EP93XX_PLATFORM_TYPE== EDB9302)

	#ifndef EP93XX_FLASH_WIDTH
	#define EP93XX_FLASH_WIDTH 16
	#endif

	#include "memorymap-01.h"

#elif EP93XX_PLATFORM_TYPE==EDB9307A || EP93XX_PLATFORM_TYPE == EDB9315A

	#ifndef EP93XX_FLASH_WIDTH
	#define EP93XX_FLASH_WIDTH 16
	#endif

	#include "memorymap-9307a.h"

#elif EP93XX_PLATFORM_TYPE == EDB9302A || EP93XX_PLATFORM_TYPE == EDB9301A

	#ifndef EP93XX_FLASH_WIDTH
	#define EP93XX_FLASH_WIDTH 16
	#endif

	#include "memorymap-9302a.h"
#else
    #error	"Error: The environment variable of the BSP type, BSP_EP93XX_PLATFORM_TYPE, is not defined."
#endif


#ifdef EP93XX_FLASH_SIZE
#undef SIZE_FLASH
#define SIZE_FLASH	EP93XX_FLASH_SIZE
#endif

#ifdef EP93XX_FLASH_PHY_ADDR
#define PHYSICAL_ADDR_FLASH EP93XX_FLASH_PHY_ADDR
#endif


#if( PHYSICAL_ADDR_FLASH ==PHYSICAL_ADDR_ASYNC_CS0)
	#define FLASH_SMC  SMC_SMCBCR0
#elif( PHYSICAL_ADDR_FLASH ==PHYSICAL_ADDR_ASYNC_CS1)
	#define FLASH_SMC  SMC_SMCBCR1
#elif( PHYSICAL_ADDR_FLASH ==PHYSICAL_ADDR_ASYNC_CS2)
	#define FLASH_SMC  SMC_SMCBCR2
#elif( PHYSICAL_ADDR_FLASH ==PHYSICAL_ADDR_ASYNC_CS3)
	#define FLASH_SMC  SMC_SMCBCR3
#elif( PHYSICAL_ADDR_FLASH ==PHYSICAL_ADDR_ASYNC_CS6)
	#define FLASH_SMC  SMC_SMCBCR6
#elif( PHYSICAL_ADDR_FLASH ==PHYSICAL_ADDR_ASYNC_CS7)
	#define FLASH_SMC  SMC_SMCBCR7
#else
	#error "Error: Flash physical address, PHYSICAL_ADDR_FLASH, is not defined."
#endif




