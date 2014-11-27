/* Created by Will Plachno */
// De Anza Fall 2014 14F Goel
// Final Project Team 5 "Shopping List"

#include "InputTestSuite.h"
#include "OutputTestSuite.h"

/* int main function */
// Instantiates the test suites, runs them, 
// then prints them to the screen
int main()
{
	// Instantiate TestSuites
	InputTestSuite* inTest = new InputTestSuite();
	OutputTestSuite* outTest = new OutputTestSuite();

	// Run TestSuites
	inTest->Run();
	outTest->Run();

	// Print Test Results
	inTest->Print(std::cout);
	outTest->Print(std::cout);

	// Wait
	system("pause");
}