/* Created by Will Plachno */
// De Anza Fall 2014 14F Goel
// Final Project Team 5 "Shopping List"

#include "Test.h"

/* Implementation file for the Test class 

Contains:
- bool Run()
- << Operator

*/

/* bool Run() */
// Runs the test function through the testFunction pointer
// Returns true if the test was a success and false if it failed or was not run
// Note: the status of this test is only set after the testFunction
//       has completely finished. Also, if testFunction == nullptr,
//       status is not changed.
bool Test::Run()
{
	// First check for null funcptr
	if (testFunction == nullptr)
		return false;

	// bool for the return value of the function pointed
	// to by testFunction
	bool functionReturnBool;

	try {
		
		// Call the testFunction
		functionReturnBool = (*testFunction)();

		// Set status appropriately
		status = (functionReturnBool ? Success : Failure);
		return functionReturnBool;

	}
	catch (...) { 

		// If ANY exceptions are caught, set the test to failed.
		status = Failure; 
		return false; 
	}
}

/* << Overloader */
// Allows the test to be printable to a stream
// Prints: "[name]: [status]"
std::ostream& operator<<(std::ostream& out, const Test& testCase)
{
	std::string statusStr = "failed";
	if (testCase.status == TestStatus::Success)
		statusStr = "successful";
	else if (testCase.status == TestStatus::NotYetRun)
		statusStr = "not run";
	out << testCase.name << ": " << statusStr;
	return out;
}