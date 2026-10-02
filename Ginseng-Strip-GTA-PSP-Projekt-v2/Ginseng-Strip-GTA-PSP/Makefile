TARGET = GinsengStripGTA
OBJS = src/main.o

CFLAGS = -O2 -G0 -Wall -I./include
LIBS = -lpspdebug -lpspdisplay -lpspge -lpspctrl

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Ginseng Strip GTA

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
