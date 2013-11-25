#include "vertcontainer.h"
#include "../widget.h"
#include "../ttk.h"

u16 VerticalContainer::child_height(Widget *child) {
  return this->rh / this->num_children;
}

u16 VerticalContainer::child_width(Widget *child) {
  return this->rw;
}

u16 VerticalContainer::child_ypos(Widget *child) {
  u16 frame = this->rh / this->num_children;
  return this->ry + frame*child->index + frame/2 - child->rh/2;
}

u16 VerticalContainer::child_xpos(Widget *child) {
  return this->rx + (this->rw - child->rw)/2;
}

/* this looks complicated and can maybe be written a bit more
 * eligantly but this handles arrow key navigation of leaf widgets.
 * I'll explain how it works later... */
bool VerticalContainer::button_press_up(ButtonPress bp, Widget *child) {
  bool can_move = true;
  u8 next_index = 0;
  u8 rollover_index = 0;

  if (bp == UP) {
    can_move = (child->index > 0);
    next_index = child->index - 1;
    rollover_index = this->num_children-1;
  } else if (bp == DOWN) {
    can_move = (child->index < this->num_children-1);
    next_index = child->index + 1;
    rollover_index = 0;
  } else if (this->parent) {
    /* current container doesn't support lateral movement;
     * try my parent container to see if he can make lateral movement
     */
    return this->parent->button_press_up(bp, this);
  } else {
    /* me nor any of my parents can make the requeted movement;
     * send failure down call stack
     */
    return false;
  }

  if (can_move) {
    this->children[next_index]->button_press_down(bp);
    /* this container can make the requested movement; yay */
    return true;
  } else {
    /* that's ok, maybe one of my parent containers can */
    if (this->parent && this->parent->button_press_up(bp, this)) {
      return true;
    } else {
      /* that's ok, we can just rollover on my own children */
     this->children[rollover_index]->button_press_down(bp);
     return true;
    }
  }
}

/* buton press is coming from somewhere above; decide which child
 * is going to intercept this button event and let then deal with it
 */
void VerticalContainer::button_press_down(ButtonPress bp) {
  if (bp == UP) {
    this->children[this->num_children-1]->button_press_down(bp);
  } else {
    this->children[0]->button_press_down(bp);
  }
}
