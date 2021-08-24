# RockPaperScissors
A small rock paper scissor game that I have made due to boredom. 

## The game has two difficulties: normal and impossible.


## Buiding the game
### With ncurses
g++ rps.cpp -o rps -lncurses -I. -DNCURSES

### With standard C++
g++ rps.cpp -o rps -I.

#### The project depends on the ncurses library (but can be built without it).




#### TO DO: I might add a CMakeLists.txt for better portability.
