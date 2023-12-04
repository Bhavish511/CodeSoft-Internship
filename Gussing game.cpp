#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int secretNumber = rand() % 100 + 1;
    int attempts = 0;
    int userGuess = 0;

    cout << "Welcome to Guess the Number!" << endl;

    while (userGuess != secretNumber) {
        try {
            cout << "Guess the number between 1 ....... : ";
            cin >> userGuess;
            attempts++;

            if (userGuess < secretNumber) {
                cout << "Too low! Try again." << endl;
            } else if (userGuess > secretNumber) {
                cout << "Too high! Try again." << endl;
            } else {
                cout << "Congratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts." << endl;
            }
        } catch (...) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}

