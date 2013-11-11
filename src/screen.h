#ifndef __screen_h__
#define __screen_h__

#include "ttk.h"

namespace screen {
  extern u16 width;
  extern u16 height;

  void set_color(u16 color);
  void put_pixel(u16 x, u16 y, u16 color);
  void draw(void);
}

#define RED_12(x) ((x>>8)&0xF)
#define GREEN_12(x) ((x>>4)&0xF)
#define BLUE_12(x) (x&0xF)
#define PACK_12(r,g,b) (((r&0xF)<<8) | ((g&0xF)<<4) | (b&0xF))
#endif
