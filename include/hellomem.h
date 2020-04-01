//################################################################################
// Memory
//################################################################################
#ifndef HB_HELLOMEM_H
#define HB_HELLOMEM_H
#include <stdint.h>

#define HB_MEM_SYSROM  0x00000000 // 0000:3FFF  16kb   32bit
#define HB_MEM_EWRAM   0x02000000 // 0203:FFFF	256kb  16bit
#define HB_MEM_IWRAM   0x03000000 // 0300:7FFF	32kb   32bit
#define HB_MEM_IORAM   0x04000000 // 0400:03FF	1kb    16bit
#define HB_MEM_PALRAM  0x05000000 // 0500:03FF	1kb    16bit
#define HB_MEM_VRAM    0x06000000 // 0601:7FFF	96kb   16bit
#define HB_MEM_OAM     0x07000000 // 0700:03FF	1kb    32bit
#define HB_MEM_PAKROM  0x08000000 // var	var    16bit
#define HB_MEM_CARTRAM 0x0E000000 // var        var    8bit


// Pointer to memory
#define HB_SYSROM_P  ((uint32_t *)HB_MEM_SYSROM)
#define HB_EWRAM_P   ((uint16_t *)HB_MEM_EWRAM)
#define HB_IWRAM_P   ((uint32_t *)HB_MEM_IWRAM)
#define HB_IORAM_P   ((uint32_t *)HB_MEM_IORAM)
#define HB_PALRAM_P  ((uint16_t *)HB_MEM_PALRAM)
#define HB_VRAM_P    ((uint16_t *)HB_MEM_VRAM)
#define HB_OAM_P     ((uint32_t *)HB_MEM_OAM)
#define HB_PAKROM_P  ((uint16_t *)HB_MEM_PAKROM)
#define HB_CARTRAM_P ((uint8_t *)MEM_CARTRAM)

#define HB_FRAME0_P &((uint16_t *)HB_MEM_VRAM)[0x0000]
#define HB_FRAME1_P &((uint16_t *)HB_MEM_VRAM)[0xA000]


// Memory Mapped IO Registers
// LCD IO
#define HB_REG_DISPCNT 	*((volatile uint32_t *)(HB_MEM_IORAM + 0x00))
#define HB_REG_DISPSTAT *((volatile uint32_t *)(HB_MEM_IORAM + 0x04))
#define HB_REG_VCOUNT 	*((volatile uint32_t *)(HB_MEM_IORAM + 0x06))
#define HB_REG_BG0CNT 	*((volatile uint32_t *)(HB_MEM_IORAM + 0x08))
#define HB_REG_BG1CNT 	*((volatile uint32_t *)(HB_MEM_IORAM + 0x0A))
#define HB_REG_BG2CNT 	*((volatile uint32_t *)(HB_MEM_IORAM + 0x0C))
#define HB_REG_BG3CNT 	*((volatile uint32_t *)(HB_MEM_IORAM + 0x0E))
#define HB_REG_BG0HOFS  *((volatile uint32_t *)(HB_MEM_IORAM + 0x10))
#define HB_REG_BG0VOFS  *((volatile uint32_t *)(HB_MEM_IORAM + 0x12))
#define HB_REG_BG1HOFS  *((volatile uint32_t *)(HB_MEM_IORAM + 0x14))
#define HB_REG_BG1VOFS  *((volatile uint32_t *)(HB_MEM_IORAM + 0x16))
#define HB_REG_BG2HOFS  *((volatile uint32_t *)(HB_MEM_IORAM + 0x18))
#define HB_REG_BG2VOFS  *((volatile uint32_t *)(HB_MEM_IORAM + 0x1A))
#define HB_REG_BG3HOFS  *((volatile uint32_t *)(HB_MEM_IORAM + 0x1C))
#define HB_REG_BG3VOFS  *((volatile uint32_t *)(HB_MEM_IORAM + 0x1E))


// Register Flags
// REG_DISPCNT LCD IO Display Control
typedef enum {
  /* Mode  Rot/Scal Layers Size               Tiles Colors       Features
   * 0     No       0123   256x256..512x515   1024  16/16..256/1 SFMABP
   * 1     Mixed    012-   (BG0,BG1 as above Mode 0, BG2 as below Mode 2)
   * 2     Yes      --23   128x128..1024x1024 256   256/1        S-MABP
   * 3     Yes      --2-   240x160            1     32768        --MABP
   * 4     Yes      --2-   240x160            2     256/1        --MABP
   * 5     Yes      --2-   160x128            2     32768        --MABP
   * S)crolling, F)lip, M)osaic, A)lphaBlending, B)rightness, P)riority. */
    HB_MODE0 	   = 0x0000, 
    HB_MODE1 	   = 0x0001,
    HB_MODE2 	   = 0x0002,
    HB_MODE3 	   = 0x0003,
    HB_MODE4 	   = 0x0004,
    HB_MODE5 	   = 0x0005,
    HB_GBC_MODE    = 0x0008, // Set by BIOS opcodes
    HB_FRAME_SLCT  = 0x0010, // Mode 4,5 Select display frame
    HB_OAM_ACCESS  = 0x0020, // H-Blank interval free, access to OAM during H-Blank
    HB_OBJ_MAP     = 0x0040, // Object Character VRAM Mapping 0=2D, 1=1D
    HB_FORCE_BLANK = 0x0080, // 1=Allow fast access to VRAM, OAM and Palette
    HB_BG0   	   = 0x0100,
    HB_BG1   	   = 0x0200,
    HB_BG2   	   = 0x0400,
    HB_BG3   	   = 0x0800,
    HB_OBJ   	   = 0x1000,
    HB_WIN0        = 0x2000, // Window 0 Display Flag
    HB_WIN1        = 0x4000, // Window 1 Display Flag
    HB_OBJWIN      = 0x8000  // Object Window Display Flag
} HB_DISPCNT_FLAG;

// REG_DISPSTAT LCD IO Interrupts and Status
typedef enum {
    HB_VBLANK = 0x0000,     // VBlank line 160..226 (read-only)
    HB_HBLAN = 0x0001,      // HBlank (read-only)
    HB_VCOUNT = 0x0002,     // 1= VCount in Setting register matched (read-only)
    HB_HBLANK_IRQ = 0x0004, // HBlank IRQ Enable
    HB_VBLANK_IRQ = 0x0008, // VBlank IRQ Enable
    HB_VCOUNT_IRQ = 0x0010, // V-Counter IRQ Enable
    HB_VCOUNT_LYC = 0xFF00  // V-Count setting for match (bit 2) and irq (bit 5)
} HB_DISPSTAT_FLAG;
//################################################################################

#endif // HB_HELLOMEM_H
