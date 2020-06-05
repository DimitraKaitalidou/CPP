// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

#include <iostream>

using namespace std;

class Circuit{

   // Access specifier
   protected:
   float r;
   int num_res;
   float v;

   // Access specifier
   public:
   Circuit(){};
   Circuit(int x){v = x;}
   ~Circuit(){}
   void intensity();
   float power();
};

void Circuit::intensity(){

   float inte;
   inte = v / r;
   cout << "The intensity of the circuit is: ";
   cout << inte << " \n";
}

float Circuit::power(){

   float pow;
   pow = (v * v) / r;
   return pow;
}

class Serial : public Circuit{

   float *serial_r;

   // Access specifier
   public:
   Serial(){};
   Serial(int x);
   ~Serial(){}
   float total_serial_resistance();
};

Serial::Serial(int x) : Circuit(x){

   v = x;
   cout << "Give the number of resistances in the serial circuit: ";
   cin >> num_res;

   // Dynamic memory allocation
   serial_r = new float(num_res);

   for(int i = 0; i < num_res; i++)
      {
         cout << "Give the resistance in the serial circuit: ";
         cin >> serial_r[i];
      }
}

float Serial::total_serial_resistance(){

   float total_res = 0;

   for(int i = 0; i < num_res; i++)
      {
         total_res += serial_r[i];
         r = total_res;
      }

   return r;
}

class Parallel : public Circuit{

   float *parallel_r;

   // Access specifier
   public:
   Parallel(){};
   Parallel(int x);
   ~Parallel(){}
   float total_parallel_resistance();
};

Parallel::Parallel(int x) : Circuit(x){

   v = x;
   cout << "Give the number of resistances in the parallel circuit: ";
   cin >> num_res;

   // Dynamic memory allocation
   parallel_r = new float(num_res);

   for(int i = 0; i < num_res; i++)
      {
         cout << "Give the resistance in the parallel circuit: ";
         cin >> parallel_r[i];
      }
}

float Parallel::total_parallel_resistance(){

   float total_res = 0;

   for(int i = 0; i < num_res; i++) total_res += 1 / parallel_r[i];

   r = 1/ total_res;
   return r;
}

void minimum_power(Serial *s, Parallel *p, int num_s, int num_p){

   // Initialize variables
   s[0].total_serial_resistance();
   p[0].total_parallel_resistance();
   float min_serial = s[0].power();
   float min_parallel = p[0].power();
   float pow = 0.0;
   int min_serial_cir = 0;
   int min_paral_cir = 0;

   // Find minimum power of serial circuits
   for(int i = 1; i < num_s; i++)
      {
         s[i].total_serial_resistance();
         pow = s[i].power();
         if(pow < min_serial)
            {
               min_serial = pow;
               min_serial_cir = i;
            }
      }

   cout << "The serial circuit with the least power is: ";
   cout << min_serial_cir << "\n";
   s[min_serial_cir].intensity();

   // Find minimum power of parallel circuits
   for(int j = 1; j < num_p; j++)
      {
         p[j].total_parallel_resistance();
         pow = p[j].power();
         if(pow < min_parallel)
            {
               min_parallel = pow;
               min_paral_cir = j;
            }
      }

   cout << "The parallel circuit with the least power is: ";
   cout << min_paral_cir << "\n";
   p[min_paral_cir].intensity();

   return;
}

int main(){

   // Initialize variables
   int num_circuits_serial = 0;
   int num_circuits_parallel = 0;
   int voltage;

   // Create the serial circuits
   cout << "*** Serial circuits ***\n";
   cout << "Give the number of serial circuits: ";
   cin >> num_circuits_serial;

   // Dynamic memory allocation
   Serial *s = new Serial[num_circuits_serial];

   for (int i = 0; i < num_circuits_serial; i++)
   {
       cout << "Serial circuit " << i << ".\n";
       cout << "Give the voltage of the serial circuit: ";
       cin >> voltage;
       s[i] = Serial(voltage);
   }

   // Create the parallel circuits
   cout << "*** Parallel circuits ***\n";
   cout << "Give the number of parallel  circuits: ";
   cin >> num_circuits_parallel;

   // Dynamic memory allocation
   Parallel *p = new Parallel[num_circuits_parallel];

   for(int j = 0; j < num_circuits_parallel; j++)
      {
         cout << "Parallel circuit " << j << ".\n";
         cout << "Give the voltage of the parallel circuit: ";
         cin >> voltage;
         p[j] = Parallel(voltage);
      }

   // Find minimum power, free memory and return
   minimum_power(s, p, num_circuits_serial, num_circuits_parallel);
   delete [] s;
   delete [] p;
   return 0;
}
