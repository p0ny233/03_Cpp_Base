/*
    让类中的某个成员函数作为其他类的友元函数
*/
#include <iostream>

class Building;  // 前向声明
// 下边定义 GoodGay好基友类之后，就要完全实现 Building类中的成员函数，再去实现 GoodGay好基友类的成员函数
// 顺序不允许变化，否则提示使用了 未定义的类型

class GoodGay  // 好基友类
{
Building* building;

public:
    GoodGay();
    void visit();

};

class Building
{
    // 设置好基友类的成员函数 可以对我的私有属性进行访问
    friend void GoodGay::visit();
private:
    std::string  mBedRom;

public:
    Building();
    std::string mSittingRom;
};

Building::Building()
{
    mBedRom = "卧室";
    mSittingRom = "客厅";
}

GoodGay::GoodGay()
{
    this->building = new Building;
}

void GoodGay::visit()
{
    std::cout << "好基友正在访问： " << building->mSittingRom << std::endl;
    std::cout << "好基友正在访问： " << building->mBedRom << std::endl;
}



void test01()
{
    GoodGay gg;
    gg.visit();
}


int main(void)
{
    test01();
    return 0;
}
/*

好基友正在访问： 客厅
好基友正在访问： 卧室

*/