#include <iostream>

class Building
{
    // friend关键字 让 好基友全局函数 可以访问 我的房子的私有属性
    friend void goodGay(Building* building);

public:
    // 客厅
    std::string m_SittingRoom;

    Building()
    {
        this->m_SittingRoom = "客厅";
        this->m_BedRoom = "卧室";
    }
private:
    // 卧室
    std::string m_BedRoom;
};

// 好基友可以访问 我的房子的私有属性
void goodGay(Building *building)
{
    std::cout << "好基友 正在访问：" << building->m_SittingRoom << std::endl;
    std::cout << "好基友 正在访问：" << building->m_BedRoom << std::endl;
}

void test01()
{
    Building building;
    goodGay(&building);
    
}

int main(void)
{
    test01();
    return 0;
}
/*

好基友 正在访问：客厅
好基友 正在访问：卧室

*/