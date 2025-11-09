/*
    将 Animal类的析构函数定义成 纯虚析构函数，没有定义在链接阶段报错
    不管 Animal类有没有被定义成虚函数，都会被调用，现在显式声明将析构函数定义成纯虚析构，那么必须要实现
        假设父类Animal有属性指向堆区，那么就要在父类的析构函数中释放该属性

            因此纯虚析构函数要声明，也要实现。
            类内声明，类外实现
*/
#include <iostream>

class Animal
{
public:

    Animal()
    {
        std::cout << "Animal 构造函数调用" << std::endl;
    }
    virtual void speak()
    {
        std::cout << "Animal Speaking..." << std::endl;
    }
    virtual ~Animal() = 0;  // 没有实现，报错，所在类被视为 抽象类
    
};

Animal::~Animal()
{
    std::cout << "Animal的纯虚析构函数调用" << std::endl;
}

class Cat : public Animal
{

char* mName;

public:
    Cat(const char* name)
    {
        std::cout << "Cat 构造函数调用" << std::endl;
        this->mName = new char[strlen(name)+1];
        memcpy(this->mName, name, strlen(name)+1);
    }
    
    void speak()
    {
        std::cout << this->mName << " Cat Speaking..." << std::endl;
    }

    ~Cat()
    {
        std::cout << this->mName << " Cat 析构函数调用" << std::endl;
        if(this->mName)
        {
            delete[] this->mName;
            this->mName = nullptr;
        }
    }

};

void test01()
{
    Animal* animal  = new Cat("Tom");
    animal->speak();
    delete animal;
}

int main(void)
{
    test01();
    return 0;
}
/*

Animal 构造函数调用
Cat 构造函数调用
Tom Cat Speaking...
Tom Cat 析构函数调用
Animal的纯虚析构函数调用

*/