// Created by Will Plachno

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