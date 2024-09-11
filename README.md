# So_long

## Project Overview

*So_long* is a 2D game developed as a project to practice graphical programming and basic game mechanics using the MinilibX library. The game is inspired by classic dungeon crawlers where the player must navigate through a simple map, collect items, avoid enemies, and reach the exit to win the game. The project emphasizes handling window management, rendering images, and processing user input in a minimalistic environment.

## Features

- *2D Game Rendering*: The game map is displayed in a 2D grid format, with distinct tiles representing walls, the player, collectibles, and the exit.
- *Player Movement*: The player can move using the WASD keys, navigating through the map while collecting items.
- *Collectibles*: The game requires the player to collect all available items on the map before being able to access the exit.
- *Exit Condition*: The game ends successfully when the player collects all items and reaches the exit.
- *Step Counter*: A step counter displays the number of moves made by the player, adding an element of challenge by encouraging minimal movement.

## Instructions

### Requirements

- *MinilibX*: The project uses the MinilibX library for rendering, which is compatible with macOS and Linux.
- *Makefile*: The project is compiled using a Makefile for ease of use.

### Compilation

1. *Clone the Repository*:
   
   git clone

   cd so_long
   

2. *Compile the Project*:
   
   make
   

### Running the Game

1. *Run the Game*:
   
   ./so_long maps/map.ber
   
   Replace maps/map.ber with the path to your custom map file if desired.

2. *Controls*:
   - W: Move up
   - A: Move left
   - S: Move down
   - D: Move right
   - ESC: Exit the game

### Map Requirements

- The map must be a valid .ber file and adhere to the following structure:
  - Rectangular shape.
  - Surrounded by walls (using the 1 character).
  - Contains one and only one player start position (P).
  - Contains one exit (E).
  - Contains at least one collectible (C).

### Example Map


1111111
1P00001
100C001
1000001
1E00001
1111111


### Error Handling

- The game handles invalid maps, missing files, and other errors by displaying appropriate error messages and exiting gracefully.
