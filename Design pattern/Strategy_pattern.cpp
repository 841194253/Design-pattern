//
// Created by apple on 8/4/21.
//
//策略模式：该模式定义了一系列算法，并将每个算法封装起来，使它们可以相互替换，且算法的变化不会影响使用算法的客户。策略模式属于对象行为模式，它通过对算法进行封装，把使用算法的责任和算法的实现分割开来，并委派给不同的对象对这些算法进行管理。
//结合本次代码可进行分析，主要分为武器和角色，武器又分文小刀和AK47，角色可以使用AK47和小刀


#include <iostream>

using namespace std;

class WeaponStrategy//武器部署
{
public:
    virtual void UseWeapon() = 0;
};

class Knife : public WeaponStrategy//小刀类
{
public:
    virtual void UseWeapon()
    {
        cout << "knife" << endl;
    }
};

class AK47 : public WeaponStrategy//AK47类
{
public:
    virtual void UseWeapon()
    {
        cout << "AK47" << endl;
    }
};

class Character//角色类
{
public:
    void setWeapon(WeaponStrategy* weaponStrategy)
    {
        this->weaponStrategy = weaponStrategy;
    }
    void ThrowWeapon()
    {
        this->weaponStrategy->UseWeapon();
    }
public:
    WeaponStrategy* weaponStrategy;
};

void test01()
{
    Character* character = new Character();//先声明并初始化角色
    WeaponStrategy* weaponStrategy = new Knife();//声明初始化武器类小刀

    character->setWeapon(weaponStrategy);//装备武器
    character->ThrowWeapon();//使用武器

    delete character;
    delete weaponStrategy;
}

int main()
{
    test01();
}