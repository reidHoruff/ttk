#include <cairo.h>
#include <gtk/gtk.h>

namespace virt{
  extern cairo_t *cr;
  extern GtkWidget *window;
  void refresh();
}
