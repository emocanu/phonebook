#pragma once
#include <memory>
#include <string>
#include <vector>

struct LessByPointerUmlauts // now write a specialization for std::wstring
{
    bool operator()(std::shared_ptr<std::wstring> lhs, std::shared_ptr<std::wstring> rhs) const
    {
        return *lhs < *rhs;
    }

    std::vector<std::wstring> phonetic = { L"ae", L"ue", L"oe" };
    std::vector<std::wstring> umlaut = { L"ä", L"ü", L"ö" };
};
