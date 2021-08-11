//
// Created by apple on 7/31/21.
//

#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

struct MyPrint{
    void operator() (int a)
    {
        std::cout << a << " ";
    }
};

void test01()
{
    std::vector<int> v1;
    std::vector<int> v2;

    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    for (int i = 5; i < 15; ++i) {
        v2.push_back(i);
    }

    std::vector<int> v3;
    v3.resize(std::min(v1.size(),v2.size()));
    std::vector<int>::iterator it = std::set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());//交集
    std::for_each(v3.begin(),it,MyPrint());

    std::cout << std::endl;

    std::vector<int> v4;
    v4.resize(v1.size() + v2.size());
    std::vector<int>::iterator it2 = std::set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v4.begin());//并集
    std::for_each(v4.begin(),it2,MyPrint());

    std::cout << std::endl;

    std::vector<int> v5;
    v5.resize(std::max(v1.size(),v2.size()));
    std::vector<int>::iterator it3 = std::set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),v5.begin());//差集
    std::for_each(v5.begin(),it3,MyPrint());
}



int main()
{
    test01();
}