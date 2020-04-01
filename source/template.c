#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <stdio.h>
#include <stdlib.h>
#include "helloboy.h"

int main(void) {    
    HB_REG_DISPCNT = HB_MODE4 | HB_BG2;
    hb_setpal_bg(1, HB_CLR_CYAN);
    hb_setpal_bg(2, HB_CLR_RED);

    uint frame = 1;
    uint16_t *page = HB_FRAME0_P;
    while (1) {
	hb_vsync();
	if ((frame % 60) == 0)
	    page = hb_pageflip(page);
	
	hb_bmp4_plot(page, 120, 80, 1);
	hb_bmp4_plot(page, 136, 80, 2);
	hb_bmp4_plot(page, 120, 96, 1);

	frame++;
    }
}


