//
// Created by apple on 8/11/21.
//

//解释器模式：给分析对象定义一个语言，并定义该语言的文法表示，再设计一个解析器来解释语言中的句子。也就是说，用编译语言的方式来分析应用中的实例。这种模式实现了文法表达式处理的接口，该接口解释一个特定的上下文。
//解释器模式包含以下主要角色。
//抽象表达式角色：定义解释器的接口，约定解释器的解释操作，主要包含解释方法 interpret()。
//终结符表达式角色：是抽象表达式的子类，用来实现文法中与终结符相关的操作，文法中的每一个终结符都有一个具体终结表达式与之相对应。
//非终结符表达式角色：也是抽象表达式的子类，用来实现文法中与非终结符相关的操作，文法中的每条规则都对应于一个非终结符表达式。
//环境角色：通常包含各个解释器需要的数据或是公共的功能，一般用来传递被所有解释器共享的数据，后面的解释器可以从这里获取这些值。
//客户端：主要任务是将需要分析的句子或表达式转换成使用解释器对象描述的抽象语法树，然后调用解释器的解释方法，当然也可以通过环境角色间接访问解释器的解释方法。

#include <iostream>
#include <map>

using namespace std;

#define DELETE(pointer) delete pointer; pointer=nullptr

const string key1 = string("s1");
const string key2 = string("s2");
const string key3 = string("s3");
const string key4 = string("s4");

class Context1
{
public:
    Context1(){
        datas[key1] = 1;
        datas[key2] = 2;
        datas[key3] = 3;
        datas[key4] = 4;
    }

    int getValue(string key) {
        if (!datas.count(key))
        {
            return 0;
        }
        return datas[key];
    }

private:
    std::map<string, int> datas;
};

class Expression
{
public:
    Expression(Expression *left, Expression *right) :left(left), right(right) { }

    virtual ~Expression() {
        if (left != nullptr)
        {
            DELETE(left);
            cout << "delete left" << endl;
        }
        if (right != nullptr)
        {
            DELETE(right);
            cout << "delete right" << endl;
        }
    }

    virtual int interpreter(Context1* context) = 0;

protected:
    Expression *left;
    Expression *right;
};

class MultiExpression : public Expression
{
public:
    MultiExpression(Expression *left, Expression *right) : Expression(left, right) { }

    int interpreter(Context1* context) override {
        if ((left == nullptr) || (right == nullptr))
        {
            return 0;
        }
        return left->interpreter(context) * right->interpreter(context);
    }
};


class DivisionExpression : public Expression
{
public:
    DivisionExpression(Expression *left, Expression *right) : Expression(left, right) { }

    int interpreter(Context1* context) override {
        if ((left == nullptr) || (right == nullptr))
        {
            return 0;
        }
        return left->interpreter(context) / right->interpreter(context);
    }
};

class TerminalExpression : public Expression
{
public:
    TerminalExpression(int value) : value(value), Expression(nullptr, nullptr) { }
    int interpreter(Context1* context) {
        return value;
    }

private:
    int value;
};

void doInterpreter() // 客户端client
{
    /*   3*4/2==6  对应语法树如下：

           /   （除法）
          / \
          *  2
         / \
        3   4
    */
    Context1 context;

    MultiExpression *multiExpression = new MultiExpression(new TerminalExpression(context.getValue(key3))
            , new TerminalExpression(context.getValue(key4))); // 终止节点作为叶子结点，非终止节点作为非叶子节点
    int mutil = multiExpression->interpreter(&context);
    cout << "mutil==" << mutil << endl;

    DivisionExpression *divisionExpression = new DivisionExpression(multiExpression
            , new TerminalExpression(context.getValue(key2))); // 乘法表达式作为左子树 / 右子树
    int division = divisionExpression->interpreter(&context); // 运行解释器
    cout << "division==" << division << endl;

    DELETE(divisionExpression);
    // 这里注意，不能第二次释放divisionExpression，因为此时它是divisionExpression的左子树
    //，divisionExpression释放的时候会自动释放左右子树，也就是递归释放，最终只需要释放最后一次嵌套调用的就行
}

int main()
{
    doInterpreter();
}

