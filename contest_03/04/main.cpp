#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
    long int n, m;
    cin >> n;
    unordered_set<string> commonWords;

    // Чтение и добавление слов из первой последовательности в множество
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        commonWords.insert(word);
    }

    cin >> m;

    unordered_set<string> wordsSet;

    // Проверка и добавление общих слов из второй последовательности
    for (int i = 0; i < m; i++) {
        string word;
        cin >> word;
        if (commonWords.count(word) > 0 && wordsSet.count(word) == 0) {
            wordsSet.insert(word);
        }
    }

    // Сортировка и вывод общих слов
    if (!wordsSet.empty()) {
        vector<string> wordsVector(wordsSet.begin(), wordsSet.end());
        sort(wordsVector.begin(), wordsVector.end());
        for (const string& element : wordsVector) {
            cout << element << " ";
        }
    } else {
        cout << -1;
    }
    return 0;
}
