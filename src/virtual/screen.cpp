#include "../screen.h"
#include "../ttk.h"
#include "../virtual/virtual.h"
#include <cairo.h>

u16 screen::height = 128;
u16 screen::width = 128;
u16 screen::color = 0;

#define SET_COLOR(color) \
  cairo_set_source_rgba(\
    virt::cr,\
    RED_12(color)/16.0,\
    GREEN_12(color)/16.0,\
    BLUE_12(color)/16.0,\
    1.0\
  )

#define PUT_PIX(x, y)\
  cairo_rectangle(virt::cr, x, y, 1, 1);

u16* mem1 = new u16[screen::width*screen::height];

void screen::set_color(u16 color) {
  screen::color = color;
}

void screen::put_pixel(u16 x, u16 y, u16 color) {
  mem1[screen::width*y+x] = color;
}

void screen::draw() {
  //log("draw\n");

  u16 last_color = 0;
  SET_COLOR(last_color);

  for (u16 y=0; y < screen::height; y++) {
    for (u16 x=0; x < screen::width; x++) {
      u16 color = mem1[screen::width*y+x];

      if (color != last_color) {
        SET_COLOR(color);
        last_color = color;
      }

      PUT_PIX(x, y);
      cairo_fill(virt::cr);
    }
  }

  //log("complete\n");
}

