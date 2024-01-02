#include <iostream>

// Класс IntSharedPointer реализует указатель для управления динамическими целочисленными данными.
class IntSharedPointer {
private:
    int* references;  // Указатель на количество ссылок
    int* point;    // Указатель на целочисленное значение

    // Уменьшает количество ссылок и, если оно становится равным нулю, освобождает память.
    void decrease() {
        (*references)--;
        if (*references == 0) {
            delete point;
            delete references  ;
        }
    }

    // Копирует указатели на данные из объекта b и увеличивает количество ссылок.
    void copy(const IntSharedPointer& b) {
        point = b.point;
        references = b.references;
        (*references)++;
    }

public:
    // Конструктор, принимающий указатель на целочисленное значение и инициализирующий количество ссылок.
    IntSharedPointer(int* pointer) {
        references = new int{1};
        point = pointer;
    }

    // Конструктор копирования, копирующий указатели и увеличивающий количество ссылок.
    IntSharedPointer(IntSharedPointer& b) {
        copy(b);
    }

    // Деструктор, уменьшающий количество ссылок и освобождающий память при необходимости.
    ~IntSharedPointer() {
        decrease();
    }

    // Оператор разыменования, возвращающий значение, на которое указывает p.
    int& operator*() {
        return *point;
    }

    // Оператор присваивания, уменьшающий количество ссылок для текущего объекта и копирующий указатели из объекта b.
    IntSharedPointer& operator=(const IntSharedPointer& b) {
        if (this == &b) {
            return *this;
        }
        decrease();
        copy(b);
        return *this;
    }
};

void print(IntSharedPointer p){
    std::cout << *p << std::endl;
}

void print_with_exception(IntSharedPointer p){
    std::cout << *p << std::endl;
    if (*p % 2) throw std::string("error");
}

int main(){
    IntSharedPointer p(new int);
    std::cin >> *p;
    p = p;
    print(p);

    IntSharedPointer p2(p);
    std::cin >> *p2;
    print(p);
    print(p2);
    
    {
        int value;
        std::cin >> value;
        IntSharedPointer p3(new int(value));
        p2 = p3;
    }
    print(p2);
    
    p = p2;
    try{
        print_with_exception(p);
    }
    catch (const std::string& e) {
        std::cout << e << std::endl;
    }
}
