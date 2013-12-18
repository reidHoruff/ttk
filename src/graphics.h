#ifndef __graphics_h__
#define __graphics_h__

#define BLACK 0
#define WHITE 0xFFFF
#define RED 0xF00
#define GREEN 0x0F0
#define BLUE 0x00F
#define GREY 0xccc
#define DARK_GREY 0xaaa


/* color theme */
#include "theme.h"

#define CHAR_HEIGHT 7
#define CHAR_WIDTH 5
#define GLYPH_HEIGHT 8
#define GLYPH_WIDTH 7

namespace gl {
  extern u16 color;

  void set_color(u16 color);
  void put_pixel(u16 x, u16 y);
  void print_str(const char *text, u16 x, u16 y);
  void print_str_b(const char *text, u16 x, u16 y);
  void draw_rect(u16 x, u16 y, u16 w, u16 h);
  void fill_rect(u16 x, u16 y, u16 w, u16 h);
  void draw_line(u16 x1, u16 y1, u16 x2, u16 y2);
  void draw_line_hor(u16 x, u16 y, u16 l);
  void draw_line_vert(u16 x, u16 y, u16 l);

  /* hgiher level graphic drawing */
  void draw_3d_rect(u16 x, u16 y, u16 w, u16 h);
  void draw_glyph(u16 x, u16 y, u8 *a);


  /* helpers */
  u16 str_width(const char *str);

  extern u8 UP_ARROW[7];
  extern u8 DOWN_ARROW[7];
  extern u8 LEFT_ARROW[7];
  extern u8 RIGHT_ARROW[7];
  extern u8 X[7];
}

#endif
