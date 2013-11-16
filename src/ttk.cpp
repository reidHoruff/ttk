#include "ttk.h"

#include "widget.h"
#include "container.h"

Widget* ttk::focused;
Container* ttk::root;

void ttk::button_press(ButtonPress bp) {
  if (ttk::focused) {
    ttk::focused->button_press(bp);
  } else {
    ttk::root->button_press(bp);
  }
}

void ttk::set_root(Container* root) {
  ttk::root = root;
}

void ttk::set_focused_widget(Widget* w) {
  if (ttk::focused) {
    ttk::focused->set_has_focus(false);
  }

  if (w) {
    w->set_has_focus(true);
  }

  ttk::focused = w;
}
