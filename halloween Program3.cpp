/*************************************************************
 * Filename: absollman42_prog3.cpp
 * Author: Anissa Sollman
 * Date: 11/06/2024
 * Purpose: Program 3 -- Halloween Party Planner
**************************************************************/

// Include header file
#include "halloween.h"

int main(){

	// Variables
	int choice = 0; 					// User's menu choice
	string guests[GUESTVAL];			// Guest list array
	string activities[ACTIVITYVAL];		// Activities array

	string food[FOODVAL] 				// Food Descriptions array
	= {"Witch Finger Cookies", "Zombie Meatloaf", "Eyeball Punch", "Spider Web Cupcakes"};	

	int foodQuantity[FOODVAL]			// Food Quantities array
	= {7, 6, 12, 15};
	int guestCount = 0;					// Guest counter
	int activityCount = 0; 				// Activity counter

	// Opening statement
	cout << "~Time to plan my awesome Halloween party!~\n";

	// Main loop
	do{

		printMenu();

		// Read in User's menu choice
		cin >> choice;

		// Validate User's menu choice
		while(choice < 1 || choice > 5){
			cout << "Please enter a valid menu option: ";
			cin >> choice;
		}

		cout << endl;

		switch(choice)
		{
			case 1:
			manageGuestList(guests, guestCount); 
			break;

			case 2:
			planHauntedActivities(activities, activityCount);
			break;

			case 3:
			trackFood(food, foodQuantity);
			break;

			case 4:
			saveToFile(guests, guestCount, activities, activityCount, food, foodQuantity);
			break;

		}
	}while(choice != 5);

	cout << "******* Closing the Halloween Party Planner *******";

	return 0; 
}
