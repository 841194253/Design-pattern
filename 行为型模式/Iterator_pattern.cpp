//
// Created by apple on 8/11/21.
//
//迭代器模式：提供一个对象来顺序访问聚合对象中的一系列数据，而不暴露聚合对象的内部表示。迭代器模式是一种对象行为型模式
//迭代器模式主要包含以下角色。
//抽象聚合角色：定义存储、添加、删除聚合对象以及创建迭代器对象的接口。
//具体聚合角色：实现抽象聚合类，返回一个具体迭代器的实例。
//抽象迭代器角色：定义访问和遍历聚合元素的接口，通常包含 hasNext()、first()、next()等方法。
//具体迭代器角色：实现抽象迭代器接口中所定义的方法，完成对聚合对象的遍历，记录遍历的当前位置。
//迭代器模式的核心思想是用一个外部接口类来遍历聚合对象的每一个元素而不暴露聚合对象的内部细节。代码实现的核心思想是内部聚合类创建返回一个迭代器指针和一些操作聚合容器的函数；迭代器也通过维护一个聚合类的指针，聚合类指针对象的传入用构造函数，然后通过该聚合指针访问聚合对象的容器的每一个元素。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define DELETE(pointer) delete (pointer); (pointer)=nullptr

class Iterator//迭代器类
{
public:
    virtual ~Iterator() { cout << "~Iterator()" << endl; }
    virtual string first() = 0;
    virtual string next() = 0;
    virtual string current() = 0;
    virtual bool isEnd() = 0;
};

class Aggregate//抽象聚合类
{
public:
    virtual ~Aggregate(){ cout << "~Aggregate()" << endl; }
    virtual void push(const string& str) = 0;
    virtual string pop(size_t index) = 0;
    virtual const size_t Count() const = 0;
    virtual Iterator* createIterator() = 0;
};

class ConcreteIterator : public Iterator//具体迭代器
{
private:
    Aggregate *aggregate;
    size_t index;
public:
    ConcreteIterator(Aggregate *aggregate) : aggregate(aggregate), index(0) {}
    ~ConcreteIterator() { cout << "~ConcreteIterator()" << endl; }
    string first() override
    {
        if (aggregate->Count() == 0)
            return string();
        return aggregate->pop(0);
    }
    string next() override
    {
        ++index;
        if (index >= aggregate->Count())
            return string();
        return aggregate->pop(index);
    }
    string current() override
    {
        if (index >= aggregate->Count())
            return string();
        return aggregate->pop(index);
    }
    bool isEnd() override { return index >= aggregate->Count() || index < 0; }
};

class ConcreteAggregate : public Aggregate//具体聚合类
{
private:
    vector<string> strs;
public:
    ~ConcreteAggregate() { cout << "~ConcreteAggregate()" << endl; }
    void push(const string& str) override { return strs.push_back(str); }
    string pop(size_t index) override
    {
        if (index >= strs.size())
            return string();
        return strs[index];
    }
    const size_t Count() const override { return strs.size(); }
    Iterator* createIterator() { return new ConcreteIterator(this); }
};


void print(string str)
{
    cout << str << endl;
}

void doIteratorPattern()
{
    Aggregate *aggregate = new ConcreteAggregate();
    aggregate->push("str1");
    aggregate->push("str2");
    aggregate->push("str3");

    Iterator *iter = aggregate->createIterator();
    print(iter->first());
    while (!iter->isEnd())
    {
        print(iter->next());
    }

    DELETE(iter);
    DELETE(aggregate);
}

int main()
{
    doIteratorPattern();
}
