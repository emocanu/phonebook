#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\PhonebookApp.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PhonebookUnitTest
{
	TEST_CLASS(PhonebookAppUnitTest)
	{
	public:
		
		TEST_METHOD(Insert_GetByPhoneNumber_Success)
		{
			PhonebookApp app;
			Phonebook entry(L"Doe", L"John", L"1234567");
			app.Insert(entry);
			Phonebook ret = app.GetByPhoneNumber(L"1234567");

			Assert::IsTrue(entry.firstName.get() == ret.firstName.get());
			Assert::IsTrue(entry.lastName.get() == ret.lastName.get());
			Assert::IsTrue(entry.phoneNumber.get() == ret.phoneNumber.get());
		}

		TEST_METHOD(Insert_GetUnknownPhoneNumber_ReturnsNull)
		{
			PhonebookApp app;
			Phonebook entry(L"Doe", L"John", L"1234567");
			app.Insert(entry);
			
			Phonebook ret = app.GetByPhoneNumber(L"007");

			Assert::IsTrue(ret.firstName.get() == nullptr);
			Assert::IsTrue(ret.lastName.get() == nullptr);
			Assert::IsTrue(ret.phoneNumber.get() == nullptr);
		}

		TEST_METHOD(Insert_PreventDuplicates_PhoneNumber_IsKey)
		{
			PhonebookApp app;
			Phonebook entry(L"Doe", L"John", L"1234567");
			app.Insert(entry);
			Phonebook entry1(L"Walker", L"Johhny", L"1234567");
			app.Insert(entry1);
			Phonebook ret = app.GetByPhoneNumber(L"1234567");

			Assert::IsTrue(entry1.firstName.get() != ret.firstName.get());
			Assert::IsTrue(entry1.lastName.get() != ret.lastName.get());
		}

		TEST_METHOD(Insert_PermitDuplicates_FirstName_ReturnsCorrect)
		{
			PhonebookApp app;
			app.Insert(Phonebook(L"Doe", L"Black", L"0234567"));
			app.Insert(Phonebook(L"Doe", L"John", L"1234567"));
			app.Insert(Phonebook(L"Walker", L"John", L"2234567"));
			app.Insert(Phonebook(L"Doe", L"Johhny", L"3234567"));
			
			PhonebookList list = app.GetByFirstName(L"John");

			Assert::IsTrue(list.size() == 2);
		}

	};
}
