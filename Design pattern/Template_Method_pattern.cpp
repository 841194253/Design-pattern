//
// Created by apple on 8/4/21.
//
//模板方法（Template Method）模式的定义如下：定义一个操作中的算法骨架，而将算法的一些步骤延迟到子类中，使得子类可以不改变该算法结构的情况下重定义该算法的某些特定步骤。它是一种类行为型模式。
//结合本次代码就可以看出，冲咖啡和泡茶的步骤相似，可以通过模版方法进行使用

#include <iostream>

using namespace std;

class DrinkTemplate
{
public:
    virtual void BoildWater() = 0;
    virtual void Brew() = 0;
    virtual void PourInCup() = 0;
    virtual void AddSomethin() = 0;

    void Make()
    {
        BoildWater();
        Brew();
        PourInCup();
        AddSomethin();
    }
};

class Coffee : public DrinkTemplate
{
public:
    virtual void BoildWater()
    {
        cout << "水" << endl;
    }
    virtual void Brew()
    {
        cout << "冲泡" << endl;
    }
    virtual void PourInCup()
    {
        cout << "coffee in cup" <<endl;
    }
    virtual void AddSomethin()
    {
        cout << "milk sugar" << endl;
    }

    void Make()
    {
        BoildWater();
        Brew();
        PourInCup();
        AddSomethin();
    }
};

class Tea : public DrinkTemplate
{
public:
    virtual void BoildWater()
    {
        cout << "水" << endl;
    }
    virtual void Brew()
    {
        cout << "冲泡" << endl;
    }
    virtual void PourInCup()
    {
        cout << "tea in cup" <<endl;
    }
    virtual void AddSomethin()
    {
        cout << "sugar" << endl;
    }

    void Make()
    {
        BoildWater();
        Brew();
        PourInCup();
        AddSomethin();
    }
};

void test01()
{
    Tea* tea = new Tea();
    tea->Make();
    
    delete tea;
}

int main()
{
    test01();
}