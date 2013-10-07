//**********************************************************************
//                                                                      
// Filename: hwdefs.h
//                                                                      
// Description: Contains the registers and bit fields for the EP931x 
// on chip peripherals.
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

#ifndef _H_HWDEFS
#define _H_HWDEFS
#include "memorymap.h"

//
// DMA 
//
#define DMA_BASE                    (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x00000000)
#define DMA_M2P0_TX_BASE            ((volatile ULONG *) (DMA_BASE + 0x0000))
#define DMA_M2P1_RX_BASE            ((volatile ULONG *) (DMA_BASE + 0x0040))
#define DMA_M2P2_TX_BASE            ((volatile ULONG *) (DMA_BASE + 0x0080))
#define DMA_M2P3_RX_BASE            ((volatile ULONG *) (DMA_BASE + 0x00C0))
#define DMA_M2P4_TX_BASE            ((volatile ULONG *) (DMA_BASE + 0x0240))
#define DMA_M2P5_RX_BASE            ((volatile ULONG *) (DMA_BASE + 0x0200))
#define DMA_M2P6_TX_BASE            ((volatile ULONG *) (DMA_BASE + 0x02C0))
#define DMA_M2P7_RX_BASE            ((volatile ULONG *) (DMA_BASE + 0x0280))
#define DMA_M2P8_TX_BASE            ((volatile ULONG *) (DMA_BASE + 0x0340))
#define DMA_M2P9_RX_BASE            ((volatile ULONG *) (DMA_BASE + 0x0300))
#define DMA_M2M0_BASE               ((volatile ULONG *) (DMA_BASE + 0x0100))
#define DMA_M2M1_BASE               ((volatile ULONG *) (DMA_BASE + 0x0140))
                                    
#define M2P_CTRL                    0x00
#define M2P_INT                     0x04
#define M2P_PPALLOC                 0x08
#define M2P_STATUS                  0x0C
#define M2P_REMAIN                  0x14
#define M2P_MAXCNT0                 0x20
#define M2P_BASE0                   0x24
#define M2P_CURRENT0                0x28
#define M2P_MAXCNT1                 0x30
#define M2P_BASE1                   0x34
#define M2P_CURRENT1                0x38

#define M2M_CTRL                    0x00
#define M2M_INT                     0x04
#define M2M_STATUS                  0x0C
#define M2M_BCR0                    0x10            
#define M2M_BCR1                    0x14
#define M2M_SAR_BASE0               0x18
#define M2M_SAR_BASE1               0x1C
#define M2M_SAR_CURRENT0            0x24
#define M2M_SAR_CURRENT1            0x28
#define M2M_DAR_BASE0               0x2C
#define M2M_DAR_BASE1               0x30
#define M2M_DAR_CURRENT0            0x34
#define M2M_DAR_CURRENT1            0x3C


//
// Memory to peripheral DMA Control 
//
#define M2P_CTRL_STALLINTEN         0x00000001
#define M2P_CTRL_NFBINTEN           0x00000002
#define M2P_CTRL_CHERRORINTEN       0x00000008
#define M2P_CTRL_ENABLE             0x00000010
#define M2P_CTRL_ABORT              0x00000020
#define M2P_CTRL_ICE                0x00000040


//
// DMA Perhiperal Port allocation register.
//
#define PRALLOC_MASK                0x0000000F
#define PRALLOC_I2S1                0x00000000
#define PRALLOC_I2S2                0x00000001
#define PRALLOC_AAC1                0x00000002
#define PRALLOC_AAC2                0x00000003
#define PRALLOC_AAC3                0x00000004
#define PRALLOC_I2S3                0x00000005
#define PRALLOC_UART1               0x00000006
#define PRALLOC_UART2               0x00000007
#define PRALLOC_UART3               0x00000008
#define PRALLOC_IRDA                0x00000009

//
// Memory to Perphiral DMA interrupt register.
//
#define M2P_INT_STALLINT            0x00000001
#define M2P_INT_NFBINT              0x00000002
#define M2P_INT_CHERRORINT          0x00000008


//
// Memory to Peripheral DMA status register.
//
#define M2P_STATUS_STALL            0x00000001
#define M2P_STATUS_NFB              0x00000002
#define M2P_STATUS_CHERROR          0x00000008
#define M2P_STATUS_CURRSTATE_MASK   0x00000030
#define M2P_STATUS_CURRSTATE_IDLE   0x00000000
#define M2P_STATUS_CURRSTATE_STALL  0x00000010
#define M2P_STATUS_CURRSTATE_ON     0x00000020
#define M2P_STATUS_CURRSTATE_NEXT   0x00000030
#define M2P_STATUS_NEXTBUFFER       0x00000040
#define M2P_STATUS_BYTES_MASK       0x00000F80

//
// Memory to Peripheral DMA Remain register.
//
#define REMAIN_MASK                 0x0000FFFF

//
// Memory to Peripheral DMA Max Byte count 
//
#define MAXCNTX_MASK                0x0000FFFF

//
// Memory to Peripheral  DMA base address Register
//
#define BASEX_MASK                  0xFFFFFFFF


//
// Memory to Peripheral DMA current Address Register
//
#define CURRENTX_MASK               0xFFFFFFFF


//
// Memory to Memory DMA control
//
#define M2M_CTRL_STALLINTEN         0x00000001
#define M2M_CTRL_SCT                0x00000002
#define M2M_CTRL_DONEINTEN          0x00000004
#define M2M_CTRL_ENABLE             0x00000008
#define M2M_CTRL_START              0x00000010
#define M2M_CTRL_BWC_MASK           0x000001E0
#define M2M_CTRL_BWC_FULLTRANS      0x00000000
#define M2M_CTRL_BWC_16BYTES        0x00000020
#define M2M_CTRL_BWC_32BYTES        0x000000A0
#define M2M_CTRL_BWC_64BYTES        0x000000c0
#define M2M_CTRL_BWC_128BYTES       0x000000e0
#define M2M_CTRL_BWC_256BYTES       0x00000100
#define M2M_CTRL_BWC_512BYTES       0x00000120
#define M2M_CTRL_BWC_1024BYTES      0x00000140
#define M2M_CTRL_BWC_2048BYTES      0x00000160
#define M2M_CTRL_BWC_4096BYTES      0x00000180
#define M2M_CTRL_BWC_8192BYTES      0x000001a0
#define M2M_CTRL_BWC_16384BYTES     0x000001c0
#define M2M_CTRL_BWC_32768BYTES     0x000001e0
#define M2M_CTRL_PW_MASK            0x00000600
#define M2M_CTRL_PW_BYTE            0x00000000
#define M2M_CTRL_PW_HALFWORD        0x00000200
#define M2M_CTRL_PW_WORD            0x00000400
#define M2M_CTRL_DAH                0x00000800
#define M2M_CTRL_SAH                0x00001000
#define M2M_CTRL_TM_MASK            0x00006000
#define M2M_CTRL_TM_SOFTINIT        0x00000000
#define M2M_CTRL_TM_HARDINITM2P     0x00002000
#define M2M_CTRL_TM_HARDINITP2M     0x00004000
#define M2M_CTRL_ETDP_MASK          0x00018000
#define M2M_CTRL_ETDP_ALOW_INPUT    0x00000000
#define M2M_CTRL_ETDP_AHIGH_INPUT   0x00008000
#define M2M_CTRL_ETDP_ALOW_OUTPUT   0x00010000
#define M2M_CTRL_ETDP_AHIGH_OUTPUT  0x00018000
#define M2M_CTRL_DACKP_ACTIVEHIGH   0x00020000
#define M2M_CTRL_DREQP_MASK         0x00180000
#define M2M_CTRL_DREQP_LOWLEVEL     0x00000000
#define M2M_CTRL_DREQP_HIGHLEVEL    0x00080000
#define M2M_CTRL_DREQP_LOWEDGE      0x00100000
#define M2M_CTRL_DREQP_HIGHEDGE     0x00180000
#define M2M_CTRL_NFBINTEN           0x00200000
#define M2M_CTRL_RSS_MASK           0x00C00000
#define M2M_CTRL_RSS_EXTDREQ        0x00000000
#define M2M_CTRL_RSS_INTSSPRX       0x00400000
#define M2M_CTRL_RSS_INTSSPTX       0x00800000
#define M2M_CTRL_RSS_INTIDE         0x00C00000
#define M2M_CTRL_NO_HDSK            0x01000000
#define M2M_CTRL_PWSC_MASK          0xFE000000
#define M2M_CTRL_PWSC_SHIFT         25

//
// Memory to memory DMA interrupt register definitions.
//
#define M2M_INTERRUPT_STALLIN       0x00000001
#define M2M_INTERRUPT_DONEINT       0x00000002
#define M2M_INTERRUPT_NFBINT        0x00000004

//
// Memory to memory DMA status definitions.
//
#define M2M_STATUS_STALL            0x00000001
#define M2P_STATUS_CURSTATE_MASK    0x0000000E
#define M2P_STATUS_CURSTATE_IDLE    0x00000000
#define M2P_STATUS_CURSTATE_STALL   0x00000002
#define M2P_STATUS_CURSTATE_MEMRD   0x00000004
#define M2P_STATUS_CURSTATE_MEMWR   0x00000006
#define M2M_STATUS_CURSTATE_BMCWAIT 0x00000008
#define M2P_STATUS_BUFFTATE_MASK    0x00000030
#define M2M_STATUS_BUFFSTATE_NOBUF  0x00000000
#define M2M_STATUS_BUFFSTATE_BUFON  0x00000010
#define M2M_STATUS_BUFFSTATE_NEXT   0x00000020
#define M2M_STATUS_DONE             0x00000040
#define M2M_STATUS_TCS0             0x00000080
#define M2M_STATUS_TCS1             0x00000100
#define M2M_STATUS_ETOS0            0x00000200
#define M2M_STATUS_ETOS1            0x00000400
#define M2M_STATUS_NFB              0x00000800
#define M2M_STATUS_NB               0x00001000
#define M2M_STATUS_DREQS            0x00002000

//
// Memory to Memory DMA BCRx
//
#define M2M_BCR_MASK                0x0000FFFF


//
// Ethernet 
// TODO bit patters.
//
#define ETHERNET_BASE               (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x00010000)

//
// Raster Registers.
//
#define RASTER_BASE                 (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x30000)
#define RASTER_VLINESTOTAL          ((volatile ULONG *) (RASTER_BASE + 0x000) )
#define RASTER_VSYNCSTRTSTOP        ((volatile ULONG *) (RASTER_BASE + 0x004) )
#define RASTER_VACTIVESTRTSTOP      ((volatile ULONG *) (RASTER_BASE + 0x008) )
#define RASTER_VCLKSTRTSTOP         ((volatile ULONG *) (RASTER_BASE + 0x00C) )
#define RASTER_HCLKSTOTAL           ((volatile ULONG *) (RASTER_BASE + 0x010) )
#define RASTER_HSYNCSTRTSTOP        ((volatile ULONG *) (RASTER_BASE + 0x014) )
#define RASTER_HACTIVESTRTSTOP      ((volatile ULONG *) (RASTER_BASE + 0x018) )
#define RASTER_HCLKSTRTSTOP         ((volatile ULONG *) (RASTER_BASE + 0x01C) )
#define RASTER_BRIGHTNESS           ((volatile ULONG *) (RASTER_BASE + 0x020) )
#define RASTER_VIDEOATTRIBS         ((volatile ULONG *) (RASTER_BASE + 0x024) )
#define RASTER_VIDSCRNPAGE          ((volatile ULONG *) (RASTER_BASE + 0x028) )
#define RASTER_VIDSCRNHPG           ((volatile ULONG *) (RASTER_BASE + 0x02C) )
#define RASTER_SCRNLINES            ((volatile ULONG *) (RASTER_BASE + 0x030) )
#define RASTER_LINELENGTH           ((volatile ULONG *) (RASTER_BASE + 0x034) )
#define RASTER_VLINESTEP            ((volatile ULONG *) (RASTER_BASE + 0x038) )
#define RASTER_LINECARRY            ((volatile ULONG *) (RASTER_BASE + 0x03C) )
#define RASTER_BLINKRATE            ((volatile ULONG *) (RASTER_BASE + 0x040) )
#define RASTER_BLINKMASK            ((volatile ULONG *) (RASTER_BASE + 0x044) )
#define RASTER_BLINKPATRN           ((volatile ULONG *) (RASTER_BASE + 0x048) )
#define RASTER_PATTRNMASK           ((volatile ULONG *) (RASTER_BASE + 0x04C) )
#define RASTER_BG_OFFSET            ((volatile ULONG *) (RASTER_BASE + 0x050) )
#define RASTER_PIXELMODE            ((volatile ULONG *) (RASTER_BASE + 0x054) )
#define RASTER_PARLLIFOUT           ((volatile ULONG *) (RASTER_BASE + 0x058) )
#define RASTER_PARLLIFIN            ((volatile ULONG *) (RASTER_BASE + 0x05C) )
#define RASTER_CURSOR_ADR_START     ((volatile ULONG *) (RASTER_BASE + 0x060) )
#define RASTER_CURSOR_ADR_RESET     ((volatile ULONG *) (RASTER_BASE + 0x064) )
#define RASTER_CURSORSIZE           ((volatile ULONG *) (RASTER_BASE + 0x068) )
#define RASTER_CURSORCOLOR1         ((volatile ULONG *) (RASTER_BASE + 0x06C) )
#define RASTER_CURSORCOLOR2         ((volatile ULONG *) (RASTER_BASE + 0x070) )
#define RASTER_CURSORXYLOC          ((volatile ULONG *) (RASTER_BASE + 0x074) )
#define RASTER_CURSOR_DSCAN_LH_YLOC ((volatile ULONG *) (RASTER_BASE + 0x078) )
#define RASTER_REALITI_SWLOCK       ((volatile ULONG *) (RASTER_BASE + 0x07C) )
#define RASTER_GRAYSCALE_LUT        ((volatile ULONG *) (RASTER_BASE + 0x080) )
#define RASTER_SIGVAL               ((volatile ULONG *) (RASTER_BASE + 0x200) )
#define RASTER_SIGCTL               ((volatile ULONG *) (RASTER_BASE + 0x204) )
#define RASTER_VSIGSTRTSTOP         ((volatile ULONG *) (RASTER_BASE + 0x208) )
#define RASTER_HSIGSTRTSTOP         ((volatile ULONG *) (RASTER_BASE + 0x20C) )
#define RASTER_SIGCLR               ((volatile ULONG *) (RASTER_BASE + 0x210) )
#define RASTER_ACRATE               ((volatile ULONG *) (RASTER_BASE + 0x214) )
#define RASTER_LUTCONT              ((volatile ULONG *) (RASTER_BASE + 0x218) )
#define RASTER_CURSOR_BLINK1        ((volatile ULONG *) (RASTER_BASE + 0x21C) )
#define RASTER_CURSOR_BLINK2        ((volatile ULONG *) (RASTER_BASE + 0x220) )
#define RASTER_CURSOR_BLINK         ((volatile ULONG *) (RASTER_BASE + 0x224) )
#define RASTER_VBLANKSTRTSTOP       ((volatile ULONG *) (RASTER_BASE + 0x228) )
#define RASTER_HBLANKSTRTSTOP       ((volatile ULONG *) (RASTER_BASE + 0x22C) )
#define RASTER_COLOR_LUT            ((volatile ULONG *) (RASTER_BASE + 0x400) )

//
// VLINESTOTAL
//
#define VLINESTOTAL_MASK            0x000007FFF

//
// Raster Start and Stop Masks.  Used for a bunch of the Video registers.
//
#define RASTER_START_SHIFT          0L
#define RASTER_START_MASK           0x000007FF
#define RASTER_STOP_SHIFT           16L
#define RASTER_STOP_MASK            0x07FF0000

//
// Definitions for the pixel mode register.
//
#define PIXELMODE_P13951            0x00010000
#define PIXELMODE_TRBSW             0x00008000
#define PIXELMODE_DSCAN             0x00004000
#define PIXELMODE_C_LUT             0x00000000
#define PIXELMODE_C_TRIPLE8         0x00001000
#define PIXELMODE_C_565             0x00001400
#define PIXELMODE_C_555             0x00001800
#define PIXELMODE_C_GREYSCALE       0x00002000
#define PIXELMODE_M_BLINKDISABLED   0x00000000
#define PIXELMODE_S_MODE0           0x00000000
#define PIXELMODE_S_MODE1           0x00000008
#define PIXELMODE_S_MODE2           0x00000010
#define PIXELMODE_P_4BITS           0x00000001
#define PIXELMODE_P_8BITS           0x00000002
#define PIXELMODE_P_16BITS          0x00000004
#define PIXELMODE_P_24BITS          0x00000006

//
// Video Attributes register.
//
#define VIDEOATTRIBS_EN             0x00000001
#define VIDEOATTRIBS_PCLKEN         0x00000002
#define VIDEOATTRIBS_SYNCEN         0x00000004
#define VIDEOATTRIBS_DATEN          0x00000008
#define VIDEOATTRIBS_CSYNC          0x00000010
#define VIDEOATTRIBS_VCPOL          0x00000020
#define VIDEOATTRIBS_HSPOL          0x00000040
#define VIDEOATTRIBS_BLKPOL         0x00000080
#define VIDEOATTRIBS_INVCLK         0x00000100
#define VIDEOATTRIBS_ACLEN          0x00000200
#define VIDEOATTRIBS_LCDEN          0x00000400
#define VIDEOATTRIBS_RBGEN          0x00000800
#define VIDEOATTRIBS_CCIREN         0x00001000
#define VIDEOATTRIBS_PIFEN          0x00002000
#define VIDEOATTRIBS_INTEN          0x00004000
#define VIDEOATTRIBS_INT            0x00008000
#define VIDEOATTRIBS_INTRLC         0x00010000
#define VIDEOATTRIBS_EQUSER         0x00020000
#define VIDEOATTRIBS_DHORZ          0x00040000
#define VIDEOATTRIBS_DVERT          0x00080000
#define VIDEOATTRIBS_BKPXD          0x00100000
#define VIDEOATTRIBS_SDSEL_CS0      0x00000000
#define VIDEOATTRIBS_SDSEL_CS1      0x00200000
#define VIDEOATTRIBS_SDSEL_CS2      0x00400000
#define VIDEOATTRIBS_SDSEL_CS3      0x00600000
                                    
#if (EP93XX_PLATFORM_TYPE== EDB9307) ||  (EP93XX_PLATFORM_TYPE== EDB9312)  || (EP93XX_PLATFORM_TYPE== EDB9315) 
#define VIDEOATTRIBS_SDSEL VIDEOATTRIBS_SDSEL_CS3
#endif

#if EP93XX_PLATFORM_TYPE == EDB9315A
#define VIDEOATTRIBS_SDSEL VIDEOATTRIBS_SDSEL_CS0
#endif

#if EP93XX_PLATFORM_TYPE==EDB9307A
#define VIDEOATTRIBS_SDSEL VIDEOATTRIBS_SDSEL_CS0
#endif

//
// Video Screen page register.
//
#define VIDSCRNPAGE_MASK            0x0FFFFFF0

//
// Color Lookup table control register 
//
#define LUTCONT_SSTAT               0x00000002
#define LUTCONT_SWTCH               0x00000001

//
// Color Lookup table control register 
//
#define LUTCONT_SSTAT               0x00000002
#define LUTCONT_SWTCH               0x00000001

#define CURSORSIZE_CWID_16PIXELS    0x00000000
#define CURSORSIZE_CWID_32PIXELS    0x00000001
#define CURSORSIZE_CWID_48PIXELS    0x00000002
#define CURSORSIZE_CWID_64PIXELS    0x00000003
#define CURSORSIZE_CWID_SHIFT       0
#define CURSORSIZE_CLINS_MASK       0x000000fC
#define CURSORSIZE_CLINS_SHIFT      2
#define CURSORSIZE_CSTEP_16PIXELS   0x00000000
#define CURSORSIZE_CSTEP_32PIXELS   0x00000100
#define CURSORSIZE_CSTEP_48PIXELS   0x00000200
#define CURSORSIZE_CSTEP_64PIXELS   0x00000300

#define CURSORXYLOC_CEN             0x00008000
#define CURSORXYLOC_YMASK           0x07FF0000
#define CURSORXYLOC_YSHIFT          16
#define CURSORXYLOC_XMASK           0x000007FF
#define CURSORXYLOC_XSHIFT          0


//
// USB registers.
//
#define USB_BASE                    (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x00020000)


//
// GRAPHICS (display acceleration hardware)
//

#define GRAPHICS_BASE               (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x00040000)
#define GRAPHICS_SRCPIXELSTRT       ((volatile ULONG *)(GRAPHICS_BASE + 0x0000 ))
#define GRAPHICS_DESTPIXELSTRT      ((volatile ULONG *)(GRAPHICS_BASE + 0x0004 ))
#define GRAPHICS_BLKSRCSTRT         ((volatile ULONG *)(GRAPHICS_BASE + 0x0008 ))
#define GRAPHICS_BLKDESTSTRT        ((volatile ULONG *)(GRAPHICS_BASE + 0x000C ))
#define GRAPHICS_BLKSRCWIDTH        ((volatile ULONG *)(GRAPHICS_BASE + 0x0010 ))
#define GRAPHICS_SRCLINELENGTH      ((volatile ULONG *)(GRAPHICS_BASE + 0x0014 ))
#define GRAPHICS_BLKDESTWIDTH       ((volatile ULONG *)(GRAPHICS_BASE + 0x0018 ))
#define GRAPHICS_BLKDESTHEIGHT      ((volatile ULONG *)(GRAPHICS_BASE + 0x001C ))
#define GRAPHICS_DESTLINELENGTH     ((volatile ULONG *)(GRAPHICS_BASE + 0x0020 ))
#define GRAPHICS_BLOCKCTRL          ((volatile ULONG *)(GRAPHICS_BASE + 0x0024 ))
#define GRAPHICS_TRANSPATTRN        ((volatile ULONG *)(GRAPHICS_BASE + 0x0028 ))
#define GRAPHICS_BLOCKMASK          ((volatile ULONG *)(GRAPHICS_BASE + 0x002C ))
#define GRAPHICS_BACKGROUND         ((volatile ULONG *)(GRAPHICS_BASE + 0x0030 ))
#define GRAPHICS_LINEINC            ((volatile ULONG *)(GRAPHICS_BASE + 0x0034 ))
#define GRAPHICS_LINEINIT           ((volatile ULONG *)(GRAPHICS_BASE + 0x0038 ))
#define GRAPHICS_LINEPATTRN         ((volatile ULONG *)(GRAPHICS_BASE + 0x003C ))



//#define GRAPHICS_SRCPXLST         0x000
#define SRCPIXELSTRT_PEL_MASK       0x0000001F

//#define GRAPHICS_DSTPXLST         0x001
#define DESTPIXELSTRT_EPEL_MASK     0x001F0000
#define DESTPIXELSTRT_EPEL_SHIFT    16
#define DESTPIXELSTRT_SPEL_MASK     0x0000001F
#define DESTPIXELSTRT_SPEL_SHIFT    0

//#define GRAPHICS_BLKSRCST
#define SRC_START_MASK              0xFFFFFFFC
#define DEST_START_MASK             0xFFFFFFFC

//#define GRAPHICS_BLKSRCWIDTH        0x004
#define SRC_WIDTH_MASK              0x00000FFF

//#define GRAPHICS_SRCLINELENGTH      0x005
#define SRC_LINE_LENGTH_MASK        0x00000FFF

//#define GRAPHICS_BLKDESTWIDTH       0x006
//#define DEST_WIDTH_MASK             0xfffff000
#define DEST_WIDTH_MASK             0x00000FFF

//#define GRAPHICS_BLKDESTHEIGHT      0x007
#define DEST_HEIGHT_MASK            0x000007FF

//#define GRAPHICS_DESTLINELENGTH     0x008
#define DEST_LINE_LENGTH_MASK       0x00000FFF

//#define GRAPHICS_BLOCKCTRL          0x009
//#define WRITE_BITS_MASK             0x001EFFFF
#define BLOCKCTRL_PACKD                 0x00100000

#define BLOCKCTRL_BIT_PER_PIXEL_MASK    0x000E0000
#define BLOCKCTRL_FOUR_BITS_PIXEL       0x00020000
#define BLOCKCTRL_EIGHT_BITS_PIXEL      0x00040000
#define BLOCKCTRL_SIXTEEN_BITS_PIXEL    0x00080000
#define BLOCKCTRL_TWENTYFOUR_BITS_PIXEL 0x000c0000
#define BLOCKCTRL_PIXEL_SHIFT           17

#define BLOCKCTRL_ERRORK            0x00010000
#define BLOCKCTRL_INTEOI            0x00008000
#define BLOCKCTRL_BG                0x00004000
#define BLOCKCTRL_REMAPK            0x00002000
#define BLOCKCTRL_DMODE_MASK        0x00001800

#define BLOCKCTRL_DMODE_DISABLED    0x00000000
#define BLOCKCTRL_DMODE_AND         0x00000800
#define BLOCKCTRL_DMODE_OR          0x00001000
#define BLOCKCTRL_DMODE_XOR         0x00001800
                                              
#define BLOCKCTRL_MMODE_MASK        0x00000600

#define BLOCKCTRL_MMODE_DISABLED    0x00000000
#define BLOCKCTRL_MMODE_AND         0x00000200
#define BLOCKCTRL_MMODE_OR          0x00000400
#define BLOCKCTRL_MMODE_XOR         0x00000600

#define BLOCKCTRL_SYDIR             0x00000100
#define BLOCKCTRL_SXDIR             0x00000080
#define BLOCKCTRL_DYDIR             0x00000040
#define BLOCKCTRL_DXDIR             0x00000020
#define BLOCKCTRL_LINE              0x00000010
#define BLOCKCTRL_FILL              0x00000008
#define BLOCKCTRL_TRANS             0x00000004
#define BLOCKCTRL_INTENA            0x00000002
#define BLOCKCTRL_ENABLE            0x00000001

//#define GRAPHICS_TRANSPATTRN        0x00a
#define TRANSPATTRN_MASK            0x00ffffff

//#define GRAPHICS_BLOCKMASK          0x0000000b
#define BLOCKMASK_MASK              0x00ffffff

//#define GRAPHICS_BACKGROUND         0x00c
#define BACKGROUND_MASK             0x00ffffff

//#define GRAPHICS_LINEINC          0x00d
#define LINEINC_YINC_MASK           0x0FFF0000
#define LINEINC_YINC_SHIFT          16
#define LINEINC_XINC_MASK           0x00000FFF
#define LINEINC_XINC_SHIFT          0

//#define GRAPHICS_LINEINIT         0x00e
#define LINEINIT_YINIT_MASK         0x0FFF0000
#define LINEINIT_YINIT_SHIFT        16
#define LINEINIT_XINIT_MASK         0x00000FFF
#define LINEINIT_XINIT_SHIFT        0

//#define GRAPHICS_LINEPATTRN         0x00f
#define LINEPATTRN_CNT_SHIFT        16
#define LINEPATTRN_CNT_MASK         0x000F0000
#define LINEPATTRN_PTRN_MASK        0x0000FFFF


//
// SDRAM
//
#define SDRAM_BASE                  (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x00060000)
#define SDRAM_GLOBALCFG             (volatile ULONG *)(SDRAM_BASE + 0x0004)
#define SDRAM_REFRESH               (volatile ULONG *)(SDRAM_BASE + 0x0008)
#define SDRAM_BOOTSTATUS            (volatile ULONG *)(SDRAM_BASE + 0x000C)
#define SDRAM_DEVCFG_CS0            (volatile ULONG *)(SDRAM_BASE + 0x0010)
#define SDRAM_DEVCFG_CS1            (volatile ULONG *)(SDRAM_BASE + 0x0014)
#define SDRAM_DEVCFG_CS2            (volatile ULONG *)(SDRAM_BASE + 0x0018)
#define SDRAM_DEVCFG_CS3            (volatile ULONG *)(SDRAM_BASE + 0x001C)

#define GLOBALCFG_INIT              0x00000001
#define GLOBALCFG_MRS               0x00000002
#define GLOBALCFG_SMEMBUSY          0x00000020
#define GLOBALCFG_LCR               0x00000040
#define GLOBALCFG_REARBEN           0x00000080
#define GLOBALCFG_CLKSHUTDOWN       0x40000000
#define GLOBALCFG_CKE               0x80000000


#define REFRESH_MASK                0x0000FFFF

#define BOOTSTATUS_WIDTH_32         0x00000002
#define BOOTSTATUS_WIDTH_16         0x00000001
#define BOOTSTATUS_WIDTH_8          0x00000000
#define BOOTSTATUS_WIDTH_MASK       0x00000003
#define BOOTSTATUS_MEDIA            0x00000004

#define DEVCFG_EXTBUSWIDTH          0x00000004
#define DEVCFG_BANKCOUNT            0x00000008
#define DEVCFG_SROM512              0x00000010
#define DEVCFG_SROMLL               0x00000020
#define DEVCFG_2KPAGE               0x00000040
#define DEVCFG_SFCONFIGADDR         0x00000080
#define DEVCFG_CASLAT_MASK          0x00070000
#define DEVCFG_CASLAT_2             0x00010000
#define DEVCFG_CASLAT_3             0x00020000
#define DEVCFG_CASLAT_4             0x00030000
#define DEVCFG_CASLAT_5             0x00040000
#define DEVCFG_CASLAT_6             0x00050000
#define DEVCFG_CASLAT_7             0x00060000
#define DEVCFG_CASLAT_8             0x00070000
#define DEVCFG_WBL                  0x00080000
#define DEVCFG_RASTOCAS_MASK        0x00300000
#define DEVCFG_RASTOCAS_2           0x00200000
#define DEVCFG_RASTOCAS_3           0x00300000
#define DEVCFG_AUTOPRECHARGE        0x01000000


//
// SMC and PCMCIA
// TODO bit definitions.
//
#define SMC_BASE                    (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x00080000)
#define SMC_SMCBCR0                 (volatile ULONG *)(SMC_BASE + 0x0000)
#define SMC_SMCBCR1                 (volatile ULONG *)(SMC_BASE + 0x0004)
#define SMC_SMCBCR2                 (volatile ULONG *)(SMC_BASE + 0x0008)
#define SMC_SMCBCR3                 (volatile ULONG *)(SMC_BASE + 0x000C)
#define SMC_RAZ0                    (volatile ULONG *)(SMC_BASE + 0x0010)
#define SMC_RAZ1                    (volatile ULONG *)(SMC_BASE + 0x0014)
#define SMC_SMCBCR6                 (volatile ULONG *)(SMC_BASE + 0x0018)
#define SMC_SMCBCR7                 (volatile ULONG *)(SMC_BASE + 0x001C)
#define SMC_PCCONFIG_ATT1           (volatile ULONG *)(SMC_BASE + 0x0020)
#define SMC_PCCONFIG_MEM1           (volatile ULONG *)(SMC_BASE + 0x0024)
#define SMC_PCCONFIG_IO1            (volatile ULONG *)(SMC_BASE + 0x0028)
#define SMC_RAZ2                    (volatile ULONG *)(SMC_BASE + 0x002C)
#define SMC_PCCONFIG_ATT2           (volatile ULONG *)(SMC_BASE + 0x0030)
#define SMC_PCCONFIG_MEM2           (volatile ULONG *)(SMC_BASE + 0x0034)
#define SMC_PCCONFIG_IO2            (volatile ULONG *)(SMC_BASE + 0x0038)
#define SMC_RAZ3                    (volatile ULONG *)(SMC_BASE + 0x003C)
#define SMC_PCCONT                  (volatile ULONG *)(SMC_BASE + 0x0040)


//
// Bit Fields for the SMCBCR register definition file.
//
#define SMCBCR_IDCY_MASK            0x0000000F
#define SMCBCR_IDCY_SHIFT           0
#define SMCBCR_WST1_MASK            0x000003E0
#define SMCBCR_WST1_SHIFT           5
#define SMCBCR_RBLE                 0x00000400
#define SMCBCR_WST2_MASK            0x0000F800
#define SMCBCR_WST2_SHIFT           11
#define SMCBCR_WPERR                0x02000000
#define SMCBCR_WP                   0x04000000
#define SMCBCR_PME                  0x08000000
#define SMCBCR_MASK                 0x30000000
#define SMCBCR_MW_8BIT              0x00000000
#define SMCBCR_MW_16BIT             0x10000000
#define SMCBCR_MW_32BIT             0x20000000
#define SMCBCR_EBIBRKDIS            0x40000000


//
// PCMCIA configuration registers.
//      
#define PCCONFIG_ADDRESSTIME_MASK   0x000000FF
#define PCCONFIG_ADDRESSTIME_SHIFT  0
#define PCCONFIG_HOLDTIME_MASK      0x00000F00
#define PCCONFIG_HOLDTIME_SHIFT     8
#define PCCONFIG_ACCESSTIME_MASK    0x00FF0000
#define PCCONFIG_ACCESSTIME_SHIFT   16
#define PCCONFIG_MW_8BIT            0x00000000
#define PCCONFIG_MW_16BIT           0x80000000

#define PCCONT_PC1EN                0x00000001
#define PCCONT_PC2EN                0x00000002
#define PCCONT_PC1RST               0x00000004
#define PCCONT_PC2RST               0x00000008
#define PCCONT_WEN1                 0x00000010
#define PCCONT_WEN2                 0x00000020
#define PCCONT_PREG                 0x00000040


// 
// IDE base - supports only PIO mode IDE access
//
#define IDE_BASE                    (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x000A0000)
#define IDE_CTRL                    ((volatile ULONG *) (IDE_BASE + 0x0000))
#define IDE_CFG                     ((volatile ULONG *) (IDE_BASE + 0x0004))
#define IDE_MDMAOP                  ((volatile ULONG *) (IDE_BASE + 0x0008))
#define IDE_UDMAOP                  ((volatile ULONG *) (IDE_BASE + 0x000C))
#define IDE_DATAOUT                 ((volatile ULONG *) (IDE_BASE + 0x0010))
#define IDE_DATAIN                  ((volatile ULONG *) (IDE_BASE + 0x0014))
#define IDE_MDMADATAOUT             ((volatile ULONG *) (IDE_BASE + 0x0018))
#define IDE_MDMADATAIN              ((volatile ULONG *) (IDE_BASE + 0x001C))
#define IDE_UDMADATAOUT             ((volatile ULONG *) (IDE_BASE + 0x0020))
#define IDE_UDMADATAIN              ((volatile ULONG *) (IDE_BASE + 0x0024))
#define IDE_UDMASTATUS              ((volatile ULONG *) (IDE_BASE + 0x0028))
#define IDE_UDMADEBUG               ((volatile ULONG *) (IDE_BASE + 0x002C))
#define IDE_UDMAWFST                ((volatile ULONG *) (IDE_BASE + 0x0030))
#define IDE_UDMARFST                ((volatile ULONG *) (IDE_BASE + 0x0034))


#define IDE_CTRL_CS0                0x0001
#define IDE_CTRL_CS1                0x0002
#define IDE_CTRL_DA                 0x001C
#define IDE_CTRL_DA_SHIFT           0x0002
#define IDE_CTRL_DA0                0x0004
#define IDE_CTRL_DA1                0x0008
#define IDE_CTRL_DA2                0x0010
#define IDE_CTRL_DIOR               0x0020
#define IDE_CTRL_DIOW               0x0040
#define IDE_CTRL_DASP               0x0080 //read only
#define IDE_CTRL_DMARQ              0x0100 //read only
#define IDE_CTRL_INTRQ              0x0200 //read only
#define IDE_CTRL_IORDY              0x0400 //read only

//
// Definitions to access the individial registers.
//
#define CSDA_DATA_REG               (( 0 <<IDE_CTRL_DA_SHIFT) | IDE_CTRL_CS1)   
#define CSDA_ERROR_REG              (( 1 <<IDE_CTRL_DA_SHIFT) | IDE_CTRL_CS1)   
#define CSDA_FEATURE_REG            (( 1 <<IDE_CTRL_DA_SHIFT) | IDE_CTRL_CS1)   
#define CSDA_REASON_REG             (( 2 <<IDE_CTRL_DA_SHIFT) | IDE_CTRL_CS1)   
#define CSDA_SECTCNT_REG            (( 2 <<IDE_CTRL_DA_SHIFT) | IDE_CTRL_CS1)   
#define CSDA_SECTNUM_REG            (( 3 <<IDE_CTRL_DA_SHIFT) | IDE_CTRL_CS1)   
#define CSDA_CYLL_REG               (( 4 <<IDE_CTRL_DA_SHIFT) | IDE_CTRL_CS1)   
#define CSDA_CYLH_REG               (( 5 <<IDE_CTRL_DA_SHIFT) | IDE_CTRL_CS1)   
#define CSDA_DRVHD_REG              (( 6 <<IDE_CTRL_DA_SHIFT) | IDE_CTRL_CS1)   
#define CSDA_CMD_REG                (( 7 <<IDE_CTRL_DA_SHIFT) | IDE_CTRL_CS1)   
#define CSDA_STAT_REG               (( 7 <<IDE_CTRL_DA_SHIFT) | IDE_CTRL_CS1)   


#define CSDA_ALT_CTRL_REG           (( 6 <<IDE_CTRL_DA_SHIFT) | IDE_CTRL_CS0)   
#define CSDA_ALT_STAT_REG           (( 6 <<IDE_CTRL_DA_SHIFT) | IDE_CTRL_CS0)


#define IDE_CFG_IDEEN               0x00000001
#define IDE_CFG_PIOEN               0x00000002
#define IDE_CFG_MDMAEN              0x00000004
#define IDE_CFG_UDMAEN              0x00000008
#define IDE_CFG_MODE_MASK           0x000000F0
#define IDE_CFG_MODE_SHIFT          4
#define IDE_CFG_PIO4                0x00000040
#define IDE_CFG_WST_MASK            0x00000300
#define IDE_CFG_WST_SHIFT           8

#define DMAOP_MEN                   0x00000001
#define DMAOP_RWOP                  0x00000002

#define IDE_MDMAOP_MEN              DMAOP_MEN 
#define IDE_MDMAOP_RWOP             DMAOP_RWOP
#define IDE_UDMAOP_MEN              DMAOP_MEN 
#define IDE_UDMAOP_RWOP             DMAOP_RWOP

#define UDMASTATUS_CS0              0x00000001
#define UDMASTATUS_CS1              0x00000002
#define UDMASTATUS_DA_MASK          0x0000001C
#define UDMASTATUS_HSHD             0x00000020
#define UDMASTATUS_STOP             0x00000040
#define UDMASTATUS_DM               0x00000080
#define UDMASTATUS_DDOE             0x00000100
#define UDMASTATUS_DMARQ            0x00000200
#define UDMASTATUS_DSDD             0x00000400
#define UDMASTATUS_DMAIDE           0x00010000
#define UDMASTATUS_INTIDE           0x00020000
#define UDMASTATUS_SBUSY            0x00040000
#define UDMASTATUS_NDO              0x01000000
#define UDMASTATUS_NDI              0x02000000
#define UDMASTATUS_N4X              0x04000000

#define UDMADEBUG_RWOE              0x00000001
#define UDMADEBUG_RWPTR             0x00000002
#define UDMADEBUG_RWDR              0x00000004
#define UDMADEBUG_RROE              0x00000008
#define UDMADEBUG_RRPTR             0x00000010
#define UDMADEBUG_RRDR              0x00000020       

//
// Vectored Interrupt Controller
//
#define VIC1_BASE                   (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x000B0000)
#define VIC2_BASE                   (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x000C0000)

#define VIC1_IRQSTATUS              (volatile ULONG *)(VIC1_BASE + 0x0000)
#define VIC1_FIQSTATUS              (volatile ULONG *)(VIC1_BASE + 0x0004)
#define VIC1_RAWINTR                (volatile ULONG *)(VIC1_BASE + 0x0008)
#define VIC1_INTSELECT              (volatile ULONG *)(VIC1_BASE + 0x000C)
#define VIC1_INTENABLE              (volatile ULONG *)(VIC1_BASE + 0x0010)
#define VIC1_INTCLEAR               (volatile ULONG *)(VIC1_BASE + 0x0014)
#define VIC1_SOFTINT                (volatile ULONG *)(VIC1_BASE + 0x0018)
#define VIC1_SOFTINTCLEAR           (volatile ULONG *)(VIC1_BASE + 0x001C)
#define VIC1_PROTECTION             (volatile ULONG *)(VIC1_BASE + 0x0020)

#define VIC1_VECTCURADDR            (volatile ULONG *)(VIC1_BASE + 0x0030)
#define VIC1_VECTDEFAULT            (volatile ULONG *)(VIC1_BASE + 0x0034)

#define VIC1_VECTADDR0              (volatile ULONG *)(VIC1_BASE + 0x0100)
#define VIC1_VECTADDR1              (volatile ULONG *)(VIC1_BASE + 0x0104)
#define VIC1_VECTADDR2              (volatile ULONG *)(VIC1_BASE + 0x0108)
#define VIC1_VECTADDR3              (volatile ULONG *)(VIC1_BASE + 0x010C)
#define VIC1_VECTADDR4              (volatile ULONG *)(VIC1_BASE + 0x0110)
#define VIC1_VECTADDR5              (volatile ULONG *)(VIC1_BASE + 0x0114)
#define VIC1_VECTADDR6              (volatile ULONG *)(VIC1_BASE + 0x0118)
#define VIC1_VECTADDR7              (volatile ULONG *)(VIC1_BASE + 0x011C)
#define VIC1_VECTADDR8              (volatile ULONG *)(VIC1_BASE + 0x0120)
#define VIC1_VECTADDR9              (volatile ULONG *)(VIC1_BASE + 0x0124)
#define VIC1_VECTADDR10             (volatile ULONG *)(VIC1_BASE + 0x0128)
#define VIC1_VECTADDR11             (volatile ULONG *)(VIC1_BASE + 0x012C)
#define VIC1_VECTADDR12             (volatile ULONG *)(VIC1_BASE + 0x0130)
#define VIC1_VECTADDR13             (volatile ULONG *)(VIC1_BASE + 0x0134)
#define VIC1_VECTADDR14             (volatile ULONG *)(VIC1_BASE + 0x0138)
#define VIC1_VECTADDR15             (volatile ULONG *)(VIC1_BASE + 0x013C)
#define VIC1_VECTCNTL0              (volatile ULONG *)(VIC1_BASE + 0x0200)
#define VIC1_VECTCNTL1              (volatile ULONG *)(VIC1_BASE + 0x0204)
#define VIC1_VECTCNTL2              (volatile ULONG *)(VIC1_BASE + 0x0208)
#define VIC1_VECTCNTL3              (volatile ULONG *)(VIC1_BASE + 0x020C)
#define VIC1_VECTCNTL4              (volatile ULONG *)(VIC1_BASE + 0x0210)
#define VIC1_VECTCNTL5              (volatile ULONG *)(VIC1_BASE + 0x0214)
#define VIC1_VECTCNTL6              (volatile ULONG *)(VIC1_BASE + 0x0218)
#define VIC1_VECTCNTL7              (volatile ULONG *)(VIC1_BASE + 0x021C)
#define VIC1_VECTCNTL8              (volatile ULONG *)(VIC1_BASE + 0x0220)
#define VIC1_VECTCNTL9              (volatile ULONG *)(VIC1_BASE + 0x0224)
#define VIC1_VECTCNTL10             (volatile ULONG *)(VIC1_BASE + 0x0228)
#define VIC1_VECTCNTL11             (volatile ULONG *)(VIC1_BASE + 0x022C)
#define VIC1_VECTCNTL12             (volatile ULONG *)(VIC1_BASE + 0x0230)
#define VIC1_VECTCNTL13             (volatile ULONG *)(VIC1_BASE + 0x0234)
#define VIC1_VECTCNTL14             (volatile ULONG *)(VIC1_BASE + 0x0238)
#define VIC1_VECTCNTL15             (volatile ULONG *)(VIC1_BASE + 0x023C)
#define VIC1_ITCR                   (volatile ULONG *)(VIC1_BASE + 0x0300)
#define VIC1_ITIP1                  (volatile ULONG *)(VIC1_BASE + 0x0304)
#define VIC1_ITIP2                  (volatile ULONG *)(VIC1_BASE + 0x0308)
#define VIC1_ITOP1                  (volatile ULONG *)(VIC1_BASE + 0x030C)
#define VIC1_ITOP2                  (volatile ULONG *)(VIC1_BASE + 0x0310)
#define VIC1_PERIPHID0              (volatile ULONG *)(VIC1_BASE + 0x0FE0)
#define VIC1_PERIPHID1              (volatile ULONG *)(VIC1_BASE + 0x0FE4)
#define VIC1_PERIPHID2              (volatile ULONG *)(VIC1_BASE + 0x0FE8)
#define VIC1_PERIPHID3              (volatile ULONG *)(VIC1_BASE + 0x0FEC)
#define VIC1_CELLID0                (volatile ULONG *)(VIC1_BASE + 0x0FF0)
#define VIC1_CELLID1                (volatile ULONG *)(VIC1_BASE + 0x0FF4)
#define VIC1_CELLID2                (volatile ULONG *)(VIC1_BASE + 0x0FF8)
#define VIC1_CELLID3                (volatile ULONG *)(VIC1_BASE + 0x0FFC)

#define VIC2_IRQSTATUS              (volatile ULONG *)(VIC2_BASE + 0x0000)
#define VIC2_FIQSTATUS              (volatile ULONG *)(VIC2_BASE + 0x0004)
#define VIC2_RAWINTR                (volatile ULONG *)(VIC2_BASE + 0x0008)
#define VIC2_INTSELECT              (volatile ULONG *)(VIC2_BASE + 0x000C)
#define VIC2_INTENABLE              (volatile ULONG *)(VIC2_BASE + 0x0010)
#define VIC2_INTCLEAR               (volatile ULONG *)(VIC2_BASE + 0x0014)
#define VIC2_SOFTINT                (volatile ULONG *)(VIC2_BASE + 0x0018)
#define VIC2_SOFTINTCLEAR           (volatile ULONG *)(VIC2_BASE + 0x001C)
#define VIC2_PROTECTION             (volatile ULONG *)(VIC2_BASE + 0x0020)
#define VIC2_VECTCURADDR            (volatile ULONG *)(VIC2_BASE + 0x0030)
#define VIC2_VECTDEFAULT            (volatile ULONG *)(VIC2_BASE + 0x0034)
#define VIC2_VECTADDR0              (volatile ULONG *)(VIC2_BASE + 0x0100)
#define VIC2_VECTADDR1              (volatile ULONG *)(VIC2_BASE + 0x0104)
#define VIC2_VECTADDR2              (volatile ULONG *)(VIC2_BASE + 0x0108)
#define VIC2_VECTADDR3              (volatile ULONG *)(VIC2_BASE + 0x010C)
#define VIC2_VECTADDR4              (volatile ULONG *)(VIC2_BASE + 0x0110)
#define VIC2_VECTADDR5              (volatile ULONG *)(VIC2_BASE + 0x0114)
#define VIC2_VECTADDR6              (volatile ULONG *)(VIC2_BASE + 0x0118)
#define VIC2_VECTADDR7              (volatile ULONG *)(VIC2_BASE + 0x011C)
#define VIC2_VECTADDR8              (volatile ULONG *)(VIC2_BASE + 0x0120)
#define VIC2_VECTADDR9              (volatile ULONG *)(VIC2_BASE + 0x0124)
#define VIC2_VECTADDR10             (volatile ULONG *)(VIC2_BASE + 0x0128)
#define VIC2_VECTADDR11             (volatile ULONG *)(VIC2_BASE + 0x012C)
#define VIC2_VECTADDR12             (volatile ULONG *)(VIC2_BASE + 0x0130)
#define VIC2_VECTADDR13             (volatile ULONG *)(VIC2_BASE + 0x0134)
#define VIC2_VECTADDR14             (volatile ULONG *)(VIC2_BASE + 0x0138)
#define VIC2_VECTADDR15             (volatile ULONG *)(VIC2_BASE + 0x013C)
#define VIC2_VECTCNTL0              (volatile ULONG *)(VIC2_BASE + 0x0200)
#define VIC2_VECTCNTL1              (volatile ULONG *)(VIC2_BASE + 0x0204)
#define VIC2_VECTCNTL2              (volatile ULONG *)(VIC2_BASE + 0x0208)
#define VIC2_VECTCNTL3              (volatile ULONG *)(VIC2_BASE + 0x020C)
#define VIC2_VECTCNTL4              (volatile ULONG *)(VIC2_BASE + 0x0210)
#define VIC2_VECTCNTL5              (volatile ULONG *)(VIC2_BASE + 0x0214)
#define VIC2_VECTCNTL6              (volatile ULONG *)(VIC2_BASE + 0x0218)
#define VIC2_VECTCNTL7              (volatile ULONG *)(VIC2_BASE + 0x021C)
#define VIC2_VECTCNTL8              (volatile ULONG *)(VIC2_BASE + 0x0220)
#define VIC2_VECTCNTL9              (volatile ULONG *)(VIC2_BASE + 0x0224)
#define VIC2_VECTCNTL10             (volatile ULONG *)(VIC2_BASE + 0x0228)
#define VIC2_VECTCNTL11             (volatile ULONG *)(VIC2_BASE + 0x022C)
#define VIC2_VECTCNTL12             (volatile ULONG *)(VIC2_BASE + 0x0230)
#define VIC2_VECTCNTL13             (volatile ULONG *)(VIC2_BASE + 0x0234)
#define VIC2_VECTCNTL14             (volatile ULONG *)(VIC2_BASE + 0x0238)
#define VIC2_VECTCNTL15             (volatile ULONG *)(VIC2_BASE + 0x023C)
#define VIC2_ITCR                   (volatile ULONG *)(VIC2_BASE + 0x0300)
#define VIC2_ITIP1                  (volatile ULONG *)(VIC2_BASE + 0x0304)
#define VIC2_ITIP2                  (volatile ULONG *)(VIC2_BASE + 0x0308)
#define VIC2_ITOP1                  (volatile ULONG *)(VIC2_BASE + 0x030C)
#define VIC2_ITOP2                  (volatile ULONG *)(VIC2_BASE + 0x0310)
#define VIC2_PERIPHID0              (volatile ULONG *)(VIC2_BASE + 0x0FE0)
#define VIC2_PERIPHID1              (volatile ULONG *)(VIC2_BASE + 0x0FE4)
#define VIC2_PERIPHID2              (volatile ULONG *)(VIC2_BASE + 0x0FE8)
#define VIC2_PERIPHID3              (volatile ULONG *)(VIC2_BASE + 0x0FEC)
#define VIC2_CELLID0                (volatile ULONG *)(VIC2_BASE + 0x0FF0)
#define VIC2_CELLID1                (volatile ULONG *)(VIC2_BASE + 0x0FF4)
#define VIC2_CELLID2                (volatile ULONG *)(VIC2_BASE + 0x0FF8)
#define VIC2_CELLID3                (volatile ULONG *)(VIC2_BASE + 0x0FFC)
           
           
//         
// Vic protection register definitions.
//
#define VICPROT_PROTECT             0x00000001

//
// Vector Control register.
//
#define VECTCNTL_E                  0x00000020
#define VECTCNTL_INTSOURCE          0x0000001F


//
// Interrupt bit allocation
//
#define INT1_UNUSED1                0x00000001
#define INT1_UNUSED2                0x00000002
#define INT1_COMMRX                 0x00000004
#define INT1_COMMTX                 0x00000008
#define INT1_TIMER1                 0x00000010
#define INT1_TIMER2                 0x00000020
#define INT1_AAC                    0x00000040
#define INT1_DMAM2P0                0x00000080
#define INT1_DMAM2P1                0x00000100
#define INT1_DMAM2P2                0x00000200
#define INT1_DMAM2P3                0x00000400
#define INT1_DMAM2P4                0x00000800
#define INT1_DMAM2P5                0x00001000
#define INT1_DMAM2P6                0x00002000
#define INT1_DMAM2P7                0x00004000
#define INT1_DMAM2P8                0x00008000
#define INT1_DMAM2P9                0x00010000
#define INT1_DMAM2M0                0x00020000
#define INT1_DMAM2M1                0x00040000
#define INT1_GPIO0                  0x00080000
#define INT1_GPIO1                  0x00100000
#define INT1_GPIO2                  0x00200000
#define INT1_GPIO3                  0x00400000
#define INT1_UARTRX1                0x00800000
#define INT1_UARTTX1                0x01000000
#define INT1_UARTRX2                0x02000000
#define INT1_UARTTX2                0x04000000
#define INT1_UARTRX3                0x08000000
#define INT1_UARTTX3                0x10000000
#define INT1_KEYPAD                 0x20000000
#define INT1_TOUCH                  0x40000000
#define INT1_GRAPHICS               0x80000000

#define INT2_EXT0                   0x00000001
#define INT2_EXT1                   0x00000002
#define INT2_EXT2                   0x00000004
#define INT2_TINTR                  0x00000008
#define INT2_WEINT                  0x00000010
#define INT2_RTC                    0x00000020
#define INT2_IRDA                   0x00000040
#define INT2_ETHERNET               0x00000080
#define INT2_EXT3                   0x00000100
#define INT2_PROG                   0x00000200
#define INT2_CLK1HZ                 0x00000400
#define INT2_VSYNC                  0x00000800
#define INT2_VIDEOFIFO              0x00001000
#define INT2_SSPRX                  0x00002000
#define INT2_SSPTX                  0x00004000
#define INT2_GPIO4                  0x00008000
#define INT2_GPIO5                  0x00010000
#define INT2_GPIO6                  0x00020000
#define INT2_GPIO7                  0x00040000
#define INT2_TIMER3                 0x00080000
#define INT2_UART1                  0x00100000
#define INT2_SPI                    0x00200000
#define INT2_UART2                  0x00400000
#define INT2_UART3                  0x00800000
#define INT2_USB                    0x01000000
#define INT2_PME                    0x02000000
#define INT2_DSP                    0x04000000
#define INT2_GPIO                   0x08000000
#define INT2_SAI                    0x10000000

//
// PCMCIA interrupt names
//
#define  INT1_PCMCIA_CD1            INT1_GPIO1
#define  INT1_PCMCIA_CD2            INT1_GPIO2
#define  INT1_PCMCIA_BVD1           INT1_GPIO3
#define  INT2_PCMCIA_BVD2           INT2_GPIO4
#define  INT2_PCMCIA_IRQ            INT2_GPIO6
    


//
// Timers
//
#define TIM_BASE                    (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x00810000)
#define TIM_TIMER1LOAD              (volatile ULONG *)(TIM_BASE + 0x0000)
#define TIM_TIMER1VALUE             (volatile ULONG *)(TIM_BASE + 0x0004)
#define TIM_TIMER1CONTROL           (volatile ULONG *)(TIM_BASE + 0x0008)
#define TIM_TIMER1CLEAR             (volatile ULONG *)(TIM_BASE + 0x000C)
#define TIM_TIMER2LOAD              (volatile ULONG *)(TIM_BASE + 0x0020)
#define TIM_TIMER2VALUE             (volatile ULONG *)(TIM_BASE + 0x0024)
#define TIM_TIMER2CONTROL           (volatile ULONG *)(TIM_BASE + 0x0028)
#define TIM_TIMER2CLEAR             (volatile ULONG *)(TIM_BASE + 0x002C)
#define TIM_DEBUGVALUELOW           (volatile ULONG *)(TIM_BASE + 0x0060)
#define TIM_DEBUGVALUEHIGH          (volatile ULONG *)(TIM_BASE + 0x0064)
#define TIM_TIMER3LOAD              (volatile ULONG *)(TIM_BASE + 0x0080)
#define TIM_TIMER3VALUE             (volatile ULONG *)(TIM_BASE + 0x0084)
#define TIM_TIMER3CONTROL           (volatile ULONG *)(TIM_BASE + 0x0088)
#define TIM_TIMER3CLEAR             (volatile ULONG *)(TIM_BASE + 0x008C)

//
// Timer control bits.  These are for Timers 1-3
//
#define TIMERCONTROL_CLKSEL         0x00000008
#define TIMERCONTROL_MODE           0x00000040
#define TIMERCONTROL_ENABLE         0x00000080

//
// Debug timer bit fields.
//
#define DEBUGVALUEHIGH_MASK         0x000000FF
#define DEBUGVALUEHIGH_ENABLE       0x00000100
#define DEBUGVALUELOW_MASK          0xFFFFFFFF

//
// I2S port
//
#define SAI_BASE                    (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x00820000)
#define SAI_TX_CLKCFG               (volatile ULONG *)(SAI_BASE + 0x0000)
#define SAI_RX_CLKCFG               (volatile ULONG *)(SAI_BASE + 0x0004)
#define SAI_GSR                     (volatile ULONG *)(SAI_BASE + 0x0008)
#define SAI_GCR                     (volatile ULONG *)(SAI_BASE + 0x000c)
#define SAI_TX0_LEFT                (volatile ULONG *)(SAI_BASE + 0x0010)
#define SAI_TX0_RIGHT               (volatile ULONG *)(SAI_BASE + 0x0014)
#define SAI_TX1_LEFT                (volatile ULONG *)(SAI_BASE + 0x0018)
#define SAI_TX1_RIGHT               (volatile ULONG *)(SAI_BASE + 0x001c)
#define SAI_TX2_LEFT                (volatile ULONG *)(SAI_BASE + 0x0020)
#define SAI_TX2_RIGHT               (volatile ULONG *)(SAI_BASE + 0x0024)
#define SAI_TX_LCR                  (volatile ULONG *)(SAI_BASE + 0x0028)
#define SAI_TX_CR                   (volatile ULONG *)(SAI_BASE + 0x002C)
#define SAI_TX_WL                   (volatile ULONG *)(SAI_BASE + 0x0030)
#define SAI_TX0_EN                  (volatile ULONG *)(SAI_BASE + 0x0034)
#define SAI_TX1_EN                  (volatile ULONG *)(SAI_BASE + 0x0038)
#define SAI_TX2_EN                  (volatile ULONG *)(SAI_BASE + 0x003C)
#define SAI_RX0_LEFT                (volatile ULONG *)(SAI_BASE + 0x0040)
#define SAI_RX0_RIGHT               (volatile ULONG *)(SAI_BASE + 0x0044)
#define SAI_RX1_LEFT                (volatile ULONG *)(SAI_BASE + 0x0048)
#define SAI_RX1_RIGHT               (volatile ULONG *)(SAI_BASE + 0x004c)
#define SAI_RX2_LEFT                (volatile ULONG *)(SAI_BASE + 0x0050)
#define SAI_RX2_RIGHT               (volatile ULONG *)(SAI_BASE + 0x0054)
#define SAI_RX_LCR                  (volatile ULONG *)(SAI_BASE + 0x0058)
#define SAI_RX_CR                   (volatile ULONG *)(SAI_BASE + 0x005C)
#define SAI_RX_WL                   (volatile ULONG *)(SAI_BASE + 0x0060)
#define SAI_RX0_EN                  (volatile ULONG *)(SAI_BASE + 0x0064)
#define SAI_RX1_EN                  (volatile ULONG *)(SAI_BASE + 0x0068)
#define SAI_RX2_EN                  (volatile ULONG *)(SAI_BASE + 0x006C)

#define CLKCFG_POLARITY             0x00000001
#define CLKCFG_TCKP                 0x00000002
#define CLKCFG_TREL                 0x00000004
#define CLKCFG_MST                  0x00000008
#define CLKCFG_NBCG                 0x00000010
#define CLKCFG_BCR_MASK             0x00000060
#define CLKCFG_BCR_32X              0x00000000
#define CLKCFG_BCR_64X              0x00000020
#define CLKCFG_BCR_128X             0x00000040



#define TX_LCR_TXDIR                0x00000001
#define TX_LCR_UNDERFLOW_ZERO       0x00000002
#define TX_LCR_RIGHT_JUSTIFY        0x00000004

#define TX_CR_TXHALFEMPTY          0x00000001
#define TX_CR_TXUFIE                0x00000002

#define RX_LCR_RXDIR                0x00000001
#define RX_LCR_RIGHT_JUSTIFY        0x00000002

#define RX_CR_RXHALFFULL            0x00000001
#define RX_CR_OVERFLOW_INT          0x00000002

#define WL_MASK                     0x00000003
#define WL_16BIT                    0x00000000
#define WL_24BIT                    0x00000001
#define WL_32BIT                    0x00000002


#define GSR_TX0_UNDERFLOW           0x00000001
#define GSR_TX1_UNDERFLOW           0x00000002
#define GSR_TX2_UNDERFLOW           0x00000004

#define GSR_RX0_OVERFLOW            0x00000008
#define GSR_RX1_OVERFLOW            0x00000010
#define GSR_RX2_OVERFLOW            0x00000020

#define GSR_TX0_OVERFLOW            0x00000040
#define GSR_TX1_OVERFLOW            0x00000080
#define GSR_TX2_OVERFLOW            0x00000100

#define GSR_RX0_UNDERFLOW           0x00000200
#define GSR_RX1_UNDERFLOW           0x00000400
#define GSR_RX2_UNDERFLOW           0x00000800

#define GSR_TX0_FIFO_FULL           0x00001000
#define GSR_TX0_FIFO_EMPTY          0x00002000
#define GSR_TX0_FIFO_HALF_EMPTY     0x00004000

#define GSR_RX0_FIFO_FULL           0x00008000
#define GSR_RX0_FIFO_EMPTY          0x00010000
#define GSR_RX0_FIFO_HALF_FULL      0x00020000

#define GSR_TX1_FIFO_FULL           0x00040000
#define GSR_TX1_FIFO_EMPTY          0x00080000
#define GSR_TX1_FIFO_HALF_EMPTY     0x00100000

#define RX1_FIFO_FULL               0x00200000
#define RX1_FIFO_EMPTY              0x00400000
#define RX1_FIFO_HALF_FULL          0x00800000

#define TX2_FIFO_FULL               0x01000000
#define TX2_FIFO_EMPTY              0x02000000
#define TX2_FIFO_HALF_EMPTY         0x04000000

#define RX2_FIFO_FULL               0x08000000
#define RX2_FIFO_EMPTY              0x10000000
#define RX2_FIFO_HALF_FULL          0x20000000

#define GCR_PCLK                    0x00000001
#define GCR_LOOPBACK                0x00000002


//
// GPIO port
//
#define  GPIO_BASE                  (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x00840000)
#define  GPIO_PADR                  (volatile ULONG *)(GPIO_BASE + 0x0000)
#define  GPIO_PBDR                  (volatile ULONG *)(GPIO_BASE + 0x0004)
#define  GPIO_PCDR                  (volatile ULONG *)(GPIO_BASE + 0x0008)
#define  GPIO_PDDR                  (volatile ULONG *)(GPIO_BASE + 0x000C)
#define  GPIO_PADDR                 (volatile ULONG *)(GPIO_BASE + 0x0010)
#define  GPIO_PBDDR                 (volatile ULONG *)(GPIO_BASE + 0x0014)
#define  GPIO_PCDDR                 (volatile ULONG *)(GPIO_BASE + 0x0018)
#define  GPIO_PDDDR                 (volatile ULONG *)(GPIO_BASE + 0x001C)
#define  GPIO_PEDR                  (volatile ULONG *)(GPIO_BASE + 0x0020)
#define  GPIO_PEDDR                 (volatile ULONG *)(GPIO_BASE + 0x0024)
#define  GPIO_KSCAN                 (volatile ULONG *)(GPIO_BASE + 0x0028)
#define  GPIO_PINMUX                (volatile ULONG *)(GPIO_BASE + 0x002C)
#define  GPIO_PFDR                  (volatile ULONG *)(GPIO_BASE + 0x0030)
#define  GPIO_PFDDR                 (volatile ULONG *)(GPIO_BASE + 0x0034)
#define  GPIO_PGDR                  (volatile ULONG *)(GPIO_BASE + 0x0038)
#define  GPIO_PGDDR                 (volatile ULONG *)(GPIO_BASE + 0x003C)
#define  GPIO_PHDR                  (volatile ULONG *)(GPIO_BASE + 0x0040)
#define  GPIO_PHDDR                 (volatile ULONG *)(GPIO_BASE + 0x0044)
#define  GPIO_RAZ                   (volatile ULONG *)(GPIO_BASE + 0x0048)
#define  GPIO_FINTTYPE1             (volatile ULONG *)(GPIO_BASE + 0x004C)
#define  GPIO_FINTTYPE2             (volatile ULONG *)(GPIO_BASE + 0x0050)
#define  GPIO_FEOI                  (volatile ULONG *)(GPIO_BASE + 0x0054)
#define  GPIO_INTENF                (volatile ULONG *)(GPIO_BASE + 0x0058)
#define  GPIO_INTSTATUSF            (volatile ULONG *)(GPIO_BASE + 0x005c)
#define  GPIO_RAWINTSTATUSF         (volatile ULONG *)(GPIO_BASE + 0x0060)
#define  GPIO_GPIOFDB               (volatile ULONG *)(GPIO_BASE + 0x0064)
#define  GPIO_AINTTYPE1             (volatile ULONG *)(GPIO_BASE + 0x0090)
#define  GPIO_AINTTYPE2             (volatile ULONG *)(GPIO_BASE + 0x0094)
#define  GPIO_AEOI                  (volatile ULONG *)(GPIO_BASE + 0x0098)
#define  GPIO_AINTEN                (volatile ULONG *)(GPIO_BASE + 0x009C)
#define  GPIO_INTSTATUSA            (volatile ULONG *)(GPIO_BASE + 0x00A0)
#define  GPIO_RAWINTSTATUSA         (volatile ULONG *)(GPIO_BASE + 0x00A4)
#define  GPIO_GPIOADB               (volatile ULONG *)(GPIO_BASE + 0x00A8)
#define  GPIO_BINTTYPE1             (volatile ULONG *)(GPIO_BASE + 0x00AC)
#define  GPIO_BINTTYPE2             (volatile ULONG *)(GPIO_BASE + 0x00B0)
#define  GPIO_BEOI                  (volatile ULONG *)(GPIO_BASE + 0x00B4)
#define  GPIO_BINTEN                (volatile ULONG *)(GPIO_BASE + 0x00B8)
#define  GPIO_INTSTATUSB            (volatile ULONG *)(GPIO_BASE + 0x00BC)
#define  GPIO_RAWINTSTATUSB         (volatile ULONG *)(GPIO_BASE + 0x00C0)
#define  GPIO_GPIOBDB               (volatile ULONG *)(GPIO_BASE + 0x00C4)
#define  GPIO_EEDRIVE               (volatile ULONG *)(GPIO_BASE + 0x00C8)


//
// GPIO Leds
//
#define GPIOE_RLED                  0x02
#define GPIOE_GLED                  0x01

//
// PCMCIA control signals.
// 
#define  GPIOF_PCMCIA_WP            0x01
#define  GPIOF_PCMCIA_CD1           0x02
#define  GPIOF_PCMCIA_CD2           0x04
#define  GPIOF_PCMCIA_BVD1          0x08
#define  GPIOF_PCMCIA_BVD2          0x10
#define  GPIOF_PCMCIA_VS1           0x20
#define  GPIOF_PCMCIA_IRQ           0x40
#define  GPIOF_PCMCIA_VS2           0x80

//
// EEprom control signals.
//
#define GPIOG_EECLK                 0x01
#define GPIOG_EEDAT                 0x02
#define GPIOG_SLA0                  0x04
#define GPIOG_SLA1                  0x08

//
// AAC/AC97 base
//
#define AC97I_BASE                  (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x00880000)
#define AC97I_CH1_BASE              ((volatile ULONG *)(AC97I_BASE + 0x00))
#define AC97I_CH2_BASE              ((volatile ULONG *)(AC97I_BASE + 0x20))
#define AC97I_CH3_BASE              ((volatile ULONG *)(AC97I_BASE + 0x40))
#define AC97I_CH4_BASE              ((volatile ULONG *)(AC97I_BASE + 0x60))
#define AC97I_S1DATA                ((volatile ULONG *)(AC97I_BASE + 0x80))
#define AC97I_S2DATA                ((volatile ULONG *)(AC97I_BASE + 0x84))
#define AC97I_S12DATA               ((volatile ULONG *)(AC97I_BASE + 0x88))
#define AC97I_RGIS                  ((volatile ULONG *)(AC97I_BASE + 0x8C))
#define AC97I_GIS                   ((volatile ULONG *)(AC97I_BASE + 0x90))
#define AC97I_IM                    ((volatile ULONG *)(AC97I_BASE + 0x94))
#define AC97I_EOI                   ((volatile ULONG *)(AC97I_BASE + 0x98))
#define AC97I_GCR                   ((volatile ULONG *)(AC97I_BASE + 0x9C))
#define AC97I_RESET                 ((volatile ULONG *)(AC97I_BASE + 0xA0))
#define AC97I_SYNC                  ((volatile ULONG *)(AC97I_BASE + 0xA4))
#define AC97I_GCIS                  ((volatile ULONG *)(AC97I_BASE + 0xA8))
                                                            
#define AC97I_DR                    0x00
#define AC97I_RXCR                  0x04
#define AC97I_TXCR                  0x08
#define AC97I_SR                    0x0c
#define AC97I_RISR                  0x10
#define AC97I_ISR                   0x14
#define AC97I_IE                    0x18

#define RXCR_REN                    0x00000001
#define RXCR_SLOT1                  0x00000002
#define RXCR_SLOT2                  0x00000004
#define RXCR_SLOT3                  0x00000008
#define RXCR_SLOT4                  0x00000010
#define RXCR_SLOT5                  0x00000020
#define RXCR_SLOT6                  0x00000040
#define RXCR_SLOT7                  0x00000080
#define RXCR_SLOT8                  0x00000100
#define RXCR_SLOT9                  0x00000200
#define RXCR_SLOT10                 0x00000400
#define RXCR_SLOT11                 0x00000800
#define RXCR_SLOT12                 0x00001000
#define RXCR_RSIZE_16               0x00000000
#define RXCR_RSIZE_18               0x00002000
#define RXCR_RSIZE_20               0x00004000
#define RXCR_RSIZE_12               0x00006000
#define RXCR_RSIZE_MASK             0x00006000
#define RXCR_CM                     0x00008000
#define RXCR_FDIS                   0x00010000

#define TXCR_TEN                    0x00000001
#define TXCR_SLOT1                  0x00000002
#define TXCR_SLOT2                  0x00000004
#define TXCR_SLOT3                  0x00000008
#define TXCR_SLOT4                  0x00000010
#define TXCR_SLOT5                  0x00000020
#define TXCR_SLOT6                  0x00000040
#define TXCR_SLOT7                  0x00000080
#define TXCR_SLOT8                  0x00000100
#define TXCR_SLOT9                  0x00000200
#define TXCR_SLOT10                 0x00000400
#define TXCR_SLOT11                 0x00000800
#define TXCR_SLOT12                 0x00001000
#define TXCR_RSIZE_16               0x00000000
#define TXCR_RSIZE_18               0x00002000
#define TXCR_RSIZE_20               0x00004000
#define TXCR_RSIZE_12               0x00006000
#define TXCR_RSIZE_MASK             0x00006000
#define TXCR_CM                     0x00008000
#define TXCR_FDIS                   0x00010000

#define SR_TXUE                     0x00000040
#define SR_RXOE                     0x00000020
#define SR_TXBUSY                   0x00000010
#define SR_TXFF                     0x00000008
#define SR_RXFF                     0x00000004
#define SR_TXFE                     0x00000002
#define SR_RXFE                     0x00000001

#define ISR_TCIS                    0x00000001
#define ISR_RTIS                    0x00000002
#define ISR_TIS                     0x00000004
#define ISR_RIS                     0x00000008

#define IE_TCIE                     0x00000001
#define IE_RTIE                     0x00000002
#define IE_TIE                      0x00000004
#define IE_RIE                      0x00000008

#define S1DATA_MASK                 0x000000ff
#define S2DATA_MASK                 0x0000ffff
#define S12DATA_MASK                0x00FFFFFF

#define GIS_SLOT1TXCOMPLETE         0x00000001
#define GIS_SLOT2RXVALID            0x00000002
#define GIS_GPIOTXCOMPLETE          0x00000004
#define GIS_GPIOINT                 0x00000008
#define GIS_WINT                    0x00000010
#define GIS_CODEC_READY             0x00000020
#define GIS_SLOT2TXCOMPLETE         0x00000040

#define IM_SLOT1TXCOMPLETE          0x00000001
#define IM_SLOT2RXVALID             0x00000002
#define IM_GPIOTXCOMPLETE           0x00000004
#define IM_GPIOINT                  0x00000008
#define IM_WINT                     0x00000010
#define IM_CODEC_READY              0x00000020
#define IM_SLOT2TXCOMPLETE          0x00000040

#define EOI_WINT                    0x00000001
#define EOI_CODECREADY              0x00000002

#define GCR_AC97IFE                 0x00000001
#define GCR_LOOP                    0x00000002
#define GCR_OCODECREADY             0x00000004

#define RESET_TIMEDRESET            0x00000001
#define RESET_FORCED_RESET          0x00000002
#define RESET_EFORCER               0x00000004

#define SYNC_TIMEDSYNC              0x00000001
#define SYNC_FORCEDSYNC             0x00000002
#define SYNC_EFORCES                0x00000004

#define GCIS_ISR1                   0x0000000F
#define GCIS_ISR2                   0x000000F0
#define GCIS_ISR3                   0x00000F00
#define GCIS_ISR4                   0x0000F000
#define GCIS_GIS                    0x003F0000


//
// SPI Base
//
#define SPI_BASE                    (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x008A0000)
#define SPI_CR0                     ((volatile ULONG *)(SPI_BASE + 0x0 ))
#define SPI_CR1                     ((volatile ULONG *)(SPI_BASE + 0x4 ))
#define SPI_DR                      ((volatile ULONG *)(SPI_BASE + 0x8 ))
#define SPI_SR                      ((volatile ULONG *)(SPI_BASE + 0xC ))
#define SPI_CPSR                    ((volatile ULONG *)(SPI_BASE + 0x10 ))
#define SPI_IIR                     ((volatile ULONG *)(SPI_BASE + 0x14 ))
#define SPI_ICR                     ((volatile ULONG *)(SPI_BASE + 0x14 ))

//
// SPI control register 0
//
#define SPICR0_DSS_MASK             0x0000000F
#define SPICR0_FRF_MASK             0x00000030
#define SPICR0_FRF_MOTOROLA         0x00000000
#define SPICR0_FRF_TI               0x00000010
#define SPICR0_FRF_MICROWIRE        0x00000020
#define SPICR0_SPO                  0x00000040
#define SPICR0_SPH                  0x00000080
#define SPICR0_SCR_MASK             0x0000FF00
#define SPICR0_SCR_SHIFT            8

//
// SPI control register 1
//
#define SPICR1_RIE                  0x00000001
#define SPICR1_TIE                  0x00000002
#define SPICR1_RORIE                0x00000004
#define SPICR1_LBM                  0x00000008
#define SPICR1_SSE                  0x00000010
#define SPICR1_MS                   0x00000020
#define SPICR1_SOD                  0x00000040

//
// SPI Status registers
//
#define SPISR_TFE                   0x00000001
#define SPISR_TNF                   0x00000002
#define SPISR_RNE                   0x00000004
#define SPISR_RFF                   0x00000008
#define SPISR_BUSY                  0x00000010

//
// SPI Clock prescale register.
//
#define SPICPSR_DVSR_MASK           0x0000000F

//
// SPI Interrupt status register.
//
#define SPIIIR_RIS                  0x00000001
#define SPIIIR_TIS                  0x00000002
#define SPIIIR_RORIS                0x00000004




//
// High speed IrDA 
//
#define IRDA_BASE                   (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x008B0000)
#define IRDA_IRENABLE               ((volatile ULONG *)(IRDA_BASE + 0x00  ))
#define IRDA_IRCON                  ((volatile ULONG *)(IRDA_BASE + 0x04  ))
#define IRDA_IRAMV                  ((volatile ULONG *)(IRDA_BASE + 0x08  ))
#define IRDA_IRFLAG                 ((volatile ULONG *)(IRDA_BASE + 0x0C  ))
#define IRDA_IRDATA                 ((volatile ULONG *)(IRDA_BASE + 0x10  ))
#define IRDA_IRDATATAIL             ((volatile ULONG *)(IRDA_BASE + 0x14  ))
#define IRDA_IRRIB                  ((volatile ULONG *)(IRDA_BASE + 0x20  ))
#define IRDA_MISR                   ((volatile ULONG *)(IRDA_BASE + 0x80  ))
#define IRDA_MIMR                   ((volatile ULONG *)(IRDA_BASE + 0x84  ))
#define IRDA_MIIR                   ((volatile ULONG *)(IRDA_BASE + 0x88  ))
#define IRDA_FISR                   ((volatile ULONG *)(IRDA_BASE + 0x180 ))
#define IRDA_FIMR                   ((volatile ULONG *)(IRDA_BASE + 0x184 ))
#define IRDA_FIIR                   ((volatile ULONG *)(IRDA_BASE + 0x188 ))

#define IRENABLE_FD                 0x10
#define IRENABLE_MD                 0x08
#define IRENABLE_LBM                0x04
#define IRENABLE_FIR                0x03
#define IRENABLE_MIR                0x02
#define IRENABLE_SIR                0x01
#define IRENABLE_DISABLE            0x00

#define IRCON_MUX                   0x01
#define IRCON_MIR_FAST              0x02
#define IRCON_TUS                   0x04
#define IRCON_TXE                   0x08
#define IRCON_RXE                   0x10
#define IRCON_TXP                   0x20
#define IRCON_RXP                   0x40
#define IRCON_AME                   0x80

#define IRFLAG_ABORT                0x01
#define IRFLAG_CRCERR               0x02
#define IRFLAG_OVRRUN               0x04
#define IRFLAG_FRAME                0x08
#define IRFLAG_EOF                  0x40
#define IRFLAG_SYNCED               0x80
#define IRFLAG_INFRM                0x100
#define IRFLAG_TXBUSY               0x200



//
// serial ports
//
#define PRODUCT_SER_BASE            (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x008C0000)
#define IR_SER_BASE                 (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x008D0000)
#define DEBUG_SER_BASE              (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x008E0000)
#define UART1_BASE                  (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x008C0000)
#define UART2_BASE                  (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x008D0000)
#define UART3_BASE                  (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x008E0000)



#define UART1_DR                    ((volatile ULONG *)(UART1_BASE + 0x00))
#define UART1_SR                    ((volatile ULONG *)(UART1_BASE + 0x04))
#define UART1_LCR_H                 ((volatile ULONG *)(UART1_BASE + 0x08))
#define UART1_LCR_M                 ((volatile ULONG *)(UART1_BASE + 0x0C))
#define UART1_LCR_L                 ((volatile ULONG *)(UART1_BASE + 0x10))
#define UART1_CR                    ((volatile ULONG *)(UART1_BASE + 0x14))
#define UART1_FR                    ((volatile ULONG *)(UART1_BASE + 0x18))
#define UART1_IIR                   ((volatile ULONG *)(UART1_BASE + 0x1C))
#define UART1_ILPR                  ((volatile ULONG *)(UART1_BASE + 0x20))
#define UART1_MCR                   ((volatile ULONG *)(UART1_BASE + 0x100))
#define UART1_MCS                   ((volatile ULONG *)(UART1_BASE + 0x104))


#define UART2_DR                    ((volatile ULONG *)(UART2_BASE + 0x00))
#define UART2_SR                    ((volatile ULONG *)(UART2_BASE + 0x04))
#define UART2_LCR_H                 ((volatile ULONG *)(UART2_BASE + 0x08))
#define UART2_LCR_M                 ((volatile ULONG *)(UART2_BASE + 0x0C))
#define UART2_LCR_L                 ((volatile ULONG *)(UART2_BASE + 0x10))
#define UART2_CR                    ((volatile ULONG *)(UART2_BASE + 0x14))
#define UART2_FR                    ((volatile ULONG *)(UART2_BASE + 0x18))
#define UART2_IIR                   ((volatile ULONG *)(UART2_BASE + 0x1C))
#define UART2_ILPR                  ((volatile ULONG *)(UART2_BASE + 0x20))

#define UART3_DR                    ((volatile ULONG *)(UART3_BASE + 0x00))
#define UART3_SR                    ((volatile ULONG *)(UART3_BASE + 0x04))
#define UART3_LCR_H                 ((volatile ULONG *)(UART3_BASE + 0x08))
#define UART3_LCR_M                 ((volatile ULONG *)(UART3_BASE + 0x0C))
#define UART3_LCR_L                 ((volatile ULONG *)(UART3_BASE + 0x10))
#define UART3_CR                    ((volatile ULONG *)(UART3_BASE + 0x14))
#define UART3_FR                    ((volatile ULONG *)(UART3_BASE + 0x18))
#define UART3_IIR                   ((volatile ULONG *)(UART3_BASE + 0x1C))
#define UART3_ILPR                  ((volatile ULONG *)(UART3_BASE + 0x20))

//
// UART status register definitions.
//
#define SR_OE                       0x00000008
#define SR_BE                       0x00000004
#define SR_PE                       0x00000002
#define SR_FE                       0x00000001

//
// Frame register definitions.
//
#define FR_TXFE                     0x00000080
#define FR_RXFF                     0x00000040
#define FR_TXFF                     0x00000020
#define FR_RXFE                     0x00000010
#define FR_BUSY                     0x00000008
#define FR_DCD                      0x00000004
#define FR_DSR                      0x00000002
#define FR_CTS                      0x00000001



#define LCR_H_DATABITS_MASK         0x00000060
#define LCR_H_DATABITS_8            0x00000060
#define LCR_H_DATABITS_7            0x00000040
#define LCR_H_DATABITS_6            0x00000020    
#define LCR_H_DATABITS_5            0x00000000
#define LCR_H_FIFO_ENABLE           0x00000010
#define LCR_H_STOP2_ENABLE          0x00000008
#define LCR_H_EVEN_PARITY           0x00000004
#define LCR_H_PARITY_ENABLE         0x00000002
#define LCR_H_BREAK_ENABLE          0x00000001

#define MCR_DTR                     0x00000001
#define MCR_RTS                     0x00000002
#define MCR_OUT1                    0x00000004
#define MCR_OUT2                    0x00000008
#define MCR_LOOP                    0x00000010

#define CR_LBE                      0x00000080
#define CR_RTIE                     0x00000040
#define CR_TIE                      0x00000020
#define CR_RIE                      0x00000010
#define CR_MSIE                     0x00000008
#define CR_SIRLP                    0x00000004
#define CR_SIREN                    0x00000002
#define CR_UARTE                    0x00000001

#define IIR_RTIS                    0x00000008
#define IIR_TIS                     0x00000004
#define IIR_RIS                     0x00000002
#define IIR_MIS                     0x00000001


//
// Keyboard registers.
//
#define KEYBOARD_BASE               (VIRTUAL_SYSTEM_ASIC_REGS_BASE +0x008F0000)
#define KEYBOARD_SCANINIT           ((volatile ULONG *)(KEYBOARD_BASE + 0x0000))
#define KEYBOARD_KEYDIAG            ((volatile ULONG *)(KEYBOARD_BASE + 0x0004))
#define KEYBOARD_KEYREG             ((volatile ULONG *)(KEYBOARD_BASE + 0x0008))
#define KEYBOARD_KEYTCR             ((volatile ULONG *)(KEYBOARD_BASE + 0x0010))
#define KEYBOARD_KEYTISR            ((volatile ULONG *)(KEYBOARD_BASE + 0x0014))
#define KEYBOARD_KEYTOCR            ((volatile ULONG *)(KEYBOARD_BASE + 0x0018))
#define KEYBOARD_KEYTCER            ((volatile ULONG *)(KEYBOARD_BASE + 0x001C))

#define SCANINIT_PRSCL_MASK         0x000003FF
#define SCANINIT_PRSCL_SHIFT        0L
#define SCANINIT_T2                 0x00001000
#define SCANINIT_BACK               0x00002000
#define SCANINIT_DIAG               0x00004000
#define SCANINIT_DIS3KY             0x00008000
#define SCANINIT_DBNC_MASK          0x00FF0000
#define SCANINIT_DBNC_SHIFT         16L

#define KEYDIAG_DIAG_MASK           0x0000003F

#define KEYREG_KEY1_MASK            0x0000003F
#define KEYREG_KEY1_SHIFT           0L
#define KEYREG_KEY2_MASK            0x00000Fc0
#define KEYREG_KEY2_SHIFT           6L
#define KEYREG_KEY1ROW_MASK         0x00000007
#define KEYREG_KEY1ROW_SHIFT        0L
#define KEYREG_KEY1COL_MASK         0x00000038
#define KEYREG_KEY1COL_SHIFT        3L
#define KEYREG_KEY2ROW_MASK         0x000001c0
#define KEYREG_KEY2ROW_SHIFT        6L
#define KEYREG_KEY2COL_MASK         0x00000E00
#define KEYREG_KEY2COL_SHIFT        9L

#define KEYREG_1KEY                 0x00001000
#define KEYREG_2KEYS                0x00002000
#define KEYREG_INT                  0x00004000
#define KEYREG_K                    0x00008000



//
// touch screen
//
#define TOUCH_BASE                  (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x00900000)
#define TOUCH_TSSETUP               ((volatile ULONG *)(TOUCH_BASE + 0x00 ))
#define TOUCH_TSMAXMIN              ((volatile ULONG *)(TOUCH_BASE + 0x04 ))
#define TOUCH_TSXYRESULT            ((volatile ULONG *)(TOUCH_BASE + 0x08 ))
#define TOUCH_DISCARGE              ((volatile ULONG *)(TOUCH_BASE + 0x0C ))
#define TOUCH_XSAMPLE               ((volatile ULONG *)(TOUCH_BASE + 0x10 ))
#define TOUCH_YSAMPLE               ((volatile ULONG *)(TOUCH_BASE + 0x14 ))
#define TOUCH_TSDIRECT              ((volatile ULONG *)(TOUCH_BASE + 0x18 ))
#define TOUCH_TSDETECT              ((volatile ULONG *)(TOUCH_BASE + 0x1C ))
#define TOUCH_TSSWLOCK              ((volatile ULONG *)(TOUCH_BASE + 0x20 ))
#define TOUCH_TSSETUP2              ((volatile ULONG *)(TOUCH_BASE + 0x24 ))

#define TSSETUP_SDLY_MASK           0x000003FF 
#define TSSETUP_SDLY_SHIFT          0
#define TSSETUP_NSMP_4              0x00000000
#define TSSETUP_NSMP_8              0x00000400
#define TSSETUP_NSMP_16             0x00000800
#define TSSETUP_NSMP_32             0x00000C00
#define TSSETUP_NSMP_MASK           0x00000C00
#define TSSETUP_DEV_4               0x00000000
#define TSSETUP_DEV_8               0x00001000
#define TSSETUP_DEV_12              0x00002000
#define TSSETUP_DEV_16              0x00003000
#define TSSETUP_DEV_24              0x00004000
#define TSSETUP_DEV_32              0x00005000
#define TSSETUP_DEV_64              0x00006000
#define TSSETUP_DEV_128             0x00007000
#define TSSETUP_EN                  0x00008000
#define TSSETUP_DLY_MASK            0x03FF0000
#define TSSETUP_DLY_SHIFT           16
#define TSSETUP_TDTCT               0x80000000

#define TSMAXMIN_XMIN_MASK          0x000000FF
#define TSMAXMIN_XMIN_SHIFT         0
#define TSMAXMIN_YMIN_MASK          0x0000FF00
#define TSMAXMIN_YMIN_SHIFT         8
#define TSMAXMIN_XMAX_MASK          0x00FF0000
#define TSMAXMIN_XMAX_SHIFT         16
#define TSMAXMIN_YMAX_MASK          0xFF000000
#define TSMAXMIN_YMAX_SHIFT         24

#define TSXYRESULT_X_MASK           0x00000FFF
#define TSXYRESULT_X_SHIFT          0
#define TSXYRESULT_AD_MASK          0x0000FFFF
#define TSXYRESULT_AD_SHIFT         0
#define TSXYRESULT_Y_MASK           0x0FFF0000
#define TSXYRESULT_Y_SHIFT          16
#define TSXYRESULT_SDR              0x80000000

#define TSX_SAMPLE_MASK             0x00003FFF
#define TSX_SAMPLE_SHIFT            0x00
#define TSY_SAMPLE_MASK             0x3FFF0000
#define TSY_SAMPLE_SHIFT            0x10

#define TSSETUP2_TINT               0x00000001
#define TSSETUP2_NICOR              0x00000002
#define TSSETUP2_PINT               0x00000004
#define TSSETUP2_PENSTS             0x00000008
#define TSSETUP2_PINTEN             0x00000010
#define TSSETUP2_DEVINT             0x00000020
#define TSSETUP2_DINEN              0x00000040
#define TSSETUP2_DTMEN              0x00000080
#define TSSETUP2_DISDEV             0x00000100
#define TSSETUP2_UNSIGND            0x00000200
#define TSSETUP2_S28EN              0x00000400
#define TSSETUP2_RINTEN             0x00000800
                                    
                                    
//                                  
// PWM for the touch screen         
// TODO bit definitions.
//
#define PWM_BASE                    (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x00910000)


//
// Real time clock RTC
//
#define RTC_BASE                    (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x00920000)
#define RTC_DR                      ((volatile ULONG *)(RTC_BASE + 0x0000))
#define RTC_MR                      ((volatile ULONG *)(RTC_BASE + 0x0004))
#define RTC_STAT                    ((volatile ULONG *)(RTC_BASE + 0x0008))
#define RTC_EOI                     RTC_STAT
#define RTC_LR                      ((volatile ULONG *)(RTC_BASE + 0x000C))
#define RTC_CR                      ((volatile ULONG *)(RTC_BASE + 0x0010))
              
//
// Interrupt status bit.
//          
#define STAT_INTR                    0x00000001


//
// CSC/ SYSCON
//
#define CSC_BASE                    (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x00930000)
#define CSC_PWSR                    ((volatile ULONG *)(CSC_BASE + 0x00))
#define CSC_PWRCNT                  ((volatile ULONG *)(CSC_BASE + 0x04))
#define CSC_HALT                    ((volatile ULONG *)(CSC_BASE + 0x08))
#define CSC_STBY                    ((volatile ULONG *)(CSC_BASE + 0x0C))
#define CSC_TEOI                    ((volatile ULONG *)(CSC_BASE + 0x18))
#define CSC_STFCLR                  ((volatile ULONG *)(CSC_BASE + 0x1C))
#define CSC_CLKSET1                 ((volatile ULONG *)(CSC_BASE + 0x20))
#define CSC_CLKSET2                 ((volatile ULONG *)(CSC_BASE + 0x24))
#define CSC_SCRREG0                 ((volatile ULONG *)(CSC_BASE + 0x40))
#define CSC_SCRREG1                 ((volatile ULONG *)(CSC_BASE + 0x44))
#define CSC_CLKTEST                 ((volatile ULONG *)(CSC_BASE + 0x48))
#define CSC_APBWAIT                 ((volatile ULONG *)(CSC_BASE + 0x50))
#define CSC_BMAR                    ((volatile ULONG *)(CSC_BASE + 0x54))
#define CSC_BOOTCLR                 ((volatile ULONG *)(CSC_BASE + 0x58))
#define CSC_DEVCFG                  ((volatile ULONG *)(CSC_BASE + 0x80))
#define CSC_VIDDIV                  ((volatile ULONG *)(CSC_BASE + 0x84))
#define CSC_MIRDIV                  ((volatile ULONG *)(CSC_BASE + 0x88))
#define CSC_I2SDIV                  ((volatile ULONG *)(CSC_BASE + 0x8C))
#define CSC_KTDIV                   ((volatile ULONG *)(CSC_BASE + 0x90))
#define CSC_CHIPID                  ((volatile ULONG *)(CSC_BASE + 0x94))
#define CSC_TESTCR                  ((volatile ULONG *)(CSC_BASE + 0x98))
#define CSC_SYSCFG                  ((volatile ULONG *)(CSC_BASE + 0x9C))
#define CSC_SYSLOCK                 ((volatile ULONG *)(CSC_BASE + 0xC0))

//
// Power Status register
//
#define PWSR_RTCDIV_MASK            0x0000001F
#define PWSR_RTCDIV_SHIFT           0
#define PWSR_RSTFLG                 0x00000800
#define PWSR_CKDFLG                 0x00002000
#define PWSR_LCKFLG                 0x00004000
#define PWSR_WDTFLG                 0x00008000
#define PWSR_CHIPID_MASK            0x00FF0000
#define PWSR_CHIPID_SHIFT           16
#define PWSR_CHIPMAN_MASK           0xFF000000
#define PWSR_CHIPMAN_SHIFT          24

//
// Power control register
//
#define PWRCNT_DMAM2PCH1            0x00010000
#define PWRCNT_DMAM2PCH0            0x00020000
#define PWRCNT_DMAM2PCH3            0x00040000
#define PWRCNT_DMAM2PCH2            0x00080000
#define PWRCNT_DMAM2PCH5            0x00100000
#define PWRCNT_DMAM2PCH4            0x00200000
#define PWRCNT_DMAM2PCH7            0x00400000
#define PWRCNT_DMAM2PCH6            0x00800000
#define PWRCNT_DMAM2PCH9            0x01000000
#define PWRCNT_DMAM2PCH8            0x02000000
#define PWRCNT_DMAM2MCH0            0x04000000
#define PWRCNT_DMAM2MCH1            0x08000000
#define PWRCNT_USB_EN               0x10000000
#define PWRCNT_UART_EN              0x20000000
#define PWRCNT_MIR_EN               0x40000000
#define PWRCNT_FIR_EN               0x80000000

//
// Clock set registers.
//
#define CLKSET1_PLL1_P_MASK         0x0000001F
#define CLKSET1_PLL1_P_SHIFT        0
#define CLKSET1_PLL1_M2_MASK        0x000007E0
#define CLKSET1_PLL1_M2_SHIFT       5
#define CLKSET1_PLL1_M1_MASK        0x0000F800
#define CLKSET1_PLL1_M1_SHIFT       11
#define CLKSET1_PLL1_PS_MASK        0x00030000
#define CLKSET1_PLL1_PS_SHIFT       16
#define CLKSET1_PCLK_DIV_MASK       0x000C0000
#define CLKSET1_PCLK_DIV_SHIFT      18
#define CLKSET1_HCLK_DIV_MASK       0x00700000
#define CLKSET1_HCLK_DIV_SHIFT      20
#define CLKSET1_PLL1_NBYP           0x00800000
#define CLKSET1_SMCROM              0x01000000
#define CLKSET1_FCLK_DIV_MASK       0x0E000000
#define CLKSET1_FCLK_DIV_SHIFT      25


#define CLKSET2_PLL2_P_MASK         0x0000001F
#define CLKSET2_PLL2_P_SHIFT        0
#define CLKSET2_PLL2_M2_MASK        0x000007E0
#define CLKSET2_PLL2_M2_SHIFT       5
#define CLKSET2_PLL2_M1_MASK        0x0000F800
#define CLKSET2_PLL2_M1_SHIFT       11
#define CLKSET2_PLL2_PS_MASK        0x00030000
#define CLKSET2_PLL2_PS_SHIFT       16
#define CLKSET2_PLL2_EN             0x00040000
#define CLKSET2_PLL2_NBYP           0x00080000
#define CLKSET2_USBDIV_MASK         0xF0000000
#define CLKSET2_USBDIV_SHIFT        28

#define BMAR_PRIORD_00              0x00000000
#define BMAR_PRIORD_01              0x00000001
#define BMAR_PRIORD_02              0x00000002
#define BMAR_PRIORD_03              0x00000003
#define BMAR_PRI_CORE               0x00000008
#define BMAR_DMA_ENIRQ              0x00000010
#define BMAR_DMA_ENFIQ              0x00000020
#define BMAR_USB_ENIRQ              0x00000040
#define BMAR_USB_ENFIQ              0x00000080
#define BMAR_MAC_ENIRQ              0x00000100
#define BMAR_MAC_ENFIQ              0x00000200
#define BMAR_GRAPHICS_ENIRQ         0x00000400
#define BMAR_GRAPHICS_ENFIQ         0x00000800

//
// Device Configuration
//
#define DEVCFG_SHENA                0x00000001
#define DEVCFG_KEYS                 0x00000002
#define DEVCFG_ADCPD                0x00000004
#define DEVCFG_RAS                  0x00000008
#define DEVCFG_RASONP3              0x00000010
#define DEVCFG_TTIC                 0x00000020
#define DEVCFG_I2SONAC97            0x00000040
#define DEVCFG_I2SONSSP             0x00000080
#define DEVCFG_EONIDE               0x00000100
#define DEVCFG_PONG                 0x00000200
#define DEVCFG_GONIDE               0x00000400
#define DEVCFG_HONIDE               0x00000800
#define DEVCFG_HC1CEN               0x00001000
#define DEVCFG_HC1IN                0x00002000
#define DEVCFG_HC3CEN               0x00004000
#define DEVCFG_HC3CIN               0x00008000
#define DEVCFG_TIN                  0x00020000
#define DEVCFG_U1EN                 0x00040000
#define DEVCFG_EXVC                 0x00080000
#define DEVCFG_U2EN                 0x00100000
#define DEVCFG_A1ONG                0x00200000
#define DEVCFG_A2ONG                0x00400000
#define DEVCFG_CPENA                0x00800000
#define DEVCFG_U3EN                 0x01000000
#define DEVCFG_MONG                 0x02000000
#define DEVCFG_TONG                 0x04000000
#define DEVCFG_GONK                 0x08000000
#define DEVCFG_IONU2                0x10000000
#define DEVCFG_D0ONG                0x20000000
#define DEVCFG_D1ONG                0x40000000
#define DEVCFG_SWRST                0x80000000

//
// Video Divisor
//
#define VIDDIV_VDIV_MASK            0x0000007F
#define VIDDIV_VDIV_SHIFT           0
#define VIDDIV_PDIV_OFF             0x00000000
#define VIDDIV_PDIV_2               0x00000100
#define VIDDIV_PDIV_25              0x00000200
#define VIDDIV_PDIV_3               0x00000300
#define VIDDIV_PDIV_MASK            0x00000300
#define VIDDIV_PSEL                 0x00002000
#define VIDDIV_ESEL                 0x00004000
#define VIDDIV_VENA                 0x00008000

//
// Mir Divider
//
#define MIRDIV_MDIV_MASK            0x0000007F
#define MIRDIV_MDIV_SHIFT           0
#define MIDDIV_PDIV_OFF             0x00000000
#define MIDDIV_PDIV_2               0x00000100
#define MIDDIV_PDIV_25              0x00000200
#define MIDDIV_PDIV_3               0x00000300
#define MIDDIV_PDIV_MASK            0x00000300
#define MIDDIV_PSEL                 0x00002000
#define MIDDIV_ESEL                 0x00004000
#define MIDDIV_VENA                 0x00008000

//
// I2S Divide
//
#define I2SDIV_MDIV_MASK            0x0000007F
#define I2SDIV_MDIV_SHIFT           0
#define I2SDIV_PDIV_OFF             0x00000000
#define I2SDIV_PDIV_2               0x00000100
#define I2SDIV_PDIV_25              0x00000200
#define I2SDIV_PDIV_3               0x00000300
#define I2SDIV_PDIV_MASK            0x00000300
#define I2SDIV_PSEL                 0x00002000
#define I2SDIV_ESEL                 0x00004000
#define I2SDIV_MENA                 0x00008000
#define I2SDIV_SDIV                 0x00010000
#define I2SDIV_LRDIV_MASK           0x00060000
#define I2SDIV_LRDIV_32             0x00000000
#define I2SDIV_LRDIV_64             0x00020000
#define I2SDIV_LRDIV_128            0x00040000
#define I2SDIV_SPOL                 0x00080000
#define I2SDIV_DROP                 0x00100000
#define I2SDIV_ORIDE                0x20000000
#define I2SDIV_SLAVE                0x40000000
#define I2SDIV_SENA                 0x80000000

//
// Keyboard and touch divide.
//
#define KTDIV_KDIV                  0x00000001
#define KTDIV_KEN                   0x00008000
#define KTDIV_ADIV                  0x00010000
#define KTDIV_TSEN                  0x80000000
                                    
                                 
                                 

//
// Watchdog timer
//
#define WATCHDOG_BASE               (VIRTUAL_SYSTEM_ASIC_REGS_BASE + 0x00940000)
#define WATCHDOG_WDCONTROL          ((volatile ULONG *)(WATCHDOG_BASE + 0x00))
#define WATCHDOG_WDSTATUS           ((volatile ULONG *)(WATCHDOG_BASE + 0x04))

#define WDCONTROL_DISABLE           0xAA55
#define WDCONTROL_ENABLE            0xAAAA

//
// Coprocessor MMU registers.
//
#define CP15_R1_MMU                             0x00000001
#define CP15_R1_ALIGN_FAULT                     0x00000002
#define CP15_R1_DATA_CACHE                      0x00000004
#define CP15_R1_RESERVED1                       0x00000038
#define CP15_R1_BIG_ENDIAN                      0x00000040
#define CP15_R1_SYSTEM_PROTECTION               0x00000080
#define CP15_R1_ROM_PROTECTION                  0x00000100
#define CP15_R1_INSTRUCTION_CACHE               0x00001000
#define CP15_R1_ROUND_ROBIN                     0x00002000
#define CP15_R1_NOT_FASTBUS                     0x40000000
#define CP15_R1_ASYNCHRONOUS                    0x80000000

//Other boards for EP931X registers.

#endif // _H_HWDEFS
