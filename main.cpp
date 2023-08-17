/*
 *  Project Three - Corner Grocer
 *  Date: 8/13/2023
 *  Author: Keegan Sevener
 */
#include "ItemSold.h"

int main() {
	ItemSold itemObj; //Create an ItemSold object for calling functions.
	vector<ItemSold> itemSoldList; // List of items sold.
	itemObj.FileBackUp(itemSoldList); //Creates backup file and adds items to the Vector.
	int userInput = 0;

	while (userInput != 4) {
		userInput = itemObj.MenuOptions(itemSoldList);
	}

	cout << "\n\nThank you for using Corner Grocer!\n\n";

	return 0;
}