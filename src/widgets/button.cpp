#include "button.h"
#include "../graphics.h"

Button::Button(const char *text) : Widget() {
  this->text = text;
}

Button::Button(const char *text, u16 x, u16 y) : Widget(x, y) {
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

  gl::draw_3d_rect(rx, ry, rw, rh);

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