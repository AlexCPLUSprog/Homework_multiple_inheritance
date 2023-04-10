#include <iostream>

class A {
public:
    virtual std::string getMethod() { return "A"; }
};

// ������ ������������ ������������ � ���������
//class B : public A {};
//class C : public A {};
//class D : public B, public C {};

// ����
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
        //�������� ������������ ������������ ����������� � ���, ��� ���� ������ B � C ����������� �� ������ A, � ����� D ��������� �� ������� B � C, �� ���� ������� � ������ A ���������� ����� ����� D, �� ����� ��������� ��������������� � ���, ����� ������ ����� �������. 
        // ��� ���������� ��-�� ����, ��� ����� D ��������� ������� �� ���� ������ ���� (�� B � C), ������� ���� ��������� �� �� A.

        //std::cout << d.getMethod() << std::endl; // ������: ��������������� � ������ ������ getMethod()


        //� ���� ������� �� ���������� ����������� ������������ ��� ������� B � C, ����� �������� ������������ ������������ �� A � D. 
        //����� �� ������� ����� ����� LastDerived, ������� ����������� �� D, � ���������� � ��� ���� ������ ������� getMethod, ������� �������� ������� getMethod �� A. 
        //��������� �� ���������� ����������� ������������ ��� ������ A, �� ������ ������ ���� LastDerived �������� ������ ���� ��������� A, ��� ��������� ��� �� �������� ��������������� � ������ ������� getMethod.



        LastDerived ld;
        std::cout << ld.getMethod() << std::endl; // ������� "A"

        return 0;
    }
