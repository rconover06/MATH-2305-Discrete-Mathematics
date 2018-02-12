/*
	Filename: Guessing_Game.cpp

	Author: Raul Conover

	Date: February 8, 2018

	Description: Program will ask a player to think of a number then
		display a set of numbers to the player. If the number appears
		in the set it will calculate the number the user is thinking of
		based upon their response.
*/

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

// Function Prototypes
void setup_game();
int in_set(int);
void generate_set(int);
void guess_number(int);
bool repeat();

int const MAX = 50;

int main ()
{
    // Variables
    int guess;
    int set;
    char ch;
    
    setup_game();
    
    do
    {
        guess = 0;
        // use 2^n to generate the sets of numbers.
        for (int i = 0; i < 6; i++)
        {
            set = pow(2, i);                         // Calculate 2^n
            cout << "\t\t   Set " << i + 1 << endl; 
            generate_set(set);
            // Use return value of in_set to calculate the total for the guess.
            guess = guess + in_set(set);
            cout << endl;
        }
        cin.get(ch);
        guess_number(guess);

    } while (repeat());
    return 0;
}

// Description: Function prints out the rules for the game.
// Pre: None
// Post: Prints the welcome and rules for the game.
void setup_game()
{
	char ch;
	cout << "|----------------------------------------------|" << endl
             << "|       Welcome to Raul's Guessing Game!       |" << endl
             << "|                                              |" << endl
             << "| You will think of a number between 1 and 50, |" << endl
	     << "| and I show you series of number sets and ask |" << endl
             << "| if your number appears in the number set.    |" << endl   
             << "|----------------------------------------------|" << endl
             << "         Press ENTER to start the game.         " << endl;
	   	 cin.get(ch);
}
// Function asks the user if their number was in the set of numbers displayed
//  If the number appeared in the set it returns it. otherwise returns 0.
// Pre: Reads in the base setNumber
// Post: returns setNumber or zero if the number was in the set or not.
int in_set(int setNumber)
{
	char response;
	cout << "Does your number appear in this set of numbers? Y/N? ";
	cin >> response;
	response = tolower(response);
	if (response == 'y')
		return setNumber;
	else
		return 0;
}
// Generates the set of numbers and prints them on the screen.
// Pre: Reads in setNumber.
// Post: uses the set number to generate and print out the numbers
//      on the screen.
void generate_set(int setNumber)
{
    int i, j = 0;
    
    cout << endl << "\t   ";
    
    for (i = setNumber; i <= MAX; i++)
    {   
        if((i / setNumber) % 2 == 1)
        {
            cout << setw(3) << i << " "; 
            j++;
            if (j % 5 == 0)
                cout << endl << "\t   ";
        }
    }
        cout << endl << endl;
}
// Function prints out the guess based on the answers the user made. 
// Pre: reads in total from guesses.
// Post: Prints out the total. If total is out of range then it tells the user
//      to play again.
void guess_number(int total)
{
    char ch;
        cout << "|----------------------------------------------|" << endl
             << "|       I am ready to guess your number.       |" << endl
             << "|         Press ENTER to reveal guess.         |" << endl
             << "|----------------------------------------------|";
        cin.get(ch);
    
        if (total < 1 || total > MAX)
            cout << "|      Your number is outside the range.       |" << endl
                 << "|              Please play again!              |" << endl
                 << "|----------------------------------------------|" << endl;
        else
            cout << "|      The number you were thinking of was     |" << endl
                 << "|" << setw(24) << total << "                      |" << endl
                 << "|----------------------------------------------|" << endl;
}
// This funciton asks the user if they would like to play the game again.
// Pre: The game is complete and a guess was made.
// Post: Returns true if player would like to play again and false if not.
bool repeat()
{
	char repeat;
	cout << endl << "\tWould you like to play again? Y/N: ";
	cin >> repeat;
	repeat = tolower(repeat);
	if (repeat == 'y')
		return true;
	else
	{
		cout << "\t\tThank you!" << endl << endl;
		return false;
	}
}