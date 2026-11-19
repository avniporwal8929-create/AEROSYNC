
CC = gcc
CFLAGS = -Wall -Wextra
INCLUDES = -Iinclude

all: aerosync aerosync_ipc aerosync_signals

aerosync: src/main.c include/atc.h
	$(CC) $(CFLAGS) $(INCLUDES) src/main.c -o aerosync

aerosync_ipc: src/ipc.c include/atc.h
	$(CC) $(CFLAGS) $(INCLUDES) src/ipc.c -o aerosync_ipc

aerosync_signals: src/signals.c include/atc.h
	$(CC) $(CFLAGS) $(INCLUDES) src/signals.c -o aerosync_signals

monitor: all
	chmod +x scripts/monitor.sh
	./scripts/monitor.sh

clean:
	rm -f aerosync aerosync_ipc aerosync_signals

.PHONY: all monitor clean
menu:
	gcc src/menu.c -o aerosync_menu
	./aerosync_menu
