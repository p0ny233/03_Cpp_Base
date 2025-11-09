#include <iostream>

class BasePage
{
public:
    void header()
    {
        std::cout << "公共的头部..." << std::endl;

    }
    void footer()
    {
        std::cout << "公共的底部..." << std::endl;
    }
    void leftList()
    {
        std::cout << "公共的左侧列表..." << std::endl;
    }

    void content()
    {
        std::cout << "公共的内容..." << std::endl;
    }
};

// 继承基本语法: class 子类类名 : 继承方式 父类类名
class NewsPage : public BasePage
{
public:
    void content()
    {
        std::cout << "新闻播报..." << std::endl;
    }
};

void test01()
{
    BasePage bp;    
    bp.header();
    bp.leftList();
    bp.footer();
    bp.content();
    std::cout << std::endl;
    NewsPage np;
    np.header();
    np.leftList();
    np.footer();
    np.content();
}

int main(void)
{
     test01();
    return 0;
}
/*

公共的头部...
公共的左侧列表...
公共的底部...
公共的内容...

公共的头部...
公共的左侧列表...
公共的底部...
新闻播报...

*/