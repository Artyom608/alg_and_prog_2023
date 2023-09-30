package main
import "fmt"
func main(){
    var N int;
    var str string;
    fmt.Scanf("%d", &N)
    arr := make([]float64, N)
    arr2 := make([]float64, N)
    for i:=0; i<N;i++{
        if _,err := fmt.Scan(&arr[i]); err!=nil{
            panic(err)
        }
    }
    for j:=1;j<N-1;j++{
        arr2[j] = (arr[j-1]+arr[j]+arr[j+1])/3.0
    }
    arr2[0] = arr[0]
    arr2[N-1] = arr[N-1]
    
    for i:=0;i<N;i++{
        str = str + fmt.Sprintf("%v",arr2[i]) + " "
    }
    fmt.Println(str)
}
