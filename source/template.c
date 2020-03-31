#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <stdio.h>
#include <stdlib.h>
#include "helloboy.h"

int main(void) {    
    // the vblank interrupt must be enabled for VBlankIntrWait() to work
    // since the default dispatcher handles the bios flags no vblank handler
    // is required
    /* irqInit(); */
    /* irqEnable(IRQ_VBLANK); */

    /* consoleDemoInit(); */

    /* // ansi escape sequence to set print co-ordinates */
    /* // /x1b[line;columnH */
    /* iprintf("\x1b[10;10HHello World!\n"); */

    *(unsigned int*)0x04000000 = 0x0403;

    hb_bitmap_plot(120, 80, HB_CLR_RED);
    hb_bitmap_plot(136, 80, HB_CLR_LIME);
    hb_bitmap_plot(120, 96, HB_CLR_BLUE);

    while (1) {
	VBlankIntrWait();
    }
}


