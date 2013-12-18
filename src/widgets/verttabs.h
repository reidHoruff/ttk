#ifndef _verttabs_h_
#define _verttabs_h_

#include "../ttk.h"
#include "../widget.h"
#include "../container.h"

#define VTABS_TAB_V_PADDING 4

class VerticalTabs : public Container {

  public:
    VerticalTabs(const char **names, u8 tabs);

    /* for when the child asks it's parent/container how big/where it should go */
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

  protected:
    void render();

  public:
    u8 ntabs, cur_tab;
    const char **names;

};

#endif
