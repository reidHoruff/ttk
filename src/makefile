CC = g++

VIRT = virtual/main.cpp virtual/virtual.cpp
WIDGETS = widgets/button.cpp widgets/vertcontainer.cpp  
CORE = screen.cpp graphics.cpp widget.cpp ttk.cpp container.cpp

all:
	$(CC) `pkg-config --cflags gtk+-3.0` -o ttk_vir $(CORE) $(WIDGETS) $(VIRT) `pkg-config --libs gtk+-3.0` 

