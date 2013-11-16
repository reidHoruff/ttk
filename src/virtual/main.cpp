#include <cairo.h>
#include <gtk/gtk.h>
#include <stdio.h>

#include "virtual.h"
#include "../screen.h"
#include "../graphics.h"
#include "../container.h"
#include "../ttk.h"
#include "../widgets/vertcontainer.h"
#include "../widgets/button.h"

/*
 * this is all hacky and copied form the internet.
 * im not really concerning myself with this currently as long as it works
 */


Container *root_container;

static void do_drawing(cairo_t *);

static void tran_setup(GtkWidget *win)
{        
  GdkScreen *screen;
  GdkVisual *visual;
  
  gtk_widget_set_app_paintable(win, TRUE);
  screen = gdk_screen_get_default();
  visual = gdk_screen_get_rgba_visual(screen);
  
  if (visual != NULL && gdk_screen_is_composited(screen)) {
    gtk_widget_set_visual(win, visual);
  }
}

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data)
{      
  do_drawing(cr);  
  return FALSE;
}

static void do_drawing(cairo_t *cr)
{
  virt::cr = cr;
  ttk::root->render();
  printf("drawing\n");
}

gboolean on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
  switch (event->keyval) {
    case 65362:
      printf("up\n");
      ttk::button_press(UP);
      break;

    case 65364:
      printf("down\n");
      ttk::button_press(DOWN);
      break;

    case 65363:
      printf("right\n");
      ttk::button_press(RIGHT);
      break;

    case 65361:
      printf("left\n");
      ttk::button_press(LEFT);
      break;
  }
  return FALSE; 
}

int main (int argc, char *argv[])
{
  root_container = new VerticalContainer();
  root_container
    ->add((new Button("hello"))->set_fill_container(true))
    ->add(new Button("hello2"))
    ->add(new Button("hello2"))
    ->add(new Button("hello2"))
    ->add(new Button("hello2"))
    ->add((new Button("this is a really long picec of text!"))->set_fill_container(true))
    ->add(new Button("# Start"));
  ttk::set_root(root_container);
  GtkWidget *window, *darea;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  
  tran_setup(window);

  darea = gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER(window), darea);

  g_signal_connect(G_OBJECT(darea), "draw", G_CALLBACK(on_draw_event), NULL); 
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect (G_OBJECT(window), "key_press_event", G_CALLBACK(on_key_press), NULL);

  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), screen::width, screen::height); 
  gtk_window_set_title(GTK_WINDOW(window), "ttk virtualizer");

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
