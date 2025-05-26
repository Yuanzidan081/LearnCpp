#pragma once
#include <iostream>
#include <bitset>
using namespace std;

void PrintX()
{
}

template <typename T, typename... Types>
void PrintX(const T &firstArg, const Types &...args)
{
    cout << firstArg << " " << sizeof...(args) << endl; // print the first argument
    PrintX(args...);                                    // call PrintX for the remaining arguments
}