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
	answer = answer.substr(answer.find_first_not_of(' '), answer.find_last_not_of(' ')+1);
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
	} while (ans > 9 || ans < 1);
	return (MainMenuOption)ans;
}

/* bool Validate(string) */
// Basically checks whether the argument is equivalent to 
// a positive statement, either "y", "Y", "yes", "Yes", "true", "True"
bool Input::Validate(std::string input)
{
	if (input == "y" || input == "Y")
		return true;
	else if (input == "yes" || input == "Yes")
		return true;
	else if (input == "true" || input == "True")
		return true;
	return false;
}

/* static int str2Int(char* charStr) */
/* Takes the argument and converts it into an int. If error, return -1;
*/
const int Input::str2Int(const std::string charStr)
{
	try {
		return std::stoi(charStr, nullptr);
	}
	catch (...) { return -1; }
}

/* static double str2Dbl(string charStr) */
/* Takes the argument and converts it into a double. If error, return -1;
*/
const double Input::str2Dbl(const std::string charStr)
{
	try {
		return std::stod(charStr, nullptr);
	}
	catch (...) { return -1; }
}