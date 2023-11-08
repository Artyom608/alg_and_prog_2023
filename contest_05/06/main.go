package main

import (
    "fmt"
    "math/rand"
    "time"
)
type Cat struct {
	IsAlive bool
}

func NewCat() Cat {
	rand.Seed(time.Now().UnixNano())
	IsAlive := rand.Intn(2) == 0
	return Cat{IsAlive}
}

func (c Cat) is_alive() bool {
	return c.IsAlive
}

type Box struct{}

func (b Box) open() Cat {
	return NewCat()
}

func main(){
    var box Box
    cat := box.open()
    if cat.is_alive() {
        fmt.Print("alive")
    } else {
        fmt.Print("dead")
    }
}
