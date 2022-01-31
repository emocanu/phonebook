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

			Assert::IsTrue(entry.firstName == ret.firstName);
			Assert::IsTrue(entry.lastName == ret.lastName);
			Assert::IsTrue(entry.phoneNumber == ret.phoneNumber);
		}

		TEST_METHOD(Insert_GetUnknownPhoneNumber_ReturnsEmpty)
		{
			PhonebookApp app;
			Phonebook entry(L"Doe", L"John", L"1234567");
			app.Insert(entry);
			
			Phonebook ret = app.GetByPhoneNumber(L"007");

			Assert::IsTrue(ret.firstName == L"");
			Assert::IsTrue(ret.lastName == L"");
			Assert::IsTrue(ret.phoneNumber == L"");
		}

		TEST_METHOD(Insert_PreventDuplicates_PhoneNumber_Correct)
		{
			PhonebookApp app;
			Phonebook entry(L"Doe", L"John", L"1234567");
			app.Insert(entry);
			Phonebook entry1(L"Walker", L"Johhny", L"1234567");
			app.Insert(entry1);
			Phonebook ret = app.GetByPhoneNumber(L"1234567");

			Assert::IsTrue(entry1.firstName != ret.firstName);
			Assert::IsTrue(entry1.lastName != ret.lastName);
		}

		TEST_METHOD(RemoveEntry_AllStructuresUpdated_Correct)
		{
			PhonebookApp app;
			app.Insert(Phonebook(L"Dove", L"Black", L"942255"));
			app.Insert(Phonebook(L"Doe", L"White", L"4420"));
			app.Insert(Phonebook(L"Smith", L"John", L"1442"));
			app.Insert(Phonebook(L"Begony", L"Johhny", L"9"));

			app.RemoveByPhoneNumber(L"4420");

			Assert::IsTrue(app.GetByPhoneNumber(L"4420").phoneNumber == L"");
			Assert::IsTrue(app.GetByLastName(L"Doe").lastName == L"");
			Assert::IsTrue(app.GetByFirstName(L"White").firstName == L"");
		}
	};
}
