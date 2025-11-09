/*
    防止使用 隐式法 来 实例化对象
*/
class MyString
{
public:
    MyString() {}
    MyString(const char*) {}

    explicit MyString(int len) {}
};

int main(void)
{
    MyString str1;  // 实例化对象
    MyString str2 = "123";
    MyString str3 = MyString("222");

    // 隐式法
    //MyString str4 = 11;  // 可读性不好，误 将 11 当作字符串 "11"，因此为了防止这种情况的发生，使用 explicit关键字杜绝这种情况
    // 只能使用 显式法
    MyString str5 = MyString(123);

    return 0;
}