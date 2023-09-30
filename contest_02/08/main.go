package main
import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "unicode"
)
func isPalindrome(start string) bool {
    //Приводим строку к нижнему регистру
    start = strings.ToLower(start)
    var dlina int = len(start)
    //Если длина строки <= 1, то строка является палиндромом
    if(dlina <= 1){
        return true
    }
    //Удаляем все символы, кроме букв и цифр
    var sb strings.Builder
    for _, c := range start {
        if unicode.IsLetter(c) || unicode.IsDigit(c) {
            sb.WriteRune(c)
        }
    }
    start = sb.String()
    
    //Проверяем, явялется ли строка палиндромом
    n := len(start)
    for i := 0; i < n/2; i++ {
        if start[i] != start[n-i-1] {
            return false
        }
    }
    return true
}

func main() {
    line, _  := bufio.NewReader(os.Stdin).ReadString('\n')
    if isPalindrome( line[:len(line)-1] ){  // Обрезаем \n в конце строки
        fmt.Println("YES")
    }else{
        fmt.Println("NO")
    }
}
