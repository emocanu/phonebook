#pragma once
#include <memory>

template<class T> struct LessByPointer
{
    bool operator()(std::shared_ptr<T> lhs, std::shared_ptr<T> rhs) const
    {
        return *lhs < *rhs;
    }
};
