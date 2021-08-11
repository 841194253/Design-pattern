//
// Created by apple on 8/1/21.
//
//依赖倒置原则的原始定义为：高层模块不应该依赖低层模块，两者都应该依赖其抽象；抽象不应该依赖细节，细节应该依赖抽象。其核心思想是：要面向接口编程，不要面向实现编程。
//结合本次例子，通过抽象工作人员，再细化为为各个功能的工作人员，通过中间函数调用工作人员
#include <iostream>

using namespace std;

//class BankWorker
//{
//public:
//    void SaveService()
//    {
//        cout << "存款" << endl;
//    }
//    void PayService()
//    {
//        cout << "支付" << endl;
//    }
//    void TranferService()
//    {
//        cout << "转账" << endl;
//    }
//};
//
////中层模块
//void DoSaveBussiness(BankWorker* bankWorker)
//{
//    bankWorker->SaveService();
//}
//
//void DoPayBussiness(BankWorker* bankWorker)
//{
//    bankWorker->PayService();
//}
//
//void DoTranferBussiness(BankWorker* bankWorker)
//{
//    bankWorker->TranferService();
//}
//
//void test01()
//{
//    BankWorker* bankWorker = new BankWorker();
//    DoSaveBussiness(bankWorker);
//    DoPayBussiness(bankWorker);
//    DoTranferBussiness(bankWorker);
//}

class AbstractWorker//抽象工作人员
{
public:
    virtual void doBusiness() = 0;
};

class SaveBankWorker : public AbstractWorker//存款人员
{
    virtual void doBusiness()
    {
        cout << "存款" << endl;
    }
};

class PayBankWorker : public AbstractWorker//支付人员
{
    virtual void doBusiness()
    {
        cout << "支付" << endl;
    }
};

class TranferWorker : public AbstractWorker//转账人员
{
    virtual void doBusiness()
    {
        cout << "转账" << endl;
    }
};

//中层业务
void doNewBusiness(AbstractWorker* abstractWorker)//传入抽象类
{
    abstractWorker->doBusiness();
}

void test02()
{
    AbstractWorker* transfer = new TranferWorker;//声明抽象类，再通过抽象类的派生类进行具体化
    doNewBusiness(transfer);//根据传入的对象，完成相应的函数

    delete transfer;
}

int main()
{
    test02();
}