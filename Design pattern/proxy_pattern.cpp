//
// Created by apple on 8/3/21.
//
//代理模式：提供一种代理来控制对其他对象的访问
//在有些情况下，一个客户不能或者不想直接访问另一个对象，这时需要找一个中介帮忙完成某项任务，这个中介就是代理对象。例如，购买火车票不一定要去火车站买，可以通过 12306 网站或者去火车票代售点买。又如找女朋友、找保姆、找工作等都可以通过找中介完成。

#include <iostream>

using namespace std;

class AbstractCommonInterface
{
public:
    virtual void run() = 0;
};

class MySystem : public AbstractCommonInterface
{
public:
    virtual void run()
    {
        cout << "System out" << endl;
    }
};

//必须要有权限认证才能启动

class MySystemProxy : public AbstractCommonInterface
{
public:
    MySystemProxy(string name,string pad)
    {
        this->user = name;
        this->pward = pad;
        mySystem = new MySystem();
    }
    bool CheckUserNameAndPassword()
    {
        if (user == "admin" && pward == "admin")
        {
            return true;
        } else
        {
            return false;
        }
    }
    virtual void run()
    {
        if (CheckUserNameAndPassword())
        {
            this->mySystem->run();
        } else
        {
            cout << "用户名或密码错误" << endl;
        }
    }
    ~MySystemProxy()
    {
        if (mySystem != NULL)
        {
            delete mySystem;
        }
    }

private:
    MySystem* mySystem;
    string user;
    string pward;
};

int main()
{
    //MySystem* mySystem = new MySystem();
    //mySystem->run();
    MySystemProxy* mySystemProxy = new MySystemProxy("admin","root");
    mySystemProxy->run();

    delete mySystemProxy;
}