
/********************************************************************************
 
 Author: Robert Hoyer
 ********************************************************************************/

#include "ShoppingList.h"
#include "Input.h"
#include "Output.h"



void main_loop(ShoppingList& theList)
{
    int option = 0;

    std::string input;


    Output::PrintLanding();

    while(1)
    {
        Output::PrintMainMenu();
        option = GetMainMenuChoice();

        switch(option)
        {
            case OPTION_ADD:
                break;
            case OPTION_DELETE:
                input = Input::StringPromt("Enter the name of the item to delete.");
                if(theList.removeRecord(input))
                    std::cout << "'" << input << "' was deleted.";
                break;
            case OPTION_PRIMARYKEY:
                input = Input::StringPrompt("Enter the name of the item to print.");
                theList.displayItem();
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

    main_loop(theList);
/*

    load list from file

    print main menu
    loop(running)
        prompt for option
            switch(option)
                OPTION_ADD
                    add_prompt(list)
                OPTION_DELETE
                    delete_prompt(list)
                OPTION_PRINT_RECORD
                    find_prompt(list)
                OPTION_PRINT_TABLE
                    list.printListHashSeq()
                OPTION_PRINT_KEY_SEQ
                    list.printListByName();
                OPTION_PRINT_TREE
                    list.printTree();
                OPTION_EFFICIENCY???
                    ???
                OPTION_FIND_BY_STORE
                    prompt for store name
                    list.printByStore
                OPTION_PRINT_OPTIONS
                    print the options list again.
                OPTION_QUIT
                    running = 0;



    write list to file

    end
    */
    return 0;
}