# City Power Supply

## Problem statement
The power supply of a city depends on a number of different types of power stations. Each station, when operating, provides a certain amount of power while, when it is idle, it consumes a minimum amount of power to keep it in standby mode.

## Code description
This C++ program defines the alert function that receives the power consumed by the city at a given time and if it is below 80% of the power currently produced by the stations, it returns a signal with the "green alarm" indication. If the power required by the city is between 80% and 90% the indication is "yellow alarm". In case the required power is between 90% and 100% the indication is "orange alarm" while if it exceeds 100% the indication is "red alarm".

The main function of the program defines an endless process, where in each iteration it reads the power required by the city and prints the type of corresponding alarm as well as the excess or extra power required for its smooth operation. The process should be terminated if zero is read as the power required by the city. The program is independent of the type and number of stations that supply the city.

Regarding the types of stations, there are stations that run on oil and stations that have solar panels. For each station, the program reads a string of characters that is its identity, the status of the station (1 if the station operates and 0 if it is in standby mode) and the power it consumes when it is in standby mode:
- For oil stations, the program reads the hourly oil consumption and an efficiency coefficient. The power of the oil station is calculated as the product of the hourly oil consumption times the efficiency factor
- For stations that use solar panels, the program reads the surface of the collector, and an efficiency coefficient. To calculate the power produced by the solar station, the program reads the luminous flux at the specific moment and calculates the product of the collector surface times the efficiency coefficient times the luminous flux
