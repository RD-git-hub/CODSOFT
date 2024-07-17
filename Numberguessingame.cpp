#include <iostream>
#include <cstdlib>  
#include <ctime>   
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    cout << "Welcome to the Number Guessing Game!" << endl;
    do {
        cout << "Enter your guess (between 1 and 100): ";
        cin >> guess;
        attempts++;
        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
        }
    } while (guess != secretNumber);
    return 0;
}
