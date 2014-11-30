#pragma once

/* Created by Will Plachno */
// De Anza Fall 2014 14F Goel
// Final Project Team 5 "Shopping List"

#include "TestSuite.h"

/* class InputTestSuite 
	The TestSuite for the Input class
   Functions:
	- SetUpTests
	- Test1		StringPrompt
	- Test2		StringPrompt
	- Test3		IntPrompt
	- Test4		IntPrompt
	- Test5		IntPrompt
	- Test6		DoublePrompt
	- Test7		DoublePrompt
	- Test8		DoublePrompt
	- Test9		DoublePrompt
	- Test10	GetMainMenuChoice
	- Test11	GetMainMenuChoice
	- Test12	GetMainMenuChoice
	- Test13	GetMainMenuChoice
	- Test14	GetMainMenuChoice
	- Test15	GetMainMenuChoice
	- Test16	GetMainMenuChoice
	- Test17	GetMainMenuChoice
	- Test18	GetMainMenuChoice
	- Test19	GetMainMenuChoice
	- Test20	GetMainMenuChoice
	- Test21	GetMainMenuChoice
	- Test22	Validate
	- Test23	Validate
	- Test24	Validate
	- Test25	Validate
	- Test26	Validate
	- Test27	Validate
	- Test28	Validate
	- Test29	AddItem
	- Test30	AddItem
	- Test31	AddItem
	- Test32	DeleteItem
	- Test33	DeleteItem
	- Test34	DeleteItem
	- Test35	EditItem
	- Test36	EditItem
	- Test37	EditItem
	- Test38	EditItem
	- Test39	EditItem
	- Test40	EditItem
	- Test41	EditItem
	- Test42	EditItem
	- Test43	EditItem
	- Test44	EditItem
	- Test45	EditItem
	- Test46	EditItem
	- Test47	EditItem

*/
class InputTestSuite : public TestSuite
{
public:

	/* InputTestSuite() */
	// Generic constructor
	// Calls the TestSuite constructor with "Input" for the name
	InputTestSuite() : TestSuite("Input"){ SetUpTests(); }

	/* ~InputTestSuite() */
	// Generic destructor
	// Stub only. Not necessary
	~InputTestSuite(){}

	/* void SetUpTests() */
	// Sets up all the test cases, then adds
	// them through the TestSuite architecture
	void SetUpTests();

	/* ------ Test Functions ------ */

	/* Test1StringPromptBasic */
	// Tests basic functionality of StringPrompt
	static bool Test1_StringPromptBasic();

	/* Test2StringPromptWhitespace */
	// Tests StringPrompt for whitespace
	static bool Test2_StringPromptWhitespace();

	/* Test3IntPromptBasic */
	// Tests IntPrompt basic functionality
	static bool Test3_IntPromptBasic();

	/* Test4IntPromptWhitespace */
	// Tests IntPrompt for whitespace
	static bool Test4_IntPromptWhitespace();

	/* Test5IntPromptNoninteger */
	// Tests IntPrompt for non-integer input
	static bool Test5_IntPromptNoninteger();

	/* Test6DoublePromptBasic */
	// Tests DoublePrompt basic functionality
	static bool Test6_DoublePromptBasic();

	/* Test7DoublePromptWhitespace */
	// Tests DoublePrompt for whitespace
	static bool Test7_DoublePromptWhitespace();

	/* Test8DoublePromptNoninteger */
	// Tests DoublePrompt for non-integer input
	static bool Test8_DoublePromptNoninteger();

	/* Test9DoublePromptInteger */
	// Tests DoublePrompt for integer input
	static bool Test9_DoublePromptInteger();

	/* Test10MainMenuOptionAdd */
	// Tests GetMainMenuChoice for correct interpretation
	// of 1 as OPTION_ADD
	static bool Test10_MainMenuOptionAdd();

	/* Test11MainMenuOptionDelete */
	// Tests GetMainMenuChoice for correct interpretation
	// of 2 as OPTION_DELETE
	static bool Test11_MainMenuOptionDelete();

	/* Test12MainMenuOptionPrimaryKey */
	// Tests GetMainMenuChoice for correct interpretation
	// of 3 as OPTION_PRIMARYKEY
	static bool Test12_MainMenuOptionPrimaryKey();

	/* Test13MainMenuOptionEdit */
	// Tests GetMainMenuChoice for correct interpretation
	// of 4 as OPTION_EDIT
	static bool Test13_MainMenuOptionEdit();

	/* Test14MainMenuOptionHashSeq */
	// Tests GetMainMenuChoice for correct interpretation
	// of 5 as OPTION_HASHSEQ
	static bool Test14_MainMenuOptionHashSeq();

	/* Test15MainMenuOptionKeySeq */
	// Tests GetMainMenuChoice for correct interpretation
	// of 6 as OPTION_KEYSEQ
	static bool Test15_MainMenuOptionKeySeq();

	/* Test16MainMenuOptionBST */
	// Tests GetMainMenuChoice for correct interpretation
	// of 7 as OPTION_BST
	static bool Test16_MainMenuOptionBST();

	/* Test17MainMenuOptionEfficiency */
	// Tests GetMainMenuChoice for correct interpretation
	// of 8 as OPTION_EFFICIENCY
	static bool Test17_MainMenuOptionEfficiency();

	/* Test18MainMenuOptionByStore */
	// Tests GetMainMenuChoice for correct interpretation
	// of 9 as OPTION_BYSTORE
	static bool Test18_MainMenuOptionByStore();

	/* Test19MainMenuOptionQuit */
	// Tests GetMainMenuChoice for correct interpretation
	// of 10 as OPTION_QUIT
	static bool Test19_MainMenuOptionQuit();

	/* Test20MainMenuNonOption */
	// Tests GetMainMenuChoice for non-option integer
	static bool Test20_MainMenuNonOption();

	/* Test21MainMenuNonInteger */
	// Tests GetMainMenuChoice for non-integer input
	static bool Test21_MainMenuNonInteger();

	/* Test22Validate_y */
	// Tests Validate with 'y'
	static bool Test22_Validate_y();

	/* Test23Validate_Y */
	// Tests Validate with 'Y'
	static bool Test23_Validate_Y();

	/* Test24Validate_yes */
	// Tests Validate with 'yes'
	static bool Test24_Validate_yes();

	/* Test25Validate_Yes */
	// Tests Validate with 'Yes'
	static bool Test25_Validate_Yes();

	/* Test26Validate_true */
	// Tests Validate with 'true'
	static bool Test26_Validate_true();

	/* Test27Validate_y */
	// Tests Validate with 'True'
	static bool Test27_Validate_True();

	/* Test28ValidateInvalid */
	// Tests Validate with invalid
	static bool Test28_ValidateInvalid();

	/* Test29AddItemBasicFunctionality */
	// Tests the basic AddItem functionality
	static bool Test29_AddItemBasic();

	/* Test30AddItemBlanks */
	// Tests blank fields in the AddItem function
	static bool Test30_AddItemBlanks();

	/* Test31AddItemExists */
	// Tests AddItem when the item already exists
	static bool Test31_AddItemExists();

	/* Test32DeleteItemBasic */
	// Tests DeleteItem basic functionality
	static bool Test32_DeleteItemBasic();

	/* Test33DeleteItemNotFound */
	// DeleteItem when trying to delete an item that
	// does not exist in the list.
	static bool Test33_DeleteItemNotFound();

	/* Test34DeleteItemCancel */
	// DeleteItem when the user cancels the delete
	static bool Test34_DeleteItemCancel();

	/* Test35EditItemNotFound */
	// EditItem when the user wants to edit a non-existent item
	static bool Test35_EditItemNotFound();

	/* Test36EditItemReturn */
	// EditItem when user wishes to return to the main menu
	// without changes
	static bool Test36_EditItemReturn();

	/* Test37EditItemInvalidChoice */
	// EditItem invalid menu choice
	static bool Test37_EditItemInvalidChoice();

	/* Test38EditItemNameNew */
	// EditItem when a new name is set
	static bool Test38_EditItemNameNew();

	/* Test39EditItemNameFound */
	// EditItem when the new name already exists
	static bool Test39_EditItemNameFound();

	/* Test40EditItemCostBasic */
	// EditItem edit cost 
	static bool Test40_EditItemCostBasic();

	/* Test41EditItemCostBlank */
	// EditItem edit cost to blank
	static bool Test41_EditItemCostBlank();

	/* Test42EditItemStoreBasic */
	// EditItem edit the store and save changes
	static bool Test42_EditItemStoreBasic();

	/* Test43EditItemStoreBlank */
	// EditItem edit the store with blank
	// and save the changes
	static bool Test43_EditItemStoreBlank();

	/* Test44EditItemQtyBasic */
	// EditItem edit quantity and save changes
	static bool Test44_EditItemQtyBasic();

	/* Test45EditItemQtyBlank */
	// EditItem set quantituy as blank and save
	static bool Test45_EditItemQtyBlank();

	/* Test46EditItemDateBasic */
	// EditItem change Date and save
	static bool Test46_EditItemDateBasic();

	/* Test47EditItemDataBlank */
	// EditItem set data to blank and save
	static bool Test47_EditItemDateBlank();

};

