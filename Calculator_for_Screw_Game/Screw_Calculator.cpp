#include<iostream>
#include <vector>
#include <string.h>
using namespace std;

int intOnly(int input)
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

#define name first 
#define score second

vector< pair<string,int> > Players;

int main()
{

    cout<<"==========================="<<" Welcome to Screw Calculator Program "<<"==========================\n";
    cout<<"-------------------------------------------------------------------------------------------\n";
    cout<<"Please Carefully read the instructions to have the best experience in our program:\n";
    cout<<"-------------------------------------------------------------------------------------------\n";
    cout<<"1- You enter the number of Players [only integers are allowed].\n";
    cout<<"2- You enter the name of each player.\n";
    cout<<"3- You enter the score for each player in each round \n";
    cout<<"4- You can end the game after any round and know who is the winner from the final score \n";
    cout<<"------------------------------------------------------------------------------------------------\n";
    while(true)
    {
        int nP;
        cout<<"Please enter the number of players: ";   // take number of players from user
        // check if the input is valid or not
        nP = intOnly(nP);
        cout<<"--------------------------------------------------------------------------------------------\n";

        // take the name of each player from user
        for (int i = 0; i < nP; i++) 
        {
            cout << "Please enter the name of player " << i + 1 << " : ";
            string playerName;
            cin >> playerName;
            Players.push_back(make_pair(playerName, 0)); // Initialize all score of the players to 0
            cin.clear();
            cin.ignore(256, '\n');
        }

        // begin the rounds...
        cout<<"-------------------------------- let's begin the rounds ------------------------------------\n";
        int round =1;
        vector<int>roundScore={0}; // temp vector to store round score temporarily
        int lowestScore;           // to check the lowest score to know the winner
        char y_n;                  // to make user choose to exit or to play another round
    
        while(true)
        {
            // take the score of each player from user in each round
            cout <<"------------------------------------------ Round "<<round<<" -----------------------------------------"<<endl;
            for (int i = 0; i < nP; i++) 
            {
                int playerScore;
                cout <<"Please enter the score of "<<Players[i].name <<": " ;
                // check if the input is valid or not
                playerScore = intOnly(playerScore);
                roundScore[i]=playerScore; // add the score for each player
            }

            // who is the winner of the round ?
            lowestScore=roundScore[0];
            for(int i=0;i<nP;i++)
            {
                if(roundScore[i]<lowestScore)
                {
                    lowestScore=roundScore[i];
                }
            }
            for(int i=0;i<nP;i++)
            {
                if(roundScore[i]==lowestScore)
                {
                    roundScore[i]=0;
                    cout<<"Congratulations!... player "<< i+1<<": \""<<Players[i].name<<"\" you won this round"<<endl;
                }
            } 

            // show the total score of each player after each round
            cout <<"----------------------------------- Total Scores after Round "<<round<<" -----------------------------------"<<endl;
            for(int i=0;i<nP;i++)
            {
                (Players[i].score)+=roundScore[i];
                cout<<"Player "<< i+1 <<" : "<<Players[i].name<<" ---> Score: "<<Players[i].score<<endl;
            }
            cout<<"-------------------------------------------------------------------------------------------\n";
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
        // who is the winner of the game ?
        lowestScore=(Players[0].score);
        for(int i=0;i<nP;i++)
        {
            if((Players[i].score)<lowestScore)
            {
                lowestScore=Players[i].score;
            }
        }

        for(int i=0;i<nP;i++)
        {
            if((Players[i].score)==lowestScore)
            {
                cout<<"Congratulations!... player "<< i+1<<": \""<<Players[i].name<<"\" you won this game"<<endl;
            }
        } 
        cout<<"If you want to play a new game enter \'y\' \n";
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
            continue;
        }
        else if(y_n=='n')
            break;
    }
    
cout<<"Thank you for your time... We hope you have enjoyed the program \n";





    return 0;
}

