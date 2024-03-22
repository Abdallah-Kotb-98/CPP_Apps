#pragma once
#include<iostream>
#include <vector>
#include <string.h>
using namespace std;

struct S_Players                               // structure type for holding name , round score and total score for each player 
{   
    string name;    
    int roundScore=0;                          // Initialize all round scores of the players to 0
    int totalScore=0;                          // Initialize all total scores of the players to 0
};      

vector<S_Players> players;                     // array of structures of type S_players for all players
int nP;                                        // number of players
// welcome function
void Welcome();                                
// function take and check that input is only integer
int take_Int_Only(int input);                  
//function to decide the winner player of the round or the game based on scores
void whoIsWinnerOf(string str);                
// function to show total scores    
void show_Total_Scores();                      