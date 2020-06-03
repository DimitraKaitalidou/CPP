// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

#include <iostream>
#include <string>

using namespace std;

class Train{

   string train_start, train_destination;
   float train_cost, train_distance, value, ins_coef, train_charge;
   int train_id;
   
   // Access specifier
   public:
   Train(int id);
   ~Train(){};
   float train_show();
};

class Truck{

   string truck_start, truck_destination;
   float truck_cost, truck_distance, truck_charge;
   int tax, truck_id;

   // Access specifier
   public:
   Truck(int id);
   ~Truck(){};
   float truck_show();
};

Train::Train(int id){

   train_id = id;
   cout << "Package " << train_id << ".\n";
   cout << "Give the start: ";
   cin >> train_start;
   cout << "Give the destination: ";
   cin >> train_destination;
   cout << "Give the distance: ";
   cin >> train_distance;
   cout << "Give the cost per distance: ";
   cin >> train_cost;
   cout << "Give the value: ";
   cin >> value;
   cout << "Give the insurance coefficient: ";
   cin >> ins_coef;
   train_charge = 0;
}

float Train::train_show(){

   train_charge = train_cost * train_distance + value * train_distance * ins_coef;

   cout << "*** Shipping cost for package " << train_id << " by train. ***\n";
   cout << "Start: ";
   cout << train_start << "\n";
   cout << "Destination: ";
   cout << train_destination << "\n";
   cout << "Package's charge: ";
   cout << train_charge << "\n";
   cout << "*********************************************\n";
   return train_charge;
}

Truck::Truck(int id){

   truck_id = id;
   cout << "Package " << truck_id << ".\n";
   cout << "Give the start: ";
   cin >> truck_start;
   cout << "Give the destination: ";
   cin >> truck_destination;
   cout << "Give the distance: ";
   cin >> truck_distance;
   cout << "Give the tax number: ";
   cin >> tax;
   cout << "Give the cost per distance: ";
   cin >> truck_cost;
   truck_charge = 0;
}

float Truck::truck_show(){

   truck_charge = truck_cost * truck_distance + tax * 0.01 * truck_cost;

   cout << "*** Shipping cost for package " << truck_id << " by truck. ***\n";
   cout << "Start: ";
   cout << truck_start << "\n";
   cout << "Destination: ";
   cout << truck_destination << "\n";
   cout << "Package's charge: ";
   cout << truck_charge << "\n";
   cout << "*********************************************\n";
   return truck_charge;
}

void total_shipping_cost(float cost1, float cost2);

int main(){

   // Initialize variables
   Train *A;
   Truck *B;
   int train_nr_packages = 0;
   int truck_nr_packages = 0;
   float train_sum = 0;
   float truck_sum = 0;

   cout << "Give number of containers that travel with train: ";
   cin >> train_nr_packages;
   cout << "Give number of containers that travel with truck: ";
   cin >> truck_nr_packages;

   A = (Train*)malloc(train_nr_packages * sizeof(Train));
   B = (Truck*)malloc(truck_nr_packages * sizeof(Truck));
   if (A == NULL) 
      {
         cout << "Allocation failure!\n";
         return 0;
      }
   if (B == NULL) 
      {
         cout << "Allocation failure!\n";
         return 0;
      }

   for (int i = 0; i < train_nr_packages; i++)
      {
         Train A(i);
         train_sum += A.train_show();
      }
   for (int j = 0; j < truck_nr_packages; j++)
      {
         Truck B(j);
         truck_sum += B.truck_show();
      }

   // Free memory and return
   free(A);
   free(B);
   total_shipping_cost(train_sum, truck_sum);
   return 0;
}

void total_shipping_cost(float cost1, float cost2){

   float totalcost;
   totalcost = cost1 + cost2;
   cout << "That is the total cost: " << totalcost << "\n";
}
