# Shipping Cost

## Problem statement
A shipping company must carry a number of containers. Shipping can be done by train or by truck:
-	If the train is used, a shipping cost per kilometer and an insurance premium are charged for each container. The premium is calculated as the product of the value of the commodity that the container carries times the distance times an ins_coef factor
-	If a truck is used, a shipping cost per kilometer is charged for each container, to which the corresponding tax is added. The tax is calculated as a percentage of the shipping cost 

## Code description
This C++ program defines, depending on the shipping mode of each container, an object which reads the necessary data concerning the container. The object has the appropriate functions for calculating the shipping cost and printing a form with the start, the destination and the shipping cost of the corresponding container.

The program also specifies the total_shipping_cost function which processes all the items of the containers and returns the total cost for their shipping.

The main function reads the number of containers to be shipped by train, the number of containers to be shipped by trucks and allocates dynamic memory (new operator) to register the corresponding items. Then, the program prints the form with the start, the destination and the shipping cost for each container and calls the total_shipping_cost function to calculate and print the total shipping cost for all the containers.

