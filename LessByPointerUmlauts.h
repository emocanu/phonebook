#pragma once
#include <memory>
#include <string>
#include <cwctype>
#include <algorithm>
#include <iterator>
#include <unordered_map>

struct LessByPointerUmlauts
{
    bool operator()(std::shared_ptr<std::wstring> lhs, std::shared_ptr<std::wstring> rhs) const
    {
        std::wstring ulhs, urhs;
        auto lambdaToUmlauts = [this](wchar_t c) -> std::wstring
        {
            auto it = this->eq.find(c);
            if (it != eq.end())
            {
                return it->second;
            }
            return std::wstring(1, c); 
        };
        
        std::transform(lhs.get()->begin(), lhs.get()->end(), std::back_inserter(ulhs), lambdaToUmlauts);
        std::transform(rhs.get()->begin(), rhs.get()->end(), std::back_inserter(urhs), lambdaToUmlauts);
        return ulhs < urhs;
    }

    std::unordered_map<wchar_t, std::wstring> eq = { {L'ä', L"ae"}, {L'ü', L"ue"}, {L'ö', L"oe"}};
};
