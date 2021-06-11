// this file is only an example as to how to make a logo file
#include "../color.h"
// this is only needed when using multi color logos
#define COLOR CYAN
#define NAMECOLOR BLUE
//this is only needed when the name is supposed to be in a different color, like with kiss linux
#define ROWS 19

char *logo[] = {
		"....",
		"....",
		"....",
		"..  ",
};

//IMPORTANT: Always make the lines the same length. There shouldn't be any extra spaces, as they are added later on by the programm itself
