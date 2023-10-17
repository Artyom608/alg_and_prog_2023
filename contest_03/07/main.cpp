#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "fstream"

int main() {
    //Считываем слово target
    std::string target;
    std::cin >> target;

    std::map<std::string, int> maps;
    std::vector < std::string> arr;
    //Считываем файл
    std::ifstream file("data.txt");
    for (int i = 0;true;i++) {
        std::string str;
        file >> str;
        if (str == "stopword") break;
        arr.push_back(str);
    }
    for (int i = 0;i < arr.size()-1;i++) {
        if (arr[i] == target) maps[arr[i + 1]] += 1;
    }

    //Считаем количество повторений слов
    int maxs1 = -1;
    int maxs2 = -1;
    int maxs3 = -1;
    for (auto i : maps) {
        if (i.second > maxs1) {
            maxs3 = maxs2;
            maxs2 = maxs1;
            maxs1 = i.second;
        }
        else if (i.second > maxs2) {
            maxs3 = maxs2;
            maxs2 = i.second;
        }
        else if (i.second > maxs3) maxs3 = i.second;
    }

    if (maps.empty()) std::cout << '-';
    for (auto i : maps) {
        if (i.second == maxs1) {
            std::cout << i.first << ' ';
            maps.erase(i.first);
            break;
        }
    }
    for (auto i : maps) {
        if (i.second == maxs2) {
            std::cout << i.first << ' ';
            maps.erase(i.first);
            break;
        }
    }
    for (auto i : maps) {
        if (i.second == maxs3) {
            std::cout << i.first << ' ';
            maps.erase(i.first);
            break;
        }
    }
}
