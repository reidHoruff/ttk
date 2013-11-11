#include "container.h"
#include "widget.h"
#include <stdio.h>

Container::Container() : Widget() {
  this->children = new Widget*[DEFAULT_CONTAINED_ELEMENTS];
  this->num_children = 0;
}

void Container::render() {
  printf("container render\n");

  this->width();
  this->height();
  this->xposition();
  this->yposition();

  for(u16 i = 0; i < this->num_children; i++) {
    this->children[i]->render();
  }
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
  return this->rx + child->xpos;
}

u16 Container::child_ypos(Widget *child) {
  return this->ry + child->ypos;
}

u16 Container::calculate_width() { return 0; }
u16 Container::calculate_height() { return 0; }

/*
 * VerticalContainer
 */

void VerticalContainer::render() {
  printf("vertical container render\n");

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
