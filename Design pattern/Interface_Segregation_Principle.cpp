//
// Created by apple on 8/11/21.
//
//接口隔离原则”的定义是：客户端不应该被迫依赖于它不使用的方法.该原则还有另外一个定义：一个类对另一个类的依赖应该建立在最小的接口上。

#include <iostream>

using namespace std;

//输入模块接口
class InputModule {
public:
        void insert()
        {

        }
        void remove()
        {

        }
        void modify()
        {

        }
};
//统计模块接口
class CountModule {
public:
        void countTotalScore()
        {

        }
        void countAverage()
        {

        }
};
//打印模块接口
class PrintModule {
public:
        void printStuInfo()
        {

        }
        void queryStuInfo()
        {

        }
};

class StuScoreList : public InputModule,public CountModule,public PrintModule
{
public:
    StuScoreList(CountModule *pModule) {}
    StuScoreList(InputModule *pModule) {}
    StuScoreList(PrintModule *pModule) {}

    static StuScoreList getInputModule() {
        return (StuScoreList)new InputModule();
    }
    static StuScoreList getCountModule() {
        return (StuScoreList)new CountModule();
    }
    static StuScoreList getPrintModule() {
        return  (StuScoreList)new PrintModule();
    }
    void insert() {
        cout << "输入模块的insert()方法被调用！" << endl;
    }
    void remove() {
        cout <<"输入模块的delete()方法被调用！" << endl;
    }
    void modify() {
        cout <<"输入模块的modify()方法被调用！" << endl;
    }
    void countTotalScore() {
        cout <<"统计模块的countTotalScore()方法被调用！" << endl;
    }
    void countAverage() {
        cout <<"统计模块的countAverage()方法被调用！" << endl;
    }
    void printStuInfo() {
        cout <<"打印模块的printStuInfo()方法被调用！" << endl;
    }
    void queryStuInfo() {
        cout <<"打印模块的queryStuInfo()方法被调用！" << endl;
    }

    StuScoreList() {}
};

int main()
{
    StuScoreList* scoreList = new StuScoreList();
    InputModule* input = scoreList->getInputModule();
    CountModule* count = scoreList->getCountModule();
    PrintModule* print = scoreList->getPrintModule();
    input->insert();
    count->countTotalScore();
    print->printStuInfo();
}