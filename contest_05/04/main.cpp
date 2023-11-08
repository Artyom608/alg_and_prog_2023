#include <iostream>
#include "json.hpp"
using json = nlohmann::json;

class Point {
private:
    double x, y, r, a;

public:
    Point(double x, double y) : x(x), y(y) {
        r = sqrt(x * x + y * y);
        a = atan2(y, x);
    }

    double get_x() const {
        return x;
    }

    double get_y() const {
        return y;
    }

    double get_r() const {
        return r;
    }

    double get_a() const {
        return a;
    }

    void set_x(double new_x) {
        x = new_x;
        updatePolar();
    }

    void set_y(double new_y) {
        y = new_y;
        updatePolar();
    }

    void set_r(double new_r) {
        r = new_r;
        updateCartesian();
    }

    void set_a(double new_a) {
        a = new_a;
        updateCartesian();
    }

private:
    void updatePolar() {
        r = sqrt(x * x + y * y);
        a = atan2(y, x);
    }

    void updateCartesian() {
        x = r * cos(a);
        y = r * sin(a);
    }
};

int main(){
    double x, y;
    std::cin >> x >> y;

    Point p(x, y);
    json moves;
    std::cin >> moves;
    
    for(auto& move : moves){
        std::string ort = move["ort"];
        double value = move["value"];
        if (ort == "x") p.set_x(p.get_x() + value);
        else if (ort == "y") p.set_y(p.get_y() + value);
        else if (ort == "r") p.set_r(p.get_r() + value);
        else p.set_a(p.get_a() + value);
        std::cout << round(p.get_x()*(1E+5))/(1E+5) << ' ' << round(p.get_y()*(1E+5))/(1E+5) << std::endl;    
    }
}
