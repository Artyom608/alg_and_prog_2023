#include <iostream>
using namespace std;
class Cat
{
public:
    Cat()
    {
        is_alive_ = (rand() % 2 == 0);
    }

    bool is_alive()
    {
        return is_alive_;
    }

private:
    bool is_alive_;
};

class Box
{
public:
    Cat open()
    {
        return Cat();
    }
};

int main(){
  Box box;
  Cat cat = box.open();
  if (cat.is_alive()) std::cout << "alive";
  else std::cout << "dead";
}
