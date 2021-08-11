//
// Created by apple on 8/1/21.
//
//开闭原则 对扩展开放，对修改关闭，增加功能是通过增加代码来实现，而不是去修改源代码
//结合本次例子就是，先声明抽象的计算方法，再通过继承实现各个计算方法

#include <iostream>

using namespace std;

//抽象类
class AbstractCaculator{
public:
    virtual int getResult() = 0;
    virtual void setOperatorNumber(int a,int b) = 0;
};

//加法计算器
class PlusCaculator : public AbstractCaculator{
public:
    virtual void setOperatorNumber(int a,int b)
    {
        this->mA = a;
        this->mB = b;
    }
    virtual int getResult()
    {
        return mA + mB;
    }

public:
    int mA;
    int mB;
};

//减法计算器
class MinuteCaculator : public AbstractCaculator{
public:
    virtual void setOperatorNumber(int a,int b)
    {
        this->mA = a;
        this->mB = b;
    }
    virtual int getResult()
    {
        return mA - mB;
    }

public:
    int mA;
    int mB;
};

//乘法计算器
class MultiplyCaculator : public AbstractCaculator{
public:
    virtual void setOperatorNumber(int a,int b)
    {
        this->mA = a;
        this->mB = b;
    }
    virtual int getResult()
    {
        return mA * mB;
    }

public:
    int mA;
    int mB;
};

//除法计算器
class DivisionCaculator : public AbstractCaculator{
public:
    virtual void setOperatorNumber(int a,int b)
    {
        this->mA = a;
        this->mB = b;
    }
    virtual int getResult()
    {
        return mA / mB;
    }

public:
    int mA;
    int mB;
};

//取模计算器
class ModularCaculator : public AbstractCaculator{
public:
    virtual void setOperatorNumber(int a,int b)
    {
        this->mA = a;
        this->mB = b;
    }
    virtual int getResult()
    {
        return mA % mB;
    }

public:
    int mA;
    int mB;
};

void test01()
{
    AbstractCaculator *caculator = new PlusCaculator;
    caculator->setOperatorNumber(10,20);
    cout << caculator->getResult() << endl;

    delete caculator;

    caculator = new MinuteCaculator;
    caculator->setOperatorNumber(10,20);
    cout << caculator->getResult() << endl;

    delete caculator;
}

int main()
{
    test01();
}

