//
// Created by apple on 8/6/21.
//
//命令模式：将一个请求封装为一个对象，使发出请求的责任和执行请求的责任分割开。这样两者之间通过命令对象进行沟通，这样方便将命令对象进行储存、传递、调用、增加与管理。
//结合本次代码，有协议客户类，抽象命令类，具体实现抽象类的类和Server类，所有的命令都可以通过Server进行调用

#include <iostream>
#include <queue>
//#include <zconf.h>
#include<unistd.h>
#include<stdio.h>


using namespace std;

class HandleClientProtocol
{
public:
    void AddMoney()
    {
        cout << "add money user" << endl;
    }

    void AddDiamond()
    {
        cout << "add diamond user" << endl;
    }

    void AddEquipment()
    {
        cout << "add Equipment user" << endl;
    }

    void AddLevel()
    {
        cout << "add level user" << endl;
    }
};

class AbstractCommand
{
public:
    virtual void handle() = 0;//处理请求
};

class AddMoneyCommand : public AbstractCommand
{
public:
    AddMoneyCommand(HandleClientProtocol* handleClientProtocol)
    {
        this->handleClientProtocol = handleClientProtocol;
    }
    virtual void handle()
    {
        this->handleClientProtocol->AddMoney();
    }

public:
    HandleClientProtocol* handleClientProtocol;
};

class AddDiamondCommand : public AbstractCommand
{
public:
    AddDiamondCommand(HandleClientProtocol* handleClientProtocol)
    {
        this->handleClientProtocol = handleClientProtocol;
    }
    virtual void handle()
    {
        this->handleClientProtocol->AddDiamond();
    }

public:
    HandleClientProtocol* handleClientProtocol;
};

class AddEquipmentCommand : public AbstractCommand
{
public:
    AddEquipmentCommand(HandleClientProtocol* handleClientProtocol)
    {
        this->handleClientProtocol = handleClientProtocol;
    }
    virtual void handle()
    {
        this->handleClientProtocol->AddEquipment();
    }

public:
    HandleClientProtocol* handleClientProtocol;
};

class AddLevelCommand : public AbstractCommand
{
public:
    AddLevelCommand(HandleClientProtocol* handleClientProtocol)
    {
        this->handleClientProtocol = handleClientProtocol;
    }
    virtual void handle()
    {
        this->handleClientProtocol->AddLevel();
    }

public:
    HandleClientProtocol* handleClientProtocol;
};

class Server
{
public:
    void AddRequest(AbstractCommand* command)
    {
        q.push(command);
    }

    void StartHandle()
    {
        while (!q.empty())
        {
            sleep(2);

            AbstractCommand* command = q.front();
            command->handle();
            q.pop();
        }
    }
public:
    queue<AbstractCommand*> q;
};

void test01()
{
    HandleClientProtocol* handleClientProtocol = new HandleClientProtocol();
    AbstractCommand* addmoney = new AddMoneyCommand(handleClientProtocol);
    AbstractCommand* adddiamond = new AddDiamondCommand(handleClientProtocol);

    Server* server = new Server();
    server->AddRequest(addmoney);
    server->AddRequest(adddiamond);

    server->StartHandle();

    delete handleClientProtocol;
    delete adddiamond;
    delete addmoney;
    delete server;

}

int main()
{
    test01();
}