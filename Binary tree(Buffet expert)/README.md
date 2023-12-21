

### Documentation

#### Global Variables:
1. `int isReadingNoBranch`: Controls the reading of the 'no' branch of a node.
2. `int stopReading`: Flag to stop further reading upon encountering an error or end of input.

#### Structure Definition:
- **struct tree**: 
  - `char value[SIZE]`: Stores the value/question at each node.
  - `struct tree* yes`: Pointer to the 'yes' subtree.
  - `struct tree* no`: Pointer to the 'no' subtree.

#### Functions:

1. **void destroy_tree(struct tree* tree)**:
   - Purpose: Recursively deallocates memory used by the tree.
   - Parameters: `tree` - pointer to the root of the tree.

2. **struct tree* read_tree(int* counter)**:
   - Purpose: Recursively reads input from stdin to build the binary tree.
   - Parameters: `counter` - keeps track of the number of 'no' branches read.
   - Returns: Pointer to the root of the constructed tree.

3. **void print_tree(struct tree* tree, int offset)**:
   - Purpose: Recursively prints the tree in a formatted manner.
   - Parameters: `tree` - pointer to the current node, `offset` - formatting offset for indentation.

4. **int knowledge_system(struct tree* node)**:
   - Purpose: Navigates through the tree based on user input and prints the final answer or error message.
   - Parameters: `node` - pointer to the current node in the tree.
   - Returns: 0 upon completion.

5. **int main()**:
   - Purpose: Main function to execute the knowledge system.
   - Initializes and builds the tree, then uses it in the knowledge system, and finally deallocates the tree.

#### Working Mechanism:
- The program starts by reading input from stdin to build a binary decision tree, where each node represents a question or a final statement.
- The `read_tree` function is designed to handle various conditions such as erroneous input or end of input.
- Once the tree is built, `print_tree` visually represents it.
- `knowledge_system` navigates through the tree based on user responses ('a' for yes and 'n' for no) until it reaches a leaf node, then prints the final statement.
- After the operation is complete, the tree is deallocated to free memory.

#### Notes:
- The tree is built based on a specific input format, where each node's question or statement is on a new line. A star ('*') at the beginning of a line denotes a 'yes' branch.
- The program has specific checks for input validity and tree structure integrity.
- The user interaction is in the form of answering 'a' or 'n' to the questions posed by the system.
