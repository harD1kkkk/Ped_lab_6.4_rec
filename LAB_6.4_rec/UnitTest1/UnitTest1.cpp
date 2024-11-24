#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>  
#include "../LAB_6.4_rec/lab_6.4_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestFindMaxAbsIndex)
		{
			double arr[] = { -3.0, 4.5, -7.2, 2.0, 1.1 };
			int size = 5;

			int result = FindMaxAbsIndex(arr, size);

			int expected = 2; 

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestFindElementsProductAfterMaxAbs)
		{
			double arr[] = { -3.0, 4.5, -7.2, 2.0, 1.1 };
			int size = 5;

			int maxAbsIndex = FindMaxAbsIndex(arr, size);

			double result = FindElementsProductAfterMaxAbs(arr, size, maxAbsIndex);

			double expected = 2.0 * 1.1; 

			Assert::AreEqual(expected, result, 0.001);
		}
	};
}
