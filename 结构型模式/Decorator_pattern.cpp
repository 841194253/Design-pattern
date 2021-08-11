//
// Created by apple on 8/7/21.
//
//装饰器模式:动态给一个类增加功能
//指在不改变现有对象结构的情况下，动态地给该对象增加一些职责（即增加其额外功能）的模式，它属于对象结构型模式。
//结合本次代码，又英雄类和装备类，装备可以给予英雄加成

#include <iostream>

using namespace std;

class AbstractHero//抽象英雄类
{
public:
    virtual void ShowStatus() = 0;

public:
    int HP;
    int MP;
    int AT;
    int DF;
};

class HeroA : public AbstractHero//具体英雄A
{
public:
    HeroA()
    {
        HP = 0;
        MP = 0;
        AT = 0;
        DF = 0;
    }
    virtual void ShowStatus()
    {
        cout << HP << " " << MP << " " << AT << " " << DF << endl;
    }

};

class AbstractEquipment : public AbstractHero//抽象装备类
{
public:
    AbstractEquipment(AbstractHero* hero)
    {
        this->hero = hero;
    }
    virtual void ShowStatus()
    {
        cout << HP << " " << MP << " " << AT << " " << DF << endl;
    }
public:
    AbstractHero* hero;
};

class KuangTuEquipment : public AbstractEquipment//狂徒装备
{
public:
    KuangTuEquipment(AbstractHero* hero) : AbstractEquipment(hero){}
    void AddKuangTu()
    {
        cout << "add kuangtu" << endl;
        this->HP = this->hero->HP;
        this->MP = this->hero->MP;
        this->AT = this->hero->AT;
        this->DF = this->hero->DF + 30;

        delete this->hero;
    }
    virtual void ShowStatus()
    {
        AddKuangTu();
        cout << HP << " " << MP << " " << AT << " " << DF << endl;
    }

};

class WuJinEquipment : public AbstractEquipment//无尽装备
{
public:
    void AddWuJin()
    {
        cout << "add WuJin" << endl;
        this->HP = this->hero->HP;
        this->MP = this->hero->MP;
        this->AT = this->hero->AT + 30;
        this->DF = this->hero->DF;
    }
    virtual void ShowStatus()
    {
        AddWuJin();
        cout << HP << " " << MP << " " << AT << " " << DF << endl;
    }

public:
    WuJinEquipment(AbstractHero* hero) : AbstractEquipment(hero){}
};

void test01()
{
    AbstractHero* hero = new HeroA();//声明英雄A
    hero->ShowStatus();//展示英雄状态
    cout << "____________" << endl;

    hero = new KuangTuEquipment(hero);
    hero->ShowStatus();

    cout << "____________" << endl;

    hero = new WuJinEquipment(hero);
    hero->ShowStatus();

    delete hero;

}

int main()
{
    test01();
}