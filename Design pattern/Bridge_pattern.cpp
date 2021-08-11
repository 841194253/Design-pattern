//
// Created by apple on 8/10/21.
//
//桥接模式：将抽象与实现分离，使它们可以独立变化。它是用组合关系代替继承关系来实现，从而降低了抽象和实现这两个可变维度的耦合度。
//抽象化角色：定义抽象类，并包含一个对实现化对象的引用。
//扩展抽象化角色：是抽象化角色的子类，实现父类中的业务方法，并通过组合关系调用实现化角色中的业务方法。
//实现化角色：定义实现化角色的接口，供扩展抽象化角色调用。
//具体实现化角色：给出实现化角色接口的具体实现。
//结合本代码先抽象接口再具体实现抽象接口，具体实现a，再实现a的细节

#include <iostream>

using namespace std;

#define DELETE(pointer) delete pointer; pointer=nullptr//定义delete对象方法

class Abstraction //抽象接口
{
public:
    virtual ~Abstraction(){}
    virtual void operation() = 0;

protected:
    Abstraction() {}
};

class Implement // 实现抽象接口
{
public:
    virtual ~Implement() {}
    virtual void operation() = 0;

protected:
    Implement() {}
};

class ConcreteImplementA : public Implement // 具体实现细节类A
{
public:
    virtual void operation() override//如果派生类在虚函数声明时使用了override描述符，那么该函数必须重载其基类中的同名函数，否则代码将无法通过编译。
    {
        cout << "ConcreteImplementA::operation()!" << endl;
    }
};

class RefinedAbstraction : public Abstraction // 具体抽象细节类
{
public:
    RefinedAbstraction(Implement* implement)
    {
        this->implement = implement;
    }
    virtual void operation() override
    {
        cout << "RefinedAbstraction::operation()!" << endl;
        implement->operation();
    }

private:
    Implement* implement;
};

void doBridgeParttern()
{
    //抽象实例调用实现A
    Implement *implement = new ConcreteImplementA();
    Abstraction *abstraction = new RefinedAbstraction(implement);
    abstraction->operation();
    DELETE(implement);
    DELETE(abstraction);
}
//https://blog.csdn.net/naibozhuan3744/article/details/106877284

int main()
{
    doBridgeParttern();
}