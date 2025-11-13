/*************************************************************
 * Filename: creatureFight.cpp
 * Author: Anissa Sollman
 * Date: 11/20/2024
 * Purpose: Program 4
**************************************************************/

#include "program4.h"

int main(){

    // Variables
    int max = 0; // Max number of creatures in the arena
    int numCreatures = 0; // Number of creatures in the arena
    int choice = 0; // User menu choice
    char choice1;


    // INTRO
    cout << "What is the maximum number of creatures that can fit in your arena?\n";
    cout << "MAX NUM OF CREATURES: ";
    cin >> max;

    // Validate user input
    while(!cin || max < 1){

         cin.clear(); //clears the error state
		//line below ignores the rest of the current line, up to '\n' or EOF - whichever comes first
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Oops! That didn't make sense. Please enter a positive integer.\n";
        cout << "MAX NUM OF CREATURES: ";
        cin >> max;
    }

    cout << endl;

    // Dynamically allocate an array of creatures at max size
    Creatures *creatures = new Creatures[max];

    do{
    // Menu
    cout << "What would you like to do?\n";
    cout << "\t1. Enter some creatures\n";
    cout << "\t2. Fight! Fight! Fight!\n";
    cout << "\t3. Delete a creature\n";
    cout << "\t4. Print creatures to screen\n";
    cout << "\t5. Print creature stats\n";
    cout << "\t6. End Program\n";
    cout << "ENTER 1-6: ";
    cin >> choice;

    // Validate user input
    while(!cin || choice < 1 || choice > 6){

        cin.clear(); //clears the error state
		//line below ignores the rest of the current line, up to '\n' or EOF - whichever comes first
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Please enter a valid menu choice: ";
        cin >> choice;
    }
    

        switch(choice){

            case 1:
                // set numCreatures equal to enterCreatures function since it returns the current number of creatures
                numCreatures = enterCreatures(max, numCreatures, creatures);
            break;

            case 2:
                numCreatures = fight(numCreatures, creatures);
            break;

            case 3:
                numCreatures = deleteCreatures(numCreatures, creatures);
            break;

            case 4:
                printCreatures(numCreatures, creatures);
            break;

            case 5:
                printStats(numCreatures, creatures);
            break;

            case 6:
                cout << "Would you like to save your creature list to a file? (y or n): ";
                cin >> choice1;
                if(choice1 == 'y'){
                    saveCreaturesToFile(numCreatures, creatures);
                }
                
                delete[] creatures;
                return 0;
        }

    }while(choice <= 6);

    return 0;
}