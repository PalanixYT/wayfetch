wayfetch
========

A neofetch rewrite that is still lacking some features

I know that the way prefix is usually used for wayland programms.

Although I haven't ported over other logos yet, it is relatively easy to do so. 
Just remember that every line should have equal length, otherwise it's going to mess up the printing. 
Multicolor Logos are a bit harder to do, see mint.h as an example. It's best to start with a normal no color Logo and then add the coloring, to preserver spacing

Displaying package count currently only works with Pacman

<<<<<<< HEAD
Example:
![example output](logos/example.png)

Configuration
-------------

Wayfetch is configured using config.h. The first include defines which logo is used.
The order function defines the order of the entries. Simply change the number inside the array.
I am working on a way to better the configuration.

Performance
-----------

Using hyperfine neofetch uses 140ms and wayfetch 1ms


Criticism is encouraged. 
