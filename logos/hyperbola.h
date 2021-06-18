#include "../color.h"
#define COLOR "\e[1;90m"
#define NAMECOLOR WHITE
#define ROWS 16
char *logo[] = {
    "                     WW               ",
    "                     KX              W",
    "                    WO0W          NX0O",
    "                    NOO0NW  WNXK0OOKW ",
    "                    W0OOOOOOOOOOOOKN  ",
    "                     N0OOOOOOO0KXW    ",
    "                       WNXXXNW        ",
    "                 NXK00000KN           ",
    "             WNK0OOOOOOOOOO0W         ",
    "           NK0OOOOOOOOOOOOOO0W        ",
    "         X0OOOOOOO00KK00OOOOOK        ",
    "       X0OOOO0KNWW      WX0OO0W       ",
    "     X0OO0XNW              KOOW       ",
    "   N00KNW                   KOW       ",
    " NKXN                       W0W       ",
    "WW                           W        ",
    "                                      ",
};
//IMPORTANT: Always make the lines the same length. There shouldn't be any extra spaces, as they are added later on by the programm itself
//IMPORTANT: the last line should be only spaces with the same length as the other lines, ROWS should exclude the last line
