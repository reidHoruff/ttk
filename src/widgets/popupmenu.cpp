#include "popupmenu.h"
#include "../ttk.h"
#include "../graphics.h"
#include "../screen.h"

PopupMenu::PopupMenu(Widget *owner, const char **text, u8 l) {
  this->len = l;
  this->text = text;
  this->selected = 0;
  this->set_visible(false);
  this->owner = owner;
}

void PopupMenu::render() {
  width();
  height();
  xposition();
  yposition();

  //draw border
  gl::set_color(BLACK);
  gl::draw_rect(rx, ry, rw, rh);
  
  //draw background
  gl::set_color(WHITE);
  gl::fill_rect(rx+1, ry+1, rw-2, rh-2);

  //text
  gl::set_color(BLACK);
  for (u8 i = 0; i < len; i++) { 
    if (i == selected) {
      gl::print_str_b(text[i], rx+3, i*15+5+ry);
    } else {
      gl::print_str(text[i], rx+3, i*15+5+ry);
    }
  }
}

void PopupMenu::unrender() {
  /* this can be optimized; but since 
   * this window will overlap other widgets when it is removed
   * from the screen it is easiest to juse re render everything
   */
  ttk::render();
}

u16 PopupMenu::width() {
  this->rw = 100;
  return this->rw;
}

u16 PopupMenu::height() {
  this->rh = len*15+5;
  return this->rh;
}

/* make sure that width() and height() are called first */
u16 PopupMenu::xposition() {
  if (owner->rx + rw > screen::width) {
    this->rx = screen::width - rw;
  } else {
    this->rx = this->owner->rx;
  }

  return this->rx;
}

/* make sure that width() and height() are called first */
u16 PopupMenu::yposition() {
  if (owner->ry + owner->rh + this->rh > screen::height) {
    this->ry = screen::height - this->rh;
  } else {
    this->ry = owner->ry + owner->rh;
  }
  return this->ry;
}


void PopupMenu::hide() {
  this->set_visible(false);
  ttk::set_focused_widget(this->owner);
  this->selected = 0;
}

/* button press handeling is for leafs */
bool PopupMenu::button_press_up(ButtonPress bp, Widget *child) {
  switch (bp) {
    case UP:
      if (this->selected == 0) {
        this->hide();
        break;
      }
      this->selected--;
      break;

    case DOWN:
      this->selected++;
      this->selected %= this->len;
      break;

    case SELECT:
      this->hide();
      break;

    case LEFT:
      this->hide();
      break;

    case RIGHT:
      break;

    defaule:
      break;
  }
  return true;
}

