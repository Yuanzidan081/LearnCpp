#include <iostream>
#include <vector>
#include <functional>
#include <complex>
#include <algorithm>
#include <array>
using namespace std;

void print(std::initializer_list<int> values)
{
    for (auto p = values.begin(); p != values.end(); ++p)
        cout << *p << " ";
    cout << std::endl;
}

class P
{
public:
    P(int a, int b)
    {
        cout << "P(int, int), a=" << a << ", b=" << b << endl;
    }
    P(initializer_list<int> values)
    {
        cout << "P(initializer_list<int>), values=";
        for (auto v : values)
            cout << v << " ";
        cout << endl;
    }
};

class Q
{
public:
    Q(int a, int b)
    {
        cout << "Q(int, int), a=" << a << ", b=" << b << endl;
    }
};
int main()
{
    int i;
    int j{};
    int *p;
    int *q{};
    cout << i << " " << j << " " << p << " " << q << endl;

    // int x1{5.3}; // error:从 "double" 到 "int" 进行收缩转换无效
    int x2 = 5.3;
    // int x4 = {5.3}; // error:从 "double" 到 "int" 进行收缩转换无效

    char c1{7};
    // char c2{99999}; // error:从 "int"(99999) 到 "char" 进行收缩转换无效
    cout << x2 << endl;
    cout << c1 << endl;

    // vector<int> v2{1, 2.3, 4, 5.6}; // error:从 "double" 到 "int" 进行收缩转换无效

    print({1, 2, 3, 4, 5, 6});

    P p1(77, 5);     // P(int, int), a=77, b=5
    P p2{77, 5};     // P(initializer_list<int>), values=77 5
    P p3{77, 5, 42}; // P(initializer_list<int>), values=77 5 42
    // 拷贝过去是浅拷贝
    P p4 = {77, 5}; // P(initializer_list<int>), values=77 5
    P p5 = p4;

    Q q1(77, 5); // Q(int, int), a=77, b=5
    Q q2{77, 5}; // Q(int, int), a=77, b=5
    // Q q3{77, 5, 42}; // error: 没有与这些操作数匹配的 "Q" 构造函数
    Q q4 = {77, 5}; // Q(int, int), a=77, b=5

    // complex没有initializer_list构造函数，所以 complex<double> z{2, 3};
    // 实际调用的构造函数是下面这样：
    /* _GLIBCXX_CONSTEXPR complex(double __r = 0.0, double __i = 0.0) */

    vector<int> v1{2, 5, 7, 13, 69, 83, 50};
    vector<int> v2({2, 5, 7, 13, 69, 83, 50});
    vector<int> v3;
    v3 = {2, 5, 7, 13, 69, 83, 50};
    v3.insert(v3.begin() + 2, {0, 1, 2, 3, 4});
    for (auto i : v3)
        cout << i << " ";
    cout << endl; // 2 5 0 1 2 3 4 7 13 69 83 50
    cout << max({string("Ace"), string("Stacy"), string("Sabrina"), string("Barkley")}) << endl;
    cout << min({string("Ace"), string("Stacy"), string("Sabrina"), string("Barkley")}) << endl;
    cout << max({54, 16, 48, 5}) << endl;
    cout << min({54, 16, 48, 5}) << endl;

    return 0;
}