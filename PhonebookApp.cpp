#include "PhonebookApp.h"

void PhonebookApp::Insert(Phonebook entry)
{
    PointerToString phoneNumberToInsert = entry.phoneNumber;
    if (m_phoneNumberMap.find(phoneNumberToInsert) == m_phoneNumberMap.end())
    {
        PointerToString lastNameToInsert = entry.lastName;
        PointerToString firstNameToInsert = entry.firstName;

        m_vectorEntries.push_back(entry);
        size_t inserted = m_vectorEntries.size() - 1;

        m_phoneNumberMap.emplace(phoneNumberToInsert, inserted);
        m_lastNameMap.emplace(lastNameToInsert, inserted);
        m_firstNameMap.emplace(firstNameToInsert, inserted);
    }
}

PhonebookList PhonebookApp::GetByName(std::wstring name, PointerToStringMultiMap map)
{
    PhonebookList list;
    PointerToString nameKey = std::make_shared<std::wstring>(name);
    auto range = map.equal_range(nameKey);
    for (auto it = range.first; it != range.second; ++it)
    {
        list.push_back(m_vectorEntries.at(it->second));
    }
    return list;
}

PhonebookList PhonebookApp::GetByFirstName(std::wstring firstName)
{
    return GetByName(firstName, m_firstNameMap);
}

PhonebookList PhonebookApp::GetByLastName(std::wstring lastName)
{
    return GetByName(lastName, m_lastNameMap);
}

Phonebook PhonebookApp::GetByPhoneNumber(std::wstring phoneNumber)
{
    PointerToString phoneNumberKey = std::make_shared<std::wstring>(phoneNumber);
    auto it = m_phoneNumberMap.find(phoneNumberKey);
    if (it == m_phoneNumberMap.end())
    {
        return Phonebook();
    }
    else
    {
        return m_vectorEntries.at(it->second);
    }
}

PhonebookList PhonebookApp::PhoneStartsWith(std::wstring prefix)
{
    PhonebookList list;
    PointerToString phoneNumber = std::make_shared<std::wstring>(prefix);
    auto first = m_phoneNumberMap.lower_bound(phoneNumber);
    PointerToString phoneNumberGreater = std::make_shared<std::wstring>(GetGreaterThan(prefix));
    auto onePastTheLast = m_phoneNumberMap.lower_bound(phoneNumberGreater);
    for (auto it = first; it != onePastTheLast; ++it)
    {
        list.push_back(m_vectorEntries.at(it->second));
    }
    return list;
}

std::wstring PhonebookApp::GetGreaterThan(std::wstring number)
{
    std::wstring next;
    long long n = std::stoll(number);
    if (n + 1 > 0)
    {
        next = std::to_wstring(n + 1);
    }
    return next;
}