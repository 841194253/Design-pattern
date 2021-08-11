//
// Created by apple on 7/31/21.
//归并排序.cpp
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

struct MyCompare{
    bool operator()(int v1,int v2)
    {
        return v1 > v2;
    }
};

void test01()
{
    std::vector<int> v1;
    std::vector<int> v2;
    std::list<int> l1;

    srand((unsigned int)time(NULL));

    for (int i = 0; i < 10; ++i) {
        v1.push_back(rand() % 100);
        //v1.push_back(rand());
    }
    for (int i = 0; i < 10; ++i) {
        v2.push_back(rand() % 100);
        //v2.push_back(rand());
        l1.push_back(rand() % 100);
    }

    std::for_each(l1.begin(),l1.end(),MyPrint());
    l1.reverse();
    std::cout << std::endl;
    std::for_each(l1.begin(),l1.end(),MyPrint());
    std::cout << std::endl;

    std::sort(v1.begin(),v1.end(),MyCompare());
    //std::sort(v2.begin(),v2.end(),MyCompare());
    l1.sort(MyCompare());

    std::vector<int> v3;
    v3.resize(v1.size()+l1.size());
    std::merge(v1.begin(),v1.end(),l1.begin(),l1.end(),v3.begin(),MyCompare());

    for (int i = 0; i < v3.size(); ++i) {
        std::cout << v3[i] << " ";
    }
}

int main()
{
    test01();
    //std::cout << "1" << std::endl;
}