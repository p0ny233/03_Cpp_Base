#include <iostream>

class Animal
{
public:
    int mAge;

    virtual void speak()
    {
        std::cout << "Animal Speaking..."  << std::endl;
    }
};

class Sheep : virtual public Animal {};
class Tuo : virtual public Animal {};

class SheepTuo : public Sheep, public Tuo
{
public:
    SheepTuo()
    {
        mAge = 10;
    }

};

void test01()
{
    SheepTuo st1;
    std::cout << std::endl;
}

int main(void)
{
    test01();
    return 0;
}


