#pragma once
#include "Phonebook.h"
#include "LessByPointer.h"
#include <vector>
#include <map>

using PhonebookList = std::vector<Phonebook>;
using PointerToString = std::shared_ptr<std::wstring>;
using PointerToStringMap = std::map<PointerToString, size_t, LessByPointer<std::wstring>>;

class PhonebookApp
{
public:
    void Insert(Phonebook entry);
    //PhonebookList GetByLastName(std::wstring lastName);
    //PhonebookList GetByFirstName(std::wstring firstName);
    Phonebook GetByPhoneNumber(std::wstring phoneNumber);

private:
    PhonebookList m_vectorEntries;
    PointerToStringMap m_lastNameMap;
    PointerToStringMap m_firstNameMap;
    PointerToStringMap m_phoneNumberMap;
};