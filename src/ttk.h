#ifndef __ttk_h__
#define __ttk_h__ 

#define VIRTUAL
#define FAST_DRAW

#ifdef VIRTUAL
#include <stdio.h>
#define log(fmt, ...) printf("[%s:%d:%s] ", __FILE__, __LINE__, __PRETTY_FUNCTION__);printf(fmt, ##__VA_ARGS__)
#else
#define log(fmt, ...)
#endif

#include <cstdint>

typedef uint16_t u16;
typedef uint8_t u8;
typedef uint32_t u32;

class Widget;
class Container;

enum ButtonPress {
  LEFT = 0,
  RIGHT,
  UP,
  DOWN,
  SELECT,
};

namespace ttk {
  extern Widget* focused;
  extern Widget* popup;
  extern Container* root;

  void button_press(ButtonPress bp);
  void set_root(Container* root);
  void set_focused_widget(Widget* w);
  void set_has_focus(Widget*);
  void set_popup(Widget*);
  void render();
}

/* some helpers */
#define del(x) delete x;x=NULL

#endif
