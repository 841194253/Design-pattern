//
// Created by apple on 8/8/21.
//
//原型模式：用一个已经创建的实例作为原型，通过复制该原型对象来创建一个和原型相同或相似的新对象。在这里，原型实例指定了要创建的对象的种类。用这种方式创建对象非常高效，根本无须知道对象创建的细节。
//类似拷贝构造函数，有一点点像move函数，但不同的是不需要转移所有权，又像浅拷贝和深拷贝
//本次代码要仿写Java中clone函数，同时也写出了重载运算符=来进行深拷贝
//原型模式的克隆分为浅克隆和深克隆。
//浅克隆：创建一个新对象，新对象的属性和原来对象完全相同，对于非基本类型属性，仍指向原有属性所指向的对象的内存地址。
//深克隆：创建一个新对象，属性中引用的其他对象也会被克隆，不再指向原有对象地址。
//结合本次代码只有一个A类，A类里边有构造函数、还有仿Java clone()函数的函数、重载后的赋值函数用来测试和clone()函数的深拷贝功能，用布尔类型来测试对象的地址是否相同


#include <iostream>

using namespace std;

class A
{
public:
    A()
    {
        cout << "A" << endl;
        b = new int();
    }

    A* clone() const
    {
        return new A(*this);
    }

    A& operator= (A &a) {
        if (this != &a)
        {
            if (b != NULL)
            {
                delete b;
                b = NULL;
            }
            b = new int();
            a.b = b;
        }
        return *this;
    }

    ~A()
    {
        delete b;
    }

public:
    const int* b;
    const int ac = 1;
};

int main()
{
    A* a1 = new A();
    A* a2;
    const A* a3;
    int c = 4;

    a1->b = &c;
    a2 = a1;
    bool a21 = (a2 == a1);//true
    cout << a21 << endl;
    cout << *a2->b << endl;
    cout << endl;

    a3 = a1->clone();
    bool a13 = (a3 == a1);//false
    cout << a13 << endl;
    cout << *a3->b << endl;
    cout << endl;

    a3 = &*a1;
    bool b1 = (a3==a1);//true
    cout << b1 << endl;

    delete &a1;//0x7ffeec330840
    //delete a2;
    //delete a3;
}