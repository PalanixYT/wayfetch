#include "logos/tux.h"
//here you can define which logo wayfetch is going to use. See logos folder for available options
//
#define PACDIR "/var/lib/pacman/local" // here are all packages incase of pacman

// SEPARATOR is the string defined that wayfetch will print for every factor
#define SEPARATOR ":" // Example: "OS: Parabola x86_64"
// #define SEPARATOR "=>" // Example: "OS => Parabola x86_64"
// #define SEPARATOR "->" // Example: "OS -> Parabola x86_64"
// #define SEPARATOR "="  // Example: "OS = Parabola x86_64"

#define ELEMENTS 19
//this is how many elements are to be printed in the info

//here comes the order of elements
void order() {
				hname();
				os("OS"SEPARATOR);
				host("Host"SEPARATOR);
				kernel("Kernel"SEPARATOR);
				spacing();
				spacing();
				get_up("Uptime"SEPARATOR);
				get_shell("Shell"SEPARATOR);
				get_term("Terminal"SEPARATOR);
				get_packages("Packages"SEPARATOR);
				get_wm("DE/WM"SEPARATOR);
				spacing();
				spacing();
				get_cpu("CPU"SEPARATOR);
				get_memory("Memory"SEPARATOR);
				spacing();
				spacing();
				get_colors();
				get_colors2();

//				customPrint("preprint", "message");
}


//usually color is defined by the logo
//#define COLOR
// BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE
