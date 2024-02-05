/*******************************************************************************

* Program: Number Guessing Game

* Description: Example of a number guessing game in C++ in 5 attempts

*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  // Seed the random number generator with the current time as returned by 
  // time() when it is passed NULL, in order to ensure a different random 
  // number seed each time the program is executed.
  srand((unsigned int) time(NULL));
  
  // Generate a random number between 1-1000, store it into the number variable.
  // rand() will return a random int value between 0 and a large number, mod 1000
  // will turn that number into a 0-999 range, and +1 shifts that range to 1-1000!
  int number = (rand() % 1000) + 1; 
  
  // Stores the guess the user enters
  int guess = 0; int attempt=5;
  
  do
  {
    // Ask the user to enter the guess, store it into guess
    cout << "Enter Guessed number (1-1000)(you have "<<attempt<<" attempts left) : ";
    cin >> guess;
    
    attempt--;
    // Tell the user to guess higher or lower or that they won based on 
    // comparing the guess to the number or they will lose if all attempts get wasted
    if (guess == number)
     { cout << "You won!" << endl; goto END;}
      if(attempt==0) goto END;
    else if (guess < number)
      cout << "Guess higher!" << endl;
    else
      cout << "Guess lower!" << endl;
      
    // Keep the game going by having the user guess as many times as  
    // they have attempts left.
  } while (guess != number && attempt!=-1);
  END:
  if(guess!=number) cout<<"You wasted all your attempt"<<endl;
   
  return 0;
}
