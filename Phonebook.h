#pragma once
#include <string>

struct Phonebook
{
    std::wstring lastName;
    std::wstring firstName;
    std::wstring phoneNumber;

    Phonebook()
        : lastName(L""), firstName(L""), phoneNumber(L"")
    {}

    Phonebook(std::wstring last_name, std::wstring first_name, std::wstring phone_number)
        : lastName(last_name), firstName(first_name), phoneNumber(phone_number)
    {
    }
};
