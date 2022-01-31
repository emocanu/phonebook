#pragma once
#include "Phonebook.h"
#include <vector>
#include <unordered_map>

using PhonebookList = std::vector<Phonebook>;
using StringMap = std::unordered_map<std::wstring, size_t>;

class PhonebookApp
{
public:
    void Insert(Phonebook entry);
    Phonebook GetByLastName(std::wstring lastName);
    Phonebook GetByFirstName(std::wstring firstName);
    Phonebook GetByPhoneNumber(std::wstring phoneNumber);
    void RemoveByLastName(std::wstring lastName);
    void RemoveByFirstName(std::wstring firstName);
    void RemoveByPhoneNumber(std::wstring phoneNumber);

private:
    Phonebook GetByString(std::wstring name, StringMap map);
    void RemoveEntry(size_t index);

    PhonebookList m_vectorEntries;
    StringMap m_lastNameMap;
    StringMap m_firstNameMap;
    StringMap m_phoneNumberMap;
};
