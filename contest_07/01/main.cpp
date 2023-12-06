#include <iostream>
#include <vector>

struct Time{
    short hours;
    short minutes;
    short seconds;
    
    void addSeconds(short count){
        seconds += count;
        if (seconds >= 60){
            count = seconds / 60;
            seconds %= 60;
        } else return;
        
        minutes += count;
        if (minutes >= 60){
            count = minutes / 60;
            minutes %= 60;
        } else return;
        
        hours += count;
        if (hours >= 60)
            hours = minutes = seconds = 0;
    }
};

bool operator==(const Time& lhs, const Time& rhs){
    return lhs.hours == rhs.hours &&
           lhs.minutes == rhs.minutes &&
           lhs.seconds == rhs.seconds;
}

bool operator!=(const Time& lhs, const Time& rhs){
    return not (lhs == rhs);
}

bool operator<(const Time& lhs, const Time& rhs){
    return lhs.hours * 3600 + lhs.hours * 60 + lhs.seconds < rhs.hours * 3600 + rhs.hours * 60 + rhs.seconds;
}

class IRunnable{
public:
    virtual void run() = 0;
};

class IClock{
public:
    virtual void add(IRunnable* client, Time time) = 0;
    virtual bool next() = 0;
};

class Clock : public IClock, public IRunnable {
public:
    // Префикс "m_" для полей класса
    std::vector<IRunnable*> m_arr; // Вектор для хранения указателей на объекты IRunnable
    std::vector<Time> m_arr_t;     // Вектор для хранения временных меток

    // Метод для проверки наличия следующего элемента в списке
    bool next() {
        // Если вектор пуст, то следующего элемента нет
        if (m_arr.size() == 0) return false;
        // В противном случае, есть следующий элемент
        return true;
    }

    // Метод для добавления объекта IRunnable с временной меткой в список
    void add(IRunnable* p_client, Time p_time) { 
        // Добавление указатель на объект IRunnable в вектор
        m_arr.push_back(p_client);
        // Добавление временную метку в вектор
        m_arr_t.push_back(p_time);
    }
    
    void run() {
        int i = 0;
        while (next()) {
            // Вывод часов, добавляя ведущий ноль, если часы меньше 10
            if (m_arr_t[i].hours < 10) std::cout << 0;
            std::cout << m_arr_t[i].hours << ':';
            
            // Вывод минут, добавляя ведущий ноль, если минуты меньше 10
            if (m_arr_t[i].minutes < 10) std::cout << 0;
            std::cout << m_arr_t[i].minutes << ':';
            
            // Вывод секунд, добавляя ведущий ноль, если секунды меньше 10
            if (m_arr_t[i].seconds < 10) std::cout << 0;
            std::cout << m_arr_t[i].seconds << ' ';
            
            // Выполнение задачи(вызов метода run() у объекта IRunnable)
            m_arr[i]->run();
            
            // Удаление выполненной задачи из списков
            m_arr.erase(m_arr.begin());
            m_arr_t.erase(m_arr_t.begin());
        }
    }
};

// Вывод на экран имени класса(OSUpdater)
class OSUpdater : public IRunnable {
public:
    void run() {
        std::cout << "OSUpdater\n";
    }
};

// Вывод на экран имени класса(Alarm)
class Alarm : public IRunnable {
public:
    void run() {
        std::cout << "Alarm\n";
    }
};

// Вывод на экран имени класса(ActivityChecker)
class ActivityChecker : public IRunnable {
public:
    void run() {
        std::cout << "ActivityChecker\n";
    }
};

int main(){
    int monentum;
    std::cin >> monentum;
    srand(monentum);  // Фиксируем случайность
    
    IClock* clock = new Clock;
    IRunnable* timer = (Clock*)clock;
    
    Time t = {0, 0, 0}, midnight = {0, 0, 0};
    
    do{
        int type = rand() % 3;
        if (type == 0) clock->add(new OSUpdater, t);
        else if (type == 1) clock->add(new Alarm, t);
        else if (type == 2) clock->add(new ActivityChecker, t);
        t.addSeconds(3600 + rand() % 3600);
    }while(t != midnight);
    
    timer->run();
}
