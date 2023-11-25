#include<iostream>
#include<string>
#include<map>
#include<cmath>

std::map<std::string, double> bonuses;


// Класс employee
class Employee {
public:
    // Инициализация имени, роли и оклада
    std::string name;
    std::string role;
    int salary;

    // Конструктор для инициализации деталей employee
    Employee(std::string name, std::string role, int salary) {
        this->name = name;
        this->role = role;
        this->salary = salary;
    }

    // Подсчет бонуса 
    int calculateBonus(double percentage = 0) {
        double buffer = this->salary;
        // Специальный бонус для менеджеров
        if (this->role == "manager" && percentage < 0.10) {
            buffer = round(buffer * 0.10);
        }
        else {
            buffer = round(buffer * percentage);
        }
        return buffer;
    }

    // Конечный оклад
    int calculateTotalSalary() {
        return this->salary + this->calculateBonus(bonuses[this->role]);
    }
};

// Оператор вывода в поток
std::ostream& operator<<(std::ostream& out, Employee& emp) {
    out << emp.name << " (" << emp.role << "): " << emp.calculateTotalSalary();
    return out;
}

// Наследник класса Employee(для менеджера)
class Manager : public Employee {
public:
    // Конструктор для менеджера с дефолтным окладом 
    Manager(std::string name, int salary = 16242)
        : Employee(name, "manager", salary) {
    }
};

class Boss: public Employee{
public:
    Boss(std::string name, int money = 16242)
    :Employee(name, "boss", money){
    }
};

int main(){
    double boss_bonus, manager_bonus;
    std::cin >> boss_bonus >> manager_bonus;
    bonuses["manager"] = manager_bonus;
    bonuses["boss"] = boss_bonus;

    int john_money, bob_money, alice_money;
    std::cin >> john_money >> bob_money >> alice_money;
    Boss john("John", john_money);
    Manager bob("Bob", bob_money);
    Manager alice("Alice", alice_money);

    std::cout << john << '\n' << bob << '\n' << alice << std::endl;
}
