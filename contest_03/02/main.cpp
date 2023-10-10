#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string input) {
    stack<char> brackets;

    for (char ch : input) {
        if (ch == '(' || ch == '{' || ch == '[') {
            brackets.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (brackets.empty()) {
                return false; // Нет соответствующей открывающей скобки
            }
            char openBracket = brackets.top();
            brackets.pop();
            if ((ch == ')' && openBracket != '(') ||
                (ch == '}' && openBracket != '{') ||
                (ch == ']' && openBracket != '[')) {
                return false; // Несоответствие типов скобок
            }
        }
    }

    return brackets.empty(); // Баланс скобок соблюден, если стек пустой в конце
}

int main() {
    string input;
    getline(cin, input, '!');

    // Добавляем проверку на символы, которые не должны влиять на баланс скобок
    string sanitizedInput = "";
    for (char ch : input) {
        if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']') {
            sanitizedInput += ch;
        }
    }

    if (isBalanced(sanitizedInput)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
