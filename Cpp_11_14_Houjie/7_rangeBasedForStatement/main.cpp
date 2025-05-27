#include <iostream>
#include <vector>
#include <string>
using namespace std;

class C
{
    string s;

public:
    explicit C(const string &s_) : s(s_) {}
};
int main()
{
    for (int i : {2, 3, 5, 7, 11, 13, 17, 19})
    {
        cout << i << " ";
    }
    cout << endl;

    vector<double> vec{1, 2, 3, 4, 5, 6, 7, 8};

    for (auto elem : vec)
    {
        cout << elem << " ";
    }
    cout << endl;
    for (auto &elem : vec)
    {
        elem *= 3;
        cout << elem << " ";
    }
    cout << endl;

    /*
    // 下面的代码会报错，因为C的构造函数是explicit的，所以不能使用C的构造函数来初始化vector<string>的元素（禁止隐式转换）
    vector<string> vs;
    for (const C &elem : vs)
    {
        cout << elem << " ";
    }
    cout << enel;
    */
    return 0;
}