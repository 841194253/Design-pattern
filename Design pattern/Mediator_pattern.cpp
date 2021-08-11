//
// Created by apple on 8/11/21.
//
//中介者模式：定义一个中介对象来封装一系列对象之间的交互，使原有对象之间的耦合松散，且可以独立地改变它们之间的交互。中介者模式又叫调停模式，它是迪米特法则的典型应用。
//中介者模式包含以下主要角色。
//抽象中介者角色：它是中介者的接口，提供了同事对象注册与转发同事对象信息的抽象方法。
//具体中介者角色：实现中介者接口，定义一个List来管理同事对象，协调各个同事角色之间的交互关系，因此它依赖于同事角色。
//抽象同事类角色：定义同事类的接口，保存中介者对象，提供同事对象交互的抽象方法，实现所有相互影响的同事类的公共功能。
//具体同事类角色：是抽象同事类的实现者，当需要与其他同事对象交互时，由中介者对象负责后续的交互。

#include <iostream>
#include <vector>

using namespace std;

#define DELETE(pointer) delete pointer; pointer=nullptr

class Colleague;

class IMediator //抽象产品
{
protected:
    vector<Colleague *> colleagues; // 维护和封装一系列同事对象

public:
    IMediator() : colleagues(0) {}
    virtual ~IMediator() {}

    virtual void add(Colleague *colleague) = 0; // 增加同事类
    virtual void send(Colleague *colleague) = 0; // 转发同事类消息

};

class Colleague
{
protected:
    IMediator *mediator; // 中介者接口

public:
    Colleague(IMediator *mediator) :mediator(mediator) {}
    virtual void notify() = 0; // 要发消息的内容
    virtual void send() = 0; // 消息发布到中介者动作

};

class ConcreteColleague1 : public Colleague //具体同事1
{
public:
    ConcreteColleague1(IMediator *mediator) : Colleague(mediator) {}
    virtual void notify() { cout << "我是租客，要租房!" << endl; }
    virtual void send() { mediator->send(this); }
};

class ConcreteColleague2 : public Colleague //具体同事2
{
public:
    ConcreteColleague2(IMediator *mediator) : Colleague(mediator) {}
    virtual void notify() { cout << "我是房东，要出租房!" << endl; }
    virtual void send() { mediator->send(this); }
};

class ConcreteMediator : public IMediator //具体中介者，要放在具体类同事1和具体同事2的后面，否则调用notify函数会报错没定义
{
public:
    void add(Colleague *colleague) override { colleagues.push_back(colleague); }
    void send(Colleague *colleague) override {
        for (auto *iter : colleagues)
            if (iter == colleague)
            {
                iter->notify();
                break;
            }
    }
};

void doMediatorPattern()
{
    // 初始化中介者对象、同事1对象、同事2对象
    IMediator *mediator = new ConcreteMediator();
    Colleague *colleague1 = new ConcreteColleague1(mediator);
    Colleague *colleague2 = new ConcreteColleague2(mediator);
    mediator->add(colleague1); // 中介者把同事加入同事集合
    mediator->add(colleague2);

    colleague1->send(); // 租客在中介者发布租房信息
    colleague2->send(); // 房东也在中介者发布出租房信息

    DELETE(colleague2);
    DELETE(colleague1);
    DELETE(mediator);
}

int main()
{
    doMediatorPattern();
}
