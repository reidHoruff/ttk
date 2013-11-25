#ifndef __widget_h__
#define __widget_h__

#include "ttk.h"

class Container;

class Widget {
  public:
    /* do not add any other constructors */
    Widget();

    virtual void update();
    virtual void request_render();
    virtual void request_unrender();

  private:
    /* these are to be invoked by the above methods */
    virtual void render();
    virtual void unrender();

  public:
    /* all these are for calculating positioning and size */
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

    virtual bool need_compute_render_vars();
    Widget* set_need_compute_render_vars(bool f);

    /* called when you spawn a child and he
     * return focus to you. typically a popup
     */
    virtual void call_home(u16 data);

  protected:
    /* to be overwritten;
     * called by button_press_up when the widget has 
     * focus and is selected
     */
    virtual void on_select();
    
    virtual void on_focus();

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
     * 4 - need compute render vars
     */
    u8 flags;
};

#endif
