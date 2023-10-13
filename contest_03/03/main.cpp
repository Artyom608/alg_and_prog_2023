#include <iostream>
#include <stack>
#include <string>
#include <cctype>

int getPriority(char op) {
    if (op == '^')
        return 4;
    else if (op == '*' || op == '/' || op == '%')
        return 3;
    else if (op == '+' || op == '-')
        return 2;
    else if (op == '(')
        return 1;
    return 0;  // Низший приоритет
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^';
}

std::string infixToPostfix(const std::string& infix) {
    std::stack<char> operatorStack;
    std::string postfix;

    for (size_t i = 0; i < infix.size(); ++i) {
        if (std::isdigit(infix[i])) {
            std::string number;
            number += infix[i];
            while (i + 1 < infix.size() && std::isdigit(infix[i + 1])) {
                number += infix[i + 1];
                ++i;
            }
            postfix += number;
            postfix += ' ';
        } else if (isOperator(infix[i])) {
            while (!operatorStack.empty() && getPriority(operatorStack.top()) >= getPriority(infix[i]) && infix[i] != '^' && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                postfix += ' ';
                operatorStack.pop();
            }
            operatorStack.push(infix[i]);
        } else if (infix[i] == '(') {
            operatorStack.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                postfix += ' ';
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '(')
                operatorStack.pop();
        }
    }

    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        postfix += ' ';
        operatorStack.pop();
    }

    // Удаляем последний лишний пробел
    if (!postfix.empty() && postfix.back() == ' ') {
        postfix.pop_back();
    }

    return postfix;
}

int main() {
    std::string infixExpression;
    std::getline(std::cin, infixExpression);
    std::string postfixExpression = infixToPostfix(infixExpression);
    std::cout << postfixExpression << std::endl;
    return 0;
}
