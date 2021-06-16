// this file is only an example as to how to make a logo file
#include "../color.h"
// this is only needed when using multi color logos
#define COLOR BLUE
#define NAMECOLOR COLOR
//this is only needed when the name is supposed to be in a different color, like with kiss linux
#define ROWS 17

char *logo[] = {
		"          /:-------------:\       ",
		"       :-------------------::     ",
		"     :-----------"WHITE"/shhOHbmp"BLUE"---:\   ",
		"   /-----------"WHITE"omMMMNNNMMD"CLOSE"  "BLUE"---:  ",
		"  :-----------"WHITE"sMMMMNMNMP."CLOSE"    "BLUE"---: ",
		" :-----------"WHITE":MMMdP"BLUE"-------    ---\\",
		",------------"WHITE":MMMd"BLUE"--------    ---:",
		":------------"WHITE":MMMd"BLUE"-------    .---:",
		":----    "WHITE"oNMMMMMMMMMNho"BLUE"     .----:",
		":--     ."WHITE"+shhhMMMmhhy++"BLUE"   .------/",
		":-    -------"WHITE":MMMd"BLUE"--------------: ",
		":-   --------"WHITE"/MMMd"BLUE"-------------;  ",
		":-    ------"WHITE"/hMMMy"BLUE"------------:   ",
		":-- "WHITE":dMNdhhdNMMNo"BLUE"------------;    ",
		":---"WHITE":sdNMMMMNds:"BLUE"------------:     ",
		":------"WHITE":://:"BLUE"-------------::       ",
		":---------------------://         ",
		"                                  ",
};

//IMPORTANT: Always make the lines the same length. There shouldn't be any extra spaces, as they are added later on by the programm itself
//IMPORTANT: the last line should be only spaces with the same length as the other lines, ROWS should exclude the last line
