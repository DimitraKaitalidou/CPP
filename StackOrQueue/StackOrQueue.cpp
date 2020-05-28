// Copyright 2019, Dimitra S. Kaitalidou, All rights reserved

#include <iostream>
#include <string>

using namespace std;

class Node{

   // Access specifier 
   public:

   // Node information
   int node_data;
   Node *next_node;
};

class Structure{

   // Access specifier 
   public:

   // Structure variables
   Node *top = NULL;

   // Structure functions
   void remove(){

      if(isEmpty())
         {
            cout << "It is empty. \n";
            return;
         }

      Node *temp_node;
      temp_node = top->next_node;
      delete top;
      top = temp_node;
   }

   int isEmpty(){

      if (top == NULL) return 1;
      else return 0;
   }

   void getTop(){

      if(isEmpty()) cout << "It is empty. \n";
      else cout << "The top is: " << top->node_data << "\n";
   }
};

class Stack : public Structure{

   // Access specifier 
   public:

   // Stack functions
   void push(int d){

      Node *new_node = new Node;
      new_node->node_data = d;
      new_node->next_node = top;
      top = new_node;
      return;
   }
};

class Queue : public Structure{

   // Access specifier 
   public:

   // Queue variables
   Node *tail;

   // Queue functions
   void insert(int d){

      Node *new_node = new Node;
      new_node->node_data = d;
      new_node->next_node = NULL;
      if(tail != NULL) tail->next_node = new_node;
      tail = new_node;
      if(top == NULL)  top = tail;
      return;
   }
};

int main(){

   // Declare variables
   char action;
   int input;
   string select;

   // Select what to create
   cout << "Press 0 to create a Stack, or 1 to create a Queue, or q to exit. \n";
   cin >> select;

   if(select.compare("q") == 0)
      {
         system("pause");
         return 0;
      }

   while(select.compare("0") != 0 && select.compare("1") != 0 && select.compare("q") != 0)
      {
         cout << "Wrong input! \n";
         cout << "Press 0 to create a Stack, or 1 to create a Queue, or q to exit. \n";
         cin >> select;

         if(select.compare("q") == 0)
            {
               system("pause");
               return 0;
            }
      }

   // Manage the data structures
   if(select.compare("0") == 0)
      {
         Stack S1;
         cout << "A Stack was created. \n";

         while(1)
            {
               cout << "Select action for the Stack: 0 -> Exit 1 -> Push 2 -> Pop 3 -> Results \n";
               cin >> action;

               switch(action)
                  {
                     case '0':
                        system("pause");
                        return 0;
                     case '1':
                        cout << "Push data into the Stack. \n";
                        cin >> input;
                        S1.push(input);
                        break;
                     case '2':
                        S1.remove();
                        break;
                     case '3':
                        S1.getTop();
                        break;
                     default:
                        cout << "Wrong input! \n";
                  }
            }
      }
   else
      {
         Queue Q1;
         cout << "A Queue was created. \n";

         while(1)
            {
               cout << "Select action for the Queue: 0 -> Exit 1 -> Insert 2 -> Remove 3 -> Results \n";
               cin >> action;

               switch(action)
                  {
                     case '0':
                        system("pause");
                        return 0;
                     case '1':
                        cout << "Insert data into the Queue. \n";
                        cin >> input;
                        Q1.insert(input);
                        break;
                     case '2':
                        Q1.remove();
                        break;
                     case '3':
                        Q1.getTop();
                        break;
                     default:
                        cout << "Wrong input! \n";
                  }
            }
      }

   system("pause");
   return 0;
}
