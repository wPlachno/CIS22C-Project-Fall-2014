#pragma once

/* Created by Will Plachno */
// De Anza Fall 2014 14F Goel
// Final Project Team 5 "Shopping List"

#include "TestSuite.h"

/* class OutputTestSuite
The TestSuite for the Output class
Functions:
	- SetUpTests
	- Test1
	- Test2
	- Test3
	- Test4
	- Test5
	- Test6

*/
class OutputTestSuite : public TestSuite
{
public:

	/* OutputTestSuite() */
	// Generic constructor
	// Calls the TestSuite constructor with "Output" for the name
	OutputTestSuite() : TestSuite("Output"){ SetUpTests(); }

	/* ~OutputTestSuite() */
	// Generic destructor
	// Stub only. Not necessary
	~OutputTestSuite(){}

	/* void SetUpTests() */
	// Sets up all the test cases, then adds
	// them through the TestSuite architecture
	void SetUpTests();

	/* ------ Test Functions ------ */

	/* Test1PrintLanding */
	// Tests basic functionality of PrintLanding
	static bool Test1_PrintLanding();

	/* Test2PrintMainMenu */
	// Tests PrintMainMenu for basic functionality
	static bool Test2_PrintMainMenu();

	/* Test3PrintError */
	// Tests PrintError for basic functionality
	static bool Test3_PrintError();

	/* Test4PrintItem Basic */
	// Tests PrintItem for basic functionality
	static bool Test4_PrintItemBasic();

	/* Test5PrintItem Blanks */
	// Tests PrintItem for nonexistent fields
	static bool Test5_PrintItemBlanks();

	/* Test6PrintItemCrazyCost */
	// Tests PrintItem for cost display
	static bool Test6_PrintItemCrazyCost();
};

