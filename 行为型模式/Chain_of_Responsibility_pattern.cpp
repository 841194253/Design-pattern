//
// Created by apple on 8/11/21.
//

//责任链模式的定义：为了避免请求发送者与多个请求处理者耦合在一起，于是将所有请求的处理者通过前一对象记住其下一个对象的引用而连成一条链；当有请求发生时，可将请求沿着这条链传递，直到有对象处理它为止。
//职责链模式主要包含以下角色。
//抽象处理者角色：定义一个处理请求的接口，包含抽象处理方法和一个后继连接。
//具体处理者角色：实现抽象处理者的处理方法，判断能否处理本次请求，如果可以处理请求则处理，否则将该请求转给它的后继者。
//客户类角色：创建处理链，并向链头的具体处理者对象提交请求，它不关心处理细节和请求的传递过程。

#include <iostream>
#include <string>

using namespace std;

//抽象处理者
class Handler
{
private:
    Handler* next;
public:
    void SetNext(Handler* next)
    {
        this->next = next;
    }
    Handler* GetNext()
    {
        return next;
    }
    virtual void HandleRequest(string request) = 0;
};

//具体处理者1
class ConcreteHandler1 : public Handler
{
public:
    void HandleRequest(string request) override
    {
        if (request == "one")
        {
            cout << "1 process" << endl;
        }
        else
        {
            if (GetNext() != NULL)
            {
                GetNext()->HandleRequest(request);
            }
            else
            {
                cout << "Nobody" << endl;
            }
        }
    }
};

//具体处理者2
class ConcreteHandler2 : public Handler
{
public:
    void HandleRequest(string request) override
    {
        if (request == "two")
        {
            cout << "2 process" << endl;
        }
        else
        {
            if (GetNext() != NULL)
            {
                GetNext()->HandleRequest(request);
            }
            else
            {
                cout << "Nobody" << endl;
            }
        }
    }
};

int main()
{
    //组装责任链
    Handler* handler1 = new ConcreteHandler1();
    Handler* handler2 = new ConcreteHandler2();
    handler1->SetNext(handler2);
    //提交请求
    handler1->HandleRequest("two");
}