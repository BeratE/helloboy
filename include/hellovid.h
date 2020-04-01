//################################################################################
// Video
// Note: Each bitmap entry in vram is a halfword.
//################################################################################
#ifndef HB_HELLOVID_H
#define HB_HELLOVID_H
#include "helloboy.h"
#include "hellomem.h"
#include <sys/types.h>

#define HB_SCR_WIDTH  240
#define HB_SCR_HEIGHT 160

// Color
typedef u_int16_t hb_color_t; // 15-bit Color
typedef u_int8_t  hb_clrid_t; // 8-bit Color Index

// Predefined color values
#define HB_CLR_BLACK   0x0000
#define HB_CLR_WHITE   0x7FFF
#define HB_CLR_RED     0x001F
#define HB_CLR_LIME    0x03E0
#define HB_CLR_YELLOW  0x03FF
#define HB_CLR_BLUE    0x7C00
#define HB_CLR_MAG     0x7C1F
#define HB_CLR_CYAN    0x7FE0

// Inline functions
static inline hb_color_t hb_rgb15(int r, int g, int b)
/* Convert rgb value into 15-bit bgr. Only the rightmost 5 bits are used.
 * Mask parameters to avoid undefined behaviour on buffer overflow. */
{
    return (r | ((g & 0x1F) << 5) | (b & 0x1F) << 10);
}

// Palette
static inline void hb_setpal_bg(hb_clrid_t id, hb_color_t color)
/* Set the given id in the background palette to the given color.
 * ID 0 is the background fill color. */
{
  HB_PALRAM_P[0x0000 + id] = color;
}


static inline hb_color_t hb_getpal_bg(hb_clrid_t id)
/* Return the color value found in the background with the given id. */
{
  return HB_PALRAM_P[0x0000 + id];
}

static inline void hb_setpal_sprite(hb_clrid_t id, hb_color_t color)
/* Set the given id in the sprite palette to the given color.*/
{
  HB_PALRAM_P[0x0200 + id] = color;
}

static inline hb_color_t hb_getpal_sprite(hb_clrid_t id)
/* Return the color value found in the background with the given id. */
{
  return HB_PALRAM_P[0x0200 + id];
}


// Bitmap Mode Plotting
static inline void hb_bmp3_plot(int x, int y, hb_color_t color)
/* Write a 15-bit color value into the appropiate location in VRAM. */
{
    HB_VRAM_P[(y*HB_SCR_WIDTH) + x] = color;
}

static inline void hb_bmp4_plot(int x, int y, hb_clrid_t clrid)
/* Write the 8-bit color id into the appropiate location in VRAM. */
{
    u_int16_t *dst = &HB_VRAM_P[((y*HB_SCR_WIDTH) +x)/2];
    if (x & 1) {
	*dst = (*dst & 0x00FF) | (clrid << 8);
    } else {
	*dst = (*dst & 0xFF00) | (clrid << 0);
    }
}

//################################################################################
// 
#endif // HB_HELLOVID_H
