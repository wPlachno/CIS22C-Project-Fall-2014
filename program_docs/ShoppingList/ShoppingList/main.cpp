
/********************************************************************************
 
 Author: Robert Hoyer
 ********************************************************************************/

#include "ShoppingList.h"
#include "Input.h"
#include "Output.h"
#include "util.h"


void main_loop(ShoppingList& theList)
{
	int option = 0;
	std::string input;

	while(1)
	{
		std::cout << std::endl;
		Output::PrintMainMenu();
		std::cout << std::endl;
		option = Input::GetMainMenuChoice();
		std::cout << std::endl;
		
		switch(option)
		{
			case OPTION_ADD:
				Input::AddItem(theList);
				break;
			case OPTION_DELETE:
				Input::DeleteItem(theList);
				break;
			case OPTION_EDIT:
				Input::EditItem(theList);
				break;
			case OPTION_PRIMARYKEY:
				input = Input::StringPrompt("Enter the name of the item to print:");
				theList.displayItem(input);
				break;
			case OPTION_HASHSEQ:
				theList.printListHashSeq();
				break;
			case OPTION_KEYSEQ:
				theList.printListByName();
				break;
			case OPTION_BST:
				theList.printTree();
				break;
			case OPTION_EFFICIENCY:
				theList.printHashTableEfficiency();
				break;
			case OPTION_BYSTORE:
				input = Input::StringPrompt("Enter the store to search by:");

				theList.printByStore(input);
				break;
			case OPTION_QUIT:
				return;
				break;
		}
		//std::cout << std::endl << "There are " << theList.getItemCount() << " items in the list." << std::endl;
	}
}



int main(void)
{
	const std::string saveFileName = "ShoppingListData.txt";
	ShoppingList theList;


	Output::PrintLanding();

//read
	if (theList.loadFromFile(saveFileName) != SL_SUCCESS)
	{
		std::cout << "Unable to open file '" << saveFileName << "'." << std::endl;
		return 1;
	}
	std::cout << std::endl << theList.getItemCount() << " records have been loaded." << std::endl;


	main_loop(theList);

	if (theList.writeToFile(saveFileName) != SL_SUCCESS)
	{
		std::cout << "Unable to write to '" << saveFileName << "'." << std::endl;
		return 1;
	}

//write
	return 0;
}