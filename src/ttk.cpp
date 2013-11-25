#include "ttk.h"

#include "widget.h"
#include "container.h"
#include "screen.h"

Widget* ttk::focused;
Widget* ttk::popup;
Container* ttk::root;

void ttk::button_press(ButtonPress bp) {
  if (ttk::focused) {
    ttk::focused->button_press_up(bp, NULL);
  } else {
    ttk::root->button_press_down(bp);
  }
  screen::draw();
}

void ttk::set_root(Container* root) {
  ttk::root = root;
}

void ttk::set_focused_widget(Widget* w) {
  if (ttk::focused) {
    ttk::focused->set_has_focus(false);
    ttk::focused->update();
  }

  if (w) {
    w->set_has_focus(true);
    w->update();
  }

  ttk::focused = w;
}

void ttk::render() {
  /* call update so it drawas the background
   * just in case
   */
  ttk::root->update();
  screen::draw();
}
