//
// Created by apple on 8/1/21.
//
//迪米特法则 也称为最少知识原则，虽然名字不同，但描述的是同一个规则：一个对象应该对其他对象有最少的了解。通俗地讲，一个类应该对自己需要耦合或者调用的类知道得最少，你（被耦合或调用的类）的内部是如何复杂都和我没关系，那是你的事情，我就知道你提供了这么多的public方法，我就调用这么多，其他的我一概不关心。
//或者可以这么认为，如果两个软件实体无须直接通信，那么就不应当发生直接的相互调用，可以通过第三方转发该调用。其目的是降低类之间的耦合度，提高模块的相对独立性。
//结合本代码的例子房子对与购买者来说是陌生的，但对于中介来说不是陌生的，购买者可以通过中介来认识房子，可以用迪米特法则

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//抽象楼房类
class AbstractBuilding
{
public:
    virtual void sale() = 0;
    virtual string getQuality() = 0;
public:
    string mQulity;
};

class BuildingA : public AbstractBuilding//建筑A类
{
public:
    virtual void sale()
    {
        cout << "A" << mQulity << "0" << endl;
    }
    BuildingA()
    {
        mQulity = "高品质";
    }

    virtual string getQuality()
    {
        return mQulity;
    }

public:
    string mQulity;
};

class BuildingB : public AbstractBuilding//建筑B类
{
public:
    virtual void sale()
    {
        cout << "B" << mQulity << "1" << endl;
    }
    BuildingB()
    {
        mQulity = "低品质";
    }

    virtual string getQuality()
    {
        return mQulity;
    }

public:
    string mQulity;
};

//中介类
class Mediator{
public:
    Mediator()
    {
        AbstractBuilding* building = new BuildingA();
        vbuilding.push_back(building);
        building = new BuildingB();
        vbuilding.push_back(building);
    }

    ~Mediator()
    {
        for(vector<AbstractBuilding*>::iterator it = vbuilding.begin(); it != vbuilding.end(); it++)
        {
            if (*it != NULL)
            {
                delete *it;
            }
        }
    }

    //提供对外接口
    AbstractBuilding* FindMyBuilding(string quality)
    {
        for(vector<AbstractBuilding*>::iterator it = vbuilding.begin(); it != vbuilding.end(); it++)
        {
            if ((*it)->getQuality() == quality)
            {
                return *it;
            }
        }
        return NULL;
    }

public:
    vector<AbstractBuilding*> vbuilding;
};

void test01()//购房者直接见房子来了解房子，这不符合迪米特法则
{
    BuildingA *ba = new BuildingA();
    if (ba->mQulity == "低品质")
    {
        ba->sale();
    }
    cout << endl;
    BuildingB *bb = new BuildingB();
    if (bb->mQulity == "低品质")
    {
        bb->sale();
    }

    delete ba;
    delete bb;
}

void test02()//购房者先认识中介，中介再了解房子，中介再将房子的细节反馈购房者
{
    Mediator* mediator = new Mediator();

    AbstractBuilding* abstractBuilding = mediator->FindMyBuilding("高品质");

    if (abstractBuilding != NULL)
    {
        abstractBuilding->sale();
    } else{
        cout << "null" <<endl;
    }

    delete mediator;
    delete abstractBuilding;
}

int main()
{
    test02();

}