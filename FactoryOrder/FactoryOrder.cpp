// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

#include <iostream>

using namespace std;

class ProductA{

   float item_cost;
   float item_time;

   // Access specifier
   public:
   ProductA();
   float get_item_cost(){return item_cost;}
   float get_item_time(){return item_time;}
};

ProductA::ProductA(){

   cout << "Give the cost for the production of one item: ";
   cin >> item_cost;
   cout << "Give the time for the production of one item: ";
   cin >> item_time;
}

class MachineA{

   float cost_per_secA;
  
   // Access specifier
   public:
   MachineA();
   float get_cost(){return cost_per_secA;}
};

MachineA::MachineA(){

   cout << "Give the cost for the function of machineA per second: ";
   cin >> cost_per_secA;
}

class MachineB{

   float cost_per_secB;
   float m_cost_per_sec;

   // Access specifier
   public:
   MachineB();
   float get_cost(){return (cost_per_secB + m_cost_per_sec);}
};

MachineB::MachineB(){

   cout << "Give the cost for the function of machineB per second: ";
   cin >> cost_per_secB;
   cout << "Give the cost for the maintenance of machineB per second: ";
   cin >> m_cost_per_sec;
}

template <class Product, class Machine> class Order{

   Product pro_type;
   Machine mac_type;
   int pro_num, mac_num;

   // Access specifier
   public:
   Order();
   float order_cost();
   float order_time();
};

template <class Product, class Machine> Order<Product, Machine>::Order(){

   cout << "Give the number of items of one product: ";
   cin >> pro_num;
   cout << "Give the number of machines for the order: ";
   cin >> mac_num;
}


template <class Product, class Machine> float Order<Product, Machine>::order_cost(){

   float total_cost;
   total_cost = pro_num * pro_type.get_item_cost() + (pro_type.get_item_time() * mac_type.get_cost()) * pro_num;
   return total_cost;
}

template <class Product, class Machine> float Order<Product, Machine>::order_time(){

   float total_time;
   total_time = (pro_type.get_item_time() * pro_num) / mac_num;
   return total_time;
}

template <class qtypeA, class qtypeB> int comp(qtypeA x, qtypeB y){

   if(x < y) return 1;
   else return 2;
}

int main(){

   // Initialize variables
   float costA, timeA, costB, timeB;
   Order<ProductA, MachineA> PA;
   Order<ProductA, MachineB> PB;

   costA = PA.order_cost();
   timeA = PA.order_time();
   cout << "The total cost for the 1st order is: " << costA << "\n";
   cout << "The total time for the 1st order is: " << timeA << "\n";

   costB = PB.order_cost();
   timeB = PB.order_time();
   cout << "The total cost for the 2nd order is: " << costB << "\n";
   cout << "The total time for the 2nd order is: " << timeB << "\n";

   cout << "Finally the comparison result is: " << comp(costA * timeA, costB * timeB) << "!\n";

   // Return
   return 0;
}
