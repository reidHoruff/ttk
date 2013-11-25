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

    virtual u16 calculate_height();
    virtual u16 calculate_width();

    virtual void call_home(u16 data);

  protected:
    virtual void on_select();

  protected:
    const char **options;
    u16 text_len();
    u8 len;
    u8 selected;
    PopupMenu *pop;
};

#endif
