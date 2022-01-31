#include "PhonebookApp.h"

void PhonebookApp::Insert(Phonebook entry)
{
    auto itFirstName = m_firstNameMap.find(entry.firstName);
    auto itLastName = m_lastNameMap.find(entry.lastName);
    auto itPhoneNo = m_phoneNumberMap.find(entry.phoneNumber);
    if(itFirstName == m_firstNameMap.end()
        && itLastName == m_lastNameMap.end()
        && itPhoneNo == m_phoneNumberMap.end())
    {
        m_vectorEntries.push_back(entry);
        size_t inserted = m_vectorEntries.size() - 1;

        m_phoneNumberMap.emplace(entry.phoneNumber, inserted);
        m_lastNameMap.emplace(entry.lastName, inserted);
        m_firstNameMap.emplace(entry.firstName, inserted);
    }
}

Phonebook PhonebookApp::GetByString(std::wstring name, StringMap map)
{
    auto it = map.find(name);
    if(it != map.end())
    {
       return m_vectorEntries.at(it->second);
    }
    return Phonebook();
}

Phonebook PhonebookApp::GetByFirstName(std::wstring firstName)
{
    return GetByString(firstName, m_firstNameMap);
}

Phonebook PhonebookApp::GetByLastName(std::wstring lastName)
{
    return GetByString(lastName, m_lastNameMap);
}

Phonebook PhonebookApp::GetByPhoneNumber(std::wstring phoneNumber)
{
    return GetByString(phoneNumber, m_phoneNumberMap);
}

void PhonebookApp::RemoveByLastName(std::wstring lastName)
{
    auto it = m_lastNameMap.find(lastName);
    if (it != m_lastNameMap.end())
    {
        RemoveEntry(it->second);
    }
}

void PhonebookApp::RemoveByFirstName(std::wstring firstName)
{
    auto it = m_firstNameMap.find(firstName);
    if (it != m_firstNameMap.end())
    {
        RemoveEntry(it->second);
    }
}

void PhonebookApp::RemoveByPhoneNumber(std::wstring phoneNumber)
{
    auto it = m_phoneNumberMap.find(phoneNumber);
    if (it != m_phoneNumberMap.end())
    {
        RemoveEntry(it->second);
    }
}

void PhonebookApp::RemoveEntry(size_t index)
{
    Phonebook entry = m_vectorEntries.at(index);
    m_lastNameMap.erase(entry.lastName);
    m_firstNameMap.erase(entry.firstName);
    m_phoneNumberMap.erase(entry.phoneNumber);
    m_vectorEntries[index] = Phonebook();
}
