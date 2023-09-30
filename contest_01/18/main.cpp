#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    string result = "";
    while (n > 0) {
        //Остаток от деления определяет букву столбца
        int remainder = (n - 1) % 26;
        //Преобразование остатка в символ, представляющий букву столбца Excel. 
        char column_char = 'A' + remainder;
        result = column_char + result;
        n = (n - 1) / 26;
    }
    cout<<result;
}
