#ifndef __button_h_
#define __button_h_
#define BUTTON_V_MARGIN 6
#define BUTTON_H_MARGIN 6

#include "widget.h"

class Button : public Widget {
  public:
    Button(char *text);
    Button(char *text, u16 x, u16 y);
    virtual void render();
    virtual u16 calculate_height();
    virtual u16 calculate_width();

  protected:
    char *text;
    u16 text_len();
};

#endif
