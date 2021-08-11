//
// Created by apple on 8/2/21.
//
//工厂方法模式是对简单工厂模式的进一步抽象化，其好处是可以使系统在不修改原来代码的情况下引进新的产品，即满足开闭原则。
//工厂方法模式 = 简单工厂模式 + 开闭原则
//既要符合简单工厂生产可选性也要尽量保证开闭原则，在不修改源代码的基础上可以增加功能，并且尽可能保证单一职责，也许可能在实际开发中无法保证满足单一职责原则
//工厂方法模式就是：先抽象工厂，然后具体工厂，再抽象产品，再具体产品
//例如本次的先抽象水果工厂，再具体指明工厂(例如苹果工厂),再抽象水果，再指明水果(例如苹果)

#include <iostream>

using namespace std;

class AbstractFruit//抽象水果类
{
public:
    virtual void ShowName() = 0;
};

class Apple : public AbstractFruit//具体抽象类的派生类苹果
{
public:
    virtual void ShowName()
    {
        cout << "apple" << endl;
    }
};

class Banana : public AbstractFruit//具体抽象类的派生类香蕉
{
public:
    virtual void ShowName()
    {
        cout << "banana" << endl;
    }
};

class Orange : public AbstractFruit//具体抽象类的派生类橙子
{
public:
    virtual void ShowName()
    {
        cout << "orange" << endl;
    }
};

//水果工厂 简单工厂模式
class FruitFactory
{
public:
    static AbstractFruit* CreateFruit(string flag)
    {
        if (flag == "apple")
        {
            return new Apple;
        } else if (flag == "banana")
        {
            return new Banana;
        } else if (flag == "orange")
        {
            return new Orange;
        } else
        {
            return NULL;
        }
    }
};

class AbstractFactory//抽象工厂 工厂方法模式
{
public:
    virtual AbstractFruit* CreateFruit() = 0;
};

class AppleFactory : public AbstractFactory//具体抽象类的派生类苹果工厂
{
    virtual AbstractFruit* CreateFruit()
    {
        return new Apple;
    }
};

class BananaFactory : public AbstractFactory//具体抽象类的派生类香蕉工厂
{
    virtual AbstractFruit* CreateFruit()
    {
        return new Banana;
    }
};

class OrangeFactory : public AbstractFactory//具体抽象类的派生类橙子工厂
{
    virtual AbstractFruit* CreateFruit()
    {
        return new Orange;
    }
};


void test01()
{
    AbstractFactory* abstractFactory = NULL;//声明抽象工厂
    AbstractFruit* abstractFruit = NULL;//声明抽象水果

    //创建苹果工厂
    abstractFactory = new AppleFactory;
    //把创建的苹果工厂的创建苹果对象函数的值赋值给抽象苹果
    abstractFruit = abstractFactory->CreateFruit();
    abstractFruit->ShowName();

    delete abstractFruit;
    delete abstractFactory;

    //以下的什么橙子、香蕉一模一样，只是改改代码名称而已
}

int main()
{
    test01();
}