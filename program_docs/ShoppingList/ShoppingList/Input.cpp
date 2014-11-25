// Created by Will Plachno

#include "Input.h"
#include <iostream>

/* Implementation file for Input class
Functions:
 - char* Prompt(char* prompt);
 - MainMenuOption GetMainMenuChoice();
*/


/* static const string StringPrompt(string prompt) */
/* Prints prompt, then gets the user input
*/
const std::string Input::StringPrompt(const std::string prompt)
{
	std::cout << prompt << std::endl;
	std::string answer;
	std::cin >> answer;
	answer = answer.substr(answer.find_first_not_of(' '), answer.find_last_not_of(' '));
	return answer;

}

/* static const double DoublePrompt(string prompt) */
/* Prints prompt, then gets the user input
*/
const double Input::DoublePrompt(const std::string prompt)
{
	std::cout << prompt << std::endl;
	std::string answer;
	std::cin >> answer;
	return str2Dbl(answer);
}

/* static int MenuPrompt(char* prompt) */
/* Prints prompt, then gets the user input and converts to int
*/
const int Input::IntPrompt(std::string prompt)
{
	std::cout << prompt << std::endl;
	std::string answer;
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
		std::string answer;
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
const int Input::str2Int(const std::string charStr)
{
	return std::stoi(charStr, nullptr);
}

/* static double str2Dbl(string charStr) */
/* Takes the argument and converts it into a double. If error, return -1;
*/
const double Input::str2Dbl(const std::string charStr)
{
	return std::stod(charStr, nullptr);
}