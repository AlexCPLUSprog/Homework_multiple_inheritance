#include <iostream>

class A {
public:
    virtual std::string getMethod() { return "A"; }
};

// Пример ромбовидного наследования с проблемой
//class B : public A {};
//class C : public A {};
//class D : public B, public C {};

// норм
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};


class LastDerived : public D {
public:
    std::string getMethod()
    {
        return A::getMethod();
    }
};

 int main() {
        D d;
        //Проблема ромбовидного наследования заключается в том, что если классы B и C наследуются от класса A, а класс D наследует от классов B и C, то если функция в классе A вызывается через класс D, то может произойти неоднозначность в том, какой именно метод вызвать. 
        // Это происходит из-за того, что класс D наследует функцию от двух разных мест (от B и C), которые сами наследуют ее от A.

        //std::cout << d.getMethod() << std::endl; // ОШИБКА: неоднозначность в вызове метода getMethod()


        //В этом примере мы используем виртуальное наследование для классов B и C, чтобы избежать дублирования наследования от A в D. 
        //Затем мы создаем новый класс LastDerived, который наследуется от D, и определяем в нем свою версию функции getMethod, которая вызывает функцию getMethod из A. 
        //Поскольку мы используем виртуальное наследование для класса A, то каждый объект типа LastDerived содержит только один экземпляр A, что избавляет нас от проблемы неоднозначности в вызове функции getMethod.



        LastDerived ld;
        std::cout << ld.getMethod() << std::endl; // Выводит "A"

        return 0;
    }
