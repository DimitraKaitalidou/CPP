# Factory Order

## Problem statement
Executing an order that arrives at a factory requires cost and time to execute. The cost is defined by the cost required for the manufacturing of the specific product (cost of raw materials, etc.) to which the operating cost of the machine that will manufacture it is added. For each product the cost and time required for the construction of an item are known while for each machine the operating cost per second is known.

The factory has a number of machines each of which can make a complete item. The production of the items is divided among the machines so that it is finished as soon as possible.

## Code description
This C++ program defines the parameterized Order class which implements an order and has the appropriate functions to calculate the cost and time required for its execution. The class accepts as parameters the type of products of the order and the type of machines available in the factory and as constants the number of items and the number of machines.

The program also has the template comp() function which accepts as parameters the types of classes that define two different orders and which returns the value 1 if the product of the total cost of the first order times the respective delivery time is less than the corresponding product of the second order, otherwise it returns the value 2.

The main function defines two objects for two different implementations of the parameterized Order class and prints for each of them the cost and the delivery time of the respective order. Finally, the main function calls the comp() function and prints the value it returns when the objects defined above are given to the function as input.

As an application, consider that the first order consists of products of type ProductA for the type of which the cost and the time of manufacturing of an item are known. The order is considered to be executed by machines of type MachineA for the type of which the operating cost of one machine per second is known. The second order is considered to also consist of products of type ProductA, which are executed by machines of type MachineB for which the operation cost and maintenance cost of a machine per second are known.
