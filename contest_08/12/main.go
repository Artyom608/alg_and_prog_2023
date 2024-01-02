package main

import (
    "fmt"
)

type Stack interface{
    empty() bool
    push(r rune)
    top() rune
    pop() rune
}

// Реализация SimpleStack
type SimpleStack struct {
	data []rune
}

// NewSimpleStack создает и возвращает новый пустой стек.
func NewSimpleStack() *SimpleStack {
	return &SimpleStack{}
}

// empty возвращает true, если стек пуст, иначе false.
func (s *SimpleStack) empty() bool {
	return len(s.data) == 0
}

// push добавляет символ r на вершину стека
func (s *SimpleStack) push(r rune) {
	s.data = append(s.data, r)
}

// top возвращает элемент, расположенный на вершине стека.
// Если стек пуст, возвращает 0 (или другое значение по умолчанию).
func (s *SimpleStack) top() rune {
	if len(s.data) == 0 {
		return 0
	}
	return s.data[len(s.data)-1]
}

// pop извлекает элемент, расположенный на вершине стека, и возвращает его.
// Если стек пуст, возвращает 0 (или другое значение по умолчанию).
func (s *SimpleStack) pop() rune {
	if len(s.data) == 0 {
		return 0
	}
	top := s.data[len(s.data)-1]
	s.data = s.data[:len(s.data)-1]
	return top
}

func bracketValidator(stack Stack, str string) bool{
    mapping := map[rune]rune{
        ')': '(',
        ']': '[',
        '}': '{',
    }

    for _, char := range str {
        if char == '(' || char == '[' || char == '{' {
            stack.push(char)
        } else if char == ')' || char == ']' || char == '}' {
            if stack.empty() || stack.top() != mapping[char] {
                return false
            }
            stack.pop()
        }
    }

    return stack.empty()
}

func main() {
    var input string
    fmt.Scan(&input)
    fmt.Println(bracketValidator(NewSimpleStack(), input))
}
