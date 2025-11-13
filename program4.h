#ifndef program4_h
#define program4_h

// Libraries
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <cstring>
#include <limits>

using namespace std;

// Structures
struct Stats{

    int hitPoints;
    int healthPoints;
    char statsArray[3];

};

struct Creatures{

    string name;
    string description;
    double avgLength;
    double avgHeight;
    string location;
    bool danger;
    Stats creatureStats;

};

// Function Prototypes
int fight(int, Creatures*);
void calculateModifier(int, Creatures*, int&);
int deleteCreatures(int, Creatures*);
int enterCreatures(int, int, Creatures*);
void printCreatures(int, Creatures*);
void printStats(int, Creatures*);
bool moveArrayElements(string, int, Creatures*);
void saveCreaturesToFile(int, Creatures*);

#endif 