#include "verttabs.h"
#include "../widget.h"
#include "../ttk.h"
#include "../graphics.h"

VerticalTabs::VerticalTabs(const char **names, u8 tabs) {
  this->ntabs = tabs;
  this->names = names;
  this->cur_tab = 0;
}

void VerticalTabs::render() {
  //draw border
  gl::set_color(BLACK);
  gl::draw_rect(rx, ry, rw, rh);

  u16 x = rx; 
  for (u8 i=0; i<ntabs; i++) {
    gl::print_str(names[i], x, ry+VTABS_TAB_V_PADDING);
    x += gl::str_width(names[i]) + 5;
    log("%d\n", x);
  }
  
  gl::draw_line_hor(rx, ry+VTABS_TAB_V_PADDING+VTABS_TAB_V_PADDING+CHAR_HEIGHT, rw);
}

u16 VerticalTabs::child_height(Widget *child) {
  return 0;
}

u16 VerticalTabs::child_width(Widget *child) {
  return 0;
}

u16 VerticalTabs::child_ypos(Widget *child) {
  return 0;
}

u16 VerticalTabs::child_xpos(Widget *child) {
  return 0;
}

bool VerticalTabs::button_press_up(ButtonPress bp, Widget *child) {
  return true;
}

void VerticalTabs::button_press_down(ButtonPress bp) {
}
