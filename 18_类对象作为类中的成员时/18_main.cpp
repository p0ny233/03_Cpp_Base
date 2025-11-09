#include <iostream>

class Phone
{
public:
    std::string mPhoneName;
    Phone()
    {
        std::cout << __func__ << " 构造函数" << std::endl;
    }
    Phone(std::string name)
    {
        std::cout << __func__ << " 构造函数" << std::endl;
    }
    ~Phone()
    {
        std::cout << __func__ << " 析构函数" << std::endl;
    }
};

class Game
{
public:
    std::string mGameName;
    Game()
    {
        std::cout << __func__ << " 构造函数" << std::endl;

    }
    Game(std::string name)
    {
        std::cout << __func__ << " 构造函数" << std::endl;

    }
    ~Game()
    {
        std::cout << __func__ << " 析构函数" << std::endl;

    }
};

class Person
{
public:
    std::string mName;
    Phone mPhone;
    Game mGame;
    // 构造成员的顺序 看 定义的顺序，不是看初始化列表的顺序
    Person()
    {
        std::cout << __func__ << " 构造函数" << std::endl;

    }

    Person(std::string name, std::string PhoneName, std::string GameName): mName(name), mGame(GameName), mPhone(PhoneName)
    {
        std::cout << __func__ << " 构造函数" << std::endl;

    }
    ~Person()
    {
        std::cout << __func__ << " 析构函数" << std::endl;

    }
};

int main(void)
{
    
    Person p;
    return 0;
}
/*
构造成员的顺序 看 定义的顺序，不是看初始化列表的顺序，析构函数则和构造成员顺序相反

Phone 构造函数
Game 构造函数
Person 构造函数
~Person 析构函数
~Game 析构函数
~Phone 析构函数

*/