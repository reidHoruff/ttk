#include "button.h"
#include "../graphics.h"
#include "../container.h"
#include "../ttk.h"

Button::Button(const char *text) {
  this->text = text;
}

void Button::render() {
  u16 text_width = this->text_len() * (CHAR_WIDTH+1);

  //background color
  gl::set_color(GREY);
  gl::fill_rect(rx, ry, rw, rh);

  //3d looking border; win98 esque
  gl::draw_3d_rect(rx, ry, rw, rh);

  //draw text
  gl::set_color(BLACK);
  gl::print_str(text, rx + (rw-text_width)/2, ry + (rh-CHAR_HEIGHT)/2);

  //halo
  if (this->has_focus()) {
    gl::set_color(BLUE);
    gl::draw_rect(rx, ry, rw, rh);
  }
}

void Button::unrender() {
  gl::set_color(BACKGROUND);
  gl::fill_rect(rx, ry, rw, rh);
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

