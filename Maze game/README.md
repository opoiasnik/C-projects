# Documentation for Maze Game with ncurses in C

## Overview

This project is a maze game implemented in C using the ncurses library. The game features a player navigating through a labyrinth with various obstacles and triggers. The player is represented by an arrow and moves in response to keyboard inputs.

## Key Features

1. **Maze Layout**: The game presents a maze with different paths, walls, and special characters (`'-'`, `'|'`, `'*'`, `'O'`, `'?'`, `'r'`).

2. **Player Movement**: The player moves using arrow keys with the symbol changing direction based on the input (`'<'`, `'>'`, `'^'`, `'v'`).

3. **Special Characters**:
   - `'*'`: Teleport points.
   - `'O'`: Win condition.
   - `'?'`: Triggers a random event like teleporting or altering move count.
   - `'r'`: Restarts the game.
   - `'!'`: Blocks that move when interacted with.

4. **Move Counter**: Tracks the number of moves the player makes.

5. **Colorful Interface**: Utilizes ncurses color pairs for a more engaging user interface.

6. **Dynamic Messages**: Displays start, win, lose, and run out of tries messages.

## Functionality

### `main` Function

- Initializes the ncurses window.
- Sets up game configurations (e.g., no echo, cursor visibility).
- Initializes color pairs.
- Calls the `draw_start` function to display the intro.
- Invokes the `moving_arrow` function for the main game loop.

### Game Loop (`moving_arrow` Function)

- Handles user inputs for navigation.
- Manages interactions with special characters and game states.
- Tracks and limits the number of moves.
- Renders player movements and updates the maze.

### Utility Functions

- `draw_start`: Displays the introductory message.
- `draw_end1` and `draw_end2`: Show messages for losing and winning the game, respectively.
- `run_out_of_tries`: Indicates that the player has run out of attempts.
- `draw1` and `draw2`: Render the initial and subsequent maze layouts.
- `again`: Notifies the player about a retry.

## Limitations

- Fixed maze size and layout.
- Limited to keyboard input without mouse support.
- The game logic and rendering are tightly coupled, which may hinder scalability.
- The move count is limited to 650 moves, which might not accommodate all gameplay strategies.

## Compiling and Running

To compile and run the game:

1. Ensure `ncurses` is installed on your system.
2. Compile the program using `gcc` with the `-lncurses` flag.
   ```sh
   gcc -o maze_game maze_game.c -lncurses
   ```
3. Run the compiled executable.
   ```sh
   ./maze_game
   ```

## Conclusion

This maze game offers a simple yet engaging experience, demonstrating the use of ncurses for interactive terminal-based applications in C. The game emphasizes navigation skills and decision-making within a limited number of moves.
