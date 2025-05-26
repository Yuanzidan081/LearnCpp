#include <iostream>
#include <vector>
#include <functional>
using namespace std;
int main()
{

    vector<string> v;
    v.push_back("hello");
    auto pos = v.begin();      // pos type: vector<string>::iterator
    auto l = [](int x) -> bool // l type function<bool(int)>
    {
        return x > 0;
    };
    cout << *pos << " " << l(100) << endl;
    return 0;
}