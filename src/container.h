#ifndef __container_h__
#define __container_h__

#include "widget.h"

#define DEFAULT_CONTAINED_ELEMENTS 10

class Container : public Widget {
  public:
    Container();
    virtual void render();
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

class VerticalContainer : public Container {
  public:
    virtual void render();
    virtual u16 child_height(Widget*); 
    virtual u16 child_width(Widget*); 
    virtual u16 child_xpos(Widget*); 
    virtual u16 child_ypos(Widget*); 
};

#endif
