#include<iostream>
#include <vector>
#include <string.h>
#include"Screw_Calculator(Struct).h"                         // header file contain decleartions
#include"Screw_Calculator(Struct).cpp"                       // Function Implemntation
using namespace std;


int main()
{
    while(true)
    {
        Welcome();
        cout<<"Please enter the number of players: ";       // take number of players from user
        nP = take_Int_Only(nP);                             // check if the input is valid or not
        cout<<"-------------------------------------------------------------------------------------------\n";

        // take the name of each player from user
        for (int i = 0; i < nP; i++) 
        {
            cout << "Please enter the name of player " << i + 1 << " : ";
            string playername;
            cin>>playername;
            players.push_back({playername});
            cin.clear();
            cin.ignore(256, '\n');
        }

        // begin the rounds...
        cout<<"-------------------------------- let's begin the rounds ------------------------------------\n";
        int round =1;               
        char y_n;                                           // to make user choose to exit or to play another round
        while(true)
        {
            // take the score of each player from user in each round
            cout <<"------------------------------------------ Round "<<round<<" -----------------------------------------"<<endl;
            for (int i = 0; i < nP; i++) 
            {
                cout <<"Please enter the score of "<<players[i].name <<": " ;
                players[i].roundScore = take_Int_Only(players[i].roundScore);          // check if the input is valid or not
            }
            cout<<"-------------------------------------------------------------------------------------------------------------\n";
            // who is the winner of the round ?
            whoIsWinnerOf("round");                         
            cout<<"-------------------------------------------------------------------------------------------------------------\n";
            cout <<"----------------------------------- Total Scores after Round "<<round<<" -----------------------------------"<<endl;
            show_Total_Scores();

            cout<<"-------------------------------------------------------------------------------------------------------------\n";
            cout<<"If you want to play another round enter \'y\' \n";
            cout<<"If you want to exit enter \'n\' \n";
            while(true)
            {
                cin>>y_n;
                if(y_n=='y')
                    break;
                else if(y_n=='n')
                    break;
                else
                {
                    cout<<"Erorr!!...invalid input\n";
                    continue;
                }
            }
            if(y_n=='y')
            {
                round++;
                continue;
            }
            else if(y_n=='n')
                break;
        }
        cout<<"-------------------------------------------------------------------------------------------------------------\n";
        // who is the winner of the game ?
        whoIsWinnerOf("game");
        cout<<"-------------------------------------------------------------------------------------------------------------\n";
        // Try agian or exit 
        cout<<"If you want to play a new game enter \'y\' \n";
        cout<<"If you want to exit enter \'n\' \n";
        while(true)
        {
            cin>>y_n;
            if(y_n=='y')
            {
                for (int i = 0; i < nP; i++) 
                {
                    players[i].roundScore = 0;          // reset all round scores
                    players[i].totalScore=0;            // reset all total scores
                }
                break;
            }
            else if(y_n=='n')
                break;
            else
            {
                cout<<"Erorr!!...invalid input\n";
                continue;
            }
        }

        if(y_n=='y')
            continue;
        else if(y_n=='n')
            break;
    }

cout<<"-------------------------------------------------------------------------------------------------------------\n";    
cout<<"Thank you for your time... We hope you have enjoyed the program \n";
cout<<"-------------------------------------------------------------------------------------------------------------\n";
    return 0;
}

