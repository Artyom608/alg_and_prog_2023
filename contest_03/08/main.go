package main

import (
    "fmt"
)

func main() {
    var n, num, result int
    fmt.Scanf("%d", &n)

    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &num)
        result ^= num 
    }

    fmt.Println(result)
}
