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
