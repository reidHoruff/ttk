#include "button.h"
#include "graphics.h"

Button::Button(char *text) : Widget() {
  this->text = text;
}

Button::Button(char *text, u16 x, u16 y) : Widget(x, y) {
  this->text = text;
}

void Button::render() {
  this->width();
  this->height();
  this->xposition();
  this->yposition();

  u16 text_width = this->text_len() * 6;

  gl::set_color(GREY);
  gl::fill_rect(this->rx, this->ry, this->rw, this->rh);
  
  gl::set_color(BLACK);
  gl::draw_line_hor(rx, ry+rh-1, rw);
  gl::draw_line_vert(rx+rw-1, ry, rh);

  gl::set_color(WHITE);
  gl::draw_line_hor(rx+1, ry+1, rw-3);
  gl::draw_line_vert(rx+1, ry+1, rh-3);

  gl::set_color(DARK_GREY);
  gl::draw_line_hor(rx+1, ry+rh-2, rw-2);
  gl::draw_line_vert(rx+rw-2, ry+1, rh-2);

  gl::set_color(BLACK);
  gl::print_str(this->text, this->rx + (this->rw-text_width)/2, this->ry + (this->rh-CHAR_HEIGHT)/2);
}

u16 Button::calculate_width() {
  return (this->text_len()*6) + (BUTTON_V_MARGIN*2) + 2;
}

u16 Button::calculate_height() {
  return 7 + BUTTON_V_MARGIN*2 + 2;
}

u16 Button::text_len() {
  u8 len = 0;
  while (this->text[len]) {len++;}
  return len;
}
