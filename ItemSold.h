#pragma once
#ifndef PROJECTTHREESEVENER_ITEMSOLD_H
#define PROJECTTHREESEVENER_ITEMSOLD_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

class ItemSold {

//Functions for the ItemSold class.
public:

	//Constructor for the ItemSold class with default values.
	ItemSold(string inName = "No Name", int inCount = 0);

	void FileBackUp(vector<ItemSold>& passedVec);
	
	void PrintHistogram(vector<ItemSold>& passedVec);
	string GetName();
	int GetCount();
	void IncrCount();
	int MenuOptions(vector<ItemSold>& passedVec);
	
	void PrintMenu();
	void PrintSoldItem();

	ItemSold* FindItem(string findItem, vector<ItemSold>& passedVec);

//Variables for the ItemSold class.
private:
	string itemName;
	int itemCount;

};
#endif