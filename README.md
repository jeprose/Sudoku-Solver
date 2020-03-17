# Sudoku-Solver
Solves a 9 by 9 sudoku puzzle with backtracing.<br>
Input can be done in two forms, with a command line link to a file, or with simple console input.<br>
Format should be as such:<br>
000400000<br>
003000000<br>
142356789<br>
000000000<br>
000000000<br>
000000000<br>
000000000<br>
000000000<br>
000000000<br>

The first line should represent the first row, with zeroes representing unknowns.<br>
Will output in same format. Runs extremely efficiently, and will not detect if no unique solution. <br>
If initial sudoku is incorrect, will leave unknowns unfilled.<br>
