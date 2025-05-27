#include <iostream>
#include <initializer_list>
using namespace std;

class P
{
public:
    P(int a, int b) { cout << "P(int a, int b)\n"; }
    P(initializer_list<int> l) { cout << "P(initializer_list<int> l)\n"; }
    explicit P(int a, int b, int c) { cout << "explicit P(int a, int b, int c)\n"; }
};

void fp(const P &) {}
class ComplexNotExplicit
{
private:
    int real, imag;

public:
    ComplexNotExplicit(int r, int i = 0) : real(r), imag(i) {}
    ComplexNotExplicit operator+(const ComplexNotExplicit &c) const { return ComplexNotExplicit(real + c.real, imag + c.imag); }
};

class ComplexExplicit
{
private:
    int real, imag;

public:
    explicit ComplexExplicit(int r, int i = 0) : real(r), imag(i) {}
    ComplexExplicit operator+(const ComplexExplicit &c) const { return ComplexExplicit(real + c.real, imag + c.imag); }
};
int main()
{

    ComplexNotExplicit c1(12, 5);
    ComplexNotExplicit c2 = c1 + 5; // 隐式转换，调用 ComplexNotExplicit(int r, int i = 0) 构造函数，将 5 转换为 ComplexNotExplicit(5, 0)

    /*
    ComplexExplicit c3(12, 5);
    ComplexExplicit c4 = c3 + 5;// Error: no matching function for call to ‘ComplexExplicit::operator+(int)’
    */
    P p1(77, 5);              // P(int a, int b)
    P p2{77, 5};              // P(initializer_list<int> l)
    P p3{77, 5, 42};          // P(initializer_list<int> l)
    P p4 = {77, 5};           // P(initializer_list<int> l)
    P p5 = {77, 5, 42};       // P(initializer_list<int> l)，侯捷老师说C++20会报错，会使用explicit的构造函数，但我用的C++14没有这种情况
    P p6(77, 5, 42);          // explicit P(int a, int b, int c)
    fp({47, 11});             // P(initializer_list<int> l)
    fp({47, 11, 3});          // P(initializer_list<int> l)，侯捷老师说C++20会报错，会使用explicit的构造函数，但我用的C++14没有这种情况
    fp(P{47, 11});            // P(initializer_list<int> l)
    fp(P{47, 11, 3});         // P(initializer_list<int> l)
    P p11{77, 5, 42, 500};    // P(initializer_list<int> l)
    P p12 = {77, 5, 42, 500}; // P(initializer_list<int> l)
    P p13{10};                // P(initializer_list<int> l)
    return 0;
}