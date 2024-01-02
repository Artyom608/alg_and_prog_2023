package main

import (
    "fmt"
)

import "strings"

// BinaryTreeNode представляет узел бинарного дерева поиска.
type BinaryTreeNode struct {
	Value int              // Значение узла.
	Left  *BinaryTreeNode  // Ссылка на левое поддерево.
	Right *BinaryTreeNode  // Ссылка на правое поддерево.
}

// NewBinaryTreeNode создает новый узел с заданным значением.
func NewBinaryTreeNode(value int) *BinaryTreeNode {
	return &BinaryTreeNode{Value: value}
}

// insertNode добавляет элемент со значением value как узел поддерева t.
func (t *BinaryTreeNode) insertNode(value int) {
	if value < t.Value {
		if t.Left == nil {
			t.Left = NewBinaryTreeNode(value)
		} else {
			t.Left.insertNode(value)
		}
	} else if value > t.Value {
		if t.Right == nil {
			t.Right = NewBinaryTreeNode(value)
		} else {
			t.Right.insertNode(value)
		}
	}
	// Игнорируем вставку, если значение уже существует.
}

func (t *BinaryTreeNode) findNode(value int) *BinaryTreeNode {
	if t == nil || t.Value == value {
		return t
	}

	if value < t.Value {
		return t.Left.findNode(value)
	}
	return t.Right.findNode(value)
}


// removeNode удаляет узел со значением value в текущем поддереве t.
func (t *BinaryTreeNode) removeNode(value int) *BinaryTreeNode {
	if t == nil {
		return nil
	}

	if value < t.Value {
		t.Left = t.Left.removeNode(value)
	} else if value > t.Value {
		t.Right = t.Right.removeNode(value)
	} else {
		if t.Left == nil {
			return t.Right
		} else if t.Right == nil {
			return t.Left
		}

		// Если есть два потомка, выбираем максимум из левого поддерева.
		maxLeft := t.Left.findMax()
		t.Value = maxLeft.Value
		t.Left = t.Left.removeNode(maxLeft.Value)
	}
	return t
}

// findMax находит узел с максимальным значением в поддереве.
func (t *BinaryTreeNode) findMax() *BinaryTreeNode {
	for t.Right != nil {
		t = t.Right
	}
	return t
}

func (t *BinaryTreeNode) String() string {
	var result strings.Builder
	if t == nil {
		return ""
	}

	queue := []*BinaryTreeNode{t}
	for len(queue) > 0 {
		node := queue[0]
		queue = queue[1:]

		result.WriteString(fmt.Sprintf("%d ", node.Value))

		if node.Left != nil {
			queue = append(queue, node.Left)
		}
		if node.Right != nil {
			queue = append(queue, node.Right)
		}
	}

	return strings.TrimSpace(result.String())
}

func main() {
    var count int
    fmt.Scan(&count)
    
    var root *BinaryTreeNode
    for count > 0 {
        var command string
        var value int
        fmt.Scan(&command, &value)
        
        if command == "insert" {
            if root == nil {
                root = NewBinaryTreeNode(value)
            }
            root.insertNode(value)
        }else if command == "remove" {
            root = root.removeNode(value)
        }else if command == "find" {
            fmt.Println(root.findNode(value))
        }
        
        count--
    }
}
