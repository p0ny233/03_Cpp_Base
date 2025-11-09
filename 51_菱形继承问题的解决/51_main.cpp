#include <iostream>

class Animal
{
public:
    int age;
};

class Sheep : virtual public Animal {};
class Tuo : virtual public Animal {};

class SheepTuo : public Sheep, public Tuo 
{
public:
    SheepTuo()
    {
        age = 10;
    }
};

void test01()
{
    SheepTuo st;
    
    std::cout << "st.age: "<< st.age << std::endl;  // 不会出现不明确的情况，因为数据只有一份
    std::cout << "st.Sheep::age: " << st.Sheep::age << std::endl;
    std::cout << "st.Tuo::age: " << st.Tuo::age << std::endl;
}

int main(void)
{
    test01();
    return 0;
}

/*

st.age: 10
st.Sheep::age: 10
st.Tuo::age: 10

*/