#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextFileTest{		
	TEST_CLASS(TextFileTest){
	public:
		
		TEST_METHOD(SortTest1){
		//compare initial letters of each line of content
			TextFile testFile("testFile");
			testFile.addCommand("b");
			testFile.addCommand("a");		
			testFile.addCommand("A");

			testFile.sortAllCommands();

			std::string actualOutput = testFile.toString();

			std::string expectedOutput = { "1.	A\n2.	a\n3.	b\n" };
			Assert::AreEqual(expectedOutput, actualOutput);
		}

		TEST_METHOD(SortTest2){
		//when the inital letters are the same, test whether the function manage to sort according to the 2nd letter in line
			TextFile testFile("testFile");
			testFile.addCommand("ab");
			testFile.addCommand("ac");
			testFile.addCommand("a2");
			testFile.addCommand("aC");

			testFile.sortAllCommands();

			std::string actualOutput = testFile.toString();

			std::string expectedOutput = { "1.	a2\n2.	aC\n3.	ab\n4.	ac\n" };
			Assert::AreEqual(expectedOutput, actualOutput);
		}

		TEST_METHOD(SortTest3){
		//test whether the function can sort lines of different lengths)
			TextFile testFile("testFile");
			testFile.addCommand("abb");
			testFile.addCommand("d");
			testFile.addCommand("t23de");
			testFile.addCommand("abbc");

			testFile.sortAllCommands();

			std::string actualOutput = testFile.toString();

			std::string expectedOutput = { "1.	abb\n2.	abbc\n3.	d\n4.	t23de\n" };
			Assert::AreEqual(expectedOutput, actualOutput);
		}

		TEST_METHOD(SearchTest1){
		//test whether lines containing key word can be found
			TextFile testFile("testFile");
			testFile.addCommand("a little fox");
			testFile.addCommand("a big cat");
			testFile.addCommand("2 cats fight");

			std::string actualOutput = testFile.searchKeyWord("cat");

			std::string expectedOutput = { "a big cat\n2 cats fight\n" };
			Assert::AreEqual(expectedOutput, actualOutput);
		}

		TEST_METHOD(SearchTest2){
		//test whether function search can handle the case where key word cannot be found
			TextFile testFile("testFile");
			testFile.addCommand("a little fox");
			testFile.addCommand("a big car");

			std::string actualOutput = testFile.searchKeyWord("cat");

			std::string expectedOutput = { "key word cannot be found\n" };
			Assert::AreEqual(expectedOutput, actualOutput);
		}
	};
}