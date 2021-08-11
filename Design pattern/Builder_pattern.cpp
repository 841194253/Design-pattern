//
// Created by apple on 8/7/21.
//
//建造者模式:指将一个复杂对象的构造与它的表示分离，使同样的构建过程可以创建不同的表示，这样的设计模式被称为建造者模式。它是将一个复杂的对象分解为多个简单的对象，然后一步一步构建而成。它将变与不变相分离，即产品的组成部分是不变的，但每一部分是可以灵活选择的。
//建造者（Builder）模式由产品、抽象建造者、具体建造者、指挥者等4个要素构成
//结合本次代码可知有产品、抽象建造者、具体建造者、指挥者，产品的创造由后面三个类进行创造，一步步构造而成

#include <iostream>
#include <string>

using namespace std;

//产品
class Product
{
private:
    string partA;
    string partB;
    string partC;
public:
    void setPartA(string partA)
    {
        this->partA = partA;
    }
    void setPartB(string partB)
    {
        this->partB = partB;
    }
    void setPartC(string partC)
    {
        this->partC = partC;
    }
    void Show()
    {
        cout << partA << " " << partB << " " << partC << endl;
    }
};

//抽象建造者
class AbstractBuilder
{
protected:
    Product* product = new Product();
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;

    Product* getResult()
    {
        return product;
    }
};

//具体建造者
class ConcreteBuilder : public AbstractBuilder
{
public:
    virtual void buildPartA()
    {
        product->setPartA("PartA");
    }
    virtual void buildPartB()
    {
        product->setPartB("PartB");
    }
    virtual void buildPartC()
    {
        product->setPartC("PartC");
    }
};

//指挥者
class Director
{
private:
    AbstractBuilder* builder;
public:
    Director(AbstractBuilder* builder)
    {
        this->builder = builder;
    }

    Product* construct()
    {
        builder->buildPartA();
        builder->buildPartB();
        builder->buildPartC();
        return builder->getResult();
    }
};

void test01()
{
    AbstractBuilder* builder = new ConcreteBuilder();
    Director* director = new Director(builder);
    Product* product = director->construct();
    product->Show();

    delete director;
    delete product;
}

int main()
{
    test01();
}
