#include <iostream>

class Animal
{
public:
    Animal()
    {
        std::cout << "Animal 构造函数" << std::endl;
    }
    ~Animal()
    {
        std::cout << "Animal 析构函数" << std::endl;
    }
    virtual void speak()
    {
        std::cout << "Animal speaking ... " << std::endl;
    }
};

class Cat : public Animal
{

    char *mName;

public:
    Cat(const char* name)
    {
        std::cout << "Cat 构造函数" << std::endl;
        this->mName = new char[strlen(name) + 1];
        memcpy(this->mName, name, strlen(name) +1);
    }

    ~Cat()
    {
        std::cout << "Cat 析构函数" << std::endl;
        if(this->mName != nullptr)
        {
            delete[] this->mName;
            this->mName = nullptr;
        }
    }
    void speak()
    {
        std::cout << mName <<" Cat speaking ..." << std::endl;
    }
};

void test0()
{
    Animal* ani = new Cat("Tom");
    std::cout << std::endl;
    delete ani;
}

int main(void)
{
    test0();
    return 0;
}
/*

Animal 构造函数
Cat 构造函数

Animal 析构函数

看到输出顺序，在析构时，只调用了 父类的析构函数
这将会导致 Cat类的 堆区指针没被释放，引起了内存泄露问题

*/

