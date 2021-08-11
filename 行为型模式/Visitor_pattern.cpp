//
// Created by apple on 8/10/21.
//
//访问者（Visitor）模式的定义：将作用于某种数据结构中的各元素的操作分离出来封装成独立的类，使其在不改变数据结构的前提下可以添加作用于这些元素的新的操作，为数据结构中的每个元素提供多种访问方式。它将对数据的操作与数据结构进行分离，是行为类模式中最复杂的一种模式。
//访问者模式的核心思想是用一个访问者对象访问目标对象的成员函数或者成员变量，前提是不改变目标类的结构。代码实现的核心思想是在访问者类Visitor通过接口函数Visitor::visitorElement(ElementA*)访问目标对象成员函数，然后目标类Element通过接口函数Element::accept(Visitor* visitor){visitor->visitorElementA(this);}反射自动化调用访问自身并且将自身指针this传递给访问者访问接口Visitor::visitorElement(this)。

#include<iostream>
#include<vector>

using namespace std;

#define DELETE(pointer) delete (pointer); (pointer)=nullptr

class ElementA;

class Visitor //抽象访问者
{
public:
    virtual ~Visitor() {}

    virtual void visitorElementA(ElementA *elementA) = 0;
};

class Visitor1 : public Visitor
{
public:
    void visitorElementA(ElementA *elementA) override;
};

class Element
{
public:
    virtual ~Element() {}

    virtual void accept(Visitor *visitor) = 0;
};

class ElementA : public Element
{
public:
    void accept(Visitor *visitor) override { visitor->visitorElementA(this); }

    void operation() { cout << "ElementA::operation()" << endl; }
};

void Visitor1::visitorElementA(ElementA *elementA)
{
    cout << "Visitor1::visitorElementA()" << endl;
    elementA->operation();
}

class StructObject
{
public:
    void pushElement(Element *element) { elements.push_back(element); }
    void removeElement(Element *element)
    {
        auto it = std::find(elements.begin(), elements.end(), element);
        if (it != elements.end())
        {
            elements.erase(it);
        }
    }
    void accept(Visitor *visitor)
    {
        for (auto *element : elements)
        {
            element->accept(visitor);
        }
    }

private:
    vector<Element*> elements;
};

void doVisitorPattern()
{
    ElementA *elementA = new ElementA();
    Visitor1 *visitor1 = new Visitor1();
    StructObject *object = new StructObject();

    // 访问者visitor1访问原件ElementA、ElementB里面内容，比如operation()
    object->pushElement(elementA);
    object->accept(visitor1);

    // 访问者visitor2访问原件ElementB里面内容，比如operation()
    object->removeElement(elementA);

    DELETE(visitor1);
    DELETE(elementA);
    DELETE(object);
}

int main()
{
    doVisitorPattern();
}
