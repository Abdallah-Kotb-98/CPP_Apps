#include <iostream>
#include <algorithm>
using namespace std;


using namespace std;

void game_field(int arry_F[3][3]) // display the help game field
{
    // first row
    cout<<"-------------------\n";
    for(int i=0;i<3;i++)
    {
        cout<<"| ";
        for(int j=0;j<3;j++)
        {
        cout<<" "<< arry_F[i][j]<<" ";
        if(j<2)
        {
        cout<<" | ";
        }
        }
        cout<<" | ";
        cout<<"\n-------------------\n";
    }
    

}

void Welcome_Instructions()
{
        cout<<"========================================================= Welcome to \'X\' & \'O\' Game =========================================================\n";
        cout<<" -------------------------------------------------------------------------------------------\n";
        cout<<" Please Carefully read the instructions of the game to have the best experience in our game:\n";
        cout<<" -------------------------------------------------------------------------------------------\n";
        cout<<"     - Now you are looking at the gamefield of the game.\n";
        cout<<"     - Each place carries a corrosponding number.\n";
        cout<<"     - We will ask each player to enter the number corrosponding to the place where he want to play in each turn\n";
        cout<<" -------------------------------------------------------------------------------------------\n";

        int arry_explain [3][3]=
        {
            {1,2,3},
            {4,5,6},
            {7,8,9}, 
        };
        game_field(arry_explain);
        cout<<"- Thanks for reading carfeully the instructions, We hope both of you have the best experience in the game.\n"
            <<" ................................... Good Luck ................................... \n";
}

void game_field(char arry_F[3][3]) // display the game field
{
  

    cout<<"-------------------\n";
    for(int i=0;i<3;i++)
    {
        cout<<"| ";
        for(int j=0;j<3;j++)
        {
        
        cout<<" "<< arry_F[i][j]<<" ";
        if(j<2)
        {
        cout<<" | ";
        }
        }
        cout<<" | ";
        cout<<"\n-------------------\n";
    }
}

string check_if_assigned_before(char arry [3][3],char P,int place)
{
    int k=1;
    string result;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arry[i][j]==' ' &&  place==k)
            {
                result= "allowed";
            }
        k++;   
        }
    }
    return result;
}

void put_X_O(char arry [3][3],char P,int place)
{
    if(place==1)
        arry[0][0]=P;
    else if(place==2)
        arry[0][1]=P;
    else if(place==3)
        arry[0][2]=P;
    else if(place==4)
        arry[1][0]=P;
    else if(place==5)
        arry[1][1]=P;
    else if(place==6)
        arry[1][2]=P;
    else if(place==7)
        arry[2][0]=P;
    else if(place==8)
        arry[2][1]=P;
    else if(place==9)
        arry[2][2]=P;   
}

 char check_win(char arry [3][3],char P)
{
    char W_L;
    bool upper_Hor=(arry [0][0]== P && arry [0][1]== P && arry [0][2]== P);    // 1 2 3
    bool middle_Hor=(arry [1][0]== P && arry [1][1]== P && arry [1][2]== P);   // 4 5 6
    bool lower_Hor=(arry [2][0]== P && arry [2][1]== P && arry [2][2]== P);    // 7 8 9
    bool left_ver=(arry [0][0]== P && arry [1][0]== P && arry [2][0]== P);     // 1 4 7
    bool middle_ver=(arry [0][1]== P && arry [1][1]== P && arry [2][1]== P);   // 2 5 8
    bool right_ver=(arry [0][2]== P && arry [1][2]== P && arry [2][2]== P);   // 3 6 9
    bool right_cross=(arry [0][0]== P && arry [1][1]== P && arry [2][2]== P);  // 1 5 9
    bool left_cross=(arry [0][2]== P && arry [1][1]== P && arry [2][0]== P);   // 3 5 7

    if(upper_Hor || middle_Hor || lower_Hor || left_ver || middle_ver || right_ver || right_cross || left_cross)
    {
        W_L='W';       
    }
    else
    {
        W_L='L';
    }

    return W_L; 
} 



int main()
{
    Welcome_Instructions();
    char arry [3][3]=
    {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}, 
    };            
    char P1;
    char P2;
       
    while(true)
    {
        cout<<"-------------------------------------------------------------------------------------------\n";
        cout<<"                     Let's begin the game...\n";
        cout<<"-------------------------------------------------------------------------------------------\n";

        while(true)
        {
            cout<<"Player 1 : please enter your choice \'X\' or \'O\'\n"; cin>>P1;
            if(P1=='X' || P1=='x')
            {
                P2='O';
                break;
            }
            else if (P1=='O' || P1=='o')
            {
                P2='X';
                break;
            }
            else
            {
                cout<<"Erorr!!...invalid input\n";
                continue;
            }
        }


        cout<<"-------------------------------------------------------------------------------------------\n";
        cout<<"              Player 1: you are \'"<<P1 <<"\'\n";
        cout<<"              Player 2: you are \'"<< P2 <<"\'\n"; 
        cout<<"-------------------------------------------------------------------------------------------\n"; 

        int place_P1;
        int place_P2;
        int c=1;
        while(true)
        {
            while(true) // to check if the place is assigned before for player 1 input
            {
                cout<<"-------------------------------------------------------------------------------------------\n"; 
                cout<<"              Player 1: this is your turn\n"
                    <<"              Please Enter your place in the gamefield\n"; 

                while(!(cin>>place_P1) || place_P1<0 || place_P1>10)
                {
                    cout<<"Erorr!!...invalid input\n";
                    cout<<"-------------------------------------------------------------------------------------------\n"; 
                    cout<<"              Player 1: this is your turn\n"
                        <<"              Please Enter the number corrosponding to your desired place in the gamefield\n";
                    cin.clear();
                    cin.ignore(100,'\n');
                }

                if(check_if_assigned_before(arry , P1 , place_P1)=="allowed")
                {
                    put_X_O(arry , P1 , place_P1);
                    break;
                }
                else
                {
                    cout<<"Erorr!!...invalid input.\n"
                        <<"Player 1 : you are trying to play in a place where a player already played in it before\n";
                    cout<<"Please try to choose another place by choosing another number\n";
                    continue; // restart if the selected place is assigned before
                } 
            }
                game_field(arry);

                if(check_win(arry,P1)=='W') // check if player 1 won
                {
                    cout<<"-------------------------------------------------------------------------------------------\n"; 
                    cout<<"              Congrats... Player 1 ('"<<P1<<"') you won.\n";
                    cout<<"              Game Over... Player 2 ('"<<P2<<"') you lose.\n";
                    cout<<"-------------------------------------------------------------------------------------------\n"; 
                    break;
                }
                
                if(c==5) // check if end with draw
                {
                    break;
                }
            while(true) // to check if the place is assigned before for player 2 input
            {
                cout<<"-------------------------------------------------------------------------------------------\n";   
                cout<<"              Player 2: this is your turn\n"
                    <<"              Please Enter your place in the gamefield\n"; 
                cout<<"-------------------------------------------------------------------------------------------\n"; 

                while(!(cin>>place_P2) || place_P2<0 || place_P2>10)
                {
                    cout<<"Erorr!!...invalid input\n";
                    cout<<"-------------------------------------------------------------------------------------------\n";   
                    cout<<"              Player 2: this is your turn\n"
                        <<"              Please Enter the number corrosponding to your desired place in the gamefield\n"; 
                    cout<<"-------------------------------------------------------------------------------------------\n"; 
                    cin.clear();
                    cin.ignore(100,'\n');
                }
                
                if(check_if_assigned_before(arry , P2 , place_P2)=="allowed")
                {
                    put_X_O(arry , P2 , place_P2);
                    break;
                }
                else
                {
                    cout<<"Erorr!!...invalid input\n"
                        <<"Player 2 : you are trying to play in a place where a player already played in it before\n";
                    cout<<"Please try to choose another place by choosing another number\n";
                    continue;  // restart if the selected place is assigned before
                }
            }
                game_field(arry);

                if(check_win(arry,P2)=='W') // check if player 2 won
                {
                    cout<<"              Congrats... Player 2 ('"<<P2<<"') you won.\n";
                    cout<<"              Game over... Player 1 ('"<<P1<<"') you lose.\n";
                    cout<<"-------------------------------------------------------------------------------------------\n"; 
                    break;
                }
            c++;     
        }
        if(check_win(arry,P2)!='W' && check_win(arry,P1)!='W') // if Draw
        {
            cout<<"-------------------------------------------------------------------------------------------\n"; 
            cout<<" Game over... Player 1 and Player 2 you are draw.\n";
            cout<<"-------------------------------------------------------------------------------------------\n"; 
        }

        string r_e;
        while(true)
        {
            cout<<"if you please want to restart enter \'r\' or \'restart\'\n";
            cout<<"if you please want to exit enter \'e\' or \'exit\'\n";
            cin>>r_e;

            if(r_e=="r" || r_e=="restart" || r_e=="e" || r_e=="exit" )
            {
                break; 
            }
            else
            {
                cout<<"Erorr!!...invalid input\n"
                    <<"please try again.";
                continue;  
            } 
        }

        //condition of restarting
        if(r_e=="r" || r_e=="restart")
        {
            // reset the database array again to defualt settings (fill it with spaces) 
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    arry[i][j]=' ';
                }
            }
            continue;
        }
        //condition of exiting
        else 
        {
            cout<<"thanks for your experience throughout our game...good bye!\n";
            break;
        }   
    }
        return 0;
}

