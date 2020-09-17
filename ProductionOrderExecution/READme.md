# ProductionOrderExecution

## Problem statement
A factory can produce a number of different types of products. For each type of product, there are different categories which depend on the quality of materials, processing time, etc. An order that will come to the factory determines the categories of products that will be produced and the number of pieces for each category. According to this information, the factory needs to calculate the total cost and the total profit from the execution of an order that arrives at the factory.

## Code description
This C++ program calculates the total cost and the total profit from the execution of an order that arrived at the factory. The program defines the calculate_cost_and_profit function which reads the number of pieces for each product category and calculates the total cost of the order and the total amount of money that the factory will receive from its execution. The calculate_cost_and_profit function should be independent of the type and category of products requested to be manufactured.

The factory can manufacture products of the following types:
 - Type A: for which the program reads the cost of materials and the cost of processing per piece as well as the percentage of profit left by the construction of such a piece
 - Type B: for which the program reads the cost of materials, the cost of processing and the percentage of profit per piece, and additionally the minimum required time for its construction, the time required for its construction by a worker and the wage of each worker per piece. Specifically, regarding the employment of workers for the construction of a product of type B, a worker has to work a certain number of hours to make a piece of the product. If the factory wishes to expedite the order, it can employ other workers for the construction of the same piece. In this case, the time it takes to build a piece is equal to the number of hours required for its construction by a worker divided by the number of workers that will be used to build it if the order is expedited. The wage of a worker is determined per piece that he/she builds either alone or with other workers

The main function of the program reads the number of products of type A and B and allocates dynamic memory to register the corresponding objects, calls the calculate_cost_and_profit function to calculate the total cost and value of the order and prints the total profit from its execution.
