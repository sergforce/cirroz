//**********************************************************************
//                                                                      
// Filename: memorymap-9307a.h
//                                                                      
// Description: Memory map for the ep9307a/15a emulation and bringup board.
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
#ifndef _H_MEMORYMAP
#define _H_MEMORYMAP

//
#define PHYSICAL_ADDR_SDRAM_MAIN          PHYSICAL_ADDR_SYNC_CS0
#define PHYSICAL_ADDR_SDRAM_MAIN_BLOCK0   PHYSICAL_ADDR_SDRAM_MAIN
#define PHYSICAL_ADDR_SDRAM_MAIN_BLOCK1   (PHYSICAL_ADDR_SDRAM_MAIN + 0x4000000)

#define SDRAM_MAIN_BLOCK_SIZE               0x2000000

#define PHYSICAL_ADDR_FLASH                     PHYSICAL_ADDR_ASYNC_CS6
//
// Size of the diffent memory blocks for the boards.
//
#define SIZE_SDRAM_MAIN                        0x04000000
#define SIZE_FLASH                             0x01000000
#define SIZE_SYSTEM_ASIC_REG                   0x01000000



//************************************************************************
// Physical to virtual address conversions.
//************************************************************************
//
// Be very careful not to have any of the memory overlap.
//
#ifdef PHYSICAL_EQUAL_VIRTUAL
#define SDRAM_VIRTUAL_MEMORY                PHYSICAL_ADDR_SDRAM_MAIN
#define FLASH_VIRTUAL_MEMORY                PHYSICAL_ADDR_FLASH
#define VIRTUAL_SYSTEM_ASIC_REGS_BASE       PHYSICAL_SYSTEM_ASIC_REG_BASE
#define SDRAM_UNCACHED_VIRTUAL_MEMORY       SDRAM_VIRTUAL_MEMORY

#else // PHYSICAL_EQUAL_VIRTUAL
#define SDRAM_VIRTUAL_MEMORY                0x80000000
#define FLASH_VIRTUAL_MEMORY                0x88000000
#define VIRTUAL_SYSTEM_ASIC_REGS_BASE       (0x90000000 | 0x20000000)
#define SDRAM_UNCACHED_VIRTUAL_MEMORY       (SDRAM_VIRTUAL_MEMORY | 0x20000000)
#endif // PHYSICAL_EQUAL_VIRTUAL 

//
// Size of the blocks.
//
// Memory offsets relative to begining of SDRAM.
//
#define DRIVER_GLOBALS_MEMORY_OFFSET        0x00008000
#define CS8950_MEMORY_OFFSET                0x00010000
#define EDBG_MEMORY_OFFSET                  0x00040000
#define FRAMEBUF_MEMORY_OFFSET              0x000C0000
#define FLASH_CACHE_MEMORY_OFFSET           0x00200000


//
// SDRAM Physical address
//
#define DRIVER_GLOBALS_PHYSICAL_MEMORY      (DRIVER_GLOBALS_MEMORY_OFFSET + PHYSICAL_ADDR_SDRAM_MAIN)
#define CS8950_PHYSICAL_MEMORY              (CS8950_MEMORY_OFFSET         + PHYSICAL_ADDR_SDRAM_MAIN)
#define FRAMEBUF_PHYSICAL_MEMORY            (FRAMEBUF_MEMORY_OFFSET       + PHYSICAL_ADDR_SDRAM_MAIN)
#define EDBG_PHYSICAL_MEMORY                (EDBG_MEMORY_OFFSET           + PHYSICAL_ADDR_SDRAM_MAIN)  
#define FLASH_CACHE_PHYSICAL_MEMORY         (FLASH_CACHE_MEMORY_OFFSET    + PHYSICAL_ADDR_SDRAM_MAIN)


//
// Memory sizes for blocks inside SDRAM and flash
//
#define CS8950_MEMORY_SIZE                  0x00030000
#define FRAMEBUF_MEMORY_SIZE                0x00200000 
#define EDBG_MEMORY_SIZE                    0x00080000


//
// Add this to make an address uncached unbuffered.
//
#define UNCACHED_OFFSET                     0x20000000

#define DRIVER_GLOBALS_VIRTUAL_MEMORY       (DRIVER_GLOBALS_MEMORY_OFFSET | SDRAM_UNCACHED_VIRTUAL_MEMORY)
#define CS8950_VIRTUAL_MEMORY               (CS8950_MEMORY_OFFSET         | SDRAM_UNCACHED_VIRTUAL_MEMORY)
#define FRAMEBUF_VIRTUAL_MEMORY             (FRAMEBUF_MEMORY_OFFSET       | SDRAM_UNCACHED_VIRTUAL_MEMORY)
#define EDBG_VIRTUAL_MEMORY                 (EDBG_MEMORY_OFFSET           | SDRAM_VIRTUAL_MEMORY)

#define FLASH_CACHE_VIRTUAL_MEMORY          (FLASH_CACHE_MEMORY_OFFSET)

#endif // _H_MEMORYMAP
