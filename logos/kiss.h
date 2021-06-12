// this file is only an example as to how to make a logo file
#include "../color.h"
// this is only needed when using multi color logos
#define COLOR MAGENTA
//colors are defined in color.h
#define NAMECOLOR BLUE
//this is only needed when the name is supposed to be in a different color, like with kiss linux
#define ROWS 19
//the programm only prints as many lines as defined in ROWS

char *logo[] = {
BLUE"    ___   ",
BLUE"   ("WHITE".·"BLUE" |  ",
BLUE"   ("MAGENTA"<>"BLUE" |  ",
BLUE"  /"WHITE" __"BLUE"  \\ ",
BLUE" ( "WHITE"/  \\"BLUE" /|",
MAGENTA"_"BLUE"/\\"WHITE" __)"BLUE"/"MAGENTA"_"BLUE")",
MAGENTA"\\/"BLUE"-____"MAGENTA"\\/ ",
"          ",
"          ",
"          ",
"          ",
"          ",
"          ",
"          ",
"          ",
"          ",
"          ",
"          ",
"          ",
};

//IMPORTANT: Always make the lines the same length. There shouldn't be any extra spaces, as they are added later on by the programm itself
