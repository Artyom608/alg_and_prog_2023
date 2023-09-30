package main
import (
    "strconv"
    "fmt"
    "strings"
)
func det(a int) int{
    if a / 100>0{
        return 2
    }else if a/10>0{
            return 1
    }else{
        return 0    
    }
}

func main(){
    var row, col int
    fmt.Scan(&row,&col)
    var mat = make([][]int, row+1)
    for i:= range mat{
        mat[i] = make([]int, col+1)
    }
    
    for i:=0;i<=row;i++{
        for j:=0;j<=col;j++{
            if j==0 ||i == 0{
                mat[i][j] = j+i
            }else{
                mat[i][j] = i*j
            }
        }
    }
    str_1 := "    |"
    for i := 1; i<= col; i++{
        str_1 = str_1 + strings.Repeat(" ", 3-det(mat[0][i])) + strconv.Itoa(mat[0][i])
    }
    fmt.Println(str_1)
    fmt.Println("   " + strings.Repeat("-", 3*(col+1)+col-1))
    
    for j:=1;j<=row;j++{
        str_1:=strings.Repeat(" ", 3-det(j)) + strconv.Itoa(mat[j][0])+"|"
        for i:=1;i<=col;i++{
            str_1 = str_1 + strings.Repeat(" ", 3-det(mat[j][i])) + strconv.Itoa(mat[j][i])
        }
        fmt.Println(str_1)
    }
}
