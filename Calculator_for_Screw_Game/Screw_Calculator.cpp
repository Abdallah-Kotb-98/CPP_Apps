#include<iostream>
#include <vector>
#include <string.h>
#include"Screw_Calculator(Struct).h"

using namespace std;


void Welcome()
{
    cout<<"==========================="<<" Welcome to Screw Calculator Program "<<"===========================\n";
    cout<<"-------------------------------------------------------------------------------------------\n";
    cout<<"Please Carefully read the instructions to have the best experience in our program:\n";
    cout<<"-------------------------------------------------------------------------------------------\n";
    cout<<"1- You enter the number of Players [only integers are allowed].\n";
    cout<<"2- You enter the name of each player.\n";
    cout<<"3- You enter the score for each player in each round \n";
    cout<<"4- You can end the game after any round and know who is the winner from the total score \n";
    cout<<"-------------------------------------------------------------------------------------------\n";
}

int take_Int_Only(int input)
{
    cin>>input;
    while(cin.fail()) 
    {
    cout<<"Erorr!!...invalid input\n";
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Please enter an integer number: "; cin>>input;
    }
    return input;
}

void whoIsWinnerOf(string str)
{
    int lowestScore;
    if(str=="round")
    {
        lowestScore=players[0].roundScore;
        for(int i=0;i<nP;i++)
        {
            if(players[i].roundScore<lowestScore)
            {
                lowestScore=players[i].roundScore;
            }
        }
        for(int i=0;i<nP;i++)
        {
            if(players[i].roundScore==lowestScore)
            {
                players[i].roundScore=0;
                cout<<"Congratulations!... player "<< i+1<<": \""<<players[i].name<<"\" you won this round"<<endl;
            }
        }
    }
    else if(str=="game")
    {
        lowestScore=players[0].totalScore;
        for(int i=0;i<nP;i++)
        {
            if((players[i].totalScore)<lowestScore)
            {
                lowestScore=players[i].totalScore;
            }
        }

        for(int i=0;i<nP;i++)
        {
            if((players[i].totalScore)==lowestScore)
            {
                cout<<"Congratulations!... player "<< i+1<<": \""<<players[i].name<<"\" you won this game"<<endl;
            }
        }
    }
}

void show_Total_Scores()
{

    for(int i=0;i<nP;i++)
    {
        (players[i].totalScore)+=players[i].roundScore;
        cout<<"Player "<< i+1 <<" : "<<players[i].name<<" ---> Score: "<<players[i].totalScore<<endl;
    }
}