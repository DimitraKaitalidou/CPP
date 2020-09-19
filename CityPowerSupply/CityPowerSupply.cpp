// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

#include <iostream>

using namespace std;

class station{

   // Access specifier
   public:
   int mode;
   char station_name[30];
   double efficiency_factor;
   double station_power;
};

class oilstation : public station{

   double consumption_per_h;

   // Access specifier
   public:
   oilstation();
   double oil_power();
};

oilstation::oilstation(){

   cout << "Give the name of the oil station: ";
   cin >> station_name;
   cout << "Give the consumption per hour: ";
   cin >> consumption_per_h;
   cout << "Give the efficiency factor for the oil station: ";
   cin >> efficiency_factor;
   station_power = 0;
   cout << "Type 1 if the oil station works properly and 0 if not: ";
   cin >> mode;
}

double oilstation::oil_power(){

   if(mode)
      {
         station_power = consumption_per_h * efficiency_factor;
         cout << "The oil power is: " << station_power << "\n";
      }
   else 
      {
         cout << "Give the minimum power to keep the station in standby mode: ";
         cin >> station_power;
      }

   return station_power;
}

class solarstation : public station{

   double collector_surface;
   double luminous_flux;

   // Access specifier
   public:
   solarstation();
   double solar_power();
};

solarstation::solarstation(){

   cout << "Give the name of the solar station: ";
   cin >> station_name;
   cout << "Give the collector area: ";
   cin >> collector_surface;
   cout << "Give the efficiency factor for the solar station: ";
   cin >> efficiency_factor;
   cout << "Give the luminous flux: ";
   cin >> luminous_flux;
   station_power = 0;
   cout << "Type 1 if the solar station works properly and 0 if not: ";
   cin >> mode;
}

double solarstation::solar_power(){

   if(mode) 
      {
         station_power = collector_surface * efficiency_factor * luminous_flux;
         cout << "The solar power is: " << station_power << "\n";
      }
   else 
      {
         cout << "Give the minimum power to keep the station in standby mode: ";
         cin >> station_power;
      }

   return station_power;
}

void alert(double power, double power_sum) {

   if(power <= 0.8 * power_sum) cout << "Green alarm!\n";
   else if(power <= 0.9 * power_sum && power > 0.8 * power_sum) cout << "Yellow alarm!\n"; 
   else if(power <= power_sum && power > 0.9 * power_sum) cout << "Orange alarm!\n"; 
   else if(power > power_sum) cout << "Red alarm!\n"; 

   return;
}

int main(){

   // Initialize variables
   double power;

   while(1)
      {
         cout << "Give the power that the city needs: ";
         cin >> power;

         if(power)
            {
               int oil_num, solar_num;
               double power_sum = 0;

               cout << "Give the number of the oil stations: ";
               cin >> oil_num;
               oilstation *oil = new oilstation[oil_num];

               for(int i = 0; i < oil_num; i++) 
                  {
                     if(oil[i].mode == 0) power_sum -= oil[i].oil_power();
                     else power_sum += oil[i].oil_power();
                  }

               cout << "Give the number of the solar stations: ";
               cin >> solar_num;
               solarstation *solar = new solarstation[solar_num];

               for(int i = 0; i < solar_num; i++)
                  {
                     if (solar[i].mode == 0) power_sum -= solar[i].solar_power();
                     else power_sum += solar[i].solar_power();
                  }

               // Create alert and print the excess or extra power
               alert(power, power_sum);

               if(power < power_sum * 0.8) cout << "The power produced by the stations must be " << (power_sum * 0.8 - power) << " Watt less.\n";
               else if(power == power_sum * 0.8) cout << "The power is in normal levels.\n";
               else if (power_sum < 0) cout << "The power produced by the stations must be " << (-1) * power_sum + power / 0.8 << " Watt more.\n";
               else cout << "The power produced by the stations must be " << (power - 0.8 * power_sum) << " Watt more.\n";

               // Free memory
               delete [] oil;
               delete [] solar;
            }
         else return 0;
      }
}
