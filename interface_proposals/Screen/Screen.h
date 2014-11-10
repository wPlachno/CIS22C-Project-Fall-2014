// Created by Will Plachno
#ifndef SCREEN_H
#define SCREEN_H

/* class Screen
	class for printing 'screen's to the user.
	This style shows pages to the user, one at a time, then 
	flushes the terminal to remove the screen from view.
   Variables:
	- char* prompt - the content, or 'prompt', to print in this screen.
	               Accessed/Set by the Prompt() functions
	- const SCREENHEIGHT - the height, including the border, of the screen
	- const SCREENWIDTH - the width, including the border, of the screen
   Functions:
	-  Screen()
	- ~Screen()
	- int   Display()
	- char* Prompt ()
	- void  Prompt (char* newPrompt)
	- void  print  ()
	- int   print  (int   startChar)
	- void  print  (char* miniPrompt)
	- int   print  (char* promptStr, int startChar)
    - void  print  (char* promptStr, int numLinesToPrint, int startChar)
*/

class Screen
{
public:
	/*
	Screen()
	Generic Constructor
	*/
	Screen() : prompt("No prompt entered.") {}

	/*
	~Screen()
	Generic Destructor
	*/
	~Screen() { prompt = nullptr; }

	/*
	int Display()
	Prints the screen for the user, then pauses.
	returns 0; The int return value is used mainly for
	inheriting classes
	*/
	virtual int Display();

	/*
	char* Prompt()
	Accessor for the prompt variable
	*/
	char* Prompt() { return prompt; }

	/*
	void Prompt(char* newPrompt)
	Setter for the prompt variable
	*/
	void Prompt(char* newPrompt) { prompt = newPrompt; }

protected:

	/*
	void print()
	prints a line of asterisks equal to the SCREENWIDTH
	*/
	void print();

	/*
	int print(int startChar)
	Prints the prompt starting at startChar
	Returns the next start pos for the next line 
	or -1 if complete.
	*/
	int print(int startChar);

	/*
	void print(char* miniPrompt)
	prints miniPrompt in a bordered line, right-aligned
	*/
	void print(char* miniPrompt);

	/*
	int print(char* promptStr, int startChar)
	prints promptStr in a bordered line, starting at the startChar index
	*/
	int print(char* promptStr, int startChar);

	/*
	void print(char* promptStr, int numLinesToPrint, int startChar)
	prints bordered promptStr lines for numLinesToPrint lines starting from startChar
	returns the index of the next char to be printed if end was not reached
	*/
	int print(char* promptStr, int numLinesToPrint, int startChar);

	/*
	char* prompt
	The prompt to send to the screen 
	Access/setter: Prompt()
	*/
	char* prompt;

	/*
	int screenHeight
	We can make this static.
	The height of the output of the display function
	*/
	const int SCREENHEIGHT = 25;

	/*
	int screenWidth
	We can make this static
	The width of the output of our display function
	*/
	const int SCREENWIDTH = 79;
};

#endif