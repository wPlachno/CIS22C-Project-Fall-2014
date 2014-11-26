/* Created by Will Plachno */
// De Anza Fall 2014 14F Goel
// Final Project Team 5 "Shopping List"

#include "OutputTestSuite.h"
#include "Input.h"
#include "Output.h"

/* Implementation file for OutputTestSuite class
Contains:
- SetUpTests()
- Test1()
- Test2()
- Test3()
- Test4()
- Test5()
- Test6()

*/

/* void SetUpTests() */
// Sets up all the test cases, then adds
// them through the TestSuite architecture
void OutputTestSuite::SetUpTests()
{
	// Create test names
	std::string test1Name = "PrintLanding Basic";
	std::string test2Name = "PrintMainMenu Basic";
	std::string test3Name = "PrintError Basic";
	std::string test4Name = "PrintItem Basic";
	std::string test5Name = "PrintItem Blank Fields";
	std::string test6Name = "PrintItem Cost View Normalized";

	// Create test function pointers
	TestFunction testFunc1 = &Test1_PrintLanding;
	TestFunction testFunc2 = &Test2_PrintMainMenu;
	TestFunction testFunc3 = &Test3_PrintError;
	TestFunction testFunc4 = &Test4_PrintItemBasic;
	TestFunction testFunc5 = &Test5_PrintItemBlanks;
	TestFunction testFunc6 = &Test6_PrintItemCrazyCost;

	// Create Tests
	Test test1(test1Name, testFunc1);
	Test test2(test2Name, testFunc2);
	Test test3(test3Name, testFunc3);
	Test test4(test4Name, testFunc4);
	Test test5(test5Name, testFunc5);
	Test test6(test6Name, testFunc6);

	// Add Tests
	AddTest(test1);
	AddTest(test2);
	AddTest(test3);
	AddTest(test4);
	AddTest(test5);
	AddTest(test6);
}

/* ------ Test Functions ------ */

/* Test1PrintLanding */
// Tests basic functionality of PrintLanding
bool OutputTestSuite::Test1_PrintLanding()
{
	Output::PrintLanding();
	std::string answer = Input::StringPrompt("As expected?");
	return Input::Validate(answer);
}

/* Test2PrintMainMenu */
// Tests PrintMainMenu for basic functionality
bool OutputTestSuite::Test2_PrintMainMenu()
{
	Output::PrintMainMenu();
	std::string answer = Input::StringPrompt("As expected?");
	return Input::Validate(answer);
}

/* Test3PrintError */
// Tests PrintError for basic functionality
bool OutputTestSuite::Test3_PrintError()
{
	std::string errMsg = "Fake Error";
	Output::PrintError(errMsg);
	std::string answer = Input::StringPrompt("As expected?");
	return Input::Validate(answer);
}

/* Test4PrintItem Basic */
// Tests PrintItem for basic functionality
bool OutputTestSuite::Test4_PrintItemBasic()
{
	ListItem fakeItem("Wishes", 1000.99, "The Dream Store", 1000, "Today");
	Output::PrintItem(fakeItem);
	std::string prompt = "name: Wishes, cost: $1000.99, store: The Dream Store, quantity: 1000, date: Today. \nDid you see all these aspects of the item get printed?";
	std::string answer = Input::StringPrompt(prompt);
	return Input::Validate(answer);
}

/* Test5PrintItem Blanks */
// Tests PrintItem for nonexistent fields
bool OutputTestSuite::Test5_PrintItemBlanks()
{
	ListItem fakeItem("Wishes");
	Output::PrintItem(fakeItem);
	std::string prompt = "Did you only see the name (Wishes) printed?";
	std::string answer = Input::StringPrompt(prompt);
	return Input::Validate(answer);
}

/* Test6PrintItemCrazyCost */
// Tests PrintItem for cost display
bool OutputTestSuite::Test6_PrintItemCrazyCost()
{
	ListItem fakeItem("Wishes", 1000.99001, "The Dream Store", 1000, "Today");
	Output::PrintItem(fakeItem);
	std::string prompt = "Did the cost print as $1000.99?";
	std::string answer = Input::StringPrompt(prompt);
	return Input::Validate(answer);
}