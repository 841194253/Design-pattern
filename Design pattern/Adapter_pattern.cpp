//
// Created by apple on 8/4/21.
//
//适配器模式就是将我们写好的接口，但是这个接口不符合需求
//将写好的接口转换成目标需要的接口
//将一个类的接口转换成客户希望的另外一个接口，使得原本由于接口不兼容而不能一起工作的那些类能一起工作。适配器模式分为类结构型模式和对象结构型模式两种，前者类之间的耦合度比后者高，且要求程序员了解现有组件库中的相关组件的内部结构，所以应用相对较少些。


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct MyPrint
{
    void operator()(int v1,int v2)
    {
        cout << v1 + v2 << endl;
    }
};

//定义目标接口适配什么样的
class target
{
public:
    virtual void operator()(int v) = 0;
};

//适配器
class Adapter : public target
{
public:
    Adapter(int param)
    {
        this->param = param;
    }
    virtual void operator()(int v)
    {
        myPrint(v,param);
    }

public:
    MyPrint myPrint;
    int param;
};

Adapter MyBind2nd(int v)
{
    return Adapter(v);
}

int main()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    for_each(v.begin(),v.end(), MyBind2nd(10));
}