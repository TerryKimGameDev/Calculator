#include "pch.h"
#include "CppUnitTest.h"
#include "..\Calculator\CalcProcessor.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProcessorTest
{
	TEST_CLASS(ProcessorTest)
	{
		CalcProcessor* _processor = CalcProcessor::GetInstances();
	public:


		TEST_METHOD(TestAdd)
		{
			int add = _processor->Addition(15, 2);
			Assert::AreEqual(add, 17);
		}

		TEST_METHOD(TestDivide)
		{
			int divide = _processor->Division(8, 4);
			Assert::AreEqual(divide, 2);
		}

		TEST_METHOD(TestSubtract)
		{
			int minus = _processor->Subtraction(8, 7);
			Assert::AreEqual(minus, 1);
		}

		TEST_METHOD(TestMultipy)
		{
			int mult = _processor->Multiplication(5, 5);
			Assert::AreEqual(mult, 25);
		}

		TEST_METHOD(TestModulo)
		{
			int mod = _processor->Modulo(90, 5);
			Assert::AreEqual(mod, 0);
		}

		TEST_METHOD(TestDecimal)
		{
			_processor->setBaseNumber(198);
			Assert::AreEqual(_processor->GetDecimal(), string("198"));
		}

		TEST_METHOD(TestNegativeDecimal)
		{
			_processor->setBaseNumber(-198);
			Assert::AreEqual(_processor->GetDecimal(), string("(~198)"));
		}

		

		TEST_METHOD(TestBin)
		{
			_processor->setBaseNumber(198);
			Assert::AreEqual(_processor->GetBinary(), string("0000000011000110"));
		}

		TEST_METHOD(TestHex)
		{
			_processor->setBaseNumber(198);
			Assert::AreEqual(_processor->GetHexadecimal(), string("0xC6"));
		}

		TEST_METHOD(TestNotAdd)
		{
			int add = _processor->Addition(15, 2);
			Assert::AreNotEqual(add, 16);
		}

		TEST_METHOD(TestNotDivide)
		{
			int divide = _processor->Division(8, 4);
			Assert::AreNotEqual(divide, 0);
		}

		TEST_METHOD(TestNotSubtract)
		{
			int minus = _processor->Subtraction(8, 7);
			Assert::AreNotEqual(minus, -1);
		}

		TEST_METHOD(TestNotMultipy)
		{
			int mult = _processor->Multiplication(5, 5);
			Assert::AreNotEqual(mult, 20);
		}

		TEST_METHOD(TestNotModulo)
		{
			int mod = _processor->Modulo(90, 5);
			Assert::AreNotEqual(mod, 2);
		}

		TEST_METHOD(TestNotDecimal)
		{
			_processor->setBaseNumber(198);
			Assert::AreNotEqual(_processor->GetDecimal(), string("891"));
		}

		TEST_METHOD(TestNotNegativeDecimal)
		{
			_processor->setBaseNumber(-198);
			Assert::AreNotEqual(_processor->GetDecimal(), string("198"));
		}



		TEST_METHOD(TestNotBin)
		{
			_processor->setBaseNumber(198);
			Assert::AreNotEqual(_processor->GetBinary(), string("0010000011100110"));
		}

		TEST_METHOD(TestNotHex)
		{
			_processor->setBaseNumber(198);
			Assert::AreNotEqual(_processor->GetHexadecimal(), string("0xD6"));
		}

	};
}
