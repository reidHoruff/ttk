#ifndef __widget_h__
#define __widget_h__

#include "ttk.h"

class Container;

class Widget {
  public:
    Widget();
    virtual void render();
    virtual void unrender();
    virtual u16 width();
    virtual u16 height();
    virtual u16 xposition();
    virtual u16 yposition();
    virtual u16 calculate_width();
    virtual u16 calculate_height();
    virtual u16 calculate_xposition();
    virtual u16 calculate_yposition();

    /*
     * up down does not refer to the button being pressed.
     * if refers to which way up the tree the call is travelling
     */
    virtual bool button_press_up(ButtonPress bp, Widget *child);
    virtual void button_press_down(ButtonPress bp);

  /* getters / setters */
  public:
    virtual bool visible();
    Widget* set_visible(bool v);

    virtual bool is_enabled();
    Widget* set_enabled(bool e);

    virtual bool fills_container();
    Widget* set_fill_container(bool f);

    virtual bool has_focus();
    Widget* set_has_focus(bool f);

    /* attributes */
  public:
    Container *parent;
    u16 index, rx, ry, rw, rh;

  protected:
    /*
     * 0 - visible
     * 1 - enabled
     * 2 - fill container
     * 3 - has focus
     */
    u8 flags;
};

#endif
