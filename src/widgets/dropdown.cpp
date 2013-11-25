#include "dropdown.h"
#include "../graphics.h"
#include "../container.h"
#include "../ttk.h"
#include "popupmenu.h"

Dropdown::Dropdown(const char **options, u8 l) : Widget() {
  this->options = options;
  this->len = l;
  this->pop = NULL;
  this->selected = 0;
}

/* this context ommited in some places */
void Dropdown::render() {
  u16 text_width = this->text_len() * 6;

  gl::set_color(GREY);
  gl::fill_rect(rx, ry, rw, rh);

  gl::draw_3d_rect(rx, ry, rw, rh);

  gl::set_color(BLACK);
  gl::print_str(options[this->selected], rx + (rw-text_width)/2, ry + (rh-CHAR_HEIGHT)/2);
  gl::draw_glyph(rx+rw-GLYPH_WIDTH-SELECT_H_MARGIN, ry + (rh-GLYPH_HEIGHT)/2, gl::DOWN_ARROW);

  if (this->has_focus()) {
    gl::set_color(BLUE);
    gl::draw_rect(rx, ry, rw, rh);
  }

  if (this->pop && this->pop->visible()) {
    this->pop->request_render();
  }
}

void Dropdown::unrender() {
  gl::set_color(BACKGROUND);
  gl::fill_rect(rx, ry, rw, rh);
}

u16 Dropdown::calculate_width() {
  return (this->text_len()*6) + (SELECT_H_MARGIN*2) + 2;
}

u16 Dropdown::calculate_height() {
  return 7 + SELECT_V_MARGIN*2 + 2;
}

u16 Dropdown::text_len() {
  u8 len = 0;
  return 10;
}

void Dropdown::call_home(u16 data) {
  del(this->pop);
  this->selected = data;
  this->render();
}

/* button press handeling is for leafs */
void Dropdown::on_select() {
  if (!this->pop) {
    this->pop = new PopupMenu(this, this->options, this->len);
  }

  ttk::set_focused_widget(this->pop);
}
