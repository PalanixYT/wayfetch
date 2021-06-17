#include "../color.h"
#define COLOR CYAN
#define NAMECOLOR BLUE
#define ROWS 19
char *logo[] = {
BLUE"                         ▄▄▄▄▄▄     ",
BLUE"                      ▄█████████▄   ",
BLUE"      ▄▄▄▄▄▄         ████▀   ▀████  ",
BLUE"   ▄██████████▄     ████▀   ▄▄ ▀███ ",
BLUE" ▄███▀▀   ▀▀████     ███▄   ▄█   ███",
BLUE"▄███   ▄▄▄   ████▄    ▀██████   ▄███",
BLUE"███   █▀▀██▄  █████▄     ▀▀   ▄████ ",
BLUE"▀███      ███  ███████▄▄  ▄▄██████  ",
BLUE" ▀███▄   ▄███  █████████████"CYAN"████▀   ",
BLUE"  ▀█████████    ██████"CYAN"████▀▀▀       ",
"    ▀▀███▀▀     ██████▀▀            ",
"               ██████▀   ▄▄▄▄       ",
"              █████▀   ████████     ",
"              █████   ███▀  ▀███    ",
"               ████▄   ██▄▄▄  ███   ",
"                █████▄   ▀▀  ▄██    ",
"                  ██████▄▄▄████     ",
"                     ▀▀█████▀▀      ",
"                                    ",
};
//IMPORTANT: Always make the lines the same length. There shouldn't be any extra spaces, as they are added later on by the programm itself
//IMPORTANT: the last line should be only spaces with the same length as the other lines, ROWS should exclude the last line
