//
// Created by apple on 8/3/21.
//
//抽象工厂模式是一种为访问类提供一个创建一组相关或相互依赖对象的接口，且访问类无须指定所要产品的具体类就能得到同族的不同等级的产品的模式结构。
//抽象工厂模式是工厂方法模式的升级版本，工厂方法模式只生产一个等级的产品，而抽象工厂模式可生产多个等级的产品。
//模式的结构：抽象工厂模式的主要角色如下：抽象工厂、具体工厂、抽象产品、具体产品
//结合本次的例子抽象了三个水果，抽象了工厂，然后都具体实现


#include <iostream>

using namespace std;

//抽象苹果
class AbstractApple
{
public:
    virtual void ShowName() = 0;
};

class ChinaApple : public AbstractApple//中国苹果
{
public:
    virtual void ShowName()
    {
        cout << "china apple" << endl;
    }
};

class AmericanApple : public AbstractApple//美国苹果
{
public:
    virtual void ShowName()
    {
        cout << "usa apple" << endl;
    }
};

class JapanApple : public AbstractApple//日本苹果
{
public:
    virtual void ShowName()
    {
        cout << "japan apple" << endl;
    }
};
//抽象香蕉
class AbstractBanana
{
public:
    virtual void ShowName() = 0;
};

class ChinaBanana : public AbstractBanana//中国香蕉
{
public:
    virtual void ShowName()
    {
        cout << "china banana" << endl;
    }
};

class AmericanBanana : public AbstractBanana//美国香蕉
{
public:
    virtual void ShowName()
    {
        cout << "usa banana" << endl;
    }
};

class JapanBanana : public AbstractBanana//日本香蕉
{
public:
    virtual void ShowName()
    {
        cout << "japan banana" << endl;
    }
};
//抽象橙子
class AbstractOrange
{
public:
    virtual void ShowName() = 0;
};

class ChinaOrange : public AbstractOrange//中国橙子
{
public:
    virtual void ShowName()
    {
        cout << "china orange" << endl;
    }
};

class AmericanOrange : public AbstractOrange//美国橙子
{
public:
    virtual void ShowName()
    {
        cout << "usa orange" << endl;
    }
};

class JapanOrange : public AbstractOrange//日本橙子
{
public:
    virtual void ShowName()
    {
        cout << "japan orange" << endl;
    }
};
//抽象工厂
class AbstractFactory
{
public:
    virtual AbstractApple* CreateApple() = 0;
    virtual AbstractBanana* CreateBanana() = 0;
    virtual AbstractOrange* CreateOrange() = 0;
};

class ChinaFactory : public AbstractFactory//中国工厂
{
public:
    virtual AbstractApple* CreateApple()
    {
        return new ChinaApple;
    }
    virtual AbstractBanana* CreateBanana()
    {
        return new ChinaBanana;
    }
    virtual AbstractOrange* CreateOrange()
    {
        return new ChinaOrange;
    }
};

class AmericanFactory : public AbstractFactory//美国工厂
{
public:
    virtual AbstractApple* CreateApple()
    {
        return new AmericanApple;
    }
    virtual AbstractBanana* CreateBanana()
    {
        return new AmericanBanana;
    }
    virtual AbstractOrange* CreateOrange()
    {
        return new AmericanOrange;
    }
};

class JapanFactory : public AbstractFactory//日本工厂
{
public:
    virtual AbstractApple* CreateApple()
    {
        return new JapanApple;
    }
    virtual AbstractBanana* CreateBanana()
    {
        return new JapanBanana;
    }
    virtual AbstractOrange* CreateOrange()
    {
        return new JapanOrange;
    }
};

void test01()
{
    //先声明抽象工厂和水果
    AbstractFactory* abstractFactory = NULL;
    AbstractApple* apple = NULL;
    AbstractBanana* banana = NULL;
    AbstractOrange* orange = NULL;

    //在通过赋值具体化
    abstractFactory = new ChinaFactory;
    apple = abstractFactory->CreateApple();
    banana = abstractFactory->CreateBanana();
    orange = abstractFactory->CreateOrange();

    //具体化后直接调用对象函数
    apple->ShowName();
    banana->ShowName();
    orange->ShowName();

    delete abstractFactory;
    delete apple;
    delete banana;
    delete orange;
}

int main()
{
    test01();
}