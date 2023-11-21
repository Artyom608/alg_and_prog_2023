#include <iostream>
#include <string>
#include <complex>

class Complex {
public:
    // Создание формы комплексного число
    Complex(std::string input) {
        double real_part, imag_part;
        std::stringstream ss(input);
        ss >> real_part;
        
        std::string imag_str;
        ss >> imag_str;
        if (imag_str.length() == 1) {
            std::string temp;
            ss >> temp;
            imag_str += temp;
        }
        
        imag_part = std::stod(imag_str);

        // Проверка на -0
        if (real_part == -0) real_part = 0;
        if (imag_part == -0) imag_part = 0;

        number = std::complex<double>(real_part, imag_part);
    }

    // Инициализация объекта
    Complex(std::complex<double> init_num) {
        number = init_num;
    }

    // Возврат вещественной части комплексного числа
    double real() const {
        return number.real();
    }

    // Возврат мнимой части комплексного числа
    double imag() const {
        return number.imag();
    }

    // Сложение
    Complex operator+(const Complex &b) {
        return Complex(number + b.number);
    }

    // Вычитание
    Complex operator-(const Complex &b) {
        return Complex(number - b.number);
    }

    // Умножение
    Complex operator*(const Complex &b) {
        return Complex(number * b.number);
    }

    // Деление
    Complex operator/(const Complex &b) {
        return Complex(number / b.number);
    }

    // Оператор вывода комплексного числа в поток <<(дружественный)
    friend std::ostream& operator<<(std::ostream& out, const Complex& num){
        out << (num.real() == 0.0 ? 0.0 : num.real())
            << (num.imag() < 0 ? "" : "+")
            << (num.imag() == 0.0 ? 0.0 : num.imag()) << 'j';
        return out;
    }

private:
    std::complex<double> number; 
};

int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1(num);
    
    std::getline(std::cin, num, 'j');
    Complex c2(num);
    
    std::cout << c1+c2 << '\n' << c1-c2 << '\n'
              << c1*c2 << '\n' << c1/c2 << std::endl;
}
