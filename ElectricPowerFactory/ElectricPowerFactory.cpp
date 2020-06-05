// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

#include <iostream>
#include <string>

using namespace std;

class Sun{

   float sun_hours, oil_hours, surface, oil_per_hour, oil_cost, sun_factor, oil_factor, main_cost;
   int intensity;

   // Access specifier
   public:
   Sun(){};
   Sun(float x, int y);
   Sun(float x);
   ~Sun(){}
   float energy_cost(int x);
};

Sun::Sun(float x, int  y){

   sun_hours = x;
   intensity = y;
   cout << "*** Solar collector ***\n";
   cout << "Give the surface: ";
   cin >> surface;
   cout << "Give the performance factor for the sollar collector: ";
   cin >> sun_factor;
   cout << "Give the cost of maintance: ";
   cin >> main_cost;
   cout << "***********************\n";
}

Sun::Sun(float x){

   oil_hours = x;
   cout << "*** Oil generator in solar collector system ***\n";
   cout << "Give the oil consumed in one hour: ";
   cin >> oil_per_hour;
   cout << "Give the cost of the oil: ";
   cin >> oil_cost;
   cout << "Give the performance factor for the oil system: ";
   cin >> oil_factor;
   cout << "Give the cost of maintenance: ";
   cin >> main_cost;
   cout << "***********************************************\n";
}

float Sun::energy_cost(int x){

   float cost1, cost2, sun_energy1, sun_energy2;

   switch(x)
      {
         case 0:
            sun_energy1 = surface * sun_hours * intensity * sun_factor;
            return sun_energy1;
         case 1:
            cost1 = main_cost;
            return cost1;
         case 2:
            sun_energy2 = oil_hours * oil_per_hour * oil_factor;
            return sun_energy2;
         case 3:
            cost2 = oil_hours * oil_per_hour * oil_cost + main_cost;
            return cost2;
         default:
            cout << "Wrong number!\n";
      }
}

class Wind{

   float wind_hours, oil_hours, oil_per_hour, oil_cost, wind_factor, oil_factor, main_cost;
   int wind_speed;

   // Access specifier
   public:
   Wind(){};
   Wind(float x, int y);
   Wind(float x);
   ~Wind(){}
   float energy_cost(int x);
};

Wind::Wind(float x, int y){

   wind_hours = x;
   wind_speed = y;
   cout << "*** Wind turbine ***\n";
   cout << "Give the performance factor for the wind turbine: ";
   cin >> wind_factor;
   cout << "Give the cost of maintance: ";
   cin >> main_cost;
   cout << "********************\n";
}

Wind::Wind(float x){

   oil_hours = x;
   cout << "*** Oil generator in wind turbine system ***\n";
   cout << "Give the oil consumed in one hour: ";
   cin >> oil_per_hour;
   cout << "Give the cost of the oil: ";
   cin >> oil_cost;
   cout << "Give the performance factor for the oil system: ";
   cin >> oil_factor;
   cout << "Give the cost of maintance: ";
   cin >> main_cost;
   cout << "********************************************\n";
}

float Wind::energy_cost(int x){

   float cost1, cost2, wind_energy1, wind_energy2;

   switch(x)
      {
         case 0:
            wind_energy1 = wind_speed * wind_factor * wind_hours;
            return wind_energy1;
         case 1:
            cost1 = main_cost;
            return cost1;
         case 2:
            wind_energy2 = oil_hours * oil_per_hour * oil_factor;
            return wind_energy2;
         case 3:
            cost2 = oil_hours * oil_per_hour * oil_cost + main_cost;
            return cost2;
         default:
            cout << "Wrong number!\n";
      }
}

class Factory : public Sun, public Wind {

   // Access specifier
   public:
   Factory() : Sun(), Wind(){}
   Factory(float x, int y, float z, int w) : Sun(x, y), Wind(z, w){}
   Factory(float x, float z, int w) : Sun(x), Wind(z, w){}
   Factory(float x, float z) : Sun(x), Wind(z){}
   Factory(float x, int y, float z) : Sun(x, y), Wind(z){}
   float energy_cost(float x, float y);
};

float Factory::energy_cost(float x, float y){

   return x + y;
}

int main(){

   // Initialize variables
   int N = 0;
   Factory *F;
   string s, w;
   float sun_energy, sun_main_cost, wind_energy, wind_main_cost, daily_energy, daily_cost;
   float sun_hours, sun_oil_hours, wind_hours, wind_oil_hours;
   int intensity, wind_speed;
   float total_energy = 0;
   float total_cost = 0;

   cout << "Give the number of stations: ";
   cin >> N;

   // Dynamic memory allocation
   Factory *f = new Factory[N];

   for(int i = 0; i < N; i++)
      {
         cout << "-----------\n";
         cout << "Station " << i << "\n";
         cout << "-----------\n";

         // Select the type of system
         cout << "Type 0 for the solar collector or 1 for the oil system of the solar collector system: ";
         cin >> s;

         while(s.compare("0") != 0 && s.compare("1") != 0)
            {
               cout << "Wrong input! \n";
               cout << "Type 0 for the solar collector or 1 for the oil system of the solar collector system: ";
               cin >> s;
            }

         cout << "Type 0 for the wind turbine or 1 for the oil system of the wind turbine system: ";
         cin >> w;

         while (w.compare("0") != 0 && w.compare("1") != 0)
            {
               cout << "Wrong input! \n";
               cout << "Type 0 for the wind turbine or 1 for the oil system of the wind turbine system: ";
               cin >> w;
            }

         // Perform main operations
         if(s.compare(w) == 0)
            {
               if(s.compare("0") == 0)
                  {
                     cout << "+++ Solar collector system +++\n";
                     cout << "Give the hours of sunshine: ";
                     cin >> sun_hours;
                     cout << "Give the intensity of the luminous flux: ";
                     cin >> intensity;
                     cout << "+++ Wind turbine system +++\n";
                     cout << "Give the operating hours of the wind turbine: ";
                     cin >> wind_hours;
                     cout << "Give the wind speed: ";
                     cin >> wind_speed;

                     f[i] = Factory(sun_hours, intensity, wind_hours, wind_speed);
                     sun_energy = f[i].Sun::energy_cost(0);
                     sun_main_cost = f[i].Sun::energy_cost(1);
                     wind_energy = f[i].Wind::energy_cost(0);
                     wind_main_cost = f[i].Wind::energy_cost(1);
                     daily_energy = f[i].energy_cost(sun_energy, wind_energy);
                     daily_cost = f[i].energy_cost(sun_main_cost, wind_main_cost);
                  }
               else
                  {
                     cout << "+++ Solar collector system +++\n";
                     cout << "Give the operating hours of oil generator of the solar collector system: ";
                     cin >> sun_oil_hours;
                     cout << "+++ Wind turbine system +++\n";
                     cout << "Give the operating hours of oil generator of the wind turbine system: ";
                     cin >> wind_oil_hours;

                     f[i] = Factory(sun_oil_hours, wind_oil_hours);
                     sun_energy = f[i].Sun::energy_cost(2);
                     sun_main_cost = f[i].Sun::energy_cost(3);
                     wind_energy = f[i].Wind::energy_cost(2);
                     wind_main_cost = f[i].Wind::energy_cost(3);
                     daily_energy = f[i].energy_cost(sun_energy, wind_energy);
                     daily_cost = f[i].energy_cost(sun_main_cost, wind_main_cost);
                  }
            }
         else
            {
               if(s.compare("0") == 0)
                  {
                     cout << "+++ Solar collector system +++\n";
                     cout << "Give the hours of sunshine: ";
                     cin >> sun_hours;
                     cout << "Give the intensity of the luminous flux: ";
                     cin >> intensity;
                     cout << "+++ Wind turbine system +++\n";
                     cout << "Give the operating hours of the oil generator of the wind turbine system: ";
                     cin >> wind_oil_hours;

                     f[i] = Factory(sun_hours, intensity, wind_oil_hours);
                     sun_energy = f[i].Sun::energy_cost(0);
                     sun_main_cost = f[i].Sun::energy_cost(1);
                     wind_energy = f[i].Wind::energy_cost(2);
                     wind_main_cost = f[i].Wind::energy_cost(3);
                     daily_energy = f[i].energy_cost(sun_energy, wind_energy);
                     daily_cost = f[i].energy_cost(sun_main_cost, wind_main_cost);
                  }
               else
                  {
                     cout << "+++ Solar collector system +++\n";
                     cout << "Give the operating hours of the oil generator of the solar collector system: ";
                     cin >> sun_oil_hours;
                     cout << "+++ Wind turbine system +++\n";
                     cout << "Give the operating hours of the wind turbine: ";
                     cin >> wind_hours;
                     cout << "Give the wind speed: ";
                     cin >> wind_speed;

                     f[i] = Factory(sun_oil_hours, wind_hours, wind_speed);
                     sun_energy = f[i].Sun::energy_cost(2);
                     sun_main_cost = f[i].Sun::energy_cost(3);
                     wind_energy = f[i].Wind::energy_cost(0);
                     wind_main_cost = f[i].Wind::energy_cost(1);
                     daily_energy = f[i].energy_cost(sun_energy, wind_energy);
                     daily_cost = f[i].energy_cost(sun_main_cost, wind_main_cost);
                  }
            }
         total_energy += daily_energy;
         total_cost += daily_cost;
   }

   // Print results, free memory and return
   cout << "The total energy consumption for a day is: ";
   cout << total_energy;
   cout << "\n";
   cout << "The total cost for a day is: ";
   cout << total_cost;
   cout << "\n";
   delete [] f;
   return 0;
}
