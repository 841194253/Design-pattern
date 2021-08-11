//
// Created by apple on 7/31/21.
//重置排序.cpp

#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <list>

struct MyPrint{
    void operator() (int a)
    {
        std::cout << a << " ";
    }
};

void test01()
{
    //std::vector<int> v;
    std::list<int> v;//list不支持随机访问

    for (int i = 0; i < 9; ++i) {
        v.push_back(i);
    }

    std::for_each(v.begin(),v.end(),MyPrint());
    std::random_shuffle(v.begin(),v.end());
    std::cout << std::endl;
    std::for_each(v.begin(),v.end(),MyPrint());
}

int main()
{
    test01();
    //std::cout << "!" << std::endl;
}