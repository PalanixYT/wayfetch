#include "logos/tux.h"
//here you can define which logo wayfetch is going to use. See logos folder for available options
#define PACDIR "/var/lib/pacman/local" // here are all packages incase of pacman
char info[ROWS][150];

//usually color is defined by the logo
//#define COLOR
// BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE


//here comes the order of elements
// info[0] and info[1] are reserved for the title and bar
void order() {
		hname();
		os();
		host();
		kernel();
		get_up();
		get_shell();
		get_term();
		get_cpu();
		get_memory();
		get_packages();
		get_colors(); //this is to make sure the colors are at the end
		get_colors2();
}
