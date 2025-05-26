#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
int main()
{
    int values[]{1, 2, 3};
    vector<int> v{2, 3, 5, 7, 11, 13, 17};
    vector<string> cites{
        "Berlin", "New York", "London", "Bucharest", "Cairo", "Cologne"};
    complex<double> z{2, 3};

    for_each(values, values + 3, [](int i)
             { cout << i << " "; });
    cout << endl;
    for_each(v.begin(), v.end(), [](int i)
             { cout << i << " "; });
    cout << endl;
    for_each(cites.begin(), cites.end(), [](const string &s)
             { cout << s << " "; });
    cout << endl;
    cout << "z = " << real(z) << " + " << imag(z) << "i" << endl;
    return 0;
}