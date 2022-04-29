#include "pch.h"
#include "CppUnitTest.h"
#include "../Object.h"
#include "../Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UTlab33G
{
	TEST_CLASS(UTlab33G)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Object t;
			int a = t.Count();
			Assert::AreEqual(a, 1);
		}
	};
}
