// 最不安全的转换

// 没有任何关联的两个类
class Base {};
class Other {};  

void test04()
{
    Base* base1 = nullptr;
    Other* other1 = reinterpret_cast<Other*>(base1);  // 相当于C语言强制转换

    int a = 1;
    Other* other2 = reinterpret_cast<Other*>(a);  // 相当于C语言强制转换
}
int main(void)
{
    test04();
    return 0;
}