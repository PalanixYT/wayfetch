all: wayfetch

clean:
	rm -f wayfetch

install: wayfetch
	install -D wayfetch /bin/wayfetch

uninstall:
	rm -f /bin/wayfetch

.PHONY: all clean install uninstall

config: | config.pre.h
	cp config.pre.h $@

wayfetch: wayfetch.c
	gcc -o wayfetch wayfetch.c
