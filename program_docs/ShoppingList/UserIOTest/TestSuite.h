#pragma once

/* Created by Will Plachno */
// De Anza Fall 2014 14F Goel
// Final Project Team 5 "Shopping List"

#include "Test.h"

/* class TestSuite
	A class built for running and printing a
	selection of test cases, built as Test objects
   Functions:
	- TestSuite()
	- TestSuite(string)
	- ~TestSuite()
	- void Print(ostream)
	- void Run()
	- void SetUpTests()
	- bool AddTest(Test)
   Members:
	- int numTests
	- Test tests[]
*/

class TestSuite
{
public:
	/* TestSuite() */
	// Generic constructor.
	TestSuite() : name("N/A"), numTests(0) { SetUpTests(); }

	/* TestSuite(string) */
	// Constructor + string name initialization.
	TestSuite(std::string suiteName) : name(suiteName), numTests(0) { SetUpTests(); }

	/* ~TestSuite() */
	// Generic destructor.
	~TestSuite(){ numTests = 0; name = "\0"; }

	/* void Print(ostream) */
	// Prints the status of all test cases
	void Print(std::ostream& out);

	/* void Run() */
	// Runs all of the test cases
	void Run();

	/* void SetUpTests */
	// The function that will instantiate all Test objects
	// and add them to this TestSuite. To create your own
	// TestSuite, inherit this class and rewrite this function
	// to create your own Tests.
	virtual void SetUpTests(){}

protected:

	/* bool AddTest(test) */
	// This function adds a new test to the array 
	// and increments numTests accordingly
	bool AddTest(Test test);

	/* string name */
	// A name for the testSuite
	std::string name;

	/* int numTests */
	// A counter for how many tests are currently in the array
	int numTests;

	/* Test tests[] */
	// The array of Test objects to be run.
	// Instantiated by SetUpTests(),
	// amount kept by numTests
	Test tests[40];
};

