#pragma once
#include <cstddef>
#include <functional>

template <typename T>
inline void hash_combine(size_t &seed, const T &val)
{
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template <typename T>
inline void hash_val(size_t &seed, const T &val)
{
    hash_combine(seed, val);
}

template <typename T, typename... Type>
inline void hash_val(size_t &seed, const T &val, const Type &...args)
{
    hash_combine(seed, val);
    hash_val(seed, args...);
}

template <typename... Type>
inline size_t hash_val(const Type &...args)
{
    size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

class Customer
{
public:
    std::string fname; // first name
    std::string lname; // last name
    int no;            // number

    // 构造函数
    Customer(const std::string &first, const std::string &last, int number)
        : fname(first), lname(last), no(number) {}
};

class CustomerHash
{
public:
    std::size_t operator()(const Customer &c) const
    {
        return hash_val(c.fname, c.lname, c.no); // 假设 Customer 类有一个名为 name 的 std::string 成员
    }
};