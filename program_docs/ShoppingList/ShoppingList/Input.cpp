// Created by Will Plachno

#include "Input.h"
#include <iostream>

/* Implementation file for Input class
Functions:
 - char* Prompt(char* prompt);
 - MainMenuOption GetMainMenuChoice();
*/

		/* static char* StringPrompt(char* prompt) */
		/* Prints prompt, then gets the user input
		*/
char* Input::StringPrompt(char* prompt)
{
	std::cout << prompt << std::endl;
	char answer[MAX_INPUT_CHARS_STRING];
	std::cin >> answer;
	return answer;
}

/* static int MenuPrompt(char* prompt) */
/* Prints prompt, then gets the user input and converts to int
*/
int Input::MenuPrompt(char* prompt)
{
	std::cout << prompt << std::endl;
	char answer[MAX_INPUT_CHARS_MENU];
	std::cin >> answer;
	return str2Int(answer);
}

/* static int MainMenu() */
/* Prompts for the users main menu choice, then returns the option
*/
MainMenuOption Input::GetMainMenuChoice()
{
	int ans = -1;
	do
	{
		std::cout << "Your menu choice: ";
		char answer[MAX_INPUT_CHARS_MENU];
		std::cin >> answer;
		ans = str2Int(answer);
		if (ans > 9 || ans < 1)
			std::cout << "Invalid choice. (Valid: 1-9)" << std::endl;
	} while (ans < 10 && ans > 0);
	return (MainMenuOption)ans;
}

/* static int str2Int(char* charStr) */
/* Takes the argument and converts it into an int. If error, return -1;
*/
int Input::str2Int(char* charStr)
{
	int currentNum = 0;
	int curIndex = 0;
	while (charStr[curIndex] != '\0')
	{
		char curChar = charStr[curIndex];
		int numFromChar = (int)curChar - 48;
		if (numFromChar >= 0 && numFromChar <= 10)
		{
			currentNum *= 10;
			currentNum += numFromChar;
		}
		else if (curChar != ' ')
		{
			return -1;
		}
		++curIndex;
	}
	return currentNum;
}