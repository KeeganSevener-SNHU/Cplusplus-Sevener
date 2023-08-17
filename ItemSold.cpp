#include "ItemSold.h"
#include <fstream>


ItemSold::ItemSold(string inName, int inCount) { // Constructor for the ItemSold class.
    itemName = inName;
    itemCount = inCount;
}

void ItemSold::FileBackUp(vector<ItemSold>& passedVec) {
    //Declare variabels for reading and writing files.
    ifstream inputFile;
    ofstream outputFile;
    string currWord;
    ItemSold* currItem;

    
    //Open the list of items sold and open the  backup file frequency.dat.
    inputFile.open("CS210_Project_Three_Input_File.txt");
    outputFile.open("frequency.dat");


    //Add the first item to the vector prior to entering the loop.
    inputFile >> currWord;
    currItem = new ItemSold(currWord, 1);
    passedVec.push_back(*currItem);


    //The while loop reads the inputFile and adds all the items to the pass by reference vector.
    while (!inputFile.eof()) {
        

        inputFile >> currWord; //Get next line from the file.
        currItem = currItem->FindItem(currWord, passedVec); //Check if item is already on the list.



        if (currItem->GetName() == "none") { //Item was not on the list, so it is added.
           currItem = new ItemSold(currWord, 1);
           passedVec.push_back(*currItem);

        }
        else { //Item was found on the list, so it is incremented.
            currItem->IncrCount();
        }
    }


    //This for loop backs up the file information to frequency.dat
    for (int i = 0; i < passedVec.size(); i++) {
        outputFile << passedVec.at(i).itemName << " " << passedVec.at(i).itemCount << endl;
    }
    //Close files at the function's end.
    inputFile.close();
    outputFile.close();
}





int ItemSold::MenuOptions(vector<ItemSold>& passedVec) {// Gets input from the user for the menu options.
    cin.exceptions(ios::failbit);
    int userChoice = 0;
    bool valCheck = true;
    
    PrintMenu();
    while (valCheck) {
        try { // Try and catch statements accommodate non-integer inputs.

            cout << "\nPlease select an option...";
            cin >> userChoice; //Get the user's choice.
            

            if (userChoice == 1) { // Option 1, find an item.
                system("cls");
                string userInputString;
                ItemSold* findItem = new ItemSold;

                while (userInputString != "Exit") {

                    //Requests input from the user.
                    cout << "\nPlease type an item to search for (type 'Exit' to end search)...";
                    cin >> userInputString;


                    findItem = findItem->FindItem(userInputString, passedVec); //Calls the FindItem function.
                    if (userInputString == "Exit") {
                        break;
                    }
                    else if (findItem->GetName() == "none") { //Item was not on the list.
                        cout << "\nSorry, no such item was found." << endl;
                    }
                    else { //Item was found on the list.
                        cout << findItem->GetCount();
                    }
                }
                valCheck = false;
            }

            else if (userChoice == 2) { // Option 2, print all items.
                system("cls");
                for (int i = 0; i < passedVec.size(); i++) { // Loop ouptuts all items and quantites.
                    passedVec.at(i).PrintSoldItem();
                }
                valCheck = false;
            }

            else if (userChoice == 3) { // Option 3, print histogram.
                system("cls");
                PrintHistogram(passedVec);
                valCheck = false;
            }

            else if (userChoice == 4) { // Option 4.
                cout << "Exiting program...\n";
                return userChoice;
            }
        }


        catch (ios_base::failure) { // Catch statement for non-integer inputs.
            cin.clear();
            cin.ignore();
            userChoice = 5;
        }

        //This is a separate IF statement so that catch can utilize it.
        if ((userChoice < 1) || (userChoice > 4)) { // For invalid inputs. 
            cout << "Invalid input, please input 1, 2, 3, or 4\n";
        }
    }
    

    cout << "\nPress any key to clear the screen and continue...";
    _getch(); //Pauses until input is received and then continues.

    system("cls"); //Clear screen.
    return userChoice;
}



void ItemSold::IncrCount() { //Increment's the object's item quantity.
    itemCount += 1;
}
string ItemSold::GetName() { //Return's the item's name.
    return itemName;
}
int ItemSold::GetCount() { //Return's the item's quantity.
    return itemCount;
}
void ItemSold::PrintSoldItem() { // Print's the object's name and quantity.
    cout << itemName << ", " << itemCount << endl;
}



//This function finds an item on the list and returns it.
ItemSold* ItemSold::FindItem(string findItem, vector<ItemSold>& passedVec) {
    ItemSold* itemFound = new ItemSold();
    bool noItem = true;


    *itemFound = passedVec.at(0);

    for (int i = 0; i < passedVec.size(); i++) { //Iterate through the vector and compare all items.

        if (findItem == passedVec.at(i).GetName()) {

            noItem = false;
            itemFound = &passedVec.at(i);
            break; //Break the loop if an item is found.
        }
    }

    if (noItem == true) { //If no item is found, a new item with "none" is returned.
        itemFound = new ItemSold("none");
    }
    return itemFound;
}



void ItemSold::PrintHistogram(vector<ItemSold>& passedVec) {
    HANDLE colorChange = GetStdHandle(STD_OUTPUT_HANDLE); //Declare HANDLE variable for changing colors.

    //Header for histogram.
    cout << "List#" << setw(11) << "Item" << setw(9) << "Qty\n"
        << "------------------------------\n";


    for (int i = 0; i < passedVec.size(); i++) { // Loop for printing the histogram.
        
        //Colors alternate to make the histogram easier to read.
        SetConsoleTextAttribute(colorChange, 9); //This text is yellow.
        if (i % 2 == 0) {
            SetConsoleTextAttribute(colorChange, 6); //This text is blue.
        }


        int widthSet; // Integer delcaration and if statement format the print statement.
        widthSet = (i > 8) ? 14 : 15;

        cout << (i+1) << setw(widthSet) << passedVec.at(i).GetName() << setw(5); //The item name and provides formatting.


        for (int j = 0; j < passedVec.at(i).GetCount(); j++) { //Loop prints the specified number of items.
            cout << "*";
        }
        cout << endl;
    }
    SetConsoleTextAttribute(colorChange, 7); //returns text to white after loops end.
    cout << "------------------------------\n"; //Footer for the histogram.
    return;
}



void ItemSold::PrintMenu() {
    
    cout << "*******************************" << endl
         << " ******* Corner Grocer ******* \n"
         << "  ****** Menu Options ******  \n";
    cout <<   "  **************************" << "\n\n";


    cout << " ************************** " << "\n";
    cout << "*" << setw(28) << "[Menu Option 1]     *\n"
         << "*" << setw(27) << "Print an item's quantity *" << "\n"
         << " ************************** " << "\n";
    
    
    cout << "*" << setw(28) << "[Menu Option 2]     *\n"
         << "*" << setw(27) << "Print all items     *" << "\n"
         << " ************************** " << "\n";

    
    cout << "*" << setw(28) << "[Menu Option 3]     *\n"
         << "*" << setw(27) << "Print histogram     *" << "\n"
         << " ************************** " << "\n";


    cout << "*" << setw(28) << "[Menu Option 4]     *\n"
         << "*" << setw(27) << "Exit the program    *" << "\n"
        << " ************************** " << endl;
    


    //FIXME: THIS text will move to MenuOptions()
    /*cout << "\nPress any key to clear the screen and continue...";
    _getch(); //Pauses until input is received and then continues.
    
    system("cls");*/
    return;
}
