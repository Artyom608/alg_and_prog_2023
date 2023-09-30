#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() 
{
    long long int num1, num2;
    cin >> num1 >> num2;
    // Превращаем числа в строчки
    string num1_string = to_string(num1);
    string num2_string = to_string(num2);
    //Сортируем цифры в числах
    sort(num1_string.begin(), num1_string.end());
    sort(num2_string.begin(), num2_string.end());
    if (num1_string.length() != num2_string.length())
    {
        cout << "NO" << endl;
    }
    else if (num1_string == num2_string) 
    {
        cout << "YES" << endl;
    } 
    else
    {
        cout << "NO" << endl;    
    }
    return 0;
}
