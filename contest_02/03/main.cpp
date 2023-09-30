#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int numOfOnes(string a){
    int summa = 0;
    for(auto i:a){
        if(i=='1'){
            summa +=1;
        }
    }
    return summa;
}
bool compare(std::string a, std::string b){
    int a_int = numOfOnes(a);
    int b_int = numOfOnes(b);
    
    if(a==b){
        return false;
    }
    
    if(a_int == b_int){
        return stoi(a) < stoi(b);
    }
    return a_int > b_int;
}

int main(){
    int count;
    std::cin >> count;
    
    std::vector<std::string> nums(count);
    for(auto& line : nums) std::cin >> line;
    
    std::sort(nums.begin(), nums.end(), compare);
    
    for(auto& line : nums) std::cout << line << ' ';
}
