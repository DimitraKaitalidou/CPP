# TicTacToe
This is an implementation of the TicTacToe game, in both C++ and Java. 

## Game rules
1. The game is played on an empty 3x3 matrix, with 2 players
2. Player A plays first and puts symbol X on a selected box. Player B plays second and puts symbol O on a box that has not been selected yet. Then, players A and B take turns
3. The first player to get 3 of his/her symbols in a vertical, horizontal or diagonal row is the winner and the game stops
4. When all boxes are full, the game is over. If no player gets 3 of his/her symbols in a row, it is a tie

## Implementation details
The 3x3 matrix is named TicTacToe. The program reads the user input for box selection. Valid numbers are 0 to 8 for box selection and 9 to quit the game. In order to make sure that the selections are valid the following checks are performed on the input:
- If a player enters an invalid number, i.e., lower than 0 or higher than 9, the program prompts to select a box again
- If a player enters a number which corresponds to an already selected box, the program prompts to select a box again

The following functions were created:
- main: this function implements the core functionality of the game
- showBoard: this function shows the current state of the TicTacToe so that the players know which boxes are available for selection
- checkResult: this function checks all the combinations in the TicTacToe that would qualify a win, i.e., 3 same symbols in a vertical, horizontal or diagonal row

## References
1.https://en.wikipedia.org/wiki/Tic-tac-toe
