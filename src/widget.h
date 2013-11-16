#ifndef __widget_h__
#define __widget_h__

#include "ttk.h"

class Container;

class Widget {
  public:
    Widget();
    Widget(u16 x, u16 y);
    virtual void render();
    virtual u16 width();
    virtual u16 height();
    virtual u16 xposition();
    virtual u16 yposition();
    virtual u16 calculate_width() = 0;
    virtual u16 calculate_height() = 0;
    virtual u16 calculate_xposition();
    virtual u16 calculate_yposition();
    virtual void button_press(ButtonPress bp);

  /* getters / setters */
  public:
    bool visible();
    Widget* set_visible(bool v);

    bool is_enabled();
    Widget* set_enabled(bool e);

    bool fills_container();
    Widget* set_fill_container(bool f);

    bool has_focus();
    Widget* set_has_focus(bool f);

    /* attributes */
  public:
    Container *parent;
    u16 xpos, ypos, index, rx, ry, rw, rh;

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
