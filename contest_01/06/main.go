package main
import "fmt"

func main(){
    var a1, a2, a3, a4, a5, N int
    fmt.Scanf("%d", &N)
    for N != 0{
        if N-5000>=0{
            N-=5000
            a1+=1
        }else if N-1000>=0{
            N-=1000
            a2+=1
        }else if N-500>=0{
            N-=500
            a3+=1
        }else if N-200>=0{
            N-=200
            a4+=1
        }else if N-100>=0{
            N-=100
            a5+=1
        }
    }
    fmt.Println(a1, a2, a3, a4, a5)
}
