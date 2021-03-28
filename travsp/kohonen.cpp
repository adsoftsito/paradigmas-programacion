#include <iostream>
#include <cmath>    // for fabs, exp
#include <cstdlib>
#include <ctime>
#include <iomanip>  // for setprecision
using namespace std;

// find the position in the array d
// which possess the smallest number
int minimun(double *d, int M)
{
  int m=0;
  double r = d[0];
  
  for (int j=1; j<M; j++)
  {
    if ( d[j] < r)
    {
      r = d[j];
      m = j;
    }
  }
  return m;
}

// lateral interaction of neurons
double map(double a, double b, double c, double d, double s)
{
  double result;
  result = exp(-(fabs(a-c) + fabs(b-d)) / (2*s*s));
  return result;
}
int main(void)
{
  int N = 8; // number of cities
  double *x = new double[N];
  double *y = new double[N];

  // coordinates of cities
  x[0] = 10.1; x[1] = 4.0; x[2] = 0.1; x[3] = 0.5;
  x[4] = 10.5; x[5] = 8.0; x[6] = 12.0; x[7] = 18.0;

  y[0] = 20.2; y[1] = 7.0;  y[2] = 2.0; y[3] = 10.7;
  y[4] = 0.6;  y[5] = 10.0; y[6] = 16.0; y[7] = 8.0;

  int M = 3*N; // M number of neurons
  double *u = new double[M];
  double *v = new double[M];

  const double PI = 3.14159;

  // neuron pattern at t=0
  
  for (int j=0; j<M; j++)
  {
    double k=j;
    double K=M;
    u[j] = 10.0 + 10.0*sin(2.0*PI*k/K);
    v[j] = 10.0 + 10.0*cos(2.0*PI*k/K);
  }
  
  double *dist = new double[M];
  double *delW1 = new double[M];
  double *delW2 = new double[M];

  double eta0 = 0.8;  // learning rate at t=0
  long T = 15000;        // number of iterations
  
  srand((unsigned long) time(NULL)); // seed for random numbers
  
  // iterations starts here

  for (long cnt=0; cnt<T; cnt++)
  {
    cout << cnt << endl;
    int nrand = rand()%N;
    for(int j=0; j<M; j++)
    {
      dist[j] = fabs(u[j] - x[nrand]) + fabs(v[j] - y[nrand]);
      //cout << dist[j] << " ";
    }
    cout << endl;

    int imin = minimun(dist, M);
    double c = cnt;
    double it = T;
    double s;
    s = eta0 * (1.0 - c/(it + 10000.0));

    for(int j=0; j<M; j++)
    {
      delW1[j] = 1.0 * map(u[j], v[j], u[imin], v[imin], s) * (x[nrand] - u[j]);
      delW2[j] = 1.0 * map(u[j], v[j], u[imin], v[imin], s) * (y[nrand] - v[j]);

      // cout << delW1[j] << " ";
    }
 
    for(int j=0; j<M; j++)
    {
      u[j] += delW1[j];
      v[j] += delW2[j];
    } 
 } // end iteration

 // display of output
  cout << endl << endl;

  for(int j=0; j<M; j++)
  {
    cout << "u[" << j << "] = " << setprecision(3) << u[j] << " ";
    cout << "v[" << j << "] = " << setprecision(3) << v[j] << endl;

  }

 delete[] x;
 delete[] y;
 delete[] delW1;
 delete[] delW2;
 delete[] dist;
 return 0;

}
