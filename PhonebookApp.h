#pragma once
#include "Phonebook.h"
#include "LessByPointer.h"
#include "LessByPointerUmlauts.h"
#include <vector>
#include <map>

using PhonebookList = std::vector<Phonebook>;
using PointerToString = std::shared_ptr<std::wstring>;
using PointerToStringMap = std::map<PointerToString, size_t, LessByPointer<std::wstring>>;
using PointerToStringMultiMap = std::multimap<PointerToString, size_t, LessByPointer<std::wstring>>;
using PointerToStringMapUmlauts = std::map<PointerToString, size_t, LessByPointerUmlauts>;

class PhonebookApp
{
public:
    void Insert(Phonebook entry);
    PhonebookList GetByLastName(std::wstring lastName);     // last name can be found multiple times
    PhonebookList GetByFirstName(std::wstring firstName);   // also the first name
    Phonebook GetByPhoneNumber(std::wstring phoneNumber);   // I relates uniqueness to the phone number
    PhonebookList PhoneStartsWith(std::wstring prefix);

private:
    PhonebookList GetByName(std::wstring name, PointerToStringMultiMap map);
    std::wstring GetGreaterThan(std::wstring number);

    PhonebookList m_vectorEntries;
    PointerToStringMultiMap m_lastNameMap;
    PointerToStringMultiMap m_firstNameMap;
    PointerToStringMap m_phoneNumberMap;
};