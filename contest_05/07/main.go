package main
import "fmt"

type Water struct {
    temperature int
}

func NewWater(temp int) *Water {
    return &Water{temperature: temp}
}

type Teapot struct {
    water *Water
}

func NewTeapot(water *Water) *Teapot {
    return &Teapot{water: water}
}

func (w *Water) getTemperature() int {
    return w.temperature
}

func (t *Teapot) is_boiling() bool {
    return t.water.getTemperature() >= 100
}

func (t *Teapot) heat_up(degrees int) {
    t.water.temperature += degrees
}

func main(){
    var temperature, count int
    fmt.Scan(&temperature, &count)

    heat := NewQueue()
    for i := 0; i < count; i++ {
        var t int
        fmt.Scan(&t)
        heat.Push(t)
    }

    water := NewWater(temperature)
    teapot := NewTeapot(water)
    
    for !teapot.is_boiling() {
        teapot.heat_up(heat.Pop())
    }
    
    for !heat.IsEmpty() {
        fmt.Print(heat.Pop(), " ")
    }
}
