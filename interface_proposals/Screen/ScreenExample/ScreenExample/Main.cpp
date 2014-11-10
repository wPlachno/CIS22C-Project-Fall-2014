// Created by Will Plachno
#include "Screen.h"
#include "DividedScreen.h"
#include "MenuScreen.h"

int main()
{
	Screen* myScreen = new Screen();
	myScreen->Prompt(
"Hello and welcome to the Screen Test!\nThis was created by Will Plachno to show an example of a 'screen-style' interface. This line should be broken across multiple lines.\nThis one should be just fine though. \nINSERTTEXTHERE \n\n");
	myScreen->Display();
	delete myScreen;
	myScreen = new Screen();
	myScreen->Prompt(
"This is the second screen. "
"Please take care to notice how awesome this is. "
"Why, you ask? Quite simply, in code, this prompt is written on multiple lines!!!! OMG!!!!!!"
		);
	myScreen->Display();
	delete myScreen;
	myScreen = new DividedScreen(
		"This is the third screen.\
		 Notice that there is text here..."
		);
	myScreen->Prompt("...And even more down here!!!\
					 Cool, right? You'll see as we go on that this will be the basis for the menu screens. This division is perfect for giving the user some background on a choice, then giving them the actual choices to make on the bottom!");
	myScreen->Display();
	delete myScreen;

	int choice = 0;
	while (choice != 2)
	{
		myScreen = new MenuScreen("This is an example of the menu screens we will be using.\nWhen you call the new MenuScreen, you must include the Header and the max choice. The header is this content! Its what appears on the upper division of the screen.\
The max choice is the highest choice in the menu, 7 in this case. \nNote: all menus should be one-based, not zero-based. The actual menu char* should be given to the Prompt() function after the new process is over.", 7);
		myScreen->Prompt("1. Print 'Monkey'\n2. Quit the program\n3. Print 'Banana'\n4. Print 'Wibble Wobble'\n5. Print 'Forever unclean!'\n6. Print 'Dude! What's mine say?'\n7. Print 'Sweet! What's mine say?'");
		choice = myScreen->Display();
		delete myScreen;
		switch (choice) {
		case 1:
			myScreen = new DividedScreen("You entered 1!");
			myScreen->Prompt("Monkey");
			myScreen->Display();
			delete myScreen;
			break;
		case 2:
			myScreen = new DividedScreen("You entered 2!");
			myScreen->Prompt("You will now be exiting the menu loop and thus the program.\nThank you!!!!");
			myScreen->Display();
			delete myScreen;
			break;
		case 3:
			myScreen = new DividedScreen("You entered 3!");
			myScreen->Prompt("Banana");
			myScreen->Display();
			delete myScreen;
			break;
		case 4:
			myScreen = new DividedScreen("You entered 4!");
			myScreen->Prompt("Wibble Wobble");
			myScreen->Display();
			delete myScreen;
			break;
		case 5:
			myScreen = new DividedScreen("You entered 5!");
			myScreen->Prompt("Forever unclean!");
			myScreen->Display();
			delete myScreen;
			break;
		case 6:
			myScreen = new DividedScreen("You entered 6!");
			myScreen->Prompt("Dude! What's mine say?");
			myScreen->Display();
			delete myScreen;
			break;
		case 7:
			myScreen = new DividedScreen("You entered 7!");
			myScreen->Prompt("Sweet! What's mine say?");
			myScreen->Display();
			delete myScreen;
			break;
		}
	}
}