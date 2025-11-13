/*****************************************************************
 *****************************************************************
	Title: 			functions.cpp
	Authors: 		Anissa Sollman
	Date Created: 	11/20/2024
	Last Edit:		11/22/2024
	Purpose: 		Creature Fight Game
******************************************************************
******************************************************************/

#include "program4.h"

/******************************************************************
	Function name: enterCreatures()
	Function purpose:
	
		Allows user to add creatures to the array from a file or manual input
*******************************************************************/
int enterCreatures(int max, int numCreatures, Creatures *creatures){

    // Variables
    int choice = 0; // User choice
    ifstream creaturesFile; // Input file containing creatures
    string fileName; // User's text file name
    string input; // User input for strings
	double input1 = 0; // User input for integers
	char choice2;
	char hitModifier; 


	// Check that the creatures array is not at max capacity
	if(numCreatures == max){
		cout << "You are already at max capacity. You cannot add more creatures to the arena\n";
		return 1;
	}

    // INTRO
    cout << "\n********************************************************************************\n";
    cout << "---------- ENTER CREATURES! ----------\n\n";

    cout << "Would you like to (1)Load my creatures from a text file or (2)Enter one creature manually?\n";
    cout << "CHOOSE 1 or 2: ";
    cin >> choice;
	cout << endl;

	// Validate user input
    while(!cin || choice < 1 || choice > 2){

        cin.clear(); //clears the error state
		//line below ignores the rest of the current line, up to '\n' or EOF - whichever comes first
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Please enter a valid number: ";
        cin >> choice;
    }

    // Load creatures from input file
    if(choice == 1){

        cout << "What is the name of the file with your list of creatures? (ex. filename.txt)\n";
		cout << "FILENAME: ";
		cin.ignore();
        getline(cin, fileName);

        // Open file
        creaturesFile.open(fileName);

        // Validate file was opened
        while(!creaturesFile.is_open()){
            cout << "Cannot open the file. Please enter the name of the file again\n";
            getline(cin, fileName);
            creaturesFile.open(fileName);
        }

        
        /* 
		For each element/creature: 
		Get the creature's characteristics/description from the file input
		Put the information into the struct array
		*/
        while(getline(creaturesFile, input, '#')){

			creatures[numCreatures].name = input;  // Get name

			getline(creaturesFile, input, '#'); // Get description
			creatures[numCreatures].description = input;

			getline(creaturesFile, input, '#'); // Get average length
			creatures[numCreatures].avgLength = stof(input);

			getline(creaturesFile, input, '#'); // Get average height
			creatures[numCreatures].avgHeight = stof(input);

			getline(creaturesFile, input, '#'); // Get location
			creatures[numCreatures].location = input;

			getline(creaturesFile, input, '#'); // Get danger
			creatures[numCreatures].danger = stoi(input);

			getline(creaturesFile, input, '#'); // Get creature stats - hit points
			creatures[numCreatures].creatureStats.hitPoints = stof(input);

			getline(creaturesFile, input, '#'); // Get creature stats - health points
			creatures[numCreatures].creatureStats.healthPoints = stof(input);

			getline(creaturesFile, input, '#'); // Get creature stats - hit modifier
			creatures[numCreatures].creatureStats.statsArray[0] = input.at(0);
			creatures[numCreatures].creatureStats.statsArray[1] = input.at(1);

			numCreatures++; // Increment the number of creatures by 1 since 1 creature's information was fully added
		}
		creaturesFile.close();

		cout << numCreatures << " creatures from " << fileName << " have been added to the program!\n\n"; 
    }
	
	// User enters creature's characteristics
	if(choice == 2){

		do{
			
			cout << "NAME: ";
			cin.ignore();
			getline(cin, input);
			creatures[numCreatures].name = input;

			cout << "DESCRIPTION: ";
			getline(cin, input);
			creatures[numCreatures].description = input;

			cout << "AVERAGE LENGTH: (in feet): ";
			cin >> input1;
			creatures[numCreatures].avgLength = input1;

			cout << "AVERAGE HEIGHT (in feet): ";
			cin >> input1;
			creatures[numCreatures].avgHeight = input1;

			cout << "LOCATION: ";
			cin.ignore();
			getline(cin, input);
			creatures[numCreatures].location = input;

			cout << "IS IT A DANGEROUS CREATURE (y or n): ";
			getline(cin, input);
			if(input == "y"){
				creatures[numCreatures].danger = 1;
			}
			else{
				creatures[numCreatures].danger = 0;
			}

			cout << "HIT POINTS: ";
			getline(cin, input);
			creatures[numCreatures].creatureStats.hitPoints = stof(input);

			cout << "HEALTH POINTS: ";
			getline(cin, input);
			creatures[numCreatures].creatureStats.healthPoints = stof(input);

			cout << "HIT SPECIAL MODIFIER? (y/n): ";
			getline(cin, input);

			if(input == "y"){
				cout << "HIT MODIFIER (0 through 9): ";
				cin >> hitModifier;
			
				creatures[numCreatures].creatureStats.statsArray[0] = '1'; // Creature has a hit modifier
				creatures[numCreatures].creatureStats.statsArray[1] = hitModifier;
			}
			else{
				creatures[numCreatures].creatureStats.statsArray[0] = '0'; // Creature does not have a hit modifier
				creatures[numCreatures].creatureStats.statsArray[1] = '0';
			}
	
			cout << "\nThe " << creatures[numCreatures].name << " has been added!\n";
			numCreatures++;

			cout << "\nWould you like to enter a new creature? (y or n): ";
			cin >> choice2;
			cout << endl;

		}while(choice2 == 'y');

	}

    return numCreatures;
}


/******************************************************************
	Function name: fight()
	Function purpose:
	
		The fight function will allow two dinosaurs to fight.
		The user gets to select the two dinos. 
*******************************************************************/
int fight(int numCreatures, Creatures* creatureList)
{
	int random, first, second, numRounds;
	int hitter, victim, hitterHP, victimHP;
	
	int f1Hit, f2Hit;

	string lineOfStars (60, '*');
	
	cout << endl << lineOfStars << endl;
	cout << "---------- FIGHT! FIGHT! FIGHT! ----------\n\n";
	
	//if there are no creatures, tell the user and then exit this function
	if(numCreatures == 0)
	{
		cout << "Oh no! There are no creatures in the arena!\n\n";
		return numCreatures;
	}
	
	//print the creatures
	cout << "Here is the list of creatures who are eligible to fight:\n";
	for(int i=0; i<numCreatures; i++)
	{
		cout << i+1 << ") " << creatureList[i].name << ", HIT: " 
		     << creatureList[i].creatureStats.hitPoints << ", HEALTH: "
			 << creatureList[i].creatureStats.healthPoints << endl;
	}
	
	//get the first creature fighter
	cout << "\nFIRST FIGHTER (CHOOSE 1-" << numCreatures << "):  ";
	cin >> first;
	//validate the user's input
	while(!cin || first < 1 || first > numCreatures)
	{
		
		if(!cin)
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "Oops! That wasn't an integer.\n";
		}
		else
			cout << "Oops! That number wasn't in the correct range.\n";	
		cout << "FIRST FIGHTER (CHOOSE 1-" << numCreatures << "):  ";
		cin >> first;
	}
	
	//Get the second creature figher
	cout << "SECOND FIGHTER (CHOOSE 1-" << numCreatures << "):  ";
	cin >> second;
	//validate the user's input
	while(!cin || second<1 || second>numCreatures || second == first)
	{
		if(!cin)
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "Oops! That wasn't an integer.\n";
		}
		else if(second<1 || second>numCreatures)
			cout << "Oops! That number wasn't in the correct range.\n";
		else
			cout << "Oops! " << creatureList[second-1].name 
		         << " can't fight itself!!\n";
		cout << "SECOND FIGHTER (CHOOSE 1-" << numCreatures << "):  ";
		cin >> second;
	}
	//Since the numbers in first & second are the element numbers, we
	//need to change them to the index values, so I am decrementing both
	first--;
	second--;
	
	//FIGHT UNTIL DEATH
	numRounds = 0;
	
	//While both fighting creatures are not dead (don't have health points of 0 or less), keep fighting
	while(creatureList[first].creatureStats.healthPoints > 0 && creatureList[second].creatureStats.healthPoints > 0)
	{
		//Random Number to see who hits who first
		random = rand()%(2-1+1)+1;
		
		//calculate hit modifier for both creatures
		calculateModifier(first, creatureList, f1Hit);
		calculateModifier(second, creatureList, f2Hit);
		
		if(random == 1) //first hits second
		{
			hitter = first;
			hitterHP = f1Hit;
			victim = second;
		}
		else //second hits first
		{
			hitter = second;
			hitterHP = f2Hit;
			victim = first;
		}
		
		numRounds++;
		cout << "\n>>>>>>>>>> ROUND " << numRounds << " <<<<<<<<<<\n";
		cout << creatureList[hitter].name << " hits " 
		     << creatureList[victim].name << " with "
			 << hitterHP << " hit points!\n";
		
		//update creature's health points
		creatureList[victim].creatureStats.healthPoints -= hitterHP;
		cout << creatureList[victim].name << " now has " 
		<< creatureList[victim].creatureStats.healthPoints
			 << " health points.\n";
	
		//is the creature's health points at or below 0? if so, it is dead, 
		// so remove it from array, decrement the number of creatures, and
		// break from the loop
		if(creatureList[victim].creatureStats.healthPoints <= 0)
		{
			cout << creatureList[victim].name << "'s body is being removed from the arena.\n";
			cout << creatureList[hitter].name << " IS THE WINNER!!!\n\n";
			moveArrayElements(creatureList[victim].name, numCreatures, creatureList);
			--numCreatures;
			break;
		}
	}//end of fight loop	
	
	//return the updated number of creatures because one creature died
	return numCreatures;
}//end of fight()


/******************************************************************
	Function name: deleteCreatures()
	Function purpose:
	
		Allows user to delete a creature
*******************************************************************/

int deleteCreatures(int numCreatures, Creatures *creatures){

	// Variables
	int i = 0; // for-loop iterations
	string input; // User input for creature name

	// Intro
	cout << "********************************************************************************\n";
	cout << "---------- DELETE CREATURE ----------\n\n";

	// Validate there are creatures in the array
	if(numCreatures < 1){
		cout << "Oh no! There are no creatures in the arena!\n\n";
		return 1;
	}

	else{
		cout << "The following is a list of all the creatures:\n";

		// Print the creatures in the arena
		for(i = 0; i < numCreatures; i++){
			cout << creatures[i].name << endl;
		}
	}

	cout << "\nWhat creature do you wish to remove?\n";
	cout << "CREATURE NAME: ";
	cin.ignore();
	getline(cin, input);
	
	// if moveArrayElements is true
	if(moveArrayElements(input, numCreatures, creatures)){
		cout << "\nYou have removed " << input << ".\n\n";
	}
	else // else moveArraryElements is false
		cout << "Sorry, a creature by the name " << input << " could not be found.\n\n";

	return numCreatures;
}

/******************************************************************
	Function name: moveArrayElements()
	Function purpose:
	
		When a creature is deleted, array elements will be shifted to the next index
*******************************************************************/

bool moveArrayElements(string input, int numCreatures, Creatures *creatures){

	// Variables
	int i = 0; //  For-loop iterations
	int creatureIndex = 0;
	bool found = false; // Does the creature name exist

	// Find the index where the creature the user wants to remove is
	for(i = 0; i < numCreatures; i ++){

		if (creatures[i].name == input){
			creatureIndex = i;
			found = true;
		}

	}
	
	// Shift the array elements after this index
	for(i = creatureIndex; i < numCreatures - 1; i ++){
		creatures[i] = creatures[i+1];
	}

	return found;

}



/******************************************************************
	Function name: calculateModifier()
	Function purpose:
	
		The calculateModifier function will accept the index value
		of the creature that will have its hit points modified
		by the special bonus modifier. This function also accepts
		the creature array and an integer that is passed by reference
		that will hold the updated hit points for this creature
*******************************************************************/
void calculateModifier(int i, Creatures* creatureList, int& fHit)
{
	int randomNum = rand()%(11-7+1)+7;
	if(strncmp(creatureList[i].creatureStats.statsArray,"1",1) == 0)	//hit modification
		fHit = (creatureList[i].creatureStats.statsArray[1]-'0') * randomNum + creatureList[i].creatureStats.hitPoints;
	else  //no special modifications
		fHit = creatureList[i].creatureStats.hitPoints;
}

/******************************************************************
	Function name: printCreatures()
	Function purpose:
	
		This function prints creatures and their characteristics to the screen
*******************************************************************/

void printCreatures(int numCreatures, Creatures *creatures){

	// Variables
	int i = 0; // For-loop iterations
	int x = 0; // holds length of creature decription

	// INTRO
	cout << "*******************************************************************************\n";
	cout << "---------- PRINT CREATURES ----------\n\n";

	// Validate there are creatures in the array
	if(numCreatures < 1){
		cout << "Oh no! There are no creatures in the arena!\n\n";
	}

	else{
		cout << "Here is a detailed list of all the creatures who are eligible to fight:\n\n";

		// Print the creatures in the arena
		for(i = 0; i < numCreatures; i++){
			cout << "---------- CREATURE " << (i + 1) << " ----------\n";
			cout << "Name:\t\t" << creatures[i].name << endl;
			cout << "Description:\n\t";
			cout << "\t" << setw(10) << creatures[i].description << endl << endl;
			cout << "Length:\t\t" << creatures[i].avgLength << " feet" << endl;
			cout << "Height:\t\t" << creatures[i].avgHeight << " feet" << endl;
			cout << "Locations:\t" << creatures[i].location << endl;
			cout << "Dangerous?\t";

			if(creatures[i].danger == 1){
				cout << "Yes\n";
			}
			else
				cout << "No\n";

			cout << "Hit Points:\t" << creatures[i].creatureStats.hitPoints << endl;
			cout << "Health Points:\t" << creatures[i].creatureStats.healthPoints << endl;
			cout << "Special Bonus:\t";

			if(creatures[i].creatureStats.statsArray[0] == '1'){ // Creature has a hit modifier
				cout << "Hit modifier: " << creatures[i].creatureStats.statsArray[1] << endl << endl;
			}
			else
				cout << "No hit modifier\n\n";
		}
	}

}

/******************************************************************
	Function name: printStats()
	Function purpose:
	
		This function prints the creature's name, their hit points, health points, and special bonus
*******************************************************************/

void printStats(int numCreatures, Creatures *creatures){

	// Variables
	int i = 0; // For-loop iterations

	// INTRO
	cout << "*******************************************************************************\n";
	cout << "---------- PRINT CREATURE STATISTICS ----------\n\n";

	// Validate there are creatures in the array
	if(numCreatures < 1){
		cout << "Oh no! There are no creatures in the arena!\n\n";
	}

	else{
		cout << "Here are the current stats of each creature:\n\n";

		cout << "CREATURE\t";
		cout << right << setw(20) << "HIT PTS   " << "HEALTH PTS   " << "SPECIAL BONUS\n";
		cout << "--------------------------------------------------------------------------------\n";

		for(i = 0; i < numCreatures; i++){

			// Printing the name, hit points, health points, and special bonus of each creature
			cout << left << setw(20) << creatures[i].name;
			cout << setw(13) << right << creatures[i].creatureStats.hitPoints;
			cout << setw(13) << right << creatures[i].creatureStats.healthPoints;

			if(creatures[i].creatureStats.statsArray[0] == '1')
				cout << setw(20) << left << "   Hit modifier of " << creatures[i].creatureStats.statsArray[1] << endl;
			else	
				cout << setw(15) << left << "   No hit modifier\n";
		}
		cout << endl;
	}


}

/******************************************************************
	Function name: saveCreaturesToFile()
	Function purpose:
	
		This function saves all the creatures and their characteristics into an output file
*******************************************************************/

void saveCreaturesToFile(int numCreatures, Creatures *creatures){

	// Variables
	ofstream outFile; // file which will hold the creatures
	string fileName; // Name of the file that the User wants to create to store creatures in
	int i = 0; // For-Loop iterations

	// INTRO
	cout << "*******************************************************************************\n";
	cout << "---------- SAVE CREATURES TO FILE ----------\n\n";

	cout << "What is the name of the file you want to save your creatures to?\n";
	cout << "FILENAME: ";
	cin.ignore();
	getline(cin, fileName);

	// Create and/or open the file
	outFile.open(fileName);

	// Print information for each creature to the file and add the delimiter after each
	for(i = 0; i < numCreatures; i++){

		outFile << creatures[i].name << "#";
		outFile << creatures[i].description << "#";
		outFile << creatures[i].avgLength << "#";
		outFile << creatures[i].avgHeight << "#";
		outFile << creatures[i].location << "#";
		outFile << creatures[i].danger << "#";
		outFile << creatures[i].creatureStats.hitPoints << "#";
		outFile << creatures[i].creatureStats.healthPoints << "#";
		outFile << creatures[i].creatureStats.statsArray[0] << creatures[i].creatureStats.statsArray[1] << "#";
		
		// Creature[i] was successfully added to the file
		cout << creatures[i].name << " was successfully saved to the file!\n";
		
	}
	cout << "\n" << numCreatures << " creatures were successfully saved to the " << fileName << " file.\n\n";

	// Close File
	outFile.close();
}