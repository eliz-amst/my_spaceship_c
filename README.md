# SpacePro Ship Simulator

## Overview

SpacePro, a cutting-edge rocket manufacturer, has developed a new simulator to track the movements and orientation of their spaceships. This document describes the design and implementation of the simulator which takes a string of commands and returns the final position and orientation of the spaceship. The commands include turning right, turning left, and advancing forward. The simulator uses a coordinate system where the spaceship starts at the origin (0,0) facing upwards.

## Function Specification

The main function `myspaceship` processes a string of commands and calculates the final coordinates and orientation of the spaceship.

### Command Descriptions

- **R**: Turn right (90 degrees clockwise)
- **L**: Turn left (90 degrees counterclockwise)
- **A**: Advance in the current direction

### Directions

- **Up**: Initially facing upwards
- **Right**: 90 degrees right turn from upwards
- **Down**: 180 degrees turn from upwards
- **Left**: 270 degrees turn from upwards

### Coordinates System

- **X-Axis**: Increases to the right, decreases to the left
- **Y-Axis**: Increases upwards, decreases downwards

## Function Signature

```c
char* myspaceship(char* flightPath);
```

- **Input**: `flightPath` - A string consisting of commands 'R', 'L', and 'A'.
- **Output**: A string representing the final position and direction in the format `"{x: X, y: Y, direction: 'DIRECTION'}"`.

## Implementation

### Steps

1. **Initialize Position and Direction**:
   - Start at (0, 0).
   - Initial direction is 'up'.
2. **Process Commands**:
   - Iterate through the command string.
   - Update direction for 'R' and 'L' commands.
   - Update position for 'A' command based on the current direction.
3. **Format and Return Result**:
   - Return the final position and direction as a formatted string.

### Example

For a flight path "RRALAA":

- Initial position: (0, 0), facing up.
- Turn right (R): facing right.
- Turn right (R): facing down.
- Advance (A): move to (0, -1).
- Turn left (L): facing right.
- Advance (A): move to (1, -1).
- Advance (A): move to (2, -1).
- Final position: (2, -1), facing right.
- Output: `"{x: 2, y: -1, direction: 'right'}"`.

## Usage

To use the `myspaceship` function, simply call it with the flight path as a string argument. For example:

```c
#include <stdio.h>

int main() {
    char flightPath[] = "RRALAA";
    char* result = myspaceship(flightPath);
    printf("%s\n", result);
    free(result);
    return 0;
}
```

This will output:

```
{x: 2, y: -1, direction: 'right'}
```

## Conclusion

This simulator effectively tracks and outputs the final position and orientation of the spaceship based on a series of movement commands. It is designed to handle an infinite coordinate space and provides clear, formatted results for integration into larger systems or for further processing.
