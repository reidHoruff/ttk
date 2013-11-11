#ifndef __ttk_h__
#define __ttk_h__ 

#define VIRTUAL

#ifdef VIRTUAL
#include <stdio.h>
#endif

#include <cstdint>

typedef uint16_t u16;
typedef uint8_t u8;
typedef uint32_t u32;

namespace ttk {
  void up_button();
  void down_button();
  void right_button();
  void left_button();
}

#endif
