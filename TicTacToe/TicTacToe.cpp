// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

#include <iostream>

using namespace std;

void showBoard(char *ticTacToe){

   for(int i = 0; i < 9; i++)
      {
         cout << "|" << ticTacToe[i];
         if(i == 2 || i == 5 || i == 8) cout << "| \n";
      }
}

int checkResult(char *ticTacToe){

   int result;

   if(ticTacToe[0] == ticTacToe[1]
   && ticTacToe[1] == ticTacToe[2]) result = (ticTacToe[0] == 'X') ? 1 : 2;
   else if(ticTacToe[3] == ticTacToe[4]
   && ticTacToe[4] == ticTacToe[5]) result = (ticTacToe[3] == 'X') ? 1 : 2;
   else if(ticTacToe[6] == ticTacToe[7]
   && ticTacToe[7] == ticTacToe[8]) result = (ticTacToe[6] == 'X') ? 1 : 2;
   else if(ticTacToe[0] == ticTacToe[3]
   && ticTacToe[3] == ticTacToe[6]) result = (ticTacToe[0] == 'X') ? 1 : 2;
   else if(ticTacToe[1] == ticTacToe[4]
   && ticTacToe[4] == ticTacToe[7]) result = (ticTacToe[1] == 'X') ? 1 : 2;
   else if(ticTacToe[2] == ticTacToe[5]
   && ticTacToe[5] == ticTacToe[8]) result = (ticTacToe[2] == 'X') ? 1 : 2;
   else if(ticTacToe[0] == ticTacToe[4]
   && ticTacToe[4] == ticTacToe[8]) result = (ticTacToe[0] == 'X') ? 1 : 2;
   else if(ticTacToe[2] == ticTacToe[4]
   && ticTacToe[4] == ticTacToe[6]) result = (ticTacToe[2] == 'X') ? 1 : 2;
   else if(ticTacToe[0] == ticTacToe[3]
   && ticTacToe[3] == ticTacToe[6]) result = (ticTacToe[0] == 'X') ? 1 : 2;
   else result = 0;

   return result;
}

int main(){

   // Initialize variables
   char player = 'A';
   int box = 0;
   char ticTacToe[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
   int result = 0;
   int round = 0;

   // Start the game
   cout << "Let's play Tic Tac Toe! \n";
   cout << "*********************** \n";
   cout << "Important tip: To select a box, select an integer number from '0' to '8', or select '9' to quit. \n";

   while(result == 0)
      {
         round++;

         // Read the box the current player selects
         cout << "*********************** \n";
         cout << "Player " << player << " select a box. \n";
         cin >> box;

         // The game is stopped
         if(box == 9)
            {
               system("pause");
               return 0;
            }

         // The current player selected an invalid box
         while(box < 0 || box > 8)
            {
               cout << "Wrong input! \n";
               cout << "Player " << player << " select a valid box, i.e., select a number from 0 to 8. \n";
               cin >> box;

               // The game is stopped
               if(box == 9)
                  {
                     system("pause");
                     return 0;
                  }
            }

         // The current player selected a box that has already been selected by a previous player
         while(ticTacToe[box] != box + 48)
            {
               cout << "This box is taken! \n";
               cout << "Player " << player << " select an available box. \n";
               cin >> box;

               // The game is stopped
               if(box == 9)
                  {
                     system("pause");
                     return 0;
                  }

               // The current player selected an invalid box
               while(box < 0 || box > 8)
                  {
                     cout << "Wrong input! \n";
                     cout << "Player " << player << " select a valid box, i.e., select a number from 0 to 8. \n";
                     cin >> box;
  
                     // The game is stopped
                     if(box == 9)
                        {
                           system("pause");
                           return 0;
                        }
                  }
            }

         // The selection of the current player is being handled
         if(player == 'A')
            {
               ticTacToe[box] = 'X';
               player = 'B';
            }
         else
            {
               ticTacToe[box] = 'O';
               player = 'A';
            }

         showBoard(ticTacToe);
         result = checkResult(ticTacToe);

         if(result == 1)
            {
               cout << "Player A is the winner! \n";
               break;
            }
         else if(result == 2)
            {
               cout << "Player B is the winner! \n";
               break;
            }
         else
            {
               if(round == 9)
                  {
                     cout << "It is a tie! \n";
                     break;
                  }
            }
      }

   return 0;
}

