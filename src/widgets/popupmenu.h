#ifndef _ppmennu_h_
#define _ppmennu_h_

#include "../widget.h"

#define POPUP_BOX_V_PADDING 5
#define POPUP_BOX_L_PADDING 4

/* so this is a kind of hacky use of the widget
 * base class. really the only reason it is being used is
 * so that Popupmenu can have ttk focus and accept button_press_up
 * events.
 */

class PopupMenu : public Widget {
  public:
    PopupMenu(Widget *owner, const char **text, u8 l);

  private:
    virtual void render();
    virtual void unrender();

  public:
    virtual u16 width();
    virtual u16 height();
    virtual u16 xposition();
    virtual u16 yposition();

    virtual bool button_press_up(ButtonPress bp, Widget *child);

    void hide();

  protected:
    const char **text;
    u8 len, selected;
    Widget *owner;
};

#endif
