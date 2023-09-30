#include <iostream>
#include <cmath>
using namespace std;

int is_prime(int number)
{
    for(int i = 2; i <= sqrt(number);i++){
        if(number%i==0)
        {
            return false;
        }
    }   
    return true;
} 

int main(){
    int number;
    std::cin >> number;
    std::cout << (is_prime(number) ? "YES" : "NO") << std::endl;
}
