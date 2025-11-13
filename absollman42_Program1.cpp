/*
	Title:  	Program1.cpp
	Author:		Anissa Sollman
	Date:		09/18/2024
	Purpose:	Program 1
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){

// Variables
string game_master = "";
float distance = 0;
float meters_per_second = 0.0;
float saucer_time = 0.0;
char saucer_choice;
int tracked_saucers = 0;
int blasted_saucers = 0;

// Title of program with fancy outline
cout <<  left;
cout << setfill('*') << setw(30) << "" << endl;
cout << setfill ('*') << setw(30) << "*     ALIEN CARNIVAL GAME    *" << endl;
cout << setfill('*') << setw(30) << "" << endl;

// Ask for user's name
cout << "Enter you name as the Game Master: ";
getline(cin, game_master);
cout << "\nWelcome, Game Master " << game_master << ", to the Alien Blaster Showdown!\n";

// Alien Blaster Showdown; Main loop
do{

    // Ask user for distance and speed of alien saucer
    cout << "\nEnter the distance of the alien saucer in meters: ";
    cin >> distance;
    cout << "Enter the speed of the alien saucer in meters per second: ";
    cin >> meters_per_second;

    // Distance of alien saucer from crowd in seconds
    cout << "Alien saucer detected! Time until it reaches the crowd: ";
    saucer_time = distance / meters_per_second;
    cout << fixed << setprecision(2) << saucer_time << " seconds" << endl;

    // To blast or not to blast alien saucer

    // Saucer time is less than 5 seconds
    if (saucer_time < 5.0)
        cout << "Blast it with foam cannons! It's zooming in too fast!\n";
    // Saucer time is within the range 5-15 seconds
    else if ((saucer_time >= 5.0) && (saucer_time <= 15.0))
        cout << "Let it go! The audience loves a bit of dramatics.\n";
    // Saucer time is greater than 15 seconds
    else if (saucer_time > 15.0)
        cout << "No need to worry. It's just hovering around. Keep enjoying the show!\n";

    //tracked saucers and blasted saucer counts
        tracked_saucers = tracked_saucers + 1;
        if (saucer_time < 5.0)
        blasted_saucers =  blasted_saucers + 1;

    // Ask user if there is another alien saucer approaching
    cout << "Is there another saucer approaching? (y/n)";
    cin >> saucer_choice;
    // User did not input (y/n)
    while ((saucer_choice != 'n') && (saucer_choice != 'y'))
{       
    cout << "Please enter either a (y/n)";
    cin >> saucer_choice;
}

}while (saucer_choice == 'y');
    
// User ends loop
if (saucer_choice == 'n')
/*
    End Alien Blaster Showdown
    Tell user how many alien saucers were tracked and blasted
    Tell user how good the show was depending on amount of saucers blasted
*/
{   cout << "\nThe Alien Blaster Showdown has ended! You tracked ";
        // Number of saucers tracked; number of while loop iterations
        cout << tracked_saucers << " saucers.\n";

    cout << "You blasted ";
        /* 
        Number of saucers blasted; number of while loop iterations if 
        saucer time to reach crowd is less than 5 seconds
        */
        cout << blasted_saucers << " saucers out of the air! Great job!\n"; 

    // How eventful or peaceful the show was depending on number of blasted saucers
    if (blasted_saucers < 7)
        cout << "What a peaceful show! Everyone left with smiles on their faces.";
    else if (blasted_saucers > 7)
        cout << "That was intense! The crowd loved it, 10/10 entertainment!";

}

}