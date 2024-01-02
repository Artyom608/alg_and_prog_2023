#include <iostream>

class Point {
public:
    // Координаты точки в ПДСК
    int x, y;
    // Конструктор, принимающий и запоминающий координаты точки
    Point(int x, int y) : x(x), y(y) {}
    // Метод, который принимает ссылку на вектор и сдвигает точку в новое положение
    void move(const class Vector &v);
};

class Vector {
public:
    // Компоненты вектора по соответствующим осям
    int x, y;
    //конструктор, принимающий две ссылки на точки- 
    //в порядке: точка начала и точка конца вектора соответственно
    Vector(const Point &start, const Point &end) : x(end.x - start.x), y(end.y - start.y) {}
};

void Point::move(const Vector &v) {
    // Меняем координаты
    x += v.x;
    y += v.y;
}

int main(){
    int x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    Point p(x1, y1);
    Vector dir(Point(x2, y2), Point(x3, y3));
    p.move(dir);
    
    std::cout << p.x << ' ' << p.y;
}
