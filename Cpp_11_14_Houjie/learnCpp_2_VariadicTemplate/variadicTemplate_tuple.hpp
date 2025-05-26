#pragma once
template <typename... Values>
class Tuple;

template <>
class Tuple<>
{
};

template <typename Head, typename... Tail>
class Tuple<Head, Tail...> : private Tuple<Tail...>
{
    typedef Tuple<Tail...> inherited;

public:
    Tuple() {}
    Tuple(Head v, Tail... vtail) : m_head(v), inherited(vtail...) {}

    Head head() { return m_head; }
    inherited &tail()
    {
        return *this; // 通过隐式类型转换转换为基类引用
    }

protected:
    Head m_head;
};