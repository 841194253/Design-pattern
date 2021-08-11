//
// Created by apple on 8/1/21.
//
//简单工厂模式有一个具体的工厂类，可以生成多个不同的产品，属于创建型设计模式。简单工厂模式不在 GoF 23 种设计模式之列。
//简单工厂模式每增加一个产品就要增加一个具体产品类和一个对应的具体工厂类，这增加了系统的复杂度，违背了“开闭原则”。
//从上一条具体来说简单工厂要增加功能时，就要修改源代码所以违背了开闭原则
//具体到本次代码上只要增加新的水果就要在工厂类里边增加一个新的else if(同理switch也一样),这样维护起来可能会相对麻烦一点，修改源代码就可能引发新的bug

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

//水果工厂
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

void test01()
{
    FruitFactory *fruit = new FruitFactory();
    AbstractFruit *apple = fruit->CreateFruit("apple");
    apple->ShowName();

    delete fruit;
    //delete apple;
}

int main()
{
    test01();
}