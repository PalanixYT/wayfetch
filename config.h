#include "artix.h"
#define PACDIR "/var/lib/pacman/local" // here are all packages incase of pacman
char info[ROWS][150];

//usually color is defined by the logo
//#define COLOR
// BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE


//here comes the order of elements
// info[0] and info[1] are reserved for the title and bar
void order() {
		os(							info[2]			);
		host(						info[3]			);
		kernel(						info[4]			);
		get_up(						info[7]			);
		get_shell(					info[8]			);
		get_term(					info[9]			);
		get_cpu(					info[13]			);
		get_memory(					info[14]		);
		get_packages(				info[10]		);
		get_colors(					info[ROWS-3]		); //this is to make sure the colors are at the end
		get_colors2(				info[ROWS-2]		);
}
