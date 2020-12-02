A Block Game 

Coming Soon TM

TODO:

* Most things
* Sound
* Graphics
* Input
* File handling (saving and loading)
* INI Parsing
* Optimizing and fixing up memory problems (Y'see, I'm *very* good at C...)
* Gamerule handling
* Main game logic loop
* Scoring system
* Adding more defines for things like default screen size
* Get rid of the second TODO in main.c (but I'm too lazy right *Now*)


==Piece Format==
    MCCRRSSDDDDDD...
M - Mode
CC - Color
RR - Rotation States (number of)
SS - Size (of bounding square)
DDD.. - Piece Matrix Data


==Bag Format==
    MSSDDDDD...
M - Mode
SS - Size (number of pieces)
DDD.. - Pieces


==Playfield Format==
    MWWWHHH
M - Mode
WWW - Width
HHH - Height