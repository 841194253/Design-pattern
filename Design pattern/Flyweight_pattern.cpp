//
// Created by apple on 8/10/21.
//
//享元模式：运用共享技术来有效地支持大量细粒度对象的复用。它通过共享已经存在的对象来大幅度减少需要创建的对象数量、避免大量相似类的开销，从而提高系统资源的利用率。
//定义一个抽象接口类IFlyweight，定义一个接口函数operation()用于子类继承；（抽象类）
//定义一个实现享元接口类ConcreteFlyweight，重写接口函数operation()；（具体构建器）
//定义一个工厂类Factory，主要功能是创建和获取享元对象，一次只能获取一个对象；


#include <iostream>
#include <map>
#include <string>

using namespace std;

#define DELETE(pointer) delete pointer; pointer=nullptr

class IFlyweight // 抽象接口
{
public:
    IFlyweight() {}
    virtual ~IFlyweight() {}

    virtual void operation() = 0;
};

class ConcreteFlyweight : public IFlyweight // 共享部分
{
public:
    ConcreteFlyweight() {}
    ~ConcreteFlyweight() {}

    void operation() override { cout << "ConcreteFlyweight" << endl; }
};

class UnsharedFlyweight : public IFlyweight // 共享部分
{
public:
    UnsharedFlyweight() {}
    ~UnsharedFlyweight() {}

    void operation() override { cout << "UnsharedFlyweight" << endl; }
};

class Factory //享元工厂，创建和返回享元对象
{
public:
    IFlyweight* getFlyweight(string type) {
        if (!flyweights.count(type)) // 如果不存在，则创建一个共享模块；存在则不用创建直接返回对象
            flyweights[type] = new ConcreteFlyweight();
        return flyweights.at(type);
    }

    size_t size() { return flyweights.size(); }

private:
    map<string, IFlyweight*> flyweights;
};

void doFlyweightPattern()
{
    Factory *factory = new Factory(); //创建享元工厂
    IFlyweight *f1 = factory->getFlyweight(string("f1")); //获取f1的共享部分，非共享部分外部获取，不在factory获取
    IFlyweight *f2 = factory->getFlyweight(string("f2"));
    IFlyweight *f3 = factory->getFlyweight(string("f3"));

    f1->operation();
    f2->operation();
    f3->operation();

    cout << "factory->size()==" << factory->size() << endl;

    DELETE(f3);
    DELETE(f2);
    DELETE(f1);
    DELETE(factory);
}

int main()
{
    doFlyweightPattern();
}
