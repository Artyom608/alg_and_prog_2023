#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;


int main() 
{
    int a, b, c;
    scanf("%i%i%i",&a,&b,&c);
    if (abs(a-b) < abs(a-c))
    {
        cout<<"B "<<abs(a-b);
    }
    else if (abs(a-b) > abs(a-c))
    {
        cout<<"C "<<abs(a-c);
    }

}
