// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

import java.util.Scanner;

public class TicTacToe{

   public static void showBoard(char [] ticTacToe){

      for(int i = 0; i < ticTacToe.length; i++)
         {
            System.out.print("|" + ticTacToe[i]);
            if(i == 2 || i == 5 || i == 8) System.out.println("|");
         }
   }

   public static int checkResult(char [] ticTacToe){

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

   public static void main(String[] args){

      // Initialize variables
      char player = 'A';
      int box = 0;
      char[] ticTacToe = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
      int result = 0;
      int round = 0;
      Scanner scanner = new Scanner(System.in);

      // Start the game
      System.out.println("Let's play Tic Tac Toe!");
      System.out.println("***********************");
      System.out.println("Important tip: To select a box, select an integer number from '0' to '8', or select '9' to quit.");

      while(result == 0)
         {
            round++;

            // Read the box the current player selects
            System.out.println("***********************");
            System.out.println("Player " + player + " select a box.");
            box = scanner.nextInt();

            // The game is stopped
            if(box == 9)
               {
                  scanner.close();
                  return;
               }

            // The current player selected an invalid box
            while(box < 0 || box > 8)
               {
                  System.out.println("Wrong input!");
                  System.out.println("Player " + player + " select a valid box, i.e., select a number from 0 to 8.");
                  box = scanner.nextInt();

                  // The game is stopped
                  if(box == 9)
                     {
                        scanner.close();
                        return;
                     }
               }

            // The current player selected a box that has already been selected by a previous player
            while(ticTacToe[box] != box + 48)
               {
                  System.out.println("This box is taken!");
                  System.out.println("Player " + player + " select an available box.");
                  box = scanner.nextInt();

                  // The game is stopped
                  if(box == 9)
                     {
                        scanner.close();
                        return;
                     }

                  // The current player selected an invalid box
                  while(box < 0 || box > 8)
                     {
                        System.out.println("Wrong input!");
                        System.out.println("Player " + player + " select a valid box, i.e., select a number from 0 to 8.");
                        box = scanner.nextInt();

                        // The game is stopped
                        if(box == 9)
                           {
                              scanner.close();
                              return;
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
                  System.out.println("Player A is the winner!");
                  break;
               }
            else if(result == 2)
               {
                  System.out.println("Player B is the winner!");
                  break;
               }
            else
               {
                  if(round == 9)
                     {
                        System.out.println("It is a tie!");
                        break;
                     }
               }
         }

      scanner.close();
      return;
   }
}
