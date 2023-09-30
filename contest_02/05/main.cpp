#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct Complex{
  double re;  // Действительная часть
  double im;  // Мнимая часть
};

Complex make_complex(const string& input) {
    Complex result;
    istringstream ss(input);

    ss >> result.re;  // Чтение действительной части
    char plus_sign;
    ss >> plus_sign;  // Чтение символа "+" или "-"
    ss >> result.im;  // Чтение мнимой части

    // Учтем знак "-" перед мнимой частью
    if (plus_sign == '-') {
        result.im = -result.im;
    }

    return result;
}

Complex sum(const Complex& c1, const Complex& c2) {
    Complex result;
    result.re = c1.re + c2.re;
    result.im = c1.im + c2.im;
    return result;
}

Complex sub(const Complex& c1, const Complex& c2) {
    Complex result;
    result.re = c1.re - c2.re;
    result.im = c1.im - c2.im;
    return result;
}

Complex mul(const Complex& c1, const Complex& c2) {
    Complex result;
    result.re = c1.re * c2.re - c1.im * c2.im;
    result.im = c1.re * c2.im + c1.im * c2.re;
    return result;
}

Complex div(const Complex& c1, const Complex& c2) {
    Complex result;
    double denominator = c2.re * c2.re + c2.im * c2.im;

    result.re = (c1.re * c2.re + c1.im * c2.im) / denominator;
    result.im = (c1.im * c2.re - c1.re * c2.im) / denominator;

    return result;
}

void print(const Complex& c) {
    cout << c.re;

    if (c.im < 0) {
        cout << c.im << "j";
    } else if (c.im > 0) {
        cout << "+" << c.im << "j";
    } else {
        cout << "+0j";
    }

    cout << endl;
}

int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1 = make_complex(num);
    
    std::getline(std::cin, num, 'j');
    Complex c2 = make_complex(num);
    
    print(sum(c1, c2));
    print(sub(c1, c2));
    print(mul(c1, c2));
    print(div(c1, c2));
}
