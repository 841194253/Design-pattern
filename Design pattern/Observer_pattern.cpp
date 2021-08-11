//
// Created by apple on 8/7/21.
//
//观察者模式指多个对象间存在一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并被自动更新。这种模式有时又称作发布-订阅模式、模型-视图模式，它是对象行为型模式。
//结合本次例子，有英雄类和Boss类，英雄要打boss，boss也能打英雄，当英雄或boss出现伤亡的时候更新状态并通知。

#include <iostream>
#include <list>

using namespace std;

//抽象观察者
class AbstractHero
{
public:
    virtual void Update() = 0;
};

class HeroA : public AbstractHero
{
public:
    HeroA()
    {
        cout << "HeroA attack Master" << endl;
    }
    virtual void Update()
    {
        cout << "HeroA stop attack Master" << endl;
    }
};

class HeroB : public AbstractHero
{
public:
    HeroB()
    {
        cout << "HeroB attack Master" << endl;
    }
    virtual void Update()
    {
        cout << "HeroB stop attack Master" << endl;
    }
};

class HeroC : public AbstractHero
{
public:
    HeroC()
    {
        cout << "HeroC attack Master" << endl;
    }
    virtual void Update()
    {
        cout << "HeroC stop attack Master" << endl;
    }
};

class AbstractBoss
{
public:
    virtual void AddHero(AbstractHero* hero) = 0;
    virtual void DeleteHero(AbstractHero* hero) = 0;
    virtual void Notify() = 0;
};

class BossA : public AbstractBoss
{
public:
    virtual void AddHero(AbstractHero* hero)
    {
        this->hero.push_back(hero);
    }
    virtual void DeleteHero(AbstractHero* hero)
    {
        this->hero.remove(hero);
    }
    virtual void Notify()
    {
        for (list<AbstractHero*>::iterator it = hero.begin(); it != hero.end(); it++) {
            (*it)->Update();
        }
    }

public:
    list<AbstractHero*> hero;
};

void test01()
{
    AbstractHero* hero = new HeroA();
    AbstractHero* hero1 = new HeroB();
    AbstractHero* hero2 = new HeroC();

    AbstractBoss* boss = new BossA();

    boss->AddHero(hero);
    boss->AddHero(hero1);
    boss->AddHero(hero2);

    cout << "heroC Die" <<endl;
    boss->DeleteHero(hero2);

    cout << "boss die" << endl;
    boss->Notify();

    delete hero;
    delete hero1;
    delete hero2;
    delete boss;

}

int main()
{
    test01();
}