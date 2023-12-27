# Documentation for Train Station Management System

## Overview

This C program represents a basic train station management system. It is designed to manage various train targets (destinations) and their respective capacities (number of passengers). The system allows adding new targets, calculating the total number of targets and capacities, and displaying this information.

## Key Components

- **Structures**: 
  - `car`: Represents a single train car with a destination (`value`) and passenger capacity (`capacity`).
  - `station`: Contains an array of pointers to `car` structures (`tracks`) and the count of tracks (`track_count`).

- **Constants**:
  - `STATION_SIZE`: Determines the size of the station (number of tracks).
  - `TARGET_SIZE`: Defines the maximum length of a target name.

## Functions

### `create_station()`

- **Purpose**: Allocates and initializes a new station with `STATION_SIZE` tracks.
- **Returns**: A pointer to the newly created `station`.

### `destroy_station(struct station* station)`

- **Purpose**: Frees all allocated memory associated with the station, including tracks and cars.
- **Parameters**: A pointer to the `station` to be destroyed.

### `select_track(struct station* station, const char* target)`

- **Purpose**: Determines which track to use for a given target based on a simple hash function.
- **Parameters**:
  - `station`: Pointer to the station.
  - `target`: The target name.
- **Returns**: The index of the selected track.

### `add_target_capacity(struct station* station, const char* target, int capacity)`

- **Purpose**: Adds a new target or updates the capacity of an existing target.
- **Parameters**:
  - `station`: Pointer to the station.
  - `target`: The target name.
  - `capacity`: The number of passengers.

### `get_target_capacity(struct station* station, const char* target)`

- **Purpose**: Retrieves the capacity for a given target.
- **Parameters**:
  - `station`: Pointer to the station.
  - `target`: The target name.
- **Returns**: Capacity of the target; `0` if the target does not exist.

### `count_targets(struct station* station)`

- **Purpose**: Counts the total number of targets in the station.
- **Parameters**: A pointer to the station.
- **Returns**: The number of targets.

### `count_capacity(struct station* station)`

- **Purpose**: Calculates the total passenger capacity across all targets.
- **Parameters**: A pointer to the station.
- **Returns**: The total capacity.

### User Interaction Functions

- `print_menu()`: Displays the main menu options.
- `add_target_interaction(struct station* station)`: Interaction to add a target.
- `print_station_interaction(struct station* station)`: Interaction to print station details.
- `print_summary_interaction(struct station* station)`: Interaction to print a summary of the station.

### Main Function

- Initializes the station and handles user inputs based on the menu options.
- Cleans up and frees memory before exiting.

## Usage

Compile and run the program using a C compiler. Interact with the program through the console by selecting options from the menu. You can add targets, view the station's configuration, and get a summary of the total targets and capacities.

## Limitations

- The program uses a simple hash function for target selection, which may not be optimal for larger datasets.
- Memory management is manual; care must be taken to avoid memory leaks.
- The system is designed for console-based interaction and does not have a graphical user interface.
