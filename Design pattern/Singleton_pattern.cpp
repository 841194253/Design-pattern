//
// Created by apple on 8/3/21.
//
//单例模式:指一个类只有一个实例，且该类能自行创建这个实例的一种模式。
//构造单例步骤：1.构造函数私有化 2.增加静态私有当前类的指针变量 3.提供一个静态对外接口可以让用户获得单例对象
//单例分为：懒汉式、饿汉式
//单例模式的优点：单例模式可以保证内存里只有一个实例，减少了内存的开销。可以避免对资源的多重占用。单例模式设置全局访问点，可以优化和共享资源的访问。
//单例模式的缺点：
//单例模式一般没有接口，扩展困难。如果要扩展，则除了修改原来的代码，没有第二种途径，违背开闭原则。
//在并发测试中，单例模式不利于代码调试。在调试过程中，如果单例中的代码没有执行完，也不能模拟生成一个新的对象。
//单例模式的功能代码通常写在一个类中，如果功能设计不合理，则很容易违背单一职责原则。
//这个单例模式面试问的还挺多的，要注意！！！
//饿汉式和懒汉式区别：1.懒汉式在对外调用接口的函数里要有判断类内静态对象变量是否为空。饿汉式不需要判断。2.饿汉式在类外初始化对象变量需要新new一个，懒汉式直接在接口函数的if里边直接new，类外初始化为NULL
#include <iostream>

using namespace std;

class A
{
private:
    A()
    {
        a = new A;
    }

public:
    static A* getInstance()
    {
        return a;
    }

public:
    static A* a;
};

A* A::a = NULL;

//懒汉式
//懒汉式碰见多线程，线程不安全
class Singleton_lazy
{
private:
    Singleton_lazy(){cout << "懒汉式" << endl;}

public:
    static Singleton_lazy* getInstance()
    {
        if (singletonLazy == NULL)
        {
            singletonLazy == new Singleton_lazy;
        }
        return singletonLazy;
    }
private:
    static Singleton_lazy* singletonLazy;
};
//类外初始化
Singleton_lazy* Singleton_lazy::singletonLazy = NULL;

//饿汉式
//饿汉式是线程安全的
class Singleton_hungry
{
private:
    Singleton_hungry(){cout << "饿汉式" << endl;}

public:
    static Singleton_hungry* getInstance()
    {
        return singletonHungry;
    }

#if 0//对于单例方法的对象，不可以随意清除
    static void FreeSpace()
    {
        if (singletonHungry != NULL)
        {
            delete singletonHungry;
        }
    }
#endif
    class Garbo//可以回收单例对象的空间,一般是不需要考虑回收空间的
    {
    public:
        ~Garbo()
        {
            if (singletonHungry != NULL)
            {
                delete singletonHungry;
            }
        }
    };
private:
    static Singleton_hungry* singletonHungry;
    static Garbo garbo;
};

Singleton_hungry* Singleton_hungry::singletonHungry = new Singleton_hungry;


void test01()
{
    Singleton_lazy* p1 = Singleton_lazy::getInstance();
    Singleton_lazy* p2 = Singleton_lazy::getInstance();

    if (p1 == p2)
    {
        cout << "指针指向同一块内存" << endl;
    } else
    {
        cout << "指针没有指向同一内存" << endl;
    }

    Singleton_hungry* p3 = Singleton_hungry::getInstance();
    Singleton_hungry* p4 = Singleton_hungry::getInstance();
    if (p3 == p4)
    {
        cout << "指针指向同一块内存" << endl;
    }
    else
    {
        cout << "指针没有指向同一内存" << endl;
    }

}

void test02()
{
    Singleton_hungry::Garbo* garbo = new Singleton_hungry::Garbo();
    //delete garbo;
}

int main()
{
    //A a;//A* a = new A();
    //A* a = A::getInstance();
    //A::a = NULL;
    test02();
    test01();

}