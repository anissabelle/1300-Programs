#ifndef halloween_h
#define halloween_h

// Include pre-existing c++ libraries
#include <iostream>
#include <string>       // String class and functions
#include <fstream>      // File input and file output
#include <cstring>      // Char Arrays / C-strings

using namespace std;

// Programmer-defined function definitions
int manageGuestList(string guests[], int& num);
int planHauntedActivities(string activities[], int& num);
void trackFood(string food[], int foodQuantity[]);
void saveToFile(string guests[], int guestCount, string activities[], int activityCount, string food[], int foodQuantity[]);
void printMenu();

// Global Variables
const int GUESTVAL = 10;			// Guest array size
const int ACTIVITYVAL = 10;
const int FOODVAL = 4;

#endif