
#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */
#include <set>
using namespace std;
#include <iostream>
#include <fstream>
#include<omp.h>

int main(int argc, char ** argv)
{
 #pragma omp parallel
	{
  int thread_id = omp_get_thread_num();   
  int thread_count = omp_get_num_threads(); 
  char idd[3];
  double delta;
  double L;
  int N;
 ofstream myfile;
  String mensaje = "sample";
  mensaje += idd;
  mesnaje += ".dat";
 myfile.open (mensaje);
cout << "Please enter MIU: ";
  delta = 0.05;
  L = 4.0;
  N = L/delta + 1;
  double x[N];
  double u[N];
  myfile << N;
  int i ;
  double c = 0;
  cout << N;
  for(i = 0; i<N; i ++)
    {
      x[i] = c;
      c = c + delta;
      if(x[i]<2.0)
	{
	  u[i]= 1.0;
	}
      else
	{
	  u[i] = 0;
	}
    }
  
  int tmax[4];
  tmax[0] = 0.0;
  tmax[1] = 0.5;
  tmax[2] = 1.0;
  tmax[3] = 2.0;

  int j;
  double Nt;
  double ufinal[N];
  double f[N];
  int s;
  int m;
  for(j = 0; j<4; j++)
    {
	Nt = 0.45/0.015;
	ufinal[0]=u[0];
	ufinal[N-1]= u[0];

	for (m= 1; m<N-1; m++)
	{  	
	for(i = 0; i<N;i++)
	{
		f[m]= u[m]*u[m]*0.5;
	}
		ufinal[i] = 0.5*(u[i-1]+u[i+1]);
		ufinal[i] = ufinal[i]-(0.5*0.015/5.0)*(f[i-1]-f[i+1]);
		for(s = 0; s<N; s++)
		{
			u[i] = ufinal[i];
		}
	}

  for(i=0;i<N; i++)
    {
      myfile << ufinal[i];
    }


    }
   myfile.close();
 }
}


