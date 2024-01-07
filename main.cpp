#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

/**
 * @brief The main function of the program.
 * 
 * This function allows the user to play a casino game. It prompts the user to enter the number of games they want to play,
 * and then runs a loop to simulate the game for the specified number of times. After each game, it checks if the user wants
 * to continue playing or not. If the user chooses to continue, the loop runs again with the new number of games. If the user
 * chooses to stop playing, the function displays the total number of wins and losses and exits the program.
 * 
 * @return 0 indicating successful execution of the program.
 */
int main() {
    int userInput = -1;
    int counter = 0;
    std::cout << "How many games would you like to play?: ";
    std::cin >> userInput;
    int totalWins = 0;
    int totalLosses = 0;
    
    // Ask user for total games they wish to play
    // Loop through the game until the user has played the total amount of games they wish to play

    while (counter < userInput) {
        

        srand(time(0));
        sleep(rand() % 4);
        int out1 = rand() % 10;
        sleep(rand() % 3);
        int out2 = rand() % 10;
        sleep(rand() % 4);
        int out3 = rand() % 10;

        std::cout << out1 << " " << out2 << " " << out3;
        if (out1 == out2 || out1 == out3 || out2 == out3) {
            totalWins++;
            std::cout << " - You win Minor Prize! Wins = " << totalWins << " | Losses = " << totalLosses << std::endl;
            counter++;
        } else if (out1 == out2 && out3) {
            totalWins++;
            std::cout << " - You win Major Prize! Wins = " << totalWins << " | Losses = " << totalLosses << std::endl;
            counter++;
        } else if (out1 != out2 && out1 != out3) {
            totalLosses++;
            std::cout <<  " - You lose! Wins = " << totalWins << " | Losses = " << totalLosses << std::endl;
            counter++;
            }
        
        }
    // Asks user if they wish to continue playing
    // If yes continue for x number of games if no output record of wins and losses
    std::cout << "Would you like to continue playing? (Y/N): ";
    char userContinue;
    std::cin >> userContinue;
    if (userContinue == 'Y' || userContinue == 'y') {
        std::cout << "How many games would you like to play?: ";
        std::cin >> userInput;
        counter = 0;
        while (counter < userInput) {
        

        srand(time(0));
        sleep (rand() % 4);
        int out1 = rand() % 10;
        sleep(rand() % 3);
        int out2 = rand() % 10;
        sleep(rand() % 4);
        int out3 = rand() % 10;

        std::cout << out1 << " " << out2 << " " << out3;
        if (out1 == out2 || out1 == out3) {
            totalWins++;
            std::cout << " - You win Minor Prize! Wins = " << totalWins << " | Losses = " << totalLosses << std::endl;
            counter++;
        } else if (out1 == out2 && out3) {
            totalWins++;
            std::cout << " - You win Major Prize! Wins = " << totalWins << " | Losses = " << totalLosses << std::endl;
            counter++;
        } else if (out1 != out2 && out1 != out3) {
            totalLosses++;
            std::cout <<  " - You lose! Wins = " << totalWins << " | Losses = " << totalLosses << std::endl;
            counter++;
            }
        if (counter == userInput) {
            std::cout << "Thanks for playing! Wins = " << totalWins << " | Losses = " << totalLosses << std::endl;
            sleep (1000);
        }
        
        }
    } else if (userContinue == 'N' || userContinue == 'n') {
        std::cout << "Thanks for playing! Wins = " << totalWins << " | Losses = " << totalLosses << std::endl;
        sleep (1000);
    }
    return 0;
}