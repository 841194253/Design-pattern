cmake_minimum_required(VERSION 3.19)
project(Design_pattern)

set(CMAKE_CXX_STANDARD 11)

add_executable(Design_pattern main.cpp)
add_executable(merge merge.cpp)
add_executable(random_shuffle random_shuffle.cpp)
add_executable(accumulate accumulate.cpp)
add_executable(set set.cpp)
add_executable(speech-contest speech-contest.cpp)

#软件设计原则
add_executable(Opening_and_closing_principle Opening_and_closing_principle.cpp)#开闭原则
add_executable(Dimitt_rule Dimitt_rule.cpp)#迪米特法则
add_executable(Composite_Reuse_Principle Composite_Reuse_Principle.cpp)#合成复用原则
add_executable(Dependence_Inversion_Principle Dependence_Inversion_Principle.cpp)#依赖倒置原则
add_executable(Liskov_Substitution_Principle Liskov_Substitution_Principle.cpp)#里氏替换原则
add_executable(Single_Responsibility_Principle Single_Responsibility_Principle.cpp)#单一职责原则
add_executable(Interface_Segregation_Principle Interface_Segregation_Principle.cpp)#接口隔离原则

#创建型模式
add_executable(Factory_method_model Factory_method_model.cpp)#工厂方法模式
add_executable(Singleton_pattern Singleton_pattern.cpp)#单例模式
add_executable(Abstract_factory_pattern Abstract_factory_pattern.cpp)#抽象工厂模式
add_executable(Builder_pattern Builder_pattern.cpp)#建造者模式
add_executable(Prototype_pattern Prototype_pattern.cpp)#原型设计模式


#结构型模式
add_executable(Adapter_pattern Adapter_pattern.cpp)#适配器模式
add_executable(Bridge_pattern Bridge_pattern.cpp)#桥接模式
add_executable(Composite_pattern Composite_pattern.cpp)#组合模式
add_executable(Decorator_pattern Decorator_pattern.cpp)#装饰器模式
add_executable(Facade_pattern Facade_pattern.cpp)#外观模式
add_executable(Flyweight_pattern Flyweight_pattern.cpp)#享元模式
add_executable(proxy_pattern proxy_pattern.cpp)#代理模式

#行为型模式
add_executable(Visitor_pattern Visitor_pattern.cpp)#访问者模式
add_executable(Template_Method_pattern Template_Method_pattern.cpp)#模版方法模式
add_executable(Strategy_pattern Strategy_pattern.cpp)#策略模式
add_executable(State_pattern State_pattern.cpp)#状态模式
add_executable(Observer_pattern Observer_pattern.cpp)#观察者模式
add_executable(Memento_pattern Memento_pattern.cpp)#备忘录模式
add_executable(Mediator_pattern Mediator_pattern.cpp)#中介者模式
add_executable(Iterator_pattern Iterator_pattern.cpp)#迭代器模式
add_executable(Interpreter_pattern Interpreter_pattern.cpp)#解释器模式
add_executable(Command_pattern Command_pattern.cpp)#命令模式
add_executable(Chain_of_Responsibility_pattern Chain_of_Responsibility_pattern.cpp)#责任链模式

#非23种设计模式
add_executable(Simple_factory_pattern Simple_factory_pattern.cpp)#简单工厂模式