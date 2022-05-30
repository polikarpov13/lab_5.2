#include "pch.h"
#include "CppUnitTest.h"
#include "../../../../../політех/ооп/5/lab_5.2/lab_5.2/lab_5.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a = 5;
			int b = 2;
		
			Assert::AreEqual(2, wholePart1(a, b));
		}
	};
}
