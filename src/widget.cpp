#include "widget.h"
#include "container.h"
#include "screen.h"
#include "ttk.h"
#include "graphics.h"
#include <stdio.h>

Widget::Widget() {
  this->parent = NULL;
  this->index = 0;
  this->flags = 0;

  this->rx = 0;
  this->ry = 0;
  this->rw = 0;
  this->rh = 0;

  this->set_visible(true);
  this->set_enabled(true);
  this->set_need_compute_render_vars(true);
}

void Widget::render() {
  log("render needs to be overwritten\n");
}

void Widget::unrender() {
  gl::set_color(BACKGROUND);
  gl::fill_rect(rx, ry, rw, rh);
}

void Widget::update() {
  this->request_unrender();
  this->request_render();
}

void Widget::request_render() {
  if (this->visible()) {
    //calc all rendered coords and dimensions
    if (this->need_compute_render_vars()) {
      this->width();
      this->height();
      this->xposition();
      this->yposition();
      this->set_need_compute_render_vars(false);
    }
    //render will rely on all of these
    this->render();
  }
}

void Widget::request_unrender() {
  //calc all rendered coords and dimensions
  if (this->need_compute_render_vars()) {
    this->width();
    this->height();
    this->xposition();
    this->yposition();
    this->set_need_compute_render_vars(false);
  }
  //render will rely on all of these
  this->unrender();
}

/*
 * here comes all the getters and setters
 */

#define _SET(_field, _bit, _value)\
  if (_value) {\
    _field |= (1<<_bit);\
  } else {\
    _field &= ~(1<<_bit);\
  }\

#define _GET(_field, _bit)\
  (_field>>_bit)&1;


#define _VISIBLE 0
#define _ENABLED 1
#define _FILLS_CONTAINER 2
#define _HAS_FOCUS 3
#define _NEED_COMPUTE 4

bool Widget::visible() {
  return _GET(this->flags, _VISIBLE);
}

Widget* Widget::set_visible(bool v) {
  _SET(this->flags, _VISIBLE, v);
  return this;
}

bool Widget::is_enabled() {
  return _GET(this->flags, _ENABLED);
}

Widget* Widget::set_enabled(bool e) {
  _SET(this->flags, _ENABLED, e);
  return this;
}

bool Widget::fills_container() {
  return _GET(this->flags, _FILLS_CONTAINER);
}

Widget* Widget::set_fill_container(bool f) {
  _SET(this->flags, _FILLS_CONTAINER, f);
  return this;
}

bool Widget::has_focus() {
  return _GET(this->flags, _HAS_FOCUS);
}

Widget* Widget::set_has_focus(bool f) {
  _SET(this->flags, _HAS_FOCUS, f);
  return this;
}

bool Widget::need_compute_render_vars() {
  return _GET(this->flags, _NEED_COMPUTE);
}

Widget* Widget::set_need_compute_render_vars(bool f) {
  _SET(this->flags, _NEED_COMPUTE, f);
  return this;
}

/* DONE! fuck that repetetive shit... */

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
  return 0;
}

u16 Widget::calculate_yposition() {
  return 0;
}

u16 Widget::calculate_width() {
  return 0; 
}

u16 Widget::calculate_height() { 
  return 0; 
}

/* button press handeling is for leafs */
bool Widget::button_press_up(ButtonPress bp, Widget *child) {
  if (bp == SELECT) {
    this->on_select();
  } else {
    this->parent->button_press_up(bp, this);
  } 
  return true;
}

void Widget::button_press_down(ButtonPress bp) {
  ttk::set_focused_widget(this);
}

void Widget::on_select() {
  ;
}

void Widget::on_focus() {
  ;
}

void Widget::call_home(u16 data) {
  log("home called: %d\n", data);
}
