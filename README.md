# Sudoku-Solver
Solves a 9 by 9 sudoku puzzle with backtracing.
Input can be done in two forms, with a command line link to a file, or with simple console input.
Format should be as such:
000400000<br>
003000000\n
142356789
000000000
000000000
000000000
000000000
000000000
000000000

The first line should represent the first row, with zeroes representing unknowns.
Will output in same format. Runs extremely efficiently, and will not detect if no unique solution. 
If initial sudoku is incorrect, will leave unknowns unfilled.
