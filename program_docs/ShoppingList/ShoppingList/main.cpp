
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


    Output::PrintLanding();

    while(1)
    {
        Output::PrintMainMenu();
        option = Input::GetMainMenuChoice();

        switch(option)
        {
            case OPTION_ADD:
                break;
            case OPTION_DELETE:
                input = Input::StringPrompt("Enter the name of the item to delete.");
                if(theList.removeRecord(input))
                    std::cout << "'" << input << "' was deleted.";
                break;
            case OPTION_PRIMARYKEY:
                input = Input::StringPrompt("Enter the name of the item to print.");
                theList.displayItem(input);
                break;
            case OPTION_HASHSEQ:
                theList.printListHashSeq();
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
                break;
        }
        
    }
}



int main(int argc, char* argv[])
{
    ShoppingList theList;
//read

    if (!theList.loadFromFile("ShoppingListData.txt"))
        return 1;


    main_loop(theList);
//write
    return 0;
}