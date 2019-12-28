#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
char game_pins[4]={0};
int is_it_diffrent (char);
int main(int argc, char** argv)
{
	cout << "************************THE FEKRE BEKR************************" << endl;
	// making a string that have pins to generate random pins for game ;
	char colored_pins[8] = {'A','B','C','D','E','F','G','H'} ;
	// pins that player choose for game
	string input_pins;
	// use for cheking same pins for game mode ;
	char diffrent_checker;
	// for taking a copy of game_pins array to make changes so the game work well
	char copy_pins[4];
	/*
	these integres are for :
	random_chooser : the random number that produse by the rand function ;
	game_mode : is the integer that keeps the game mode : 1 for diffrent pins 2 for same pins ;
	counter : for computer to choose pins for game;
	tries_left : for number of turns that player can guess the pins ;
	*/
	int random_chooser , game_mode , counter=1 , tries_left=10 ;
	srand (time(NULL));
	random_chooser=rand() % 8;
	game_pins[0]=colored_pins[random_chooser];

	ofstream lg;
	lg.open("last_game.txt");

	cout << " Choose Game Mode :" << '\n' << "   1- With diffrent pins     " << "2-With same pins" << endl;
	lg << " Choose Game Mode :" << '\n' << "   1- With diffrent pins     " << "2-With same pins" << endl;

	while (cin >> game_mode)
	{
		if(game_mode == 1)
		{
			break;
		}else if ( game_mode == 2)
		{
			break;
		}else
		{
		cout << " please enter a valuable number" << endl;
		}
	}
	lg << game_mode << endl;
	while (counter <=3)
	{
		// the value that returns  from is_it_diffrent function saved in this integer
		int diffrent_number;
		random_chooser=rand() % 8;
		diffrent_checker = colored_pins[random_chooser];
		if(game_mode == 1 )
		{
				diffrent_number = is_it_diffrent( diffrent_checker);
				if (diffrent_number == 0)
				{
					game_pins[counter]=diffrent_checker;
					counter ++;
				}
		}
		if (game_mode == 2)
		{
			game_pins[counter] = diffrent_checker;
			counter ++;
		}

	}
	// to print the pins that game has choosed delete the comment signs
   /* for (int i=0 ; i<4 ; i++){
        cout << game_pins[i];
     }
	 cout << endl;*/
	cout << " the game choosed it's pins now its your turn to guess the pins. " << endl;
	cout << " The pins Are : A B C D E F G H" << endl;
	cout << "you can try " << tries_left << "times more to go" << endl;
	lg << " the game choosed it's pins now its your turn to guess the pins. " << endl;
	lg << " The pins Are : A B C D E F G H" << endl;
	lg << "you can try " << tries_left << "times more to go" << endl;
	for (int i = 1 ; i<= 10 ; i++)
	{
		//this truth_pins integer is for making sure that we only print for P , T & X pins not more
		// win checker use to check for wining the game as its name
		int truth_pins=0 , win_checker=0;
		for (; ;)
		{
	      truth_pins=0;
		 int size;
		 cin >> input_pins ;
		 for(int i =0 ; i < 4  ;i++)
		 {
		 	lg<<input_pins[i];
		 }
		 lg<<endl;
		 transform(input_pins.begin(), input_pins.end(),input_pins.begin(), ::toupper);
		 size=input_pins.size();
		 if(size < 4)
		 {
		 	cout << "    please Enter 4 characters mate " << endl;
		 	lg << "    please Enter 4 characters mate " << endl;

		 }else
		 {
		 	break;
		 }

   	    }
   	    for (int j=0 ; j<=3 ; j++)
   	    {
   	    	if (input_pins[j]!= game_pins[j])
			{
					win_checker = 1;
			}
		}

		if( win_checker == 0)
		{
			cout << " YOU WIN " << '\n' << "";
			lg << " YOU WIN " << '\n' << "";
			return 0;
		}
		cout << "    ";
		lg << "    ";
        for (size_t i = 0 ; i < 4 ; i++)
        {
            copy_pins[i]=game_pins[i];
        }
   	    for(int j = 0 ; j<=3 ; j++)
		{

			if ( input_pins[j] == copy_pins[j])
			{
				cout<<"P";
				lg<<"P";
				copy_pins[j]='Z';
				input_pins[j]='Q';
				truth_pins ++;
			}
		}
		for (int j = 0 ; j<=3 ; j++)
		{
			for (int k = 0 ; k <=3 ; k++)
			{
				 if( input_pins[j]== copy_pins[k] && j!=k){
				 	cout<<"T";
				 	lg<<"T";
				 	truth_pins++;
				 	break;
				 }
			}
		}
		for ( int j = truth_pins ; j<4 ; j++){
			cout << "X";
			lg << "X";
		}
		cout << endl;
		lg << endl;
		  tries_left --;
		if(tries_left !=0)
		{
		cout << "         you have " << tries_left << " times more to go GOOD LUCK" << endl;
		lg << "         you have " << tries_left << " times more to go GOOD LUCK" << endl;
        }
    }

    cout << "*****You lose*****" << '\n ' << "Game pins were :";
    lg << "*****You lose*****" << '\n ' << "Game pins were :";
        for( int i = 0 ; i<4 ; i++){
    	cout << game_pins[i] << " ";
    	lg << game_pins[i] << " ";
        }
	lg.close();
	return 0;
}
//this function returns 1 if there is some same pins in computer game chooser or returns 0 if all the pins are unique
// x is char that we sent to this function to be checked if it is unique or not
int is_it_diffrent (char x)
{
	// checker keep the value that will be return from this function
	int checker=0;
	for (int counter = 0 ; counter <=3 ; counter ++)
	{
		if(game_pins[counter] == x)
		{
			checker = 1;
			break;
		}


	}
	return checker;
}
