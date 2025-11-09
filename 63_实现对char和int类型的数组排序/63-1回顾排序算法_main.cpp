#include <iostream>

template<typename T>
void Sorted(T &arr, int len)
{
    int minIdx = 0;
    
    for(int i = 0; i < len; i++)
    {
        minIdx = i;

        for(int j = i + 1; j < len; j++)
        {
            if (arr[minIdx] > arr[j])
                minIdx = j;
        }
        if(minIdx != i)
        {
            arr[i] = arr[i] ^ arr[minIdx];
            arr[minIdx] = arr[i] ^ arr[minIdx];
            arr[i] = arr[i] ^ arr[minIdx];
        }
    }
    for (int i = 0; i < len; i++)
        std::cout << arr[i] << ", ";

    std::cout << std::endl;
}

int main(void)
{
    int IntArr[] = { 66, 5, 9, 7, 6 ,0, 11, 33, 10, 2, 0, 1, 2, 3, 4 };

    char CharArr[] = "helloworld";
    // 对int数组排序 - 显式调用
    Sorted<int[sizeof(IntArr) / sizeof(IntArr[0])]>(IntArr, sizeof(IntArr) / sizeof(IntArr[0]));

    // 对char数组排序 - 显式调用
    Sorted<char[sizeof(CharArr) / sizeof(CharArr[0])]>(CharArr, strlen(CharArr));

    return 0;
}

/*

0, 0, 1, 2, 2, 3, 4, 5, 6, 7, 9, 10, 11, 33, 66,
d, e, h, l, l, l, o, o, r, w,

*/