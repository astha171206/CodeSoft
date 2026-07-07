#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));   // Seed for random number generation

    int randomNumber = rand() % 100 + 1; // Random number between 1 and 100
    int guess;
    int attempts = 0;

   
    cout << "NUMBER GUESSING GAME" << endl;
   
    cout << "Guess a number between 1 and 100." << endl;

    do {
        cout << "\nEnter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > randomNumber) {
            cout << "Too High! Try Again." << endl;
        }
        else if (guess < randomNumber) {
            cout << "Too Low! Try Again." << endl;
        }
        else {
            cout << "\n Congratulations!" << endl;
            cout << "You guessed the correct number: " << randomNumber << endl;
            cout << "Total Attempts: " << attempts << endl;
        }

    } while (guess != randomNumber);

    return 0;
}