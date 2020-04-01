//################################################################################
// Memory
/*
System ROM 	0000:0000 - 0000:3FFF	16kb	32bit 	BIOS Read-Only Memory
EWRAM	 	0200:0000 - 0203:FFFF	256kb	16bit 	External Work RAM
IWRAM	 	0300:0000 - 0300:7FFF	32kb	32bit 	Internal Work RAM
IORAM	 	0400:0000 - 0400:03FF	1kb	16bit 	Memory Mapped IO
PALRAM	 	0500:0000 - 0500:03FF	1kb	16bit 	Sprite+Background Palette
VRAM	 	0600:0000 - 0601:7FFF	96kb	16bit 	Video RAM
OAM	 	0700:0000 - 0700:03FF	1kb	32bit 	Object Attribute Memory
PAK ROM	 	0800:0000 - var		var	16bit 	Game Pak ROM
CART RAM	0E00:0000 - var		var	8bit 	Save Data
*/
//################################################################################
#ifndef HB_HELLOMEM_H
#define HB_HELLOMEM_H
#include <sys/types.h>

// Section definitions
#define HB_MEM_SYSROM  0x00000000
#define HB_MEM_EWRAM   0x02000000
#define HB_MEM_IWRAM   0x03000000
#define HB_MEM_IORAM   0x04000000
#define HB_MEM_PALRAM  0x05000000
#define HB_MEM_VRAM    0x06000000
#define HB_MEM_OAM     0x07000000
#define HB_MEM_PAKROM  0x08000000
#define HB_MEM_CARTRAM 0x0E000000

// Pointer to memory
#define HB_SYSROM_P  ((u_int32_t *)HB_MEM_SYSROM)
#define HB_EWRAM_P   ((u_int16_t *)HB_MEM_EWRAM)
#define HB_IWRAM_P   ((u_int32_t *)HB_MEM_IWRAM)
#define HB_IORAM_P   ((u_int32_t *)HB_MEM_IORAM)
#define HB_PALRAM_P  ((u_int16_t *)HB_MEM_PALRAM)
#define HB_VRAM_P    ((u_int16_t *)HB_MEM_VRAM)
#define HB_OAM_P     ((u_int32_t *)HB_MEM_OAM)
#define HB_PAKROM_P  ((u_int16_t *)HB_MEM_PAKROM)
#define HB_CARTRAM_P ((u_int8_t  *)MEM_CARTRAM)

// Memory Mapped IO Registers
// LCD IO
#define HB_REG_DISPCNT 	*((volatile u_int32_t *)(HB_MEM_IORAM + 0x00))
#define HB_REG_DISPSTAT *((volatile u_int32_t *)(HB_MEM_IORAM + 0x04))
#define HB_REG_VCOUNT 	*((volatile u_int32_t *)(HB_MEM_IORAM + 0x06))
#define HB_REG_BG0CNT 	*((volatile u_int32_t *)(HB_MEM_IORAM + 0x08))
#define HB_REG_BG1CNT 	*((volatile u_int32_t *)(HB_MEM_IORAM + 0x0A))
#define HB_REG_BG2CNT 	*((volatile u_int32_t *)(HB_MEM_IORAM + 0x0C))
#define HB_REG_BG3CNT 	*((volatile u_int32_t *)(HB_MEM_IORAM + 0x0E))
#define HB_REG_BG0HOFS  *((volatile u_int32_t *)(HB_MEM_IORAM + 0x10))
#define HB_REG_BG0VOFS  *((volatile u_int32_t *)(HB_MEM_IORAM + 0x12))
#define HB_REG_BG1HOFS  *((volatile u_int32_t *)(HB_MEM_IORAM + 0x14))
#define HB_REG_BG1VOFS  *((volatile u_int32_t *)(HB_MEM_IORAM + 0x16))
#define HB_REG_BG2HOFS  *((volatile u_int32_t *)(HB_MEM_IORAM + 0x18))
#define HB_REG_BG2VOFS  *((volatile u_int32_t *)(HB_MEM_IORAM + 0x1A))
#define HB_REG_BG3HOFS  *((volatile u_int32_t *)(HB_MEM_IORAM + 0x1C))
#define HB_REG_BG3VOFS  *((volatile u_int32_t *)(HB_MEM_IORAM + 0x1E))

// Register Flags
// REG_DISPCNT
typedef enum {
  HB_MODE0 	= 0x0000,
  HB_MODE1 	= 0x0001,
  HB_MODE2 	= 0x0002,
  HB_MODE3 	= 0x0003,
  HB_MODE4 	= 0x0004,
  HB_MODE5 	= 0x0005,
  HB_BG0   	= 0x0100,
  HB_BG1   	= 0x0200,
  HB_BG2   	= 0x0400,
  HB_BG3   	= 0x0800,
  HB_OBJ   	= 0x1000
} HB_DISPCNT_FLAG;
//################################################################################

#endif // HB_HELLOMEM_H
