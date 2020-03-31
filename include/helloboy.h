//################################################################################
// Small set of macros, typedefs and declarations for the GBA.
// Use the Helloboy HB_ prefix to avoid conflicts with libtonc and libgba.
//################################################################################
#ifndef HB_HELLOBOY_H
#define HB_HELLOBOY_H
#include <sys/types.h>

//################################################################################
// General
#define HB_INLINE static inline

//################################################################################


//################################################################################
// Memory sections
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
#define HB_SYSROM_P  ((u_int32_t*)HB_MEM_SYSROM)
#define HB_EWRAM_P   ((u_int16_t*)HB_MEM_EWRAM)
#define HB_IWRAM_P   ((u_int32_t*)HB_MEM_IWRAM)
#define HB_IORAM_P   ((u_int16_t*)HB_MEM_IORAM)
#define HB_PALRAM_P  ((u_int16_t*)HB_MEM_PALRAM)
#define HB_VRAM_P    ((u_int16_t*)HB_MEM_VRAM)
#define HB_OAM_P     ((u_int32_t*)HB_MEM_OAM)
#define HB_PAKROM_P  ((u_int16_t*)HB_MEM_PAKROM)
#define HB_CARTRAM_P ((u_int8_t*)MEM_CARTRAM)


//################################################################################


//################################################################################
// Video
#define HB_SCR_WIDTH  240
#define HB_SCR_HEIGHT 160

typedef u_int16_t hb_color_t;

// Predefined color values
#define HB_CLR_BLACK   0x0000
#define HB_CLR_WHITE   0x7FFF
#define HB_CLR_RED     0x001F
#define HB_CLR_LIME    0x03E0
#define HB_CLR_YELLOW  0x03FF
#define HB_CLR_BLUE    0x7C00
#define HB_CLR_MAG     0x7C1F
#define HB_CLR_CYAN    0x7FE0

HB_INLINE
hb_color_t hb_rgb15(u_int16_t r, u_int16_t g, u_int16_t b)
    /* Convert rgb value into 15-bit bgr. Only the rightmost 5 bits are used.
     * Mask parameters to avoid undefined behaviour on buffer overflow.*/
{
    return (r | ((g & 0x1F) << 5) | (b & 0x1F) << 10);
}

HB_INLINE
void hb_bitmap_plot(u_int x, u_int y, hb_color_t color)
/* Plot a pixel at given (x,y) coordinates in the vram bitmap. */
{
    HB_VRAM_P[(y*HB_SCR_WIDTH) + x] = color;
}
//################################################################################


#endif // HB_HELLOBOY_H
