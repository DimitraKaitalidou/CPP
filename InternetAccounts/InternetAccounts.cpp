// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Customer{

   string name;
   string surname;
   string login_name;
   string password;
   float charge;
   float total_amount_of_mb;

   // Access specifier
   public:
   void connect();
   string read_login_name(){return login_name;}
   string read_name(){return name;}
   string read_surname(){return surname;}
   string read_password(){return password;}
   float read_charge(){return charge;}
   void bill();
   Customer();
};

Customer::Customer(){

   cout << "Give customer name:\n";
   cin >> name;
   cout << "Give customer surname:\n";
   cin >> surname;
   cout << "Give customer login name:\n";
   cin >> login_name;
   cout << "Give customer password:\n";
   cin >> password;
   cout << "Give customer charge:\n";
   cin >> charge;

   total_amount_of_mb = 0;
}

void Customer::connect(){

   char pswrd[4];
   int amount_of_mb;

   // Read the password but hide it with "*"
   cout << "Enter password: ";
   for (int i = 0; i < 4; i++)
      {
         pswrd[i] = _getch();
         cout << "*";
      }

   string s(pswrd, 4);
   if (s == password)
      {
         cout << "\n";
         cout << "Access allowed.\n";
         cout << "Give ammount of mb: ";
         cin >> amount_of_mb;

         total_amount_of_mb = total_amount_of_mb + amount_of_mb;
      }
   else cout << "Access denied!\n";
}

void Customer::bill(){

   cout << "*** Bill statement ***\n";
   cout << "Customer name: ";
   cout << read_name() << "\n";
   cout << "Customer surname: ";
   cout << read_surname() << "\n";
   cout << "Customer charge is: ";
   cout << (read_charge())*total_amount_of_mb << " euros \n";
   cout << "**********************\n";
}

int main(){

   // Initialize variables
   int number_of_customers;
   cout << "Enter the number of customers:";
   cin >> number_of_customers;
   Customer *client_info = new Customer[number_of_customers];
   string str;

   // Start endless process 
   while(1)
      {
         cout << "Enter login name to connect or q to exit: ";
         cin >> str;

         if (str.compare("q") != 0)
            {
               for (int i = 0; i < number_of_customers; i++)
                  {
                     if (str == client_info[i].read_login_name())
                        {
                           cout << "Valid login name.\n";
                           client_info[i].connect();
                           break;
                        }

                     if(i == number_of_customers - 1)  cout << "Invalid login name.\n";
                  }
            }
         else break;
      }

   // Print the bill statements of all customers
   for (int j = 0; j < number_of_customers; j++) client_info[j].bill();

   // Free memory and return
   delete [] client_info;
   return 0;
}
