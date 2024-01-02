#include <iostream>
#include <vector>

class IComparator{
public:
    virtual bool compare(int a, int b) const = 0;
};

bool less(int a, int b){
    return a < b;
}

void greater(int a, int b, bool& verdict){
    verdict = a > b;
}

double key_func(int value){
    return abs(value);
}

class LessAdapter: public IComparator{
    using func = bool (*)(int a, int b);
    func cmp;
public:
    LessAdapter(func cmp): cmp(cmp){
    }
    
    bool compare(int a, int b) const override {
        return cmp(a, b);
    }
};

// Адаптер для функции greater, реализующий интерфейс IComparator.
class GreaterAdapter : public IComparator {
    using func = void (*)(int a, int b, bool& verdict);  // Псевдоним для указателя на функцию типа void (*)(int a, int b, bool& verdict)

    func cmp;  // Указатель на функцию greater

public:
    // Конструктор, принимающий указатель на функцию greater и инициализирующий cmp.
    GreaterAdapter(func cmp) : cmp(cmp) {}

    // Реализация метода compare интерфейса IComparator.
    // Вызывает функцию greater, передавая ей параметры a и b, и сохраняя результат в переменной verdict.
    // Возвращает значение переменной verdict.
    bool compare(int a, int b) const override {
        bool verdict;
        cmp(a, b, verdict);
        return verdict;
    }
};

// Адаптер для функции key_func и лямбды, реализующий интерфейс IComparator.
class KeyFuncLessAdapter : public IComparator {
    using func = double (*)(int value);  // Псевдоним для указателя на функцию типа double (*)(int value)

    func keyFunc;  // Указатель на функцию key_func или лямбду

public:
    // Конструктор, принимающий указатель на функцию key_func или лямбду и инициализирующий keyFunc.
    KeyFuncLessAdapter(func keyFunc) : keyFunc(keyFunc) {}

    // Реализация метода compare интерфейса IComparator.
    // Вызывает функцию key_func или лямбду, передавая ей параметры a и b, и сравнивает результаты.
    bool compare(int a, int b) const override {
        return keyFunc(a) < keyFunc(b);
    }
};

void bubbleSort(std::vector<int>& arr, const IComparator& comp) {
    for (int i = 0; i < arr.size() - 1; i++)
        for (int j = 0; j < arr.size() - i - 1; j++)
            if (comp.compare(arr[j], arr[j + 1]))
                std::swap(arr[j], arr[j+1]);
}

int main(){
    int size;
    std::cin >> size;
    std::vector<int> arr(size);
    for(auto& i : arr) std::cin >> i;
    
    bubbleSort(arr, LessAdapter(less));
    for(auto i : arr) std::cout << i << ' ';
    std::cout << std::endl;
    
    bubbleSort(arr, GreaterAdapter(greater));
    for(auto i : arr) std::cout << i << ' ';
    std::cout << std::endl;
    
    bubbleSort(arr, KeyFuncLessAdapter(key_func));
    for(auto i : arr) std::cout << i << ' ';
    std::cout << std::endl;
    
    bubbleSort(arr, KeyFuncLessAdapter([](int value)->double{
        return abs(value) % 2;
    }));
    for(auto i : arr) std::cout << i << ' ';
}
