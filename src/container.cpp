#include "container.h"
#include "widget.h"
#include "graphics.h"
#include "ttk.h"

Container::Container() : Widget() {
  this->set_fill_container(true);
  this->children = new Widget*[DEFAULT_CONTAINED_ELEMENTS];
  this->num_children = 0;
}

void Container::render() {
  for(u16 i = 0; i < this->num_children; i++) {
    this->children[i]->request_render();
  }
}

void Container::unrender() {
  //log("unrender\n");
  /* its probably faster, in most cases, to just
   * erase the whole owning area instead of erasing
   * each child; this could cause errors where the children arent 
   * all rendered inside of the container bounds
   */
  gl::set_color(BACKGROUND);
  gl::fill_rect(rx, ry, rw, rh);
}

Container* Container::add(Widget *w) {
  w->parent = this;
  w->index = this->num_children;
  this->children[this->num_children] = w;
  this->num_children += 1;
  return this;
}

u16 Container::child_height(Widget *child) {
  return this->height();
}

u16 Container::child_width(Widget *child) {
  return this->width();
}

u16 Container::child_xpos(Widget *child) {
  return this->rx;
}

u16 Container::child_ypos(Widget *child) {
  return this->ry;
}

u16 Container::calculate_width() { return 0; }
u16 Container::calculate_height() { return 0; }
