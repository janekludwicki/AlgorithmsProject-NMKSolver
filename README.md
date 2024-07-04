# NMK Solver

An m,n,k-game is an abstract board game where two players alternate placing a stone of their color on an **n-by-m** board. The winner is the first player to get **k** stones of their color in a row, either horizontally, vertically, or diagonally.

The NMK Solver is a program that uses a minimax algorithm, optimized with techniques like Alpha-Beta pruning, to evaluate the game state and predict outcomes based on optimal moves from both players. The program accepts three commands and requires input values for n, m, k, the player making the next move (either 1 or 2), and the current board state (represented by numbers: 0 for an empty cell, 1 for a stone from the first player, and 2 for a stone from the second player).

## Commands

### 1. GEN_ALL_POS_MOV
This command returns the number of possible moves for a player and generates all possible boards resulting from each move.

### 2. GEN_ALL_POS_MOV_CUT_IF_GAME_OVER
This command searches for a winning move. It returns the number of possible moves (typically outputting 1 if a winning move is found) and generates either the board after the winning move or all possible boards after each move.

### 3. SOLVE_GAME_STATE
This is the primary command of the program. It uses the minimax algorithm to evaluate the current game state and determine which player is likely to win or if the game will end in a tie. The command returns a string indicating whether one of the players should win or if a tie is expected.
