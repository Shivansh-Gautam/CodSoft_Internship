#include <iostream>
#include <cstdlib>  
#include <ctime>    

int main() {
    // Seed the random number generator
    std::srand(std::time(0)); 

    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;
    int userGuess = 0;

    std::cout << "Welcome to the number guessing game!" << std::endl;
    std::cout << "I have chosen a number between 1 and 100. Try to guess it!" << std::endl;

    // Loop until the user guesses the correct number
    while (userGuess != randomNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        if (userGuess > randomNumber) {
            std::cout << "Your guess is too high. Try again." << std::endl;
        } else if (userGuess < randomNumber) {
            std::cout << "Your guess is too low. Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the number!" << std::endl;
        }
    }

    return 0;
}
