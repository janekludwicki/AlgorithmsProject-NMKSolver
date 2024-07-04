
# NMK_Solver

An m,n,k-game is an abstract board game in which two players take turns in placing a stone of their color on an **n-by-m** board, the winner being the player who first gets **k** stones of their own color in a row, horizontally, vertically, or diagonally.

NMK_Solver is program that accepts 3 commands followed by input of values n, m, k, number of player that is supposed to make a move (either 1 or 2) and board made from numbers 0 (empty cell), 1 (first player pawn), 2 (second player pawn).

The main purpose of the program is using implemented minimax algorithm to evaluate the state of game and predict its outcome assuming best possible moves are made by each player. Additionally algorithm is optimized using techniques like for example Alpha-Beta pruning.

Description of possible commands:

## 1. GEN_ALL_POS_MOV
This command firstly returns number of possible moves for a player and secondly generates all possible boards after each move.


## 2. GEN_ALL_POS_MOV_CUT_IF_GAME_OVER
This command makes program look for a first winning move. It firstly returns number of possible moves (output 1 ususally means it found winning move) and secondly generates either board after winning move or all possible boards after each move. 


## 3. SOLVE_GAME_STATE
This is the main command of the program. It is using minimax algorithm to evaluate which player is going to win or if there is a tie. It returns string with information that either one of the players (should) win the game or if there is a tie.c 

