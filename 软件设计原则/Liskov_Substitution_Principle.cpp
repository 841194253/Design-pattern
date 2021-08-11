//
// Created by apple on 8/11/21.
//
//里氏替换原则通俗来讲就是：子类可以扩展父类的功能，但不能改变父类原有的功能。也就是说：子类继承父类时，除添加新的方法完成新增功能外，尽量不要重写父类的方法。


#include <iostream>

using namespace std;

class Bird
{
protected:
    double flyspeed;
public:
    void SetSpeed(double speed)
    {
        this->flyspeed = speed;
    }
    double getFlyTime(double distance) {
        return (distance / flyspeed);
    }
};

class Swallow : public Bird
{

};

class BrownKiwi : public Bird
{
public:
    void SetSpeed(double speed)
    {
        flyspeed = 0;
    }
};

int main()
{
    Bird* bird1 = new Swallow();
    Bird* bird2 = new BrownKiwi();

    bird1->SetSpeed(120);
    bird2->SetSpeed(0);

    cout << "300km Time" << endl;
    try {
        cout << bird1->getFlyTime(300) << endl;
        cout << bird2->getFlyTime(300) << endl;
    }
    catch (...) {
        cout << "error" << endl;
    }
}
