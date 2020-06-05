# Internet Accounts

## Problem statement
A network service company needs to manage the internet connections of the customers, i.e., calculate the cost according to the downloaded MBs and print the bill statements.

## Code description
This C++ program manages the internet connections of a network service company. For each customer of the company an object is defined which registers the name, the surname, the login name and the password, the charge per MB and the total amount of MBs downloaded from the network. The class has a connect function which reads and controls the customer's password and if it is correct, it reads the number of MBs that the customer downloaded from the network in the specific connection. The class has the appropriate functions for issuing customer bill statements.

The program creates a table of customers and uses an endless process during which the user enters the login name of the customer trying to connect to the network, to check if it belongs to one of the customers of the company and if so the program calls the connect function to make the connection. The process is terminated if the string "q" is entered as the customer's login name. After exiting the endless process, the program prints the bill statements of all customers.

