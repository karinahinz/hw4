#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

void read (double*const f, const int N, const string fname)
  {
  ifstream in (fname.c_str());
    for(int i =0; i<N; i++)
    {
    in>>f[i];
    }
  in.close();
  }



void filter(double* const f, const int N)
  {
    double x = f[0];
    double y = f[1];
    double g = (f[N-2]+f[N-1]+x)/3; // da f[N]=f[0]
    f[0]=(f[N-1]+x+y)/3;
    for(int i =1;i<N;i++) 
    { y=f[i];
      f[i]= (x+f[i]+f[i+1])/3;
      x=y;      
    }
    f[N-1]=g;
  }
  
void print_f(double* f, const int N)
   {
     ofstream out("ahoi.txt");
    for(int i=0;i<N;i++)
    { out<<f[i]<<endl;}
     out.close();
   }
     
  

int main () 
{
  const int N= 237;
  const string fname="noisy.txt";
  double*f= new double[N];
  const int n =15;//no magic numbers, Filteriterationen
  read(f,N,fname);
  for(int i=1;i<n;i++)
  filter(f,N);
  
  print_f(f,N);
  
    
    
    delete [] f;
    return 0;
}
