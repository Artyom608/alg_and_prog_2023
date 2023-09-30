package main
import (
    "fmt"
)
func main() {
    var first, second, third string
    fmt.Scanf("%s%s%s",&first, &second, &third)
    if first=="Нет" && second == "Нет" && third == "Нет"{
        fmt.Println("Кот")
    }
    if first=="Нет" && second == "Нет" && third == "Да"{
        fmt.Println("Жираф")
    }
    if first=="Нет" && second == "Да" && third == "Нет"{
        fmt.Println("Курица")
    }
    if first=="Нет" && second == "Да" && third == "Да"{
        fmt.Println("Страус")
    }
    if first=="Да" && second == "Нет" && third == "Нет"{
        fmt.Println("Дельфин")
    }
    if first=="Да" && second == "Нет" && third == "Да"{
        fmt.Println("Плезиозавры")
    }
    if first=="Да" && second == "Да" && third == "Нет"{
        fmt.Println("Пингвин")
    }
    if first=="Да" && second == "Да" && third == "Да"{
        fmt.Println("Утка")
    }
}
