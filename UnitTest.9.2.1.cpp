#include "pch.h"
#include "CppUnitTest.h"
#include "../PR.9.2.1/task1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest9_2_1
{
	TEST_CLASS(UnitTest9_2_1)
	{
	public:

		// тести для Z_VAL = 5 (гілка z > 3)
		TEST_METHOD(TestCalc_SecondSquareIsGreater)
		{
			static_assert(Z_VAL == 5, "tests are written for Z_VAL = 5");
			Assert::AreEqual(16.0, Calc(1, 2), 1e-12); // max(9, 16)
		}

		TEST_METHOD(TestCalc_Zeros)
		{
			Assert::AreEqual(25.0, Calc(0, 0), 1e-12); // max(0, 25)
		}

		TEST_METHOD(TestCalc_Negative)
		{
			Assert::AreEqual(49.0, Calc(-2, 1), 1e-12); // max(1, 49)
		}

		TEST_METHOD(TestCalc_FirstSquareIsGreater)
		{
			Assert::AreEqual(100.0, Calc(5, 5), 1e-12); // max(100, 0)
		}
	};
}
