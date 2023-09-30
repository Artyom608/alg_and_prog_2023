package main
import (
    "bufio"
    "fmt"
    "os"
    "math"
)

func isLucky(a string) bool{
    if len(a) != 6 {
        return false
    }
    var str string = a
    a1 := int(str[0] - '0')
    a2 := int(str[1] - '0')
    a3 := int(str[2] - '0')
    a4 := int(str[3] - '0')
    a5 := int(str[4] - '0')
    a6 := int(str[5] - '0')
    var summa int = a1+a2+a3+a4+a5+a6
    if (a1+a2+a3) == (a4+a5+a6){
        return true
    } else if (a1+a3+a5)==(a2+a4+a6){
        return true
    } else if (a1+a2)==(a3+a4) && (a3+a4)==(a5+a6){
        return true 
    } else if math.Mod(math.Pow(float64(summa),0.5),1)==0{
        return true    
    } else {
        return false
    }
}

func main() {
    number, _  := bufio.NewReader(os.Stdin).ReadString('\n')
    if isLucky( number[:len(number)-1] ){  // Обрезаем \n в конце строки
        fmt.Println("YES")
    }else{
        fmt.Println("NO")
    }
}
