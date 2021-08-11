//
// Created by apple on 8/1/21.
//
//合成复用原则又叫组合/聚合复用原则。它要求在软件复用时，要尽量先使用组合或者聚合等关联关系来实现，其次才考虑使用继承关系来实现。
//如果要使用继承关系，则必须严格遵循里氏替换原则。合成复用原则同里氏替换原则相辅相成的，两者都是开闭原则的具体实现规范。
//结合本次代码进行分析抽象汽车类的派生类有大众和拖拉机，人是可以驾驶汽车的，人可以通过自主选择来驾驶汽车，这样可以形成组合

#include <iostream>

using namespace std;

class AbstractCar//抽象Car类
{
public:
    virtual void run() = 0;
};

class DaZhong : public AbstractCar//具体抽象类的派生类dazhong
{
public:
    virtual void run()
    {
        cout << "DZ Runing !!!" <<endl;
    }
};

class ToLaJi : public AbstractCar//具体抽象类的派生类拖拉机
{
public:
    virtual void run()
    {
        cout << "TLJ Runing !!!" <<endl;
    }
};

//针对具体类,不适用继承
#if 0
class Person : public ToLaJi
{
public:
    void DouFeng()
    {
        run();
    }
};

class PersonB : public DaZhong
{
public:
    void DouFeng()
    {
        run();
    }
};
#endif

//可以使用组合
class Person{
public:
    void setCar(AbstractCar* car)
    {
        this->car = car;
    }
    void DouFeng()
    {
        this->car->run();
    }
    ~Person()
    {
        if (this->car != NULL)
        {
            delete this->car;
        }
    }
public:
    AbstractCar* car ;
};

void test01()
{
    Person *p = new Person();
    p->setCar(new DaZhong);
    p->DouFeng();
    delete p;
}

int main()
{
    test01();
}