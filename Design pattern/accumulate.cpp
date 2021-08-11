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

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    int a = std::accumulate(v.begin(),v.end(),0);//求和
    std::cout << a << std::endl;

    std::vector<int> v2;
    v2.resize(10);
    std::fill(v2.begin(),v2.end(),10);//填充
    std::for_each(v2.begin(),v2.end(),MyPrint());

}
