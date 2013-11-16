#include "screen.h"
#include <stdio.h>
#include "ttk.h"
#include "virtual/virtual.h"
#include <cairo.h>

u16 screen::height = 240;
u16 screen::width = 320;

void screen::set_color(u16 color) {
  cairo_set_source_rgba(
    virt::cr, 
    RED_12(color)/16.0, 
    GREEN_12(color)/16.0, 
    BLUE_12(color)/16.0, 
    1.0
  );
}

void screen::put_pixel(u16 x, u16 y, u16 color) {
  cairo_rectangle(virt::cr, x, y, 1, 1);
}

void screen::draw() {
  cairo_fill(virt::cr);
}

