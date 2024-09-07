all:
	cc -O3 -I./include src/main.c src/get_info.c -o cleofetch

test:
	cc -O3 -I./include src/main.c src/get_info.c -o cleofetch
	./cleofetch
