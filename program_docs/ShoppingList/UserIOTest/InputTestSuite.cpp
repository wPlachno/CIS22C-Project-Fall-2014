/* Created by Will Plachno */
// De Anza Fall 2014 14F Goel
// Final Project Team 5 "Shopping List"

#include "InputTestSuite.h"
#include "Input.h"

/* Implementation file for InputTestSuite class
	Contains:
	- SetUpTests()
	- Test1()
	- Test2()
	- Test3()
	- Test4()
	- Test5()
	- Test6()
	- Test7()
	- Test8()
	- Test9()
	- Test10()
	- Test11()
	- Test12()
	- Test13()
	- Test14()
	- Test15()
	- Test16()
	- Test17()
	- Test18()
	- Test19()
	- Test20()
	- Test21()
	- Test22()
	- Test23()
	- Test24()
	- Test25()
	- Test26()
	- Test27()
	- Test28()
	- Test29()
	- Test30()
	- Test31()
	- Test32()
	- Test33()

*/

/* void SetUpTests() */
// Sets up all the test cases, then adds
// them through the TestSuite architecture
void InputTestSuite::SetUpTests()
{
	// Create name strings
	std::string test1Name = "StringPrompt Basic";
	std::string test2Name = "StringPrompt Whitespace";
	std::string test3Name = "IntPrompt Basic";
	std::string test4Name = "IntPrompt Whitespace";
	std::string test5Name = "IntPrompt Non-Integer";
	std::string test6Name = "DoublePrompt Basic";
	std::string test7Name = "DoublePrompt Whitespace";
	std::string test8Name = "DoublePrompt Non-Integer";
	std::string test9Name = "DoublePrompt Integer";
	std::string test10Name = "GetMainMenuChoice OPTION_ADD";
	std::string test11Name = "GetMainMenuChoice OPTION_DELETE";
	std::string test12Name = "GetMainMenuChoice OPTION_PRIMARYKEY";
	std::string test13Name = "GetMainMenuChoice OPTION_HASHSEQ";
	std::string test14Name = "GetMainMenuChoice OPTION_KEYSEQ";
	std::string test15Name = "GetMainMenuChoice OPTION_BST";
	std::string test16Name = "GetMainMenuChoice OPTION_EFFICIENCY";
	std::string test17Name = "GetMainMenuChoice OPTION_BYSTORE";
	std::string test18Name = "GetMainMenuChoice OPTION_QUIT";
	std::string test19Name = "GetMainMenuChoice Non-Option Integer";
	std::string test20Name = "GetMainMenuChoice Non-Integer";
	std::string test21Name = "Validate true on y";
	std::string test22Name = "Validate true on Y";
	std::string test23Name = "Validate true on yes";
	std::string test24Name = "Validate true on Yes";
	std::string test25Name = "Validate true on true";
	std::string test26Name = "Validate true on True";
	std::string test27Name = "Validate false on n";
	std::string test28Name = "AddItem Basic";
	std::string test29Name = "AddItem Blank fields";
	std::string test30Name = "AddItem Existing Item";
	std::string test31Name = "DeleteItem Basic";
	std::string test32Name = "DeleteItem Item Not Found";
	std::string test33Name = "DeleteItem Cancel";

	// Create TestFunction function pointers
	TestFunction test1Func = &Test1_StringPromptBasic;
	TestFunction test2Func = &Test2_StringPromptWhitespace;
	TestFunction test3Func = &Test3_IntPromptBasic;
	TestFunction test4Func = &Test4_IntPromptWhitespace;
	TestFunction test5Func = &Test5_IntPromptNoninteger;
	TestFunction test6Func = &Test6_DoublePromptBasic;
	TestFunction test7Func = &Test7_DoublePromptWhitespace;
	TestFunction test8Func = &Test8_DoublePromptNoninteger;
	TestFunction test9Func = &Test9_DoublePromptInteger;
	TestFunction test10Func = &Test10_MainMenuOptionAdd;
	TestFunction test11Func = &Test11_MainMenuOptionDelete;
	TestFunction test12Func = &Test12_MainMenuOptionPrimaryKey;
	TestFunction test13Func = &Test13_MainMenuOptionHashSeq;
	TestFunction test14Func = &Test14_MainMenuOptionKeySeq;
	TestFunction test15Func = &Test15_MainMenuOptionBST;
	TestFunction test16Func = &Test16_MainMenuOptionEfficiency;
	TestFunction test17Func = &Test17_MainMenuOptionByStore;
	TestFunction test18Func = &Test18_MainMenuOptionQuit;
	TestFunction test19Func = &Test19_MainMenuNonOption;
	TestFunction test20Func = &Test20_MainMenuNonInteger;
	TestFunction test21Func = &Test21_Validate_y;
	TestFunction test22Func = &Test22_Validate_Y;
	TestFunction test23Func = &Test23_Validate_yes;
	TestFunction test24Func = &Test24_Validate_Yes;
	TestFunction test25Func = &Test25_Validate_true;
	TestFunction test26Func = &Test26_Validate_True;
	TestFunction test27Func = &Test27_ValidateInvalid;
	TestFunction test28Func = &Test28_AddItemBasic;
	TestFunction test29Func = &Test29_AddItemBlanks;
	TestFunction test30Func = &Test30_AddItemExists;
	TestFunction test31Func = &Test31_DeleteItemBasic;
	TestFunction test32Func = &Test32_DeleteItemNotFound;
	TestFunction test33Func = &Test33_DeleteItemCancel;

	// Create the test cases
	Test test1(test1Name, test1Func);
	Test test2(test2Name, test2Func);
	Test test3(test3Name, test3Func);
	Test test4(test4Name, test4Func);
	Test test5(test5Name, test5Func);
	Test test6(test6Name, test6Func);
	Test test7(test7Name, test7Func);
	Test test8(test8Name, test8Func);
	Test test9(test9Name, test9Func);
	Test test10(test10Name, test10Func);
	Test test11(test11Name, test11Func);
	Test test12(test12Name, test12Func);
	Test test13(test13Name, test13Func);
	Test test14(test14Name, test14Func);
	Test test15(test15Name, test15Func);
	Test test16(test16Name, test16Func);
	Test test17(test17Name, test17Func);
	Test test18(test18Name, test18Func);
	Test test19(test19Name, test19Func);
	Test test20(test20Name, test20Func);
	Test test21(test21Name, test21Func);
	Test test22(test22Name, test22Func);
	Test test23(test23Name, test23Func);
	Test test24(test24Name, test24Func);
	Test test25(test25Name, test25Func);
	Test test26(test26Name, test26Func); 
	Test test27(test27Name, test27Func);
	Test test28(test28Name, test28Func);
	Test test29(test29Name, test29Func);
	Test test30(test30Name, test30Func);
	Test test31(test31Name, test31Func);
	Test test32(test32Name, test32Func);
	Test test33(test33Name, test33Func);
	
	// Add the Tests to the TestSuite architecture
	AddTest(test1);
	AddTest(test2);
	AddTest(test3);
	AddTest(test4);
	AddTest(test5);
	AddTest(test6);
	AddTest(test7);
	AddTest(test8);
	AddTest(test9);
	AddTest(test10);
	AddTest(test11);
	AddTest(test12);
	AddTest(test13);
	AddTest(test14);
	AddTest(test15);
	AddTest(test16);
	AddTest(test17);
	AddTest(test18);
	AddTest(test19);
	AddTest(test20);
	AddTest(test21);
	AddTest(test22);
	AddTest(test23);
	AddTest(test24);
	AddTest(test25);
	AddTest(test26);
	AddTest(test27);
	AddTest(test28);
	AddTest(test29);
	AddTest(test30);
	AddTest(test31);
	AddTest(test32);
	AddTest(test33);
}

/* ------ Test Functions ------ */

/* Test1StringPromptBasic */
// Tests basic functionality of StringPrompt
bool InputTestSuite::Test1_StringPromptBasic()
{
	std::string prompt, answer;
	prompt = "Please type 'hello' and press enter";
	answer = Input::StringPrompt(prompt);
	return answer == "hello";
}

/* Test2StringPromptWhitespace */
// Tests StringPrompt for whitespace
bool InputTestSuite::Test2_StringPromptWhitespace()
{
	std::string prompt, answer;
	prompt = "Please type '  hello  ' (2 spaces beginning and end) and press enter";
	answer = Input::StringPrompt(prompt);
	return answer == "hello";
}

/* Test3IntPromptBasic */
// Tests IntPrompt basic functionality
bool InputTestSuite::Test3_IntPromptBasic()
{
	std::string prompt;
	prompt = "Please type '1' and press enter";
	int answer = Input::IntPrompt(prompt);
	return answer == 1;
}

/* Test4IntPromptWhitespace */
// Tests IntPrompt for whitespace
bool InputTestSuite::Test4_IntPromptWhitespace()
{
	std::string prompt;
	prompt = "Please type '  1  ' (2 spaces beginning and end) and press enter";
	int answer = Input::IntPrompt(prompt);
	return answer == 1;
}

/* Test5IntPromptNoninteger */
// Tests IntPrompt for non-integer input
bool InputTestSuite::Test5_IntPromptNoninteger()
{
	std::string prompt;
	prompt = "Please type 'why' and press enter";
	int answer;
	try {
		answer = Input::IntPrompt(prompt);
	}
	catch (...) { return false; }
	return answer == -1;
}

/* Test6DoublePromptBasic */
// Tests DoublePrompt basic functionality
bool InputTestSuite::Test6_DoublePromptBasic()
{
	std::string prompt;
	prompt = "Please type '1.1' and press enter";
	double answer = Input::DoublePrompt(prompt);
	return answer == 1.1;
}

/* Test7DoublePromptWhitespace */
// Tests DoublePrompt for whitespace
bool InputTestSuite::Test7_DoublePromptWhitespace()
{
	std::string prompt;
	prompt = "Please type '  1.1  ' (2 spaces beginning and end) and press enter";
	double answer = Input::DoublePrompt(prompt);
	return answer == 1.1;
}

/* Test8DoublePromptNoninteger */
// Tests DoublePrompt for non-integer input
bool InputTestSuite::Test8_DoublePromptNoninteger()
{
	std::string prompt;
	prompt = "Please type 'why' and press enter";
	double answer;
	try {
		answer = Input::DoublePrompt(prompt);
	}
	catch (...) { return false; }
	return answer == -1;
}

/* Test9DoublePromptInteger */
// Tests DoublePrompt for integer input
bool InputTestSuite::Test9_DoublePromptInteger()
{
	std::string prompt;
	prompt = "Please type '1' and press enter";
	double answer = Input::DoublePrompt(prompt);
	return answer == 1.0;
}

/* Test10MainMenuOptionAdd */
// Tests GetMainMenuChoice for correct interpretation
// of 1 as OPTION_ADD
bool InputTestSuite::Test10_MainMenuOptionAdd()
{
	std::cout << "Please enter 1 after the prompt." << std::endl;
	MainMenuOption option = Input::GetMainMenuChoice();
	return option == MainMenuOption::OPTION_ADD;
}

/* Test11MainMenuOptionDelete */
// Tests GetMainMenuChoice for correct interpretation
// of 2 as OPTION_DELETE
bool InputTestSuite::Test11_MainMenuOptionDelete()
{
	std::cout << "Please enter 2 after the prompt." << std::endl;
	MainMenuOption option = Input::GetMainMenuChoice();
	return option == MainMenuOption::OPTION_DELETE;
}

/* Test12MainMenuOptionPrimaryKey */
// Tests GetMainMenuChoice for correct interpretation
// of 3 as OPTION_PRIMARYKEY
bool InputTestSuite::Test12_MainMenuOptionPrimaryKey()
{
	std::cout << "Please enter 3 after the prompt." << std::endl;
	MainMenuOption option = Input::GetMainMenuChoice();
	return option == MainMenuOption::OPTION_PRIMARYKEY;
}

/* Test13MainMenuOptionHashSeq */
// Tests GetMainMenuChoice for correct interpretation
// of 4 as OPTION_HASHSEQ
bool InputTestSuite::Test13_MainMenuOptionHashSeq()
{
	std::cout << "Please enter 4 after the prompt." << std::endl;
	MainMenuOption option = Input::GetMainMenuChoice();
	return option == MainMenuOption::OPTION_HASHSEQ;
}

/* Test14MainMenuOptionKeySeq */
// Tests GetMainMenuChoice for correct interpretation
// of 5 as OPTION_KEYSEQ
bool InputTestSuite::Test14_MainMenuOptionKeySeq()
{
	std::cout << "Please enter 5 after the prompt." << std::endl;
	MainMenuOption option = Input::GetMainMenuChoice();
	return option == MainMenuOption::OPTION_KEYSEQ;
}

/* Test15MainMenuOptionBST */
// Tests GetMainMenuChoice for correct interpretation
// of 6 as OPTION_BST
bool InputTestSuite::Test15_MainMenuOptionBST()
{
	std::cout << "Please enter 6 after the prompt." << std::endl;
	MainMenuOption option = Input::GetMainMenuChoice();
	return option == MainMenuOption::OPTION_BST;
}

/* Test16MainMenuOptionEfficiency */
// Tests GetMainMenuChoice for correct interpretation
// of 7 as OPTION_EFFICIENCY
bool InputTestSuite::Test16_MainMenuOptionEfficiency()
{
	std::cout << "Please enter 7 after the prompt." << std::endl;
	MainMenuOption option = Input::GetMainMenuChoice();
	return option == MainMenuOption::OPTION_EFFICIENCY;
}

/* Test17MainMenuOptionByStore */
// Tests GetMainMenuChoice for correct interpretation
// of 8 as OPTION_BYSTORE
bool InputTestSuite::Test17_MainMenuOptionByStore()
{
	std::cout << "Please enter 8 after the prompt." << std::endl;
	MainMenuOption option = Input::GetMainMenuChoice();
	return option == MainMenuOption::OPTION_BYSTORE;
}

/* Test18MainMenuOptionQuit */
// Tests GetMainMenuChoice for correct interpretation
// of 9 as OPTION_QUIT
bool InputTestSuite::Test18_MainMenuOptionQuit()
{
	std::cout << "Please enter 9 after the prompt." << std::endl;
	MainMenuOption option = Input::GetMainMenuChoice();
	return option == MainMenuOption::OPTION_QUIT;
}

/* Test19MainMenuNonOption */
// Tests GetMainMenuChoice for non-option integer
bool InputTestSuite::Test19_MainMenuNonOption()
{
	std::cout << "Please enter 10 after the prompt. Then enter 9 for valid input." << std::endl;
	MainMenuOption option;
	try {
		option = Input::GetMainMenuChoice();
	}
	catch (...) { return false; }
	return option == MainMenuOption::OPTION_QUIT;
}

/* Test20MainMenuNonInteger */
// Tests GetMainMenuChoice for non-integer input
bool InputTestSuite::Test20_MainMenuNonInteger()
{
	std::cout << "Please enter 'why' after the prompt. Then enter 9 for valid input." << std::endl;
	MainMenuOption option;
	try {
		option = Input::GetMainMenuChoice();
	}
	catch (...) { return false; }
	return option == MainMenuOption::OPTION_QUIT;
}

/* Test21Validate_y */
// Tests Validate with 'y'
bool InputTestSuite::Test21_Validate_y()
{
	std::string prompt, answer;
	prompt = "Please type 'y' and press enter";
	answer = Input::StringPrompt(prompt);
	return Input::Validate(answer);
}

/* Test22Validate_Y */
// Tests Validate with 'Y'
bool InputTestSuite::Test22_Validate_Y()
{
	std::string prompt, answer;
	prompt = "Please type 'Y' and press enter";
	answer = Input::StringPrompt(prompt);
	return Input::Validate(answer);
}

/* Test23Validate_yes */
// Tests Validate with 'yes'
bool InputTestSuite::Test23_Validate_yes()
{
	std::string prompt, answer;
	prompt = "Please type 'yes' and press enter";
	answer = Input::StringPrompt(prompt);
	return Input::Validate(answer);
}

/* Test24Validate_Yes */
// Tests Validate with 'Yes'
bool InputTestSuite::Test24_Validate_Yes()
{
	std::string prompt, answer;
	prompt = "Please type 'Yes' and press enter";
	answer = Input::StringPrompt(prompt);
	return Input::Validate(answer);
}

/* Test25Validate_true */
// Tests Validate with 'true'
bool InputTestSuite::Test25_Validate_true()
{
	std::string prompt, answer;
	prompt = "Please type 'true' and press enter";
	answer = Input::StringPrompt(prompt);
	return Input::Validate(answer);
}

/* Test26Validate_y */
// Tests Validate with 'True'
bool InputTestSuite::Test26_Validate_True()
{
	std::string prompt, answer;
	prompt = "Please type 'True' and press enter";
	answer = Input::StringPrompt(prompt);
	return Input::Validate(answer);
}

/* Test27ValidateInvalid */
// Tests Validate with invalid
bool InputTestSuite::Test27_ValidateInvalid()
{
	std::string prompt, answer;
	prompt = "Please type 'n' and press enter";
	answer = Input::StringPrompt(prompt);
	return !(Input::Validate(answer));
}

/* Test28AddItemBasicFunctionality */
// Tests the basic AddItem functionality
bool InputTestSuite::Test28_AddItemBasic()
{
	ShoppingList list;
	ListItem item1("Toilet Paper", 9.99, "Safeway", 4, "11/27/2014");
	ListItem item2("Coors Light", 14.99, "Chevron", 2, "11/26/2014");
	list.addRecord(item1);
	list.addRecord(item2);
	ListItem userItem("Water", 1.99, "Wal-Mart", 1, "11/21/2014");
	std::cout << "Please enter the following item into the prompts: " << std::endl;
	std::cout << "Name: Water, Date: 11/21/2014, Store: Wal-Mart, Quantity: 1, Cost: 1.99" << std::endl;
	Input::AddItem(list);
	return list.findRecord("Water", userItem);	
}

/* Test29AddItemBlanks */
// Tests blank fields in the AddItem function
bool InputTestSuite::Test29_AddItemBlanks()
{
	ShoppingList list;
	ListItem item1("Toilet Paper", 9.99, "Safeway", 4, "11/27/2014");
	ListItem item2("Coors Light", 14.99, "Chevron", 2, "11/26/2014");
	list.addRecord(item1);
	list.addRecord(item2);
	ListItem userItem("Water", 1.99, "Wal-Mart", 1, "11/21/2014");
	std::cout << "Please enter the following item into the prompts: " << std::endl;
	std::cout << "Name: Water, Cost: _, Store: _, Quantity: _, Date: _" << std::endl;
	Input::AddItem(list);
	if (list.findRecord("Water", userItem))
	{
		bool success = true;
		success = success && (userItem.getCost() == -1);
		success = success && (userItem.getDate() == "EMPTY DATE");
		success = success && (userItem.getQuantity() == -1);
		success = success && (userItem.getStore() == "EMPTY STORE");
		return success;
	}
	else {
		return false;
	}
}

/* Test30AddItemExists */
// Tests AddItem when the item already exists
bool InputTestSuite::Test30_AddItemExists()
{
	ShoppingList list;
	ListItem item1("Toilet Paper", 9.99, "Safeway", 4, "11/27/2014");
	ListItem item2("Coors Light", 14.99, "Chevron", 2, "11/26/2014");
	list.addRecord(item1);
	list.addRecord(item2);
	std::cout << "Please attempt to enter 'Coors Light' as an item. \nTry again and attempt 'Toilet Paper'.\nAfter that do not attempt to add another item." << std::endl;
	Input::AddItem(list);
    std::string answer = Input::StringPrompt("As expected?");
	return Input::Validate(answer);
}

/* Test31DeleteItemBasic */
// Tests DeleteItem basic functionality
bool InputTestSuite::Test31_DeleteItemBasic()
{
	ShoppingList list;
	ListItem item1("Toilet Paper", 9.99, "Safeway", 4, "11/27/2014");
	ListItem item2("Coors Light", 14.99, "Chevron", 2, "11/26/2014");
	list.addRecord(item1);
	list.addRecord(item2);
	std::cout << "Please delete 'Coors Light'." << std::endl;
	Input::DeleteItem(list);
	return (!(list.findRecord("Coors Light", item2))) && list.getItemCount() == 1;
}

/* Test32DeleteItemNotFound */
// DeleteItem when trying to delete an item that
// does not exist in the list.
bool InputTestSuite::Test32_DeleteItemNotFound()
{
	ShoppingList list;
	ListItem item1("Toilet Paper", 9.99, "Safeway", 4, "11/27/2014");
	ListItem item2("Coors Light", 14.99, "Chevron", 2, "11/26/2014");
	list.addRecord(item1);
	list.addRecord(item2);
	std::cout << "Please try to delete 'Bud Light'." << std::endl;
	Input::DeleteItem(list);
	return list.getItemCount() == 2;
}

/* Test33DeleteItemCancel */
// DeleteItem when the user cancels the delete
bool InputTestSuite::Test33_DeleteItemCancel()
{
	ShoppingList list;
	ListItem item1("Toilet Paper", 9.99, "Safeway", 4, "11/27/2014");
	ListItem item2("Coors Light", 14.99, "Chevron", 2, "11/26/2014");
	list.addRecord(item1);
	list.addRecord(item2);
	std::cout << "Please begin to delete 'Coors Light', but cancel when asked for final verification." << std::endl;
	Input::DeleteItem(list);
	return list.findRecord("Coors Light", item2) && list.getItemCount() == 2;
}
