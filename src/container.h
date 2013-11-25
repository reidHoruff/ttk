#ifndef __container_h__
#define __container_h__

#include "ttk.h"
#include "widget.h"

#define DEFAULT_CONTAINED_ELEMENTS 10

/* this is an abstract base class for containers */
class Container : public Widget {
  public:
    Container();

    /* returns instance of self so calls can be linked together */
    virtual Container* add(Widget*);

    /* for when the child asks it's parent/container how big/where it should go */
    virtual u16 child_height(Widget*) = 0; 
    virtual u16 child_width(Widget*) = 0; 
    virtual u16 child_xpos(Widget*) = 0; 
    virtual u16 child_ypos(Widget*) = 0; 

  protected:
    virtual void render();
    virtual void unrender();

  protected:
    u16 num_children;
    Widget **children;
};

#endif
