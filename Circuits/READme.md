# Circuits

## Problem statement
An electrical circuit is a closed path that can conduct electric current. The elements involved in the circuit are called electrical components, e.g., sources, resistances, inductances, capacities, etc. According to Ohm’s law:

> ***I*** = ***V***/***R***

where ***I*** is the current (amperes), ***V*** is the voltage (volts) and ***R*** is the resistance (ohms) and also:

> ***P*** = ***V***<sup>2</sup>/***R***

where ***P*** is the power (watts).

Most frequently, the components of the electric circuits are connected in series or parallel:
1. Serial circuits: the total resistance is equal to the sum of resistances
2. Parallel circuits: the total resistance is equal to the reciprocal of the sum of the reciprocals of the resistances

## Code description
This C++ program defines the Circuit class, which implements the functions of a circuit consisting of an ohmic resistance to which a voltage is applied. The class defines a constructor which takes as input the value of the voltage and informs the corresponding variable of the class. The class also specifies the appropriate functions for calculating the current flowing through the resistance and the power consumed by the circuit.

The program also defines:
1. The Serial class as public, produced by the Circuit class. The class defines a table of resistances connected in series and has a constructor that allocates dynamic memory (new operator) for that table and reads the values of its elements. The class also has the appropriate functions for calculating the total resistance presented by the circuit, which should be set as the value of the resistance defined by its basic class
2. The Parallel class as public, produced by the Circuit class. The class defines a table of resistances connected in parallel and has a constructor which allocates dynamic memory (new operator) for that table and reads the values of its elements. The class also has the appropriate functions for calculating the total resistance presented by the circuit, which should be set as the value of the resistance defined by its basic class

The minimum_power function is also defined, which receives a table of Serial class objects and a table of Parallel class objects and finds which of the Serial class objects and which of the Parallel class objects consumes the least power.

The main function of the script defines dynamically a table of Serial type objects and a able of Parallel type objects (new operator), reads a value for the voltage and calls the minimum_power function. For these two objects, the current flowing through them is printed.

## References
1. https://en.wikipedia.org/wiki/Ohm%27s_law
2. https://en.wikipedia.org/wiki/Series_and_parallel_circuits
3. http://www.sciweavers.org/free-online-latex-equation-editor
