#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

double euclidean(double *vec1, double *vec2, int n)
{
  double dist=0.0;
  for (int i=0; i<n; i++)
    dist += (vec1[i]-vec2[i]) * (vec1[i]-vec2[i]);
  return dist;
  
}

double distance(int i, int jstar)
{
  return double(i!=jstar);
}

double h(double d)
{
  return 1.0 - d;
}

void train(double **W, int n, int cols, double *vec, double rate)
{
  int i,j;
  int win=0;
  double windist = euclidean(W[0], vec, n), edist;
  for (i=0; i<cols; i++)
    if ((edist=euclidean(W[i],vec,n)) < windist)
    { 
      win = i;
      windist = edist;
    }
  for (i=0; i<cols; i++)
    for (j=0; j<n; j++)
      W[i][j] += rate * h(distance(i, win)) * (vec[j]-W[i][j]);

}

int main(void)
{
 int i,j;
 int T=10000; // number of iterations
 const int m=4;
 int cols;
 double eta = 0.6; // learning rate
 
 // trainning vectors
 double x0[m] = { 1.0, 1.0, 0.0, 0.0 };
 double x1[m] = { 0.0, 0.0, 0.0, 1.0 };
 double x2[m] = { 1.0, 0.0, 0.0, 0.0 };
 double x3[m] = { 0.0, 0.0, 1.0, 1.0 };
 
 cout << "Enter number of columns for weigth matrix : ";
 cin >> cols;

 double **W = NULL;
 W = new double *[cols];
 for (i=0; i<cols; i++)
   W[i] = new double[m];

 srand(time(NULL));
 for (i=0; i<cols; i++)
 {
   for (j=0; j<m;j++)
   {
     W[i][j] = rand()/double(RAND_MAX);
     cout << W[i][j] << " ";
   }
   cout << endl;
 }

 for (i=0; i<T; i++)
 {
   train(W, m, cols, x0,eta);
   train(W, m, cols, x1,eta);
   train(W, m, cols, x2,eta);
   train(W, m, cols, x3,eta);
   eta /= 1.05;
   cout << i << " " << eta << endl;
 }

 for (i=0; i<cols; i++)
 {
   for (j=0; j<m;j++)
   {
     cout << W[i][j] << " ";
   }
   cout << endl;
 }
 for (i=0; i<cols; i++)
   delete[] W[i];

 delete[] W;

 return 0;
}
