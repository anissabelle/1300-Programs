#include "halloween.h"

// Functions for Program 3

/**********************************************************
	Function Name:  	printMenu()

	Function Purpose:	Displays the Halloween Party Menu options
                        Validates User input
***********************************************************/
void printMenu(){

    int choice = 0; // User's menu choice
    
    // Main Menu
		cout << "1. Manage Guest List\n";
		cout << "2. Manage Activities\n";
		cout << "3. Check Food\n";
		cout << "4. Save Party to File\n";
		cout << "5. Exit Party Planning\n";

        cout << "\nEnter a menu option 1-5:\n";

}

/**********************************************************
	Function Name:  	manageGuestList()

	Function Purpose:	Displays the Halloween Party guest names
                        Allows User to add, remove, and modify guest names
                        Returns a 0 if operation was successful, returns a -1 if something failed
***********************************************************/
int manageGuestList(string guests[], int& num){

    // Variables
    int i = 0;
    int choice = 0;         // User menu choice
    string guestName;       // Name of guest from User input
    int removeGuest = 0;    // User input for removing a guest
    int modifyGuest = 0;    // User input for modifying a guest's name
    string modifyGuestName; // User input for the modified guest name


    // Print Guest List
    if(num > 0){
        cout << "Guest List:\n";
        for(i = 0; i < num; i++){    
            cout << "\t" << (i + 1) << ". " << guests[i] << endl;
        }
    cout << endl;
    }
        else{
            cout << "Your guest list is currently empty.\n";
            cout << "Please select option 1 to add a guest.\n";
        }

    do{
        // Display Guest List Options
        cout << "Guest List Menu:\n";
        cout << "\t1. Add Guest\n";
        cout << "\t2. Remove Guest\n";
        cout << "\t3. Modify Guest\n";
        cout << "\t4. Exit Guest List\n";

        cout << "\nEnter a menu option 1-4:\n";
        cin >> choice;

        // Validate User's choice
        while(choice < 1 || choice > 4){
			cout << "Please enter a valid menu choice: ";
			cin >> choice;
        }

        // User selects valid menu option
        switch(choice){

            // Adding a guest to list
            case 1:

                // Ensure guest list is not at max capacity 
                if(num == GUESTVAL){
                    cout << "The guest list is full. To add a new guest, you must remove one.\n";
                }

                else{
                    cout << "Enter the guest's name you want to add:\n";
                    cin.ignore();
                    getline(cin, guestName);
                    cout << endl;

                    // Add guest to the array/list
                    guests[num] = guestName;
                    num++;

                    // Print Guest List
                    cout << "******* Guest List *******\n";
                    for(i = 0; i < num; i++){  
                        cout << "\t" << (i + 1) << ". " << guests[i] << endl;
                    }
                }
                cout << endl;
            break;

            // Removing a guest from the list 
            case 2:

                // Validate guest list contains at least one element
                if(num < 1){
                    cout << "The guest list is empty. There are no guests to remove.\n";
                }

                else{
                    // Remove guest
                    cout << "Enter the guest's number that you want removed:\n";
                    cin >> removeGuest;

                    // Validate User input
                    while(removeGuest > num || removeGuest < 1){
                        cout << "Please enter a valid guest number:\n";
                        cin >> removeGuest;
                    }

                    // Remove guest from array/list
                    --num;
                    for(i = (removeGuest - 1); i < num; i++){
                        guests[i] = guests[i + 1];
                    }

                    // Print Guest List if there are guests within it
                    if(num > 0){
                        cout << "******* Guest List *******\n";
                            for(i = 0; i < num; i++){   
                                cout << "\t" << (i + 1) << ". " << guests[i] << endl;
                            }
                    }
                    else{
                        cout << "\nYour guest list is currently empty.\n";
                        cout << "Please select option 1 to add a guest.";
                    }
                }
                cout << endl;
            break;

            // Modify guest
            case 3:

                // Validate guest list contains at least one element
                if(num < 1){
                    cout << "The guest list is empty. There are no guests to modify.";
                }

                else{
                    cout << "Enter the guest number you want to modify:\n";
                    cin >> modifyGuest;

                    // Validate User input
                    while(modifyGuest > num || modifyGuest < 1){
                        cout << "Please enter a valid guest number:\n";
                        cin >> modifyGuest;
                    }
                
                    cout << "What would you like to modify guest " << modifyGuest << "'s name to?\n";
                    cin.ignore();
                    getline(cin, modifyGuestName);

                    guests[modifyGuest - 1] = modifyGuestName;

                    // Print guest list
                    cout << "\n******* Guest List *******\n";
                        for(i = 0; i < num; i++){   
                            cout << "\t" << (i + 1) << ". " << guests[i] << endl;
                        }
                }
                cout << endl;
        }
    }while(choice != 4);

    cout << "Exiting Guest List. . .\n\n";

    return 0;
}

/**********************************************************
	Function Name:  	planHauntedActivities()

	Function Purpose:	Displays the Halloween Party activities
                        Allows User to add, remove, and modify activity names
                        Returns a 0 if operation was successful, returns a -1 if something failed
***********************************************************/
int planHauntedActivities(string activities[], int& num){

    // Variables
    int i = 0;
    int choice = 0;            // User menu choice
    string activityName;       // Name of activity from User input
    int removeActivity = 0;    // User input for removing an activity
    int modifyActivity = 0;    // User input for modifying an activity
    string modifyActivityName; // User's modified activity name

    // Print activity List
    if(num > 0){
        cout << "Activity List:\n";
        for(i = 0; i < num; i++){    
            cout << "\t" << (i + 1) << ". " << activities[i] << endl;
        }
    cout << endl;
    }
        else{
            cout << "Your activity list is currently empty.\n";
            cout << "Please select option 1 to add an activity.\n";
        }

    do{
        // Display Activity List Options
        cout << "Activity Menu:\n";
        cout << "\t1. Add Activity\n";
        cout << "\t2. Remove Activity\n";
        cout << "\t3. Modify Activity\n";
        cout << "\t4. Exit Activity List\n";

        cout << "\nEnter a menu option 1-4:\n";
        cin >> choice;

        // Validate User's choice
        while(choice < 1 || choice > 4){
			cout << "Please enter a valid menu choice: ";
			cin >> choice;
        }

        // User selects valid menu option
        switch(choice){

            // Adding an activity to list
            case 1:

                // Ensure activity list is not at max capacity 
                if(num == ACTIVITYVAL){
                    cout << "The activity list is full. To add a new activity, you must remove one.\n";
                }
            
                else{
                    cout << "Enter the activity you want to add:\n";
                    cin.ignore();
                    getline(cin, activityName);
                    cout << endl;

                    // Add activity to the array/list
                    activities[num] = activityName;
                    num++;

                    // Print Activity List
                    cout << "******* Activity List *******\n";
                    for(i = 0; i < num; i++){  
                        cout << "\t" << (i + 1) << ". " << activities[i] << endl;
                    }
                }
                cout << endl;
            break;

            // Removing an activity from the list 
            case 2:

                // Validate activity list contains at least one element
                if(num < 1){
                    cout << "The activity list is empty. There are no activities to remove.\n";
                }

                else{
                    // Remove activity
                    cout << "\nEnter the activity number that you want removed:\n";
                    cin >> removeActivity;

                    // Validate User input
                    while(removeActivity > num || removeActivity < 1){
                        cout << "Please enter a valid activity number:\n";
                        cin >> removeActivity;
                    }

                    // Remove activity from array/list
                    --num;
                    for(i = (removeActivity - 1); i < num; i++){
                        activities[i] = activities[i + 1];
                    }

                    // Print Activity List if there are activities in the list
                    if(num > 0){
                        cout << "\n******* Activity List *******\n";
                            for(i = 0; i < num; i++){   
                                cout << "\t" << (i + 1) << ". " << activities[i] << endl;
                            }
                    }
                    else{
                        cout << "\nYour guest list is currently empty.\n";
                        cout << "Please select option 1 to add a guest.";
                    }
                }
                cout << endl;
            break;

            // Modify activity
            case 3:

                // Validate activity list contains at least one element
                if(num < 1){
                    cout << "The activity list is empty. There are no activities to modify.\n";
                }

                else{
                    cout << "Enter the activity number you want to modify:\n";
                    cin >> modifyActivity;

                    // Validate User input
                    while(modifyActivity > num || modifyActivity < 1){
                        cout << "Please enter a valid activity number:\n";
                        cin >> modifyActivity;
                    }
                
                    cout << "What would you like to modify activity " << modifyActivity << " to?\n";
                    cin.ignore();
                    getline(cin, modifyActivityName);

                    activities[modifyActivity - 1] = modifyActivityName;

                    // Print activity list
                    cout << "\n******* Activity List *******\n";
                        for(i = 0; i < num; i++){   
                            cout << "\t" << (i + 1) << ". " << activities[i] << endl;
                        }
                }
                cout << endl;
        }
    }while(choice != 4);

    cout << "Exiting Activity List. . .\n\n";
    return 0;
}

/**********************************************************
	Function Name:  	trackFood()

	Function Purpose:	Displays the Halloween food items and their serving amounts
***********************************************************/

void trackFood(string food[], int foodQuantity[]){

    // Variables
    int i = 0;

        // Display food and food servings
        for(i = 0; i < FOODVAL; i++){
            cout << food[i] << " has " << foodQuantity[i] << " servings prepared.\n";
        }
    cout << endl;
}

/**********************************************************
	Function Name:  	saveToFile()

	Function Purpose:	Loops over all arrays and prints them to an output file
***********************************************************/

void saveToFile(string guests[], int guestCount, string activities[], int activityCount, string food[], int foodQuantity[]){

    // Variables
    int i = 0;
    ofstream outFile; // Output file

    outFile.open("halloween.txt"); // Creating a file name halloween

    // Outputting guest array
    outFile << "Guest List:\n";
    for(i = 0; i < guestCount; i++){
        outFile << "\t" << guests[i] << endl; 
    }

    // Outputting activities array
    outFile << "Planned Activities:\n";
    for(i = 0; i < activityCount; i++){
        outFile << "\t" << activities[i] << endl;
    }

    // Outputting food array
    outFile << "Food:\n";
    for(i = 0; i < FOODVAL; i++){
        outFile << "\t" << food[i] << ": " << foodQuantity[i] << endl;
    }

    outFile.close();
}
