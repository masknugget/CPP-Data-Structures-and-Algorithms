// Assignment_Operator_Overload.cbp
#include <iostream>

using namespace std;

class Animal
{
protected:
    string m_name;

public:
    Animal(string name) : m_name(name)  // 初始化绑定在m_name上
    {

    }

    // The interface that has to be implemented
    // in derived class
    virtual string MakeSound() = 0;   // 这是一个基类的东东， virtual mehtod implent by suclass

    string GetName()
    {
        return m_name;
    }

};

class Dog : public Animal       //继承 public Animal 
{
public:
    // Forward the constructor arguments
    Dog(string name) : Animal(name) {}

    // Copy assignment operator overloading
    void operator = (const Dog &D ) {              //这是个神马鬼
         m_name = D.m_name;
      }

    // here we implement the interface
    string MakeSound() override               // override 写在后面
    {
        return "woof-woof!";
    }

};

int main()
{
    Dog dog = Dog("Bulldog");
    cout << dog.GetName() << " is barking: ";
    cout << dog.MakeSound() << endl;

    Dog dog2 = dog;
    cout << dog2.GetName() << " is barking: ";
    cout << dog2.MakeSound() << endl;

    return 0;
}
