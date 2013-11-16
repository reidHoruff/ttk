#include "vertcontainer.h"
#include "../widget.h"
#include "../ttk.h"

void VerticalContainer::render() {
  this->width();
  this->height();
  this->xposition();
  this->yposition();

  for(u8 i = 0; i < this->num_children; i++) {
    this->children[i]->render();
  }
}

u16 VerticalContainer::child_height(Widget *child) {
  return this->rh / this->num_children;
}

u16 VerticalContainer::child_width(Widget *child) {
  return this->rw;
}

u16 VerticalContainer::child_ypos(Widget *child) {
  u16 frame = this->rh / this->num_children;
  return frame*child->index + frame/2 - child->rh/2;
}

u16 VerticalContainer::child_xpos(Widget *child) {
  return (this->rw - child->rw)/2;
}

void VerticalContainer::button_press(ButtonPress bp) {

}
