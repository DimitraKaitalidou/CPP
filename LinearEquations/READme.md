# Linear Equations

## Problem statement
To solve a system of linear equations M * X = C, where M is the square matrix, X is the vector of unknowns and C is the vector of constant terms, an iterative algorithm can be applied which is implemented by the relation R = (C - M * X + D * X) / D (Jacobi method), where M is the matrix of coefficients of the unknowns of the system, C is the vector of constant terms and D is the vector whose components are the diagonal elements of the matrix M. Applying the above expression gives a better approach R for the solution vector than that of an initial approach of the solution with the X vector. The process is repeated by setting X = R until the sum Σ|R<sub>i</sub> - X<sub>i</sub>|, where R<sub>i</sub>, X<sub>i</sub> are the corresponding components of the vectors R and X, becomes less than a small number e denoting the desired accuracy of the result.

## Code description
This C++ program defines the Matrix class, which implements a square matrix. The class has a constructor which accepts as arguments the dimensions of the matrix, allocates dynamic memory for its data and reads values for these data. In the class, the following is defined:
1. An overload of the operator [] so that the expression M [i] [j], where M is an object of Matrix class, returns the value of the element of the matrix in line i and column j of the matrix

The program also defines the Vector class, which implements a vector. In the class the following are defined:
1. An overload of the operator = so that the expression d = m, where d is an object of Vector class and m is an object of Matrix class, allocates the necessary memory and inserts in d the diagonal elements of matrix m
2. An overload of the operator * so that the expression v * d, where v and d are objects of Vector class, returns an object of the same class in which the vector it implements has as elements the product of the corresponding elements of vectors v and d
3. An overload of the operator - so that the expression v – d, where v and d are objects of Vector class, returns an object of the same class in which the vector it implements has as elements the difference of the corresponding elements of vectors v and d
4. An overload of the operator + so that the expression v + d, where v and d are objects of Vector class, returns an object of the same class in which the vector it implements has as elements the sum of the corresponding elements of vectors v and d
5. An overload of the operator / so that the expression v / d, where v and d objects of Vector class, returns an object of the same class in which the vector it implements has as elements the quotient of the corresponding elements of vectors v and d
6. An overload of the operator [] so that the expression v [i], where v is an object of Vector class, returns the value of the element i of vector v
7. An overload of the ++ operator so that the expression ++ v, where v is an object of Vector class, returns the sum of the absolute values of the elements of vector v

In the program, another overload of the operator * is defined so that the expression m * x, where m is an object of Matrix class and x is an object of Vector class, returns an object of Vector class which is the product of matrix m times vector x.

The main function defines and creates the necessary objects to solve a system of linear equations. It reads the size of the square matrix and applies the iterative solution method described above. The values of the matrix and the vectors, where necessary, are called using the operator [].

Because the convergence of the algorithm is not always guaranteed the user can interrupt the loop by pressing 0. The small number e is chosen to be equal to 1.

Finally, the following can be used for testing purposes:

4x<sub>1</sub> + 2x<sub>2</sub> + 3x<sub>3</sub> = 8

3x<sub>1</sub> + 2x<sub>2</sub> + 5x<sub>3</sub> = 10

3x<sub>1</sub> + 2x<sub>2</sub> + 8x<sub>3</sub> = 13

which is solved by the vector (1,1,1).

## References
1.	https://en.wikipedia.org/wiki/Jacobi_method
