#include "widget.h"
#include "container.h"
#include "screen.h"
#include "ttk.h"
#include <stdio.h>

Widget::Widget() {
  this->parent = NULL;
  this->xpos = 0;
  this->ypos = 0;
  this->index = 0;
}

Widget::Widget(u16 x, u16 y) {
  this->parent = NULL;
  this->xpos = x;
  this->ypos = y;
  this->index = 0;
}

void Widget::render() {
  printf("render needs to be overwritten\n");
}

bool Widget::visible() {
  return this->flags&1;
}

Widget* Widget::set_visible(bool v) {
  this->flags = ((this->flags) & (~1)) | (v&1);
  return this;
}

bool Widget::is_enabled() {
  return (this->flags) & (1<<1);
}

Widget* Widget::set_enabled(bool e) {
  this->flags = ((this->flags) & (~2)) | (e<<1);
  return this;
}

bool Widget::fills_container() {
  return (this->flags) & (1<<2);
}

Widget* Widget::set_fill_container(bool f) {
  this->flags = ((this->flags) & (~4)) | (f<<2);
  return this;
}

bool Widget::has_focus() {
  return (this->flags) & (1<<3);
}

Widget* Widget::set_has_focus(bool f) {
  this->flags = ((this->flags) & (~8)) | (f<<3);
  return this;
}

u16 Widget::height() {
  if (this->parent == NULL) {
    this->rh = screen::height;
  } else if (this->fills_container()) {
    this->rh = this->parent->child_height(this);
  } else {
    this->rh = this->calculate_height();
  }
  return this->rh;
}

u16 Widget::width() {
  if (this->parent == NULL) {
    this->rw = screen::width;
  } else if (this->fills_container()) {
    this->rw = this->parent->child_width(this);
  } else {
    this->rw = this->calculate_width();
  }
  return this->rw;
}

u16 Widget::xposition() {
  if (this->parent == NULL) {
    this->rx = 0;
  } else {
    this->rx = this->parent->child_xpos(this);
  }
  return this->rx;
}

u16 Widget::yposition() {
  if (this->parent == NULL) {
    this->ry = 0;
  } else {
    this->ry = this->parent->child_ypos(this);
  }
  return this->ry;
}

u16 Widget::calculate_xposition() {
  return this->xpos;
}

u16 Widget::calculate_yposition() {
  return this->ypos;
}

void Widget::button_press(ButtonPress bp) {
 if (bp == SELECT) {
 } else {
   this->parent->button_press(bp);
 } 
}
