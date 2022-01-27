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
	};
}
