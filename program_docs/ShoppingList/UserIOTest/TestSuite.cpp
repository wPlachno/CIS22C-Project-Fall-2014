/* Created by Will Plachno */
// De Anza Fall 2014 14F Goel
// Final Project Team 5 "Shopping List"

#include "TestSuite.h"

/* Implementation file for the TestSuite class
   Contains:
	- void Print(ostream&)
	- void Run()
	- void SetUpTests()
	- bool AddTest(Test)
*/

/* void Print(ostream) */
// Prints the status of all test cases
void TestSuite::Print(std::ostream& out)
{
	// Print Header
	std::cout << name << " Test Suite: " << std::endl;

	// If the suite is empty
	if (numTests == 0)
	{
		std::cout << "There are no tests in this suite." << std::endl;
	}
	else // The suite is not empty...
	{
		// Set up status counters
		int numSuccess = 0, numFailure = 0, numNotYet = 0;

		// With each test...
		for (int i = 0; i < numTests; ++i)
		{
			// Print it...
			std::cout << "- " << tests[i] << std::endl;

			// Then increment the respective status counter
			TestStatus thisTest = tests[i].Status();
			if (thisTest == TestStatus::Success)
				++numSuccess;
			else if (thisTest == TestStatus::Failure)
				++numFailure;
			else
				++numNotYet;
		}

		// Then print the summary
		std::cout << name << " Summary ------------------- " << numSuccess << "/" << numTests << " tests passed" << std::endl;
		std::cout << "Failed tests:      " << numFailure << " tests" << std::endl;
		std::cout << "Incomplete tests:  " << numNotYet << " tests" << std::endl;
		std::cout << "Successful tests: " << numSuccess << " tests" << std::endl;
		std::cout << std::endl;
	}
}

/* void Run() */
// Runs all of the test cases
void TestSuite::Run()
{
	// Just run em all!
	for (int i = 0; i < numTests; ++i)
	{
		tests[i].Run();
		std::cout << std::endl << std::endl;
	}
}

/* bool AddTest(test) */
// This function adds a new test to the array 
// and increments numTests accordingly
bool TestSuite::AddTest(Test test)
{
	// If the tests array is full, dont add
	if (numTests == 30)
		return false;

	// Otherwise, put the new test in the first available slot
	tests[numTests] = test;

	// Increment how many tests we have
	++numTests;

	// Send success signal
	return true;
}