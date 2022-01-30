#pragma once
#include <memory>
#include <string>
#include <cwctype>
#include <algorithm>
#include <iterator>

struct LessByPointerCaseInsensitive
{
    bool operator()(std::shared_ptr<std::wstring> lhs, std::shared_ptr<std::wstring> rhs) const
    {
        std::wstring ulhs, urhs;
        auto lambdaToUpper = [](wchar_t c) -> wchar_t { return std::towupper(c); };
        std::transform(lhs.get()->begin(), lhs.get()->end(), std::back_inserter(ulhs), lambdaToUpper);
        std::transform(rhs.get()->begin(), rhs.get()->end(), std::back_inserter(urhs), lambdaToUpper);
        return ulhs < urhs;
    }
};
