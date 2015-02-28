#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextFileTest
{		
	TEST_CLASS(TextFileTest)
	{
	public:
		
		TEST_METHOD(SortTest)
		{
			TextFile testFile("testFile");
			testFile.addCommand("b");
			testFile.addCommand("a");		
			testFile.addCommand("A");

			testFile.sortAllCommands();

			std::string actualOutput = testFile.toString();

			std::string expectedOutput = { "1.	A\n2.	a\n3.	b\n" };
			Assert::AreEqual(expectedOutput, actualOutput);
		}

	};
}