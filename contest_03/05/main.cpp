#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Игнорируем символ новой строки

    unordered_map<string, int> wordCount; // Хранение количества слов
    int maxCount = 0;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        // Увеличиваем счетчик для данного слова
        wordCount[word]++;

        // Обновляем максимальное количество встречаемых слов
        maxCount = max(maxCount, wordCount[word]);
    }

    // Создаем список слов, которые встречаются максимальное количество раз
    vector<string> mostFrequentWords;

    for (const auto& pair : wordCount) {
        if (pair.second == maxCount) {
            mostFrequentWords.push_back(pair.first);
        }
    }

    // Сортируем список в лексикографическом порядке
    sort(mostFrequentWords.begin(), mostFrequentWords.end());

    // Выводим результат
    for (const string& word : mostFrequentWords) {
        cout << word << " ";
    }

    return 0;
}
