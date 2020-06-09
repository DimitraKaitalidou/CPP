# Electric Power Factory

## Problem statement
An electricity company has a number of stations, each of which has a solar collector system and a wind turbine system.

The solar collector system also has an oil generator that goes into operation when there is no sunshine. For a given day the system works either only with the solar collector or only with the oil generator:
- If the system uses the solar collector, the energy produced is calculated as the product of the collector surface times the hours of sunshine times the intensity of the luminous flux times a performance factor
- If the system uses the oil generator, the energy produced is calculated as the product of the oil consumed in one hour times the operating hours of the generator times a performance factor. The daily operating cost of the generator is equal to the cost of the oil it consumes, while in any case there is a daily maintenance cost of the system

The wind turbine system also has an oil generator that goes into operation when there is no wind. For a given day the system works either only with the wind turbine or only with the oil generator:
- If the system uses the wind turbine, the energy produced is calculated as the product of the wind speed times the operating hours of the wind turbine times a performance factor 
- If the system uses the oil generator, the energy produced is calculated as the product of the oil consumed in one hour times the operating hours of the generator times a performance factor. The daily operating cost of the generator is equal to the cost of the oil it consumes, while in each case there is also a daily maintenance cost of the system

## Code description
This C++ program consists of the following:
- The Sun class which simulates the operation of the system that includes the solar collector. The class has two functions of initial conditions, the first of which accepts as arguments the current hours of sunshine and the intensity of the luminous flux and reads the necessary data for the calculation of the energy produced in case the system works with the solar collector. The same function reads the maintenance costs of the system. The second function of initial conditions accepts as an argument the operating hours of the oil generator and reads the necessary data for the calculation of the generated energy and the total cost in case the system uses the oil generator. The class also has the function energy_cost which in each case calculates the daily energy produced and the corresponding cost
- The Wind class which simulates the operation of the system that includes the wind turbine. The class has two functions of initial conditions, the first of which defines the operating hours of the wind turbine and the wind speed and reads the necessary data for the calculation of the energy produced in case the system operates the wind turbine. The same function reads the maintenance costs of the system. The second function of initial conditions accepts as an argument the operating hours of the oil generator and reads the necessary data to calculate the energy produced and the total cost in case the system uses the oil generator. The class also has the function energy_cost which in each case calculates the daily energy produced and the corresponding cost
- The Factory class produced by the Sun and Wind classes as public which simulates the operation of a station. The class has the function energy_cost which calculates in each case the total energy produced by the station as well as the daily total cost

The program reads the number N of the stations that the company has, allocates dynamic memory for N objects of factory class and calculates the total daily energy that has been produced as well as the corresponding cost.

