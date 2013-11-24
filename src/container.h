#ifndef __container_h__
#define __container_h__

#include "ttk.h"
#include "widget.h"

#define DEFAULT_CONTAINED_ELEMENTS 10

class Container : public Widget {
  public:
    Container();
    virtual void render();
    virtual void unrender();
    virtual Container* add(Widget*);
    virtual u16 child_height(Widget*); 
    virtual u16 child_width(Widget*); 
    virtual u16 child_xpos(Widget*); 
    virtual u16 child_ypos(Widget*); 

    virtual u16 calculate_width();
    virtual u16 calculate_height();

    u16 num_children;
    Widget **children;
};

#endif
