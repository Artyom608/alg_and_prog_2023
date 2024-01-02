package main
import "fmt"

type Human struct{
    name string
    age int
}

// Функция printTypes принимает слайс пустых интерфейсов data и выводит на экран тип каждого элемента.
func printTypes(data []interface{}) {
	for _, val := range data {
		// Используем конструкцию switch с типом переменной (type switch) для определения конкретного типа переменной.
		switch val.(type) {
		// Если тип int, выводим "int ".
		case int:
			fmt.Print("int ")
		// Если тип string, выводим "string ".
		case string:
			fmt.Print("string ")
		// Если тип Human (структура), выводим "Human ".
		case Human:
			fmt.Print("Human ")
		// Если тип *Human (указатель на структуру Human), выводим "*Human ".
		case *Human:
			fmt.Print("*Human ")
		// Если неизвестный тип, выводим "interface ".
		default:
			fmt.Print("interface ")
		}
	}
}

func main() {
    var count int
    fmt.Scan(&count)
    
    var data []interface{} = make([]interface{}, count)
    for i:=0; i<count; i++{
        var t string
        fmt.Scan(&t)
        switch t {
            case "int": 
                var val int = 0
                data[i] = interface{}(val)
            case "string":
                var val string = "0"
                data[i] = interface{}(val)
            case "Human":
                var val Human = Human{}
                data[i] = interface{}(val)
            case "*Human":
                var val *Human = &Human{}
                data[i] = interface{}(val)
        }
    }
    
    printTypes(data)
}
