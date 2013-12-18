VIRTUAL_COMPILER = g++
AVR_COMPILER = avr-g++
TEST_HARDWARE = atmega32u4
TEST_PROGRAMMER = usbtiny
AVRDUDE = avrdude

VIRT = virtual/main.cpp virtual/virtual.cpp virtual/screen.cpp
VIRT_BIN_NAME = ttk_vir

WIDGETS = widgets/button.cpp widgets/vertcontainer.cpp widgets/horcontainer.cpp widgets/dropdown.cpp widgets/popupmenu.cpp widgets/verttabs.cpp
CORE = graphics.cpp widget.cpp ttk.cpp container.cpp

all:
	$(VIRTUAL_COMPILER) `pkg-config --cflags gtk+-3.0` -o $(VIRT_BIN_NAME) $(CORE) $(WIDGETS) $(VIRT) `pkg-config --libs gtk+-3.0`

atmega32u4:
	echo "yea"
