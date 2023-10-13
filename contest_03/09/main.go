package main

import (
    "fmt"
)

func pair(arr []int, X int) (int, int) {
    seen := make(map[int]bool)
    for _, num := range arr {
        complement := X - num
        if seen[complement] {
            return num, complement
        }
        seen[num] = true
    }
    return 0, 0
}

func main() {
    var n, X int
    fmt.Scanf("%d %d", &n, &X)
    arr := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &arr[i])
    }

    A, B := pair(arr, X)

    if A == 0 && B == 0 {
        fmt.Println("0 0")
    } else {
        if(A<B){
            fmt.Printf("%d %d\n", A, B)    
        }else{
            fmt.Printf("%d %d\n", B, A)
        }
    }
}
