//
// Created by apple on 8/10/21.
//
//状态模式：对有状态的对象，把复杂的“判断逻辑”提取到不同的状态对象中，允许状态对象在其内部状态发生改变时改变其行为。
//结合本代码可以看出是模式AB的互相转换

#include <iostream>

using namespace std;

class Context;
class ConcreteStateA;
class ConcreteStateB;
class State;

class State {
public:
    virtual void Handle(Context *context);
};

class Context
{
private:
    State *state;

public:
    Context()
    {
        state = new ConcreteStateA();
    }

    void setState(State *state)
    {
        this->state = state;
    }

    State getState()
    {
        return (*state);
    }

    void Handle()
    {
        state->Handle(this);
    }
};

//class ConcreteStateA : public State
//{
//public:
//    void Handle(Context *context) override
//    {
//        cout << "A" << endl;
//        context->setState(new ConcreteStateB());
//    }
//};

class ConcreteStateB : public State
{
public:
    void Handle(Context *context) override
    {
        cout << "B" << endl;
        context->setState(new ConcreteStateA());
    }
};

class ConcreteStateA : public State
{
public:
    void Handle(Context *context) override
    {
        cout << "A" << endl;
        context->setState(new ConcreteStateB());
    }
};

int main()
{
    Context* context = new Context();    //创建环境
    context->Handle();    //处理请求
    context->Handle();
    context->Handle();
    context->Handle();

    delete context;
}