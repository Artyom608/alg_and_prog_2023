package main
import "fmt"

func main() {
    var x int
    var shagi int = 0
    var x_sled int = 0
    fmt.Scanf("%d",&x)
    for x != 1{
        if x % 2 == 0{
            x_sled = x / 2
            x = x_sled
            shagi += 1
            //fmt.Println(x)
        }else{
        x_sled = 3 * x + 1 
        x = x_sled
        shagi += 1
        //fmt.Println(x)
        }
    }
    fmt.Println(shagi)
}
