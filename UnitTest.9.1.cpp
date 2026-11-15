#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "../PR.9.1/var.cpp"
#include "../PR.9.1/dod.cpp"
#include "../PR.9.1/sum.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nsVar;

namespace UnitTest9_1
{
	TEST_CLASS(UnitTest9_1)
	{
	public:

		// ---------- dod ----------
		TEST_METHOD(TestDod_SecondTerm)
		{
			x = 0.5; n = 1; a = x; // a0 = x
			nsDod::dod();          // a1 = x^3 / 3
			Assert::AreEqual(0.5 * 0.5 * 0.5 / 3, a, 1e-12);
		}

		TEST_METHOD(TestDod_ThirdTerm)
		{
			x = 0.5; n = 2; a = 0.5 * 0.5 * 0.5 / 3; // a1
			nsDod::dod();                            // a2 = x^5 / 5
			Assert::AreEqual(pow(0.5, 5) / 5, a, 1e-12);
		}

		// ---------- sum ----------
		TEST_METHOD(TestSum_PositiveX)
		{
			x = 0.5; e = 1e-8;
			nsSum::sum();
			Assert::AreEqual(atanh(0.5), s, 1e-7);
		}

		TEST_METHOD(TestSum_NegativeX)
		{
			x = -0.3; e = 1e-8;
			nsSum::sum();
			Assert::AreEqual(atanh(-0.3), s, 1e-7);
		}

		TEST_METHOD(TestSum_ZeroX)
		{
			x = 0; e = 1e-6;
			nsSum::sum();
			Assert::AreEqual(0.0, s, 1e-12);
		}

		TEST_METHOD(TestSum_TermsCount)
		{
			x = 0.5; e = 1e-3;
			nsSum::sum();
			Assert::AreEqual(4, n); // n – номер останнього доданку
		}
	};
}
