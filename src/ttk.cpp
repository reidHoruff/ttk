#include "ttk.h"

#include "widget.h"
#include "container.h"

Widget* ttk::focused;
Widget* ttk::popup;
Container* ttk::root;

void ttk::button_press(ButtonPress bp) {
  if (ttk::focused) {
    ttk::focused->button_press_up(bp, NULL);
  } else {
    ttk::root->button_press_down(bp);
  }
}

void ttk::set_root(Container* root) {
  ttk::root = root;
}

void ttk::set_focused_widget(Widget* w) {
  if (ttk::focused) {
    ttk::focused->set_has_focus(false);
    ttk::focused->unrender();
    ttk::focused->render();
  }

  if (w) {
    w->set_has_focus(true);
    w->unrender();
    w->render();
  }

  ttk::focused = w;
}

void ttk::render() {
  ttk::root->render();
  if (ttk::popup && ttk::popup->visible()) {
    ttk::popup->render();
  }
}

void ttk::set_popup(Widget *p) {
  ttk::popup = p;
}
