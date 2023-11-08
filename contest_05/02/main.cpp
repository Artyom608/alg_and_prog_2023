#include <iostream>
#include <deque>

class Water
{
private:
    int temperature;
    
public:
    Water(int initialTemperature) : temperature(initialTemperature) {}
    
    bool is_boiling(){
        return temperature >= 100;
    }
        
    void heat_up(int degrees) {
    temperature += degrees;
    }
};

class Teapot
{
private:
    Water& water;

public:
    Teapot(Water& water) : water(water) {}

    bool is_boiling() const {
        return water.is_boiling();
    }

    void heat_up(int degrees) {
        water.heat_up(degrees);
    }    
};

int main()
{
    int temperature, count;
    std::cin >> temperature >> count;
    std::deque<int> heat(count);
    for(auto& t : heat) std::cin >> t;
    
    Water water(temperature);
    Teapot teapot(water);
    
    while(not teapot.is_boiling()){
        teapot.heat_up(heat.front());
        heat.pop_front();
    }
    
    for(auto t : heat) std::cout << t << ' ';
}
