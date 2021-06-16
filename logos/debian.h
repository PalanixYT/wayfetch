// this file is only an example as to how to make a logo file
#include "../color.h"
// this is only needed when using multi color logos
#define COLOR RED
#define NAMECOLOR COLOR
//this is only needed when the name is supposed to be in a different color, like with kiss linux
#define ROWS 17
//ALWAYS, and I mean ALWAYS exclude the last line of the logo, see the end of the file for more info

char *logo[] = {
	WHITE"       _,met$$$$$gg.       "CLOSE,
		WHITE"    ,g$$$$$$$$$$$$$$$P.    "CLOSE,
		WHITE"  ,g$$P\"     \"\"\"Y$$.\".     "CLOSE,
		WHITE" ,$$P'              `$$$.  "CLOSE,
		WHITE"',$$P       ,ggs.     `$$b:"CLOSE,
		WHITE"`d$$'     ,$P\"'   "RED"."WHITE"    $$$ "CLOSE,
		WHITE" $$P      d$'     "RED","WHITE"    $$P "CLOSE,
		WHITE" $$:      $$.   "RED"-"WHITE"    ,d$$' "CLOSE,
		WHITE" $$;      Y$b._   _,d$P'   "CLOSE,
		WHITE" Y$$.    "RED"`."WHITE"`\"Y$$$$P\"'      "CLOSE,
		WHITE" `$$b      "RED"\"-.__"WHITE"           "CLOSE,
		WHITE"  `Y$$                     "CLOSE,
		WHITE"   `Y$$.                   "CLOSE,
		WHITE"     `$$b.                 "CLOSE,
		WHITE"       `Y$$b.              "CLOSE,
		WHITE"          `\"Y$b._          "CLOSE,
		WHITE"              `\"\"\"         "CLOSE,
		"                           ",
};

//IMPORTANT: Always make the lines the same length. There shouldn't be any extra spaces, as they are added later on by the programm itself
//IMPORTANT: the last line should be only spaces with the same length as the other lines, ROWS should exclude the last line
