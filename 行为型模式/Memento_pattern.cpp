//
// Created by apple on 8/11/21.
//
//备忘录模式：在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态，以便以后当需要时能将该对象恢复到原先保存的状态。
//备忘录模式的主要角色如下。
//发起人角色：记录当前时刻的内部状态信息，提供创建备忘录和恢复备忘录数据的功能，实现其他业务功能，它可以访问备忘录里的所有信息。
//备忘录角色：负责存储发起人的内部状态，在需要的时候提供这些内部状态给发起人。
//管理者角色：对备忘录进行管理，提供保存与获取备忘录的功能，但其不能对备忘录的内容进行访问与修改。
//结合本次代码可知，有备忘录、发起人、管理者

#include <iostream>
#include <string>

#define DELETE(pointer) delete(pointer); pointer = nullptr

using namespace std;

//备忘录
class Memento
{
private:
    string state;
public:
    Memento(string state)
    {
        this->state = state;
    }
    Memento() {}
    void setState(string state)
    {
        this->state = state;
    }
    string getState()
    {
        return state;
    }
};

//发起人
class Originator
{
private:
     string state;
public:
    void setState(string state)
    {
        this->state = state;
    }
    string getState()
    {
        return state;
    }
    Memento* createMemento()
    {
        return new Memento(state);
    }
    void restoreMemento(Memento* m)
    {
        this->setState(m->getState());
    }
};

//管理者
class Caretaker
{
public:
    void setMemento(Memento* memento)
    {
        this->memento = memento;
    }
    Memento* getMemento()
    {
        return memento;
    }
    Caretaker(){}
    ~Caretaker()
    {
        delete memento;
    }
private:
     Memento* memento;
};

void test01()
{
    Originator* originator = new Originator();
    Caretaker* caretaker = new Caretaker();

    originator->setState("S0");
    cout << "1 " << originator->getState() << endl;
    caretaker->setMemento(originator->createMemento());
    originator->setState("S1");
    cout << "2 " << originator->getState() << endl;
    originator->restoreMemento(caretaker->getMemento());
    cout << "3 " << originator->getState() << endl;

    DELETE(originator);
    DELETE(caretaker);
}

int main()
{
    test01();
}