// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

#include <iostream>

using namespace std;

int total_num;

class Network;

class Neuron{

   // Access specifier
   public:
   int id;
   int state_neu;
   int num_neu;
   float thres;
   float sum;
   float *w_neu;
   int *id_neu;
   Neuron(){};
   friend istream &operator>>(istream &stream, Neuron &neu);
   void *operator new[](size_t s);
   void operator delete[](void *n);
};

istream &operator>>(istream &stream, Neuron &neu){

   neu.sum = 0;

   cout << "Give the activation threshold: ";
   stream >> neu.thres;

   cout << "Give the initial state of the main neuron: ";
   stream >> neu.state_neu;
   while(neu.state_neu != 1 && neu.state_neu != -1)
      {
         cout << "Wrong number, please type 1 or -1!\n";
         stream >> neu.state_neu;
      }

   for(int i = 0; i < neu.num_neu; i++)
      {
         cout << "Give the id of the " << i << " neuron: ";
         stream >> neu.id_neu[i];
         while(neu.id_neu[i] == neu.id || neu.id_neu[i] > total_num - 1)
            {
               cout << "The id of the connected neuron can not be the same as the id of the main neuron or larger than the total number of neurons!\n";
               stream >> neu.id_neu[i];
            }

         cout << "Give the weight of the synapsis: ";
         stream >> neu.w_neu[i];
      }

   return stream;
}

void *Neuron::operator new[](size_t s){

   Neuron *neu = (Neuron*)malloc((s / 28) * sizeof(Neuron));
   if(neu == NULL)
      {
         cout << "Memory allocation failed!\n";
         exit(0);
      }

   for(int i = 0; i < (s / 28); i++)
      {
         neu[i].id = i;
         cout << "Give the number of neurons that connect to neuron " << i << ".\n";
         cin >> neu[i].num_neu;
         while(neu[i].num_neu > total_num - 1)
            {
               cout << "The number of connected neurons can not exceed the total number of the neurons of the network!\n";
               cin >> neu[i].num_neu;
            }

         neu[i].id_neu = (int*)malloc(s);
         if(neu[i].id_neu == NULL)
            {
               cout << "Memory allocation failed!\n";
               exit(0);
            }
         neu[i].w_neu = (float*)malloc(s);
         if(neu[i].w_neu == NULL)
            {
               cout << "Memory allocation failed!\n";
               exit(0);
            }

         cin >> neu[i];
      }

   void *n = neu;
   return n;
}

void Neuron::operator delete[](void *n){

   // Free memory
   free(n);
}

class Network{

   int net_num;
   Neuron *neu;
   int is_stable;

   // Access specifier
   public:
   Network(){};
   void *operator new[](size_t s);
   friend ostream &operator<<(ostream &stream, Network net);
   void calculate_state();
};

void Network::calculate_state(){

   is_stable = 1;
   int repetitions = 0;
   int temp;
   int count = 0;

   cout << "Give the maximum number of repetitions for the redefinition: ";
   cin >> repetitions;

   while(count < repetitions)
      {
         for(int i = 0; i < net_num; i++)
            {
               for(int j = 0; j < neu[i].num_neu; j++) neu[i].sum = neu[i].sum + neu[neu[i].id_neu[j]].state_neu * neu[i].w_neu[j];

               temp = neu[i].state_neu;
               if(neu[i].sum < neu[i].thres) neu[i].state_neu = -1;
               else neu[i].state_neu = 1;
               if(temp != neu[i].state_neu) is_stable = 0;
            }

         if(!is_stable)
            {
               count++;
               is_stable = 1;
            }
         else break;
      }
}

ostream &operator<<(ostream &stream, Network net){

   if(!net.is_stable) cout << "The network is unstable.\n";
   else stream << "The network is stable.\n";

   cout << "+++ Stability synopsis of the neurons of the network +++\n";
   for(int i = 0; i < net.net_num; i++)
      {
         if(net.neu[i].state_neu == 1) stream << "The " << i << " neuron is stable.\n";
         else stream << "The " << i << " neuron is unstable.\n";

         // Free memory
         delete [] net.neu[i].id_neu;
         delete [] net.neu[i].w_neu;
      }

   // Free memory and return
   delete [] net.neu;
   return stream;
}

void *Network::operator new[](size_t s){

   Network net;
   net.net_num = s / 12;
   net.neu = new Neuron[net.net_num];

   net.calculate_state();
   cout << net;

   void *n = &net;
   return n;
}

int main(){

   cout << "Give the total number of neurons that the network consists of: ";
   cin >> total_num;
   Network *net = new Network[total_num];

   // Return
   return 0;
}
