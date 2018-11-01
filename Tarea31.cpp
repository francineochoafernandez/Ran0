# Ran0
//Generador Minimo de numeros random de Park and Miller
/*Regresa una desviacion de numeros random entre 0 y 1
Periodo para ran0 es  2^31 − 2 ≈ 2.1 × 10^9.
El valor 0 nunca se usa para el seeding inicia, se va perpetuando
Es comun usar idum=0, En ran0 se usa una constante arbitrari de entrada y de salida.*/

#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define MASK 123459876

typedef struct Ran0
{
  float ran0(long *idum)
  {
    long k;
    float ans;

    *idum ^= MASK;
    k=(*idum)/IQ;
    *idum=IA*(*idum-k*IQ)-IR*k;

    if (*idum < 0) *idum += IM;
    ans=AM*(*idum);
    *idum ^= MASK;

    return ans;
  }

  void line()
  {
    for(int i=1;i<30;i++)
    cout<<"--";
    cout<<"\n";
  }
}R0;


int main ()
{
  R0 n;
  long seed= 123456789;
  long *idum=&seed;

  n.line();
  cout<< setw(35) << "100 numeros usando ran0" << endl;
  n.line();

  for (int i=0; i<100; i++)
  {
    //cout << ran0(idum) << endl;
    cout<< setw(15) << i+1 << setw(15) << n.ran0(idum) << endl;
  }

 return 0;
}
