#pragma once

/* Created by Will Plachno */
// De Anza Fall 2014 14F Goel
// Final Project Team 5 "Shopping List"

#include <string>
#include <iostream>

// typedef: TestFunction
// A function pointer
// function must be: bool myfunc();
// For example,
//  bool myfunc(){ return true; }
//  TestFunction testFunc = &myfunc;
//  cout << (*afunc)() << endl;
//  would output the cout equivalent of true;
typedef bool(*TestFunction)();

// enum: TestStatus
// An enum that holds the current status for the test case
// either NotYetRun, Success, or Failure
enum TestStatus{ NotYetRun, Success, Failure };

/* class Test
	A class that represents a test of code.
   Note: ~Test is unneccessary. Function pointers do not need to be deleted.

	Accessibility Functions:
	- Test() - Generic constructor
	- Test(string, TestFunction) - constructor with test name and test function
	- ~Test() - Generic destructor
	- Name() - Accessor/Setter for test name
	- TestFunc() - Accessor/Setter for test function
	- Status() - Accessor for the status of the test
	Method Functions:
	- Run() - Runs the test and saves the status 
	- operator<< overload - Allows the testcase to be printed easily
	Members:
	- testFunction - pointer to the function to run
	- name - name of the test case
	- status - status of the test case. Either NotYetRun, Success, or Failure
*/

class Test
{
public:

	/* Test() */
	// Generic constructor. Sets the testFunction ptr to null, and the bools to false.
	Test() : name("N/A"), testFunction(nullptr), status(NotYetRun){}

	/* Test(string testName, TestFunction testPtr) */
	// Constructor with the test name and the test function
	Test(std::string testName, TestFunction testPtr) : name(testName), testFunction(testPtr), status(NotYetRun){}

	/* ~Test() */
	// Generic destructor. simply sets testfunction to null, name to empty, and status to NotYetRun
	~Test() { testFunction = nullptr; name = '\0'; status = NotYetRun; }

	/* void Name(string) */
	// Setter for the name member
	void Name(const std::string str) { name = str; }

	/* string Name() */
	// Accessor for the name member
	const std::string Name() { return name; }

	/* void TestFunc(TestFunction func) */
	// Setter for the testFunction member
	void TestFunc(const TestFunction func) { testFunction = func; }

	/* TestFunction TestFunc() */
	// Accessor for the testFunction member
	const TestFunction TestFunc() { return testFunction; }

	/* TestStatus Status() */
	// Accessor for the status member
	const TestStatus Status() { return status; }

	/* bool Run() */
	// Runs the test function through the testFunction pointer
	// Returns true if the test was a success and false if it failed or was not run
	// Note: the status of this test is only set after the testFunction
	//       has completely finished. Also, if testFunction == nullptr,
	//       status is not changed.
	bool Run();

	/* << Overloader */
	// Allows the test to be printable to a stream
	// Prints: "[name]: [status]"
	friend std::ostream& operator<<(std::ostream& out, const Test& testCase);

private:

	/* string name */
	// the test name. Get/set by Name()
	std::string name;

	/* TestFunction testFunction */
	// Placeholder for the function which runs the test.
	// Get/set by TestFunc()
	TestFunction testFunction;

	/* TestStatus status */
	// Holds the current status of the test
	TestStatus status;
};

