#ifndef __button_h_
#define __button_h_
#define BUTTON_V_MARGIN 6
#define BUTTON_H_MARGIN 6

#include "../widget.h"

class Button : public Widget {
  public:
    Button(const char *text);

  private:
    virtual void render();
    virtual void unrender();

  public:
    virtual u16 calculate_height();
    virtual u16 calculate_width();

  protected:
    const char *text;
    u16 text_len();
};

#endif
