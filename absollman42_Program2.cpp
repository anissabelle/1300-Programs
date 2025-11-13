/*
	Title:  	absollman42_prog2.cpp
	Author:		Anissa Sollman
	Date:		09/18/2024
	Purpose:	Program 2: Pet Store Management System
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

// Variables
ofstream animalFile1;		// Output File
ifstream animalFile2; 		// Input File
int choice = 0;				// User's menu choice
string animalType;			// Animal Type for adding an animal	
string animalName;			// Animal Name for adding an animal
string input;				// The input grabbed from animals.txt file to create display menu of animals in the shelter
int counter = 1;			// Numbering for display menu
int adoptedAnimal = 0;		// The animal that user wants to remove from display menu
int i = 0;					// For loop iterates i times for each line of text in animals.txt
ofstream tempFile;			// Temporary output file that holds the animals not sold when removing an animal

// Welcome message
cout << "Welcome to the Pet Store Management System!\n\n";

// Create text file animals.txt and open it in output mode
animalFile1.open("animals.txt");

// Error message for file not opening
if(!animalFile1.is_open()){
	cout << "Error opening file.";
}

// Add pre-existing animals to file
if(animalFile1.is_open()){
	animalFile1 << "Dog:Jack\n";
	animalFile1 << "Cat:Loki\n";
	animalFile1 << "Rat:Reuben\n";
	animalFile1 << "Pig:Wilber\n";
	animalFile1 << "Guinea Pig:Chunk\n";
}

animalFile1.close();

// Display option menu
while(choice != 4){
	cout << "Choose from the following options:\n";
	cout << "1. Add a new animal\n";
	cout << "2. Display all animals\n";
	cout << "3. Sell an animal\n";
	cout << "4. Exit\n";

    cout << "\nPlease choose an option: ";
	cin >> choice;
	cin.ignore();
    cout << endl;

	// User choice is not a valid option
	while(choice > 4 || choice < 1){
		cout << "\nOops! That option doesn't exist. Please choose 1, 2, 3, or 4: ";
		cin >> choice;
		
	}

	// Adding a new animal
	if(choice == 1){
		animalFile1.open("animals.txt", ios::app);

		cout << "Enter the animal type: ";
		getline(cin, animalType);

		cout << "Enter the animal's name: ";
		getline(cin, animalName);

		animalFile1 << animalType << ":" << animalName << endl;
		animalFile1.close();
		cout << animalName << " was added succesfully!\n\n";
	}

	// Display all animals from file
	else if (choice == 2){
		animalFile2.open("animals.txt");

		cout << "Animals currently in the shelter: " << endl;
        counter = 1; // Lists starts at 1
		while(!animalFile2.eof()){
			while(getline(animalFile2, input, ':')){
			cout << counter << ". " << input << " named ";
			animalFile2 >> input;
			animalFile2.ignore();
			cout << input << endl;
			counter++;
		    }
		}
		cout << endl;
		animalFile2.close();
	}

    // Removing animals
    else if(choice == 3){
		animalFile2.open("animals.txt");

		cout << "Animals currently in the shelter:\n";

        // Displaying animals
        counter = 1; // List starts at 1
        while(!animalFile2.eof()){
			while(getline(animalFile2, input, ':')){
				cout << counter << ". " << input << " named ";
				animalFile2 >> input;
				animalFile2.ignore();
				cout << input << endl;
				counter++;
		    }
			animalFile2.close();
        }

		animalFile2.open("animals.txt");
		tempFile.open("temp.txt");
		int counter2 = 1;

        cout << "\nEnter the number of the animal that sold: ";
        cin >> adoptedAnimal;
		cin.ignore();

		while(adoptedAnimal > (counter - 1) || adoptedAnimal < 1){
			cout << "Oops! There is no animal with number " << adoptedAnimal << " . Select an animal number between 1 and " << (counter - 1) << ".\n";
			cin >> adoptedAnimal;
			}

		// Transfer data from animals.txt to temp.txt
			while(getline(animalFile2, input)){
                if(counter2 != adoptedAnimal){
                    tempFile << input << endl;
                }
				counter2++;
            }
    
		// Renaming temp.txt to animals.txt and deleting original animals.txt file
        animalFile2.close();
		tempFile.close();
        remove("animals.txt");
        rename("temp.txt", "animals.txt");
        cout << endl;
    }
}
	// User quits program
    if(choice == 4){
        cout << "Goodbye!";
        animalFile1.close();
    }

return 0;
}

