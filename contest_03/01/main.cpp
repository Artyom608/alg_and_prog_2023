#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    std::string inputString_1;
    std::string inputString_2;
    int a;
    cin>>a;
    cin.ignore();
    std::getline(std::cin, inputString_1);
    int b;
    cin>>b;
    cin.ignore();
    std::getline(std::cin, inputString_2);
    
    //1 строка
    std::vector<int> numbers_1;
    std::istringstream iss1(inputString_1);
    int number_1;

    while (iss1 >> number_1) {
        numbers_1.push_back(number_1);
    }
    
    //2 строка
    std::vector<int> numbers_2;
    std::istringstream iss2(inputString_2);
    int number_2;

    while (iss2 >> number_2) {
        numbers_2.push_back(number_2);
    }
    std::vector<int> concatenatedVector = numbers_1;
    concatenatedVector.insert(concatenatedVector.end(), numbers_2.begin(), numbers_2.end());
    std::sort(concatenatedVector.begin(),concatenatedVector.end());
    for (int i = 0; i < concatenatedVector.size(); ++i) {
        std::cout << concatenatedVector[i] << " ";
    }
}
    
