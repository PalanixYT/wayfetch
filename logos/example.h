// this file is only an example as to how to make a logo file
#include "../color.h"
// this is only needed when using multi color logos
#define COLOR CYAN
#define NAMECOLOR COLOR
//this is only needed when the name is supposed to be in a different color, like with kiss linux
#define ROWS 19
//ALWAYS, and I mean ALWAYS exclude the last line of the logo, see the end of the file for more info

char *logo[] = {
		"....",
		"....",
		"....",
		"....",
		"    ",
};

//IMPORTANT: Always make the lines the same length. There shouldn't be any extra spaces, as they are added later on by the programm itself
//IMPORTANT: the last line should be only spaces with the same length as the other lines, ROWS should exclude the last line
