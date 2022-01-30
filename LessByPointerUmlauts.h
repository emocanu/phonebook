#pragma once
#include <memory>
#include <string>
#include <unordered_map>

struct LessByPointerUmlauts
{
    bool operator()(std::shared_ptr<std::wstring> lhs, std::shared_ptr<std::wstring> rhs) const
    {
        std::wstring ulhs, urhs;
        transform(*lhs.get(), ulhs);
        transform(*rhs.get(), urhs);
        return ulhs < urhs;
    }

    void transform(const std::wstring& in, std::wstring& out) const
    {
        out.empty();
        for (wchar_t c : in)
        {
            auto it = this->eq.find(c);
            if (it != eq.end())
            {
                out.append(it->second);
            }
            else
            {
                out.push_back(c);
            }
        }
    }

    std::unordered_map<wchar_t, std::wstring> eq = { {L'ä', L"ae"}, {L'ü', L"ue"}, {L'ö', L"oe"}};
};
