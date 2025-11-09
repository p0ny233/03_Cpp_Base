#include <iostream>

class Person
{
public:
    int mA;
    int mB;
    int mC;
    Person(int a, int b, int c) :mA(a), mB(b), mC(c)
    {
        std::cout << "mA: " << mA << ", mB: " << mB << ", mC: " << mC << std::endl;
    }
};

int main(void)
{
    Person(1, 2,3);

    return 0;
}

// mA: 1, mB: 2, mC: 3