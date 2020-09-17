// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

#include <iostream>
#include <math.h>

using namespace std;

class productA{

   // Access specifier
   public:
   float material_cost_per_prodA, cost_per_prodA, profit_per_prodA;
   productA();
};

productA::productA(){

   cout << "Give the cost of materials for products of type A: ";
   cin >> material_cost_per_prodA;
   cout << "Give the cost of processing per product of type A: ";
   cin >> cost_per_prodA;
   cout << "Give the percentage of profit per product of type A in range [0.1, 1): ";
   cin >> profit_per_prodA;
}

class productB{

   // Access specifier
   public:
   float material_cost_per_prodB, cost_per_prodB, profit_per_prodB;
   float construction_hours, worker_hours, payment_per_prodB;
   productB();
};

productB::productB(){

   cout << "Give the cost of materials for products of type B: ";
   cin >> material_cost_per_prodB;
   cout << "Give the cost of processing per product of type B: ";
   cin >> cost_per_prodB;
   cout << "Give the percentage of profit per product of type B in range [0.1, 1): ";
   cin >> profit_per_prodB;
   cout << "Give the minimum number of hours for the construction of a product of type B: ";
   cin >> construction_hours;
   cout << "Give the number of hours for the construction of a product of type B from 1 worker: ";
   cin >> worker_hours;
   cout << "Give the worker payment per product of type B: ";
   cin >> payment_per_prodB;
 }

void calculate_cost_and_profit(int numA, productA *prA, int numB, productB *prB){

   int num_per_catA = 0;
   int num_per_catB = 0;
   float value = 0.0;
   float cost = 0.0;
   float profit = 0.0;

   cout << "-------------------\n";
   cout << "Products of type A \n";
   cout << "-------------------\n";

   for(int i = 0; i < numA; i++)
      {
         cout << "Give the number of products for the " << i << " category: ";
         cin >> num_per_catA;
         value += (prA[i].material_cost_per_prodA + prA[i].cost_per_prodA + (prA[i].material_cost_per_prodA + prA[i].cost_per_prodA) * prA[i].profit_per_prodA) * num_per_catA;
         cost += (prA[i].material_cost_per_prodA + prA[i].cost_per_prodA) * num_per_catA;
      }

   cout << "-------------------\n";
   cout << "Products of type B \n";
   cout << "-------------------\n";

   for(int j = 0; j < numB; j++)
      {
         float worker_cost = 0.0;

         cout << "Give the number of products for the " << j << " category: ";
         cin >> num_per_catB;

         if (prB[j].construction_hours >= prB[j].worker_hours) worker_cost = prB[j].payment_per_prodB;
         else worker_cost = prB[j].payment_per_prodB * ceil(prB[j].worker_hours / prB[j].construction_hours);

         value += (prB[j].material_cost_per_prodB + prB[j].cost_per_prodB + worker_cost + (prB[j].material_cost_per_prodB + prB[j].cost_per_prodB + worker_cost) * prB[j].profit_per_prodB) * num_per_catB;
         cost += (prB[j].material_cost_per_prodB + prB[j].cost_per_prodB + worker_cost) * num_per_catB;
      }

   profit = value - cost;
   cout << "The total cost for the order is: " << cost << "\n";
   cout << "The total value for the order is: " << value << "\n";
   cout << "The total profit for the order is: " << profit << "\n";
}

int main(){

   // Initialize variables
   int numA = 0;
   int numB = 0;

   cout << "Give the number of categories of products of type A: ";
   cin >> numA;
   cout << "Give the number of categories of products of type B: ";
   cin >> numB;

   // Dynamic memory allocation
   cout << "-------------------\n";
   cout << "Products of Type A \n";
   cout << "-------------------\n";
   productA *prA = new productA[numA];

   cout << "-------------------\n";
   cout << "Products of Type B \n";
   cout << "-------------------\n";
   productB *prB = new productB[numB];

   calculate_cost_and_profit(numA, prA, numB, prB);

   // Free memory and return
   delete[] prA;
   delete[] prB;
   return 0;
}
