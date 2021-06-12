#include "logos/tux.h"
//here you can define which logo wayfetch is going to use. See logos folder for available options
#define PACDIR "/var/lib/pacman/local" // here are all packages incase of pacman
#define ELEMENTS 18
//this is how many elements are to be printed in the info

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
		spacing();
		spacing();
		get_up();
		get_shell();
		get_term();
		get_packages();
		spacing();
		spacing();
		get_cpu();
		get_memory();
		spacing();
		spacing();
		get_colors();
		get_colors2();
}
