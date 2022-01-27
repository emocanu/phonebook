#pragma once
#include <string>
#include <memory>

using PointerToString = std::shared_ptr<std::wstring>;

struct Phonebook
{
    PointerToString lastName;
    PointerToString firstName;
    PointerToString phoneNumber;

    Phonebook()
        : lastName(nullptr), firstName(nullptr), phoneNumber(nullptr)
    {}

    Phonebook(std::wstring last_name, std::wstring first_name, std::wstring phone_number)
    {
        lastName = std::make_shared<std::wstring>(last_name);
        firstName = std::make_shared<std::wstring>(first_name);
        phoneNumber = std::make_shared<std::wstring>(phone_number);
    }
};
