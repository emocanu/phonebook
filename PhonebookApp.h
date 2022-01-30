#pragma once
#include "Phonebook.h"
#include "LessByPointer.h"
#include "LessByPointerCaseInsensitive.h"
#include <vector>
#include <map>

using PhonebookList = std::vector<Phonebook>;
using PointerToString = std::shared_ptr<std::wstring>;
using PointerToStringMap = std::map<PointerToString, size_t, LessByPointer<std::wstring>>;
using PointerToStringCaseInsensitiveMultiMap = std::multimap<PointerToString, size_t, LessByPointerCaseInsensitive>;

class PhonebookApp
{
public:
    void Insert(Phonebook entry);
    PhonebookList GetByLastName(std::wstring lastName);     // last name can be found multiple times
    PhonebookList GetByFirstName(std::wstring firstName);   // also the first name
    Phonebook GetByPhoneNumber(std::wstring phoneNumber);   // I relates uniqueness to the phone number
    void RemoveByPhoneNumber(std::wstring phoneNumber);
    PhonebookList PhoneStartsWith(std::wstring prefix);

private:
    PhonebookList GetByName(std::wstring name, PointerToStringCaseInsensitiveMultiMap map);
    std::wstring GetGreaterThan(std::wstring number);
    void RemoveReferenceTo(PointerToStringCaseInsensitiveMultiMap& map, PointerToString name, size_t indexInVector);

    PhonebookList m_vectorEntries;
    PointerToStringCaseInsensitiveMultiMap m_lastNameMap;
    PointerToStringCaseInsensitiveMultiMap m_firstNameMap;
    PointerToStringMap m_phoneNumberMap;
};
