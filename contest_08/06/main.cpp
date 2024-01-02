#include <iostream>
#include <string>
#include <vector>

class Any{
    enum class Type{
        INT,
        DOUBLE,
        STRING,
        VECTOR_ANY_PTR
    };

    void* data;
    Type type;

public:
    Any(int* data);
    Any(double* data);
    Any(std::string* data);
    Any(std::vector<Any*>* data);
    ~Any();
    
    operator int();
    operator double();
    operator std::string();
    operator std::vector<Any*>*();

    friend std::ostream& operator<<(std::ostream& out, const Any& val);
};

std::ostream& operator<<(std::ostream& out, const Any& o);

int main(){
    Any data(new std::vector<Any*>());
    
    std::vector<Any*>* array = (std::vector<Any*>*)data;
    
    int ints_count;
    std::cin >> ints_count;
    for(int i=0; i<ints_count; i++){
        int value;
        std::cin >> value;
        Any* temp = new Any(new int(value));
        array->push_back(temp);
    }
    
    int doubles_count;
    std::cin >> doubles_count;
    for(int i=0; i<doubles_count; i++){
        double value;
        std::cin >> value;
        Any* temp = new Any(new double(value));
        array->push_back(temp);
    }

    int strings_count;
    std::cin >> strings_count;
    for(int i=0; i<strings_count; i++){
        std::string value;
        std::cin >> value;
        Any* temp = new Any(new std::string(value));
        array->push_back(temp);
    }
    
    int i = 0; double d = 0; std::string s = "";
    for(auto value: *array){
        try{ i += (int)(*value); }
        catch(...){ }
        
        try{ d += (double)(*value); }
        catch(...){ }
        
        try{ s += (std::string)(*value); }
        catch(...){ }
    }
    
    Any ai(new int(i));
    Any ad(new double(d));
    Any as(new std::string(s));
    
    std::cout << data << "\n" << ai << ' ' << ad <<  ' ' << as;
}

// Конструктор для типа int
Any::Any(int* data) {
    this->data = data;  // Устанавливаем указатель на данные
    this->type = Type::INT;  // Устанавливаем тип данных
}

// Конструктор для типа double
Any::Any(double* data) {
    this->data = data;  // Устанавливаем указатель на данные
    this->type = Type::DOUBLE;  // Устанавливаем тип данных
}

// Конструктор для типа std::string
Any::Any(std::string* data) {
    this->data = data;  // Устанавливаем указатель на данные
    this->type = Type::STRING;  // Устанавливаем тип данных
}

// Конструктор для типа std::vector<Any*>
Any::Any(std::vector<Any*>* data) {
    this->data = data;  // Устанавливаем указатель на данные
    this->type = Type::VECTOR_ANY_PTR;  // Устанавливаем тип данных
}

// Деструктор
Any::~Any() {
    // Проверяем тип данных и освобождаем память соответствующим образом
    if (type == Type::VECTOR_ANY_PTR) {
        auto realPtr = static_cast<std::vector<Any*>*>(data);
        for (auto &it : *realPtr) {
            delete it;
        }
        delete realPtr;
    } else if (type == Type::INT) {
        int* realPtr = static_cast<int*>(data);
        delete realPtr;
    } else if (type == Type::DOUBLE) {
        double* realPtr = static_cast<double*>(data);
        delete realPtr;
    } else if (type == Type::STRING) {
        std::string* realPtr = static_cast<std::string*>(data);
        delete realPtr;
    }
}

// Оператор преобразования типа int
Any::operator int() {
    if (type != Type::INT) {
        throw "";  // Выбрасываем исключение, если тип данных не соответствует ожидаемому
    }
    return *static_cast<int*>(data);
}

// Оператор преобразования типа double
Any::operator double() {
    if (type != Type::DOUBLE) {
        throw "";  // Выбрасываем исключение, если тип данных не соответствует ожидаемому
    }
    return *static_cast<double*>(data);
}

// Оператор преобразования типа std::string
Any::operator std::string() {
    if (type != Type::STRING) {
        throw "";  // Выбрасываем исключение, если тип данных не соответствует ожидаемому
    }
    return *static_cast<std::string*>(data);
}

// Оператор преобразования типа std::vector<Any*>
Any::operator std::vector<Any*>*() {
    if (type != Type::VECTOR_ANY_PTR) {
        throw "";  // Выбрасываем исключение, если тип данных не соответствует ожидаемому
    }
    return static_cast<std::vector<Any*>*>(data);
}

// Оператор вывода в поток
std::ostream& operator<<(std::ostream& out, const Any& val) {
    // Проверяем тип данных и выводим значение соответствующим образом
    if (val.type == Any::Type::VECTOR_ANY_PTR) {
        auto realPtr = static_cast<std::vector<Any*>*>(val.data);
        for (auto &it : *realPtr) {
            out << *it << " ";
        }
    } else if (val.type == Any::Type::INT) {
        int* realPtr = static_cast<int*>(val.data);
        out << *realPtr;
    } else if (val.type == Any::Type::DOUBLE) {
        double* realPtr = static_cast<double*>(val.data);
        out << *realPtr;
    } else if (val.type == Any::Type::STRING) {
        std::string* realPtr = static_cast<std::string*>(val.data);
        out << *realPtr;
    }
    return out;
}
