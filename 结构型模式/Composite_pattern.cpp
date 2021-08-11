//
// Created by apple on 8/10/21.
//
//组合模式的定义：它是一种将对象组合成树状的层次结构的模式，用来表示“整体-部分”的关系，使用户对单个对象和组合对象具有一致的访问性，属于结构型设计模式。
//总公司有财务部和技术员，分公司也有财务部和技术部，在总公司眼里分公司就是总公司的一个部门

#include<iostream>
#include<string>
#include<vector>
using namespace std;

//抽象总类
class Component
{
public:
    Component(string name):m_name(name){}
    virtual void add(Component *pComponent)=0;
    virtual void del(Component *pComponent)=0;
    virtual void showInfo()=0;

protected:
    string m_name;
};

class Leaf : public Component//下属部门
{
public:
    Leaf(string name):Component(name){}
    virtual void add(Component *pComponent)
    {
        cout <<"leaf can not add child";
    }
    virtual void del(Component *pComponent)
    {
        cout <<"leaf can not del child";
    }
    virtual void showInfo()
    {
        cout <<m_name<<endl;
    }
};

class Composite : public Component//公司类
{
public:
    Composite(string name):Component(name){}
    virtual void add(Component *pComponent)
    {
        m_children.push_back(pComponent);
    }
    virtual void del(Component *pComponent)
    {
        for(vector<Component*>::iterator iter=m_children.begin();iter!=m_children.end();iter++)
        {
            if(*iter == pComponent)
            {
                m_children.erase(iter);
                break;
            }
        }
    }
    virtual void showInfo()
    {
        cout <<m_name<<endl;

        for(auto iter=m_children.begin();iter!=m_children.end();iter++)
        {
            Composite *pComposite = dynamic_cast<Composite*>(*iter);//多态类之间的类型转换用
            Leaf *pLeaf = dynamic_cast<Leaf*>(*iter);
            if(pComposite != NULL)
            {
                pComposite->showInfo();
            }
            else if(pLeaf != NULL)
            {
                pLeaf->showInfo();
            }
        }
    }

private:
    vector<Component*>  m_children;
};

int main()
{
    Composite * pZongGongSi = new Composite("总公司");
    Leaf * pZGSCaiWuBu = new Leaf("总公司财务部");
    pZongGongSi->add(pZGSCaiWuBu);
    Leaf * pZGSJiShuBu = new Leaf("总公司技术部");
    pZongGongSi->add(pZGSJiShuBu);

    Composite * pFenGongSi = new Composite("分公司");
    Leaf * pFGSCaiWuBu = new Leaf("分公司财务部");
    pFenGongSi->add(pFGSCaiWuBu);
    Leaf * pFGSJiShuBu = new Leaf("分公司技术部");
    pFenGongSi->add(pFGSJiShuBu);
    pZongGongSi->add(pFenGongSi);

    pZongGongSi->showInfo();

    delete pZongGongSi;
    delete pZGSCaiWuBu;

    delete pZGSJiShuBu;
    delete pFenGongSi;

    delete pFGSCaiWuBu;
    delete pFGSJiShuBu;

    return 0;
}