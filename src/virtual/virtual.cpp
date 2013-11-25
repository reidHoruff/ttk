#include <cairo.h>
#include "virtual.h"
#include <stdio.h>
#include "../screen.h"
#include <gtk/gtk.h>

cairo_t *virt::cr = NULL;
GtkWidget *virt::window = NULL;

void virt::refresh() {
  gtk_widget_queue_draw(virt::window);
}
