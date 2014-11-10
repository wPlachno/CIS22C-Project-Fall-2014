// Created by Will Plachno
/* Implementation file for class MenuScreen

implements:
- int Display()
- bool isValidChoice(char* usrInput, int numChoices)
*/

#include "MenuScreen.h"
#include <iostream>
#include <cstdlib>

/*
int Display()
calls printDividedScreen()
then prompts for input and calls isValidChoice
*/
int MenuScreen::Display()
{
	bool readyForReturn = false;
	int input = -1;
	char* choicePrompt = "Please enter your choice: ";

	// Input certification loop
	while (!readyForReturn)
	{
		// Print the screen and the choice prompt
		printDividedScreen();
		std::cout << "* " << choicePrompt;

		// Read in the user input
		char usrInput[3];
		std::cin >> usrInput;
		std::cout << std::endl;

		// Convert the string to int. 
		// If the line is truly invalid, this will be -1
		input = str2Int(usrInput);

		// IF we have a valid choice, exit the loop.
		readyForReturn = isValidChoice(input, maxChoice);

		// Prepare header for invalid input screen.
		Header("Your choice was invalid.\nPlease try again");
	}
	return input;
}


/*
bool isValidChoice(char* usrInput, int numChoices)
checks the user input to make sure its valid
*/
bool MenuScreen::isValidChoice(int usrInput, int numChoices)
{
	bool qualifies = usrInput > 0;
	qualifies = qualifies && usrInput < numChoices + 1;
	return qualifies;
}

/*
int str2Int(char* input)
Uses ascii codes to convert char* to int
*/
int MenuScreen::str2Int(char* inputstr)
{
	// int input
	// the value of the usrInput as an int
	int input = 0;

	// int index
	// the current index of the usrInput array
	// which corresponds to the char we wish to conver to an int.
	int index = 0;

	// Check for negative.
	// Should never be necessary, but hey, lets be complete
	if (inputstr[0] == '-')
		index++;

	// Convert chars to int loop
	// until null char, multiply our current value by ten,
	// then add the int version of the char
	// ie "54\0", '5': inp=5, '4': 5*10=50  +4 = 54, '\0': end loop
	// Returns -1 if a character is non numeric
	while (inputstr[index] != '\0' && inputstr[index] != '\n')
	{
		if (inputstr[index] < 48 || inputstr[index] > 58)
		{
			return -1;
		}
		input *= 10;
		input += (inputstr[index] - 48);
		++index;
	}

	// Check for negative.
	// Should never be necessary, but hey, lets be complete
	if (inputstr[0] == '-')
		input *= -1;

	return input;
}