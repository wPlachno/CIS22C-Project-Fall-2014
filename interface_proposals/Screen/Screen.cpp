// Created by Will Plachno
/* Implementation file for the Screen class

includes:
- int  Display()
- void print  ()
- int  print  (int   startChar)
- void print  (char* miniPrompt)
*/

#include <iostream>
#include "Screen.h"
#include <string>

/*
int Display()
Prints the screen for the user, then pauses.
returns 0; The int return value is used mainly for
inheriting classes
*/
int Screen::Display()
{
	// print top border
	print();

	// Loop - until we've filled the height minus the
	// 'press a key to continue' prompt and the bottom border (23)
	print(prompt, SCREENHEIGHT - 3, 0);

	// print bottom border
	print();

	system("pause");

	std::cout << std::endl;

	return 0;
}

/*
void print()
prints a line of asterisks equal to the SCREENWIDTH
*/
void Screen::print()
{
	std::cout << std::string(SCREENWIDTH, '*') << std::endl;
}

/*
int print(int startChar)
Prints the prompt starting at startChar
Returns the next start pos for the next line
or -1 if complete.
*/
int Screen::print(int startChar)
{
	return print(prompt, startChar);
}

/*
void print(char* miniPrompt)
prints miniPrompt in a bordered line, right-aligned 
*/
void Screen::print(char* miniPrompt)
{
	// int promptSize
	// calculated by looping through the char* until we find '\0' or '\n'
	int promptSize = 0;
	while (miniPrompt[promptSize] != '\0' && miniPrompt[promptSize] != '\n') { ++promptSize; }

	// int numberOfSpacesBeforePrompt
	// the number of spaces to put before the prompt in
	// order to make it right-aligned.
	// Calculated by the width of the screen, then
	// subtracting the border and padding ( 1 ' ' each side)
	// and the size of the prompt
	int numberOfSpacesBeforePrompt = SCREENWIDTH - 4 - promptSize;

	// if this can fit inside the border
	// print the border, padding, spaces, prompt, padding and border
	if (numberOfSpacesBeforePrompt >= 0)
	{
		// print front border, padding, and right-align spaces
		std::cout << "* " << std::string(numberOfSpacesBeforePrompt, ' ');

		// print promptSize of the miniPrompt
		for (int i = 0; i < promptSize; ++i)
		{
			std::cout << miniPrompt[i];
		}

		// print right padding, border, and endline
		std::cout << " *" << std::endl;
	}
	// if this cannot fit inside the border,
	else {
		print("ERROR: Cannot fit prompt in line");
	}
}


/*
int print(char* promptStr, int startChar)
prints promptStr in a bordered line, starting at the startChar index
*/
int Screen::print(char* promptStr, int startChar)
{
	// if we have already run through the entire promptStr,
	// fill this line with spaces.
	if (startChar == -1)
	{
		std::cout << "* " << std::string(SCREENWIDTH - 4, ' ') << " *" << std::endl;
		return -1;
	}

	// char termChar
	// Keeps track of the char that ends the line.
	// will be either:
	// - \0  - end of prompt
	// - \n  - end of current line
	// - ' ' - end of last word that will fit
	char termChar = '!';

	// int termPos
	// the index of the last character of the prompt that will be printed
	// note: print this index too! The next index will be the terminal char.
	// the index after that is the first char of the next line.
	int termPos = startChar;

	// bool foundEnd
	// States whether we have found the terminal char
	bool foundEnd = false;

	// Loop - find the terminal char and position
	// int i = the current test character
	// until flag foundEnd is set true
	for (int i = startChar; !foundEnd; ++i)
	{
		// if we find one of the terminal chars '\0' or '\n
		// set the terminal char to the correct char
		// then set the terminal pos to the last char to be printed
		// Note: the last char to be printed is the char behind the terminal char.
		if (promptStr[i] == '\0' || promptStr[i] == '\n')
		{
			termChar = promptStr[i];
			termPos = i - 1;
			foundEnd = true;
		}

		// if we have reached the last char allowed by screen size
		// loop back until we find the last break between words
		// terminal char becomes a space
		// terminal position set to the index of the last letter of the last word
		else if (i == startChar + SCREENWIDTH - 5)
		{
			for (int j = i; j > termPos; --j)
			{
				if (promptStr[j] == ' ')
				{
					termChar = ' ';
					termPos = j - 1;
					foundEnd = true;
				}
			}
		}
	}

	// print left side buffer
	std::cout << '*' << ' ';

	// print content
	int numTabs = 0;
	for (int i = startChar; i < SCREENWIDTH - 4 + startChar + numTabs; ++i)
	{
		// print spaces past terminal character
		if (i > termPos)
			std::cout << ' ';

		// print prompt
		else if (promptStr[i] != '\t')
			std::cout << promptStr[i];
		else
			++numTabs;
	}

	// Print right side buffer
	std::cout << ' ' << '*' << std::endl;

	// if terminal char is null or the beginning of the next line is null, return -1
	if (termChar == '\0' || promptStr[termPos + 2] == '\0')
	return -1;

	// return the character after the terminal char
	return termPos + 2;

}

/*
void print(char* promptStr, int numLinesToPrint, int startChar)
prints bordered promptStr lines for numLinesToPrint lines starting from startChar
returns the index of the next char to be printed if end was not reached
*/
int Screen::print(char* promptStr, int numLinesToPrint, int startChar)
{
	int currentLine = 0;
	int nextStartIndex = startChar;
	// Loop - until we've filled numLinesToPrint
	while (currentLine < numLinesToPrint)
	{
		// This will print the prompt line-by-line, then
		// fill the rest with bordered lines.
		nextStartIndex = print(promptStr, nextStartIndex);
		++currentLine;
	}
	return nextStartIndex;
}