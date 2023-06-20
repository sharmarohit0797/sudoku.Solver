# sudoku.Solver
The algorithm used to solve the Sudoku puzzle is a backtracking algorithm. Backtracking is a technique
that explores all possible solutions by systematically trying different options and undoing incorrect
choices. In this case, the algorithm starts by finding an empty cell and tries different numbers in that
cell. If a number is found that satisfies the Sudoku rules, the algorithm recursively moves to the next
empty cell and continues the process. If a solution is not found, the algorithm backtracks to the previous
cell and tries a different number. This process continues until a valid solution is found or all possibilities
are exhausted.
