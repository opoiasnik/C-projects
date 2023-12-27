# Documentation for Bracket Checker Program

## Overview

This C program, named "Bracket Checker," is designed to validate strings containing various types of brackets. It checks for the proper nesting and pairing of brackets such as parentheses `()`, curly braces `{}`, square brackets `[]`, and angle brackets `<>`. The program highlights any discrepancies like unmatched, crossed, or missing brackets.

## Functionality

### `checkBrackets` Function

- **Purpose**: Checks a given string for balanced and properly nested brackets.
- **Parameters**: `char input[]` - A string containing the characters to be checked.
- **Return Value**: Returns `true` if all brackets are correctly nested and paired, and `false` otherwise.

#### Process:

1. **Initialization**: Allocates a stack for tracking open brackets.
2. **Bracket Matching**: Iterates through the input string, pushing open brackets onto the stack and popping them when a matching closing bracket is encountered.
3. **Error Detection**: Identifies three types of errors:
    - Unexpected closing bracket (when no matching open bracket exists in the stack).
    - Crossed brackets (when a closing bracket does not match the expected type based on the most recent open bracket).
    - Missing closing brackets (detected at the end if any open brackets remain in the stack).
4. **Error Reporting**: Prints detailed error messages for each type of bracket mismatch.
5. **Memory Management**: Frees the allocated memory for the stack before exiting the function.

### `main` Function

- **Purpose**: To read a string from the user and use the `checkBrackets` function to validate it.
- **Process**:
    1. Reads a string of up to 99 characters from standard input.
    2. Invokes the `checkBrackets` function with the input string.
    3. Exits the program.

## Usage

1. Compile the program using a C compiler.
2. Run the executable.
3. Enter a string containing brackets when prompted.
4. The program will analyze the string and output any bracket-related errors or confirm that all brackets are correctly used.

## Limitations

- The program can handle strings up to 99 characters long.
- The stack size for tracking brackets is statically allocated and limited to 100 characters.
- The program does not account for characters other than the four types of brackets.
- It may not handle very complex nested structures efficiently due to its linear approach.

## Conclusion

This Bracket Checker program is a useful tool for validating strings containing nested and paired brackets. It's particularly helpful in scenarios like checking code syntax or mathematical expressions for proper bracket usage.
