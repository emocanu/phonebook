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

		TEST_METHOD(Insert_PermitDuplicates_FirstNameCaseInsensitive_ReturnsCorrect)
		{
			PhonebookApp app;
			app.Insert(Phonebook(L"Doe", L"Black", L"0234567"));
			app.Insert(Phonebook(L"Doe", L"John", L"1234567"));
			app.Insert(Phonebook(L"Walker", L"John", L"2234567"));
			app.Insert(Phonebook(L"Winston", L"john", L"2234569"));
			app.Insert(Phonebook(L"Doe", L"Johhny", L"3234567"));

			PhonebookList list = app.GetByFirstName(L"John");

			Assert::IsTrue(list.size() == 3);
		}

		TEST_METHOD(PhoneStartsWith_Returns_Correct)
		{
			PhonebookApp app;
			app.Insert(Phonebook(L"Doe", L"Black", L"442255"));
			app.Insert(Phonebook(L"Doe", L"Black", L"4429"));
			app.Insert(Phonebook(L"Doe", L"Black", L"4420"));
			app.Insert(Phonebook(L"Doe", L"John", L"442"));
			app.Insert(Phonebook(L"Doe", L"Johhny", L"443"));
			app.Insert(Phonebook(L"Walker", L"John", L"441255"));
			app.Insert(Phonebook(L"Walker", L"John", L"441"));
			app.Insert(Phonebook(L"Doe", L"Johhny", L"443255"));

			PhonebookList list = app.PhoneStartsWith(L"442");

			Assert::IsTrue(list.size() == 4);
		}

		TEST_METHOD(PhoneStartsWith_EdgeCase_1_Returns_Correct)
		{
			PhonebookApp app;
			app.Insert(Phonebook(L"Doe", L"Black", L"0442255"));
			app.Insert(Phonebook(L"Doe", L"Black", L"0"));
			app.Insert(Phonebook(L"Doe", L"Black", L"4420"));
			app.Insert(Phonebook(L"Doe", L"John", L"1442"));
			app.Insert(Phonebook(L"Doe", L"Johhny", L"9"));
			app.Insert(Phonebook(L"Walker", L"John", L"441255"));
			app.Insert(Phonebook(L"Walker", L"John", L"001"));
			app.Insert(Phonebook(L"Doe", L"Johhny", L"00"));

			PhonebookList list = app.PhoneStartsWith(L"0");

			Assert::IsTrue(list.size() == 4);
		}

		TEST_METHOD(PhoneStartsWith_EdgeCase_2a_Returns_Correct)
		{
			PhonebookApp app;
			app.Insert(Phonebook(L"Doe", L"Black", L"492255"));
			app.Insert(Phonebook(L"Doe", L"Black", L"490"));
			app.Insert(Phonebook(L"Doe", L"Black", L"489"));
			app.Insert(Phonebook(L"Doe", L"John", L"1442"));
			app.Insert(Phonebook(L"Doe", L"Johhny", L"49"));
			app.Insert(Phonebook(L"Walker", L"John", L"501"));
			app.Insert(Phonebook(L"Walker", L"John", L"499"));
			app.Insert(Phonebook(L"Doe", L"Johhny", L"50"));

			PhonebookList list = app.PhoneStartsWith(L"49");

			Assert::IsTrue(list.size() == 4);
		}

		TEST_METHOD(PhoneStartsWith_EdgeCase_2b_Returns_Correct)
		{
			PhonebookApp app;
			app.Insert(Phonebook(L"Doe", L"Black", L"942255"));
			app.Insert(Phonebook(L"Doe", L"Black", L"10"));
			app.Insert(Phonebook(L"Doe", L"Black", L"4420"));
			app.Insert(Phonebook(L"Doe", L"John", L"1442"));
			app.Insert(Phonebook(L"Doe", L"Johhny", L"9"));
			app.Insert(Phonebook(L"Walker", L"John", L"441255"));
			app.Insert(Phonebook(L"Walker", L"John", L"9999"));
			app.Insert(Phonebook(L"Doe", L"Johhny", L"100"));

			PhonebookList list = app.PhoneStartsWith(L"9");

			Assert::IsTrue(list.size() == 3);
		}

		TEST_METHOD(PhoneStartsWith_EmptyString_Returns_Correct)
		{
			PhonebookApp app;
			app.Insert(Phonebook(L"Doe", L"Black", L"942255"));
			app.Insert(Phonebook(L"Doe", L"Black", L"10"));
			app.Insert(Phonebook(L"Doe", L"Black", L"4420"));
			app.Insert(Phonebook(L"Doe", L"John", L"1442"));
			app.Insert(Phonebook(L"Doe", L"Johhny", L"9"));
			app.Insert(Phonebook(L"Walker", L"John", L"441255"));
			app.Insert(Phonebook(L"Walker", L"John", L"9999"));
			app.Insert(Phonebook(L"Doe", L"Johhny", L"100"));

			PhonebookList list = app.PhoneStartsWith(L"");

			Assert::IsTrue(list.size() == 8);
		}

		TEST_METHOD(PhoneStartsWith_NothingFound_Returns_Correct)
		{
			PhonebookApp app;
			app.Insert(Phonebook(L"Doe", L"Black", L"942255"));
			app.Insert(Phonebook(L"Doe", L"Black", L"10"));
			app.Insert(Phonebook(L"Doe", L"Black", L"4420"));
			app.Insert(Phonebook(L"Doe", L"John", L"1442"));
			app.Insert(Phonebook(L"Doe", L"Johhny", L"9"));
			app.Insert(Phonebook(L"Walker", L"John", L"441255"));
			app.Insert(Phonebook(L"Walker", L"John", L"9999"));
			app.Insert(Phonebook(L"Doe", L"Johhny", L"100"));

			PhonebookList list = app.PhoneStartsWith(L"0");

			Assert::IsTrue(list.size() == 0);
		}

		TEST_METHOD(RemoveByPhoneNumber_AllStructuresUpdated_Correct)
		{
			PhonebookApp app;
			app.Insert(Phonebook(L"Doe", L"Black", L"942255"));
			app.Insert(Phonebook(L"Doe", L"Black", L"10"));
			app.Insert(Phonebook(L"Doe", L"Black", L"4420"));
			app.Insert(Phonebook(L"Doe", L"John", L"1442"));
			app.Insert(Phonebook(L"Doe", L"Johhny", L"9"));
			app.Insert(Phonebook(L"Walker", L"John", L"441255"));
			app.Insert(Phonebook(L"Walker", L"John", L"9999"));
			app.Insert(Phonebook(L"Doe", L"Johhny", L"100"));

			app.RemoveByPhoneNumber(L"4420"); // all indexes in the vector past the one deleted are changed, the vector re-arranged itself, references in the maps are invalid, so don't delete but make it null

			Assert::IsTrue(app.GetByPhoneNumber(L"4420").phoneNumber == nullptr);
			Assert::IsTrue(app.GetByLastName(L"Doe").size() == 5);
			Assert::IsTrue(app.GetByFirstName(L"Black").size() == 2);
		}
	};
}
