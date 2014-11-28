#pragma once

/* Created by Will Plachno */
// De Anza Fall 2014 14F Goel
// Final Project Team 5 "Shopping List"

#include "TestSuite.h"

/* class InputTestSuite 
	The TestSuite for the Input class
   Functions:
	- SetUpTests
	- Test1
	- Test2
	- Test3
	- Test4
	- Test5
	- Test6
	- Test7
	- Test8
	- Test9
	- Test10
	- Test11
	- Test12
	- Test13
	- Test14
	- Test15
	- Test16
	- Test17
	- Test18
	- Test19
	- Test20
	- Test21
	- Test22
	- Test23
	- Test24
	- Test25
	- Test26
	- Test27
	- Test28
	- Test29
	- Test30

*/
class InputTestSuite : public TestSuite
{
public:

	/* InputTestSuite() */
	// Generic constructor
	// Calls the TestSuite constructor with "Input" for the name
	InputTestSuite() : TestSuite("Input"){ SetUpTests(); }

	/* ~InputTestSuite() */
	// Generic destructor
	// Stub only. Not necessary
	~InputTestSuite(){}

	/* void SetUpTests() */
	// Sets up all the test cases, then adds
	// them through the TestSuite architecture
	void SetUpTests();

	/* ------ Test Functions ------ */

	/* Test1StringPromptBasic */
	// Tests basic functionality of StringPrompt
	static bool Test1_StringPromptBasic();

	/* Test2StringPromptWhitespace */
	// Tests StringPrompt for whitespace
	static bool Test2_StringPromptWhitespace();

	/* Test3IntPromptBasic */
	// Tests IntPrompt basic functionality
	static bool Test3_IntPromptBasic();

	/* Test4IntPromptWhitespace */
	// Tests IntPrompt for whitespace
	static bool Test4_IntPromptWhitespace();

	/* Test5IntPromptNoninteger */
	// Tests IntPrompt for non-integer input
	static bool Test5_IntPromptNoninteger();

	/* Test6DoublePromptBasic */
	// Tests DoublePrompt basic functionality
	static bool Test6_DoublePromptBasic();

	/* Test7DoublePromptWhitespace */
	// Tests DoublePrompt for whitespace
	static bool Test7_DoublePromptWhitespace();

	/* Test8DoublePromptNoninteger */
	// Tests DoublePrompt for non-integer input
	static bool Test8_DoublePromptNoninteger();

	/* Test9DoublePromptInteger */
	// Tests DoublePrompt for integer input
	static bool Test9_DoublePromptInteger();

	/* Test10MainMenuOptionAdd */
	// Tests GetMainMenuChoice for correct interpretation
	// of 1 as OPTION_ADD
	static bool Test10_MainMenuOptionAdd();

	/* Test11MainMenuOptionDelete */
	// Tests GetMainMenuChoice for correct interpretation
	// of 2 as OPTION_DELETE
	static bool Test11_MainMenuOptionDelete();

	/* Test12MainMenuOptionPrimaryKey */
	// Tests GetMainMenuChoice for correct interpretation
	// of 3 as OPTION_PRIMARYKEY
	static bool Test12_MainMenuOptionPrimaryKey();

	/* Test13MainMenuOptionHashSeq */
	// Tests GetMainMenuChoice for correct interpretation
	// of 4 as OPTION_HASHSEQ
	static bool Test13_MainMenuOptionHashSeq();

	/* Test14MainMenuOptionKeySeq */
	// Tests GetMainMenuChoice for correct interpretation
	// of 5 as OPTION_KEYSEQ
	static bool Test14_MainMenuOptionKeySeq();

	/* Test15MainMenuOptionBST */
	// Tests GetMainMenuChoice for correct interpretation
	// of 6 as OPTION_BST
	static bool Test15_MainMenuOptionBST();

	/* Test16MainMenuOptionEfficiency */
	// Tests GetMainMenuChoice for correct interpretation
	// of 7 as OPTION_EFFICIENCY
	static bool Test16_MainMenuOptionEfficiency();

	/* Test17MainMenuOptionByStore */
	// Tests GetMainMenuChoice for correct interpretation
	// of 8 as OPTION_BYSTORE
	static bool Test17_MainMenuOptionByStore();

	/* Test18MainMenuOptionQuit */
	// Tests GetMainMenuChoice for correct interpretation
	// of 9 as OPTION_QUIT
	static bool Test18_MainMenuOptionQuit();

	/* Test19MainMenuNonOption */
	// Tests GetMainMenuChoice for non-option integer
	static bool Test19_MainMenuNonOption();

	/* Test20MainMenuNonInteger */
	// Tests GetMainMenuChoice for non-integer input
	static bool Test20_MainMenuNonInteger();

	/* Test21Validate_y */
	// Tests Validate with 'y'
	static bool Test21_Validate_y();

	/* Test22Validate_Y */
	// Tests Validate with 'Y'
	static bool Test22_Validate_Y();

	/* Test23Validate_yes */
	// Tests Validate with 'yes'
	static bool Test23_Validate_yes();

	/* Test24Validate_Yes */
	// Tests Validate with 'Yes'
	static bool Test24_Validate_Yes();

	/* Test25Validate_true */
	// Tests Validate with 'true'
	static bool Test25_Validate_true();

	/* Test26Validate_y */
	// Tests Validate with 'True'
	static bool Test26_Validate_True();

	/* Test27ValidateInvalid */
	// Tests Validate with invalid
	static bool Test27_ValidateInvalid();

	/* Test28AddItemBasicFunctionality */
	// Tests the basic AddItem functionality
	static bool Test28_AddItemBasic();

	/* Test29AddItemBlanks */
	// Tests blank fields in the AddItem function
	static bool Test29_AddItemBlanks();

	/* Test30AddItemExists */
	// Tests AddItem when the item already exists
	static bool Test30_AddItemExists();
};

