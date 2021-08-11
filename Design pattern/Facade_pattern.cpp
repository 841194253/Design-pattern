//
// Created by apple on 8/4/21.
//
//外观模式
//外观（Facade）模式又叫作门面模式，是一种通过为多个复杂的子系统提供一个一致的接口，而使这些子系统更加容易被访问的模式。该模式对外有一个统一接口，外部应用程序不用关心内部子系统的具体细节，这样会大大降低应用程序的复杂度，提高了程序的可维护性。
//结合本次代码可知又TV、Light、Audio、Mircophone、DVD、Game基础类
//想要进入KTV模式，就要调用相应的基础类的开关函数，KTVMode就可以一次性调用，不会很麻烦，只需要提供一个接口函数就可以

#include <iostream>

using namespace std;

class TV
{
public:
    void On()
    {
        cout << "TV On" << endl;
    }
    void Off()
    {
        cout << "TV Off" << endl;
    }
};

class Light
{
public:
    void On()
    {
        cout << "light On" << endl;
    }
    void Off()
    {
        cout << "light Off" << endl;
    }
};

class Audio
{
public:
    void On()
    {
        cout << "audio On" << endl;
    }
    void Off()
    {
        cout << "audio Off" << endl;
    }
};

class Mircophone
{
public:
    void On()
    {
        cout << "mircophone On" << endl;
    }
    void Off()
    {
        cout << "mircophone Off" << endl;
    }
};

class DVD
{
public:
    void On()
    {
        cout << "DVD On" << endl;
    }
    void Off()
    {
        cout << "DVD Off" << endl;
    }
};

class Game
{
public:
    void On()
    {
        cout << "game On" << endl;
    }
    void Off()
    {
        cout << "game Off" << endl;
    }
};

class KTVMode {
public:
    KTVMode() {
        tv = new TV();
        light = new Light();
        audio = new Audio();
        mircophone = new Mircophone();
        dvd = new DVD();
    }

    void OnKTV()
    {
        tv->On();
        light->Off();
        audio->On();
        mircophone->On();
        dvd->On();
    }

    void OffKTV()
    {
        tv->Off();
        light->On();
        audio->Off();
        mircophone->Off();
        dvd->Off();
    }

    ~KTVMode()
    {
        delete tv;
        delete light;
        delete audio;
        delete mircophone;
        delete dvd;
    }

private:
    TV* tv;
    Light* light;
    Audio* audio;
    Mircophone* mircophone;
    DVD* dvd;
};

void test01()
{
    KTVMode* ktvMode = new KTVMode();
    ktvMode->OnKTV();
    ktvMode->OffKTV();

    delete ktvMode;
}

int main()
{
    test01();
}