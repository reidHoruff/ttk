#ifndef _horcontainer_h_
#define _horcontainer_h_

#include "../ttk.h"
#include "../widget.h"
#include "../container.h"

class HorizontalContainer : public Container {
  public:
    virtual u16 child_height(Widget*); 
    virtual u16 child_width(Widget*); 
    virtual u16 child_xpos(Widget*); 
    virtual u16 child_ypos(Widget*); 

    /*
     * up down does not refer to the button being pressed.
     * if refers to which way up the tree the call is travelling
     */
    virtual bool button_press_up(ButtonPress bp, Widget *child);
    virtual void button_press_down(ButtonPress bp);
};

#endif
