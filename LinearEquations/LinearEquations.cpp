// Copyright 2020, Dimitra S. Kaitalidou, All rights reserved

#include <iostream>
#include <cstdlib>

using namespace std;

class Matrix{

   // Access specifier
   public:
   int size;
   float **M;
   Matrix(int x);
   Matrix(){};
   float *operator[](int x){return M[x];};
};

Matrix::Matrix(int x){

   size = x;
   M = new float*[size];

   for(int i = 0; i < size; i++)
      {
         M[i] = new float[size];
         for(int j = 0; j < size; j++)
            {
               cout << "Give M" << i << j << ": ";
               cin >> M[i][j];
            }
      } 
}

class Vector{

   // Access specifier
   public:
   int size;
   float *V;
   Vector(int x);
   Vector(int x, float y);
   Vector(){};
   Vector operator=(Matrix A);
   Vector operator*(Vector C);
   Vector operator-(Vector C);
   Vector operator+(Vector C);
   Vector operator/(Vector C);
   Vector operator=(Vector C);
   float operator[](int x){return V[x];}
   float operator++();
};

Vector::Vector(int x){

   size = x;
   V = new float[size];

   for(int i = 0; i < size; i++)
      {
         cout << "Give V" << i << ": ";
         cin >> V[i];
      }
}

Vector::Vector(int x, float y){

   size = x;
   V = new float[size];

   for(int i = 0; i < size; i++) V[i] = y;
}

Vector Vector::operator=(Matrix m){

   Vector Vec(size, 1);
   for(int i = 0; i < size; i++) Vec.V[i] = m[i][i];
   return Vec;
} 

Vector Vector::operator*(Vector v){

   Vector Vec(size, 1);
   for(int i = 0; i < size; i++) Vec.V[i] = V[i] * v[i];
   return Vec;
}

Vector Vector::operator-(Vector v){

   Vector Vec(size, 1);
   for(int i = 0; i < size; i++) Vec.V[i] = V[i] - v[i];
   return Vec;
}

Vector Vector::operator+(Vector v){

   Vector Vec(size, 1);
   for(int i = 0; i < size; i++) Vec.V[i] = V[i] + v[i];
   return Vec;
}

Vector Vector::operator/(Vector v){

   Vector  Vec(size, 1);
   for(int i = 0; i < size; i++) Vec.V[i] = V[i] / v[i];
   return Vec;
}

Vector Vector::operator=(Vector v){

   for(int i = 0; i < size; i++) V[i] = v[i];
   return *this;
}

float Vector::operator++(){

   float sum = 0;
   for(int i = 0; i < size; i++) sum += abs(V[i]);
   return sum;
}

Vector operator*(Matrix m, Vector v){

   Vector Vec(m.size, 0);
   float prod;

   for(int i = 0; i < m.size; i++)
      {
         for(int j = 0; j < m.size; j++)
            {
               prod = m[i][j] * v[j];
               Vec.V[i] += prod;
            }
      }

   return Vec;
}

int main(){

   // Initialize variables
   int size;
   cout << "Give the size of the matrix: ";
   cin >> size;
   cout << "Create the " << size << "x" << size << " matrix.\n";
   Matrix M(size);
   cout << "Create the vector of constant terms.\n";
   Vector C(size);

   Vector D(size, 1);
   Vector R(size, 1);
   Vector Diff(size, 1);
   Vector X(size, 1);
   float sum;
   int run = 1;
   int e = 1;
   
   // Perform the iterative algorithm
   D = M;
   cout << "The iterations will stop when convergence is achieved or the user presses 0.\n";
   while(run)
      {
         R = (C - (M * X) + (D * X)) / D;
         Diff = R - X;
         sum = ++Diff;
         if(sum <= e) break;
         else X = R;
         cin >> run;
      }

   // Print the solution, free memory and return
   cout << "The solution vector is: (";
   for(int i = 0; i < size - 1; i++) cout << X[i] << ", ";
   cout << X[size - 1] << ")\n";

   delete [] C.V;
   delete [] D.V;
   delete [] R.V;
   delete [] Diff.V;
   delete [] X.V;
   for(int i = 0; i < size; i++) delete [] M.M[i];
   delete [] M.M;

   return 0;
}  
