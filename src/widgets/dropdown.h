#ifndef __dropdown_h_
#define __dropdown_h_

#define SELECT_V_MARGIN 6
#define SELECT_H_MARGIN 6

#include "../widget.h"
#include "popupmenu.h"

class Dropdown : public Widget {
  public:
    Dropdown(const char **options, u8 l);
    virtual void render();
    virtual void unrender();

    virtual u16 calculate_height();
    virtual u16 calculate_width();

    /*
     * up down does not refer to the button being pressed.
     * if refers to which way up the tree the call is travelling
     */
  virtual bool button_press_up(ButtonPress bp, Widget *child);

  protected:
    const char **options;
    u16 text_len();
    u8 len;
    PopupMenu *pop;
};

#endif
