#include "pch.h"
#include "CppUnitTest.h"
#include "..\Calculator\CalcButton.h"
#include "..\Calculator\ButtonFactory.h"
#include <string>
#include "wx/wx.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ButtonFactoryTest
{
	TEST_CLASS(ButtonFactoryTest)
	{
	public:
		ButtonFactory bf;
		wxPanel* _window = new wxPanel();
		CalcButton* temp = bf.CreateButton(_window, "Pringles", 1000);
		CalcButton* temp2 = bf.CreateButton(_window, "Shuffle");
		

		TEST_METHOD(TestMatchingID)
		{
			Assert::AreEqual(temp->GetId(), 1000);
		}

		TEST_METHOD(TestNotMatchingID)
		{
			Assert::AreNotEqual(temp->GetId(), 2);
		}

		TEST_METHOD(TestMatchingLabel)
		{
			Assert::AreEqual(std::string(temp->GetLabel()), std::string("Pringles")); //weird does not return... but this works in the calculator?
		}

		TEST_METHOD(TestNotMatchingLabel)
		{
			Assert::AreNotEqual(std::string(temp->GetLabel()), std::string("Doritos")); //sorry was hungry for chips
		}

		TEST_METHOD(ButtonExists)
		{			
			Assert::IsTrue(temp != nullptr);
		}

		TEST_METHOD(Button2Exists)
		{
			Assert::IsTrue(temp2 != nullptr);
		}

		TEST_METHOD(ButtonTwoHasID)
		{
			Assert::IsTrue(temp2->GetId() !=NULL);
		}

		TEST_METHOD(ButtonTwoIDNotMatching)
		{
			Assert::AreNotEqual(temp2->GetId(), 2);
		}

		TEST_METHOD(ButtonTWoLabelTest)
		{
			Assert::AreEqual(std::string(temp2->GetLabel()), std::string("Shuffle"));
		}

		TEST_METHOD(ButtonTwoLabelNotMatching)
		{
			Assert::AreNotEqual(std::string(temp2->GetLabel()), std::string("IP"));
		}

		TEST_METHOD(ButtonsAreNotsameID)
		{

			Assert::AreNotEqual(temp->GetId(), temp2->GetId());
		}

		TEST_METHOD(ButtonsAreNotsameLabel)
		{

			Assert::AreNotEqual(std::string(temp->GetLabel()), std::string(temp2->GetLabel()));
		}


		
	};
}
