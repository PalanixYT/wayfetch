all: wayfetch

clean:
	rm -f wayfetch

install: wayfetch
	install -D wayfetch /bin/wayfetch

uninstall:
	rm -f /bin/wayfetch

config.h: | config.pre.h
	cp config.pre.h $@

wayfetch: main.c config.h
	gcc -o wayfetch main.c
