# sudoku-in-cpp

This is a sudoku solver built only using C++. The program implements a backtracking algorithm which works in the following manner:

Consider a sudoku is given and we need to solve it. Let the rows be numbered from 0 to 8 and the columns be numbered from 0 to 8. Basically, a 9x9 2D array. The empty squares of the sudoku will be denoted by a zero.
Step 1: Traverse the row and look for an empty square i.e. a square containing a zero.
Step 2: Once a zero is found, check the numbers (starting from 1 to 9) which can be inserted in this square. This is done by calling three functions that tell us which numbers cannot be inserted in the sudoku. The first function checks the row, the second function checks the column, and the third function checks the 3x3 box.
Step 3: Once a valid number is found, it is inserted into that square and the program moves to the next zero. Repeats from Step 1.

There are cases when no valid number can be placed in a square containing zero. This indicates that one or more numbers were incorrectly placed in the sudoku. Thus, we move to the square we previously filled and check for the next higher valid number. In case we don't find a higher valid number, we again move to the previously filled square. Once we do find another valid number, we place this new number and move to Step 1 again.
