// 仅需要在 父类Animal的析构函数声明 添加 virtual关键字 即可
#include <iostream>

class Animal
{
public:
    Animal()
    {
        std::cout << "Animal 构造函数" << std::endl;
    }
    virtual ~Animal()
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

    char* mName;

public:
    Cat(const char* name)
    {
        std::cout << "Cat 构造函数" << std::endl;
        this->mName = new char[strlen(name) + 1];
        memcpy(this->mName, name, strlen(name) + 1);
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
        std::cout << mName << " Cat speaking ..." << std::endl;
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

Cat 析构函数
Animal 析构函数
*/
