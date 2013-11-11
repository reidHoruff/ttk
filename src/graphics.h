#ifndef __graphics_h__
#define __graphics_h__

#define BLACK 0
#define WHITE 0xFFF
#define RED 0xF00
#define GREEN 0x0F0
#define BLUE 0x00F
#define GREY 0xccc
#define DARK_GREY 0xaaa

#define CHAR_HEIGHT 7
#define CHAR_WIDTH 5

namespace gl {
  extern u16 color;

  void set_color(u16 color);
  void put_pixel(u16 x, u16 y);
  void print_str(char *text, u16 x, u16 y);
  void print_str_b(char *text, u16 x, u16 y);
  void draw_rect(u16 x, u16 y, u16 w, u16 h);
  void fill_rect(u16 x, u16 y, u16 w, u16 h);
  void draw_line(u16 x1, u16 y1, u16 x2, u16 y2);
  void draw_line_hor(u16 x, u16 y, u16 l);
  void draw_line_vert(u16 x, u16 y, u16 l);
}

#endif