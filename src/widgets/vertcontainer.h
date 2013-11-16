#ifndef _vertcontainer_h_
#define _vertcontainer_h_

#include "../ttk.h"
#include "../widget.h"
#include "../container.h"

class VerticalContainer : public Container {
  public:
    virtual void render();
    virtual u16 child_height(Widget*); 
    virtual u16 child_width(Widget*); 
    virtual u16 child_xpos(Widget*); 
    virtual u16 child_ypos(Widget*); 
    virtual void button_press(ButtonPress bp);
};

#endif
