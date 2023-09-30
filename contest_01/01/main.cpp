#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   double a = sqrt(12);
   double b = (1-1/9.0)+(1/45.0-1/189.0)+(1/729.0-1/2673.0);
   double c = a*b;
   cout<<c;
}
