#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread> // Include the <thread> header for std::this_thread::sleep_for

/**
 * @brief The main function of the program.
 * 
 * This function allows the user to play a casino game. It prompts the user for the total number of games they wish to play,
 * and then runs the game loop until the user has played the desired number of games or chooses to stop. The function keeps track
 * of the total number of wins and losses and displays the final results at the end.
 * 
 * @return int The exit status of the program.
 */
int main() {
    int userInput = -1;
    int counter = 0;
    int totalWins = 0;
    int totalLosses = 0;
    int isFinished = false;
    char userContinue;
    // Ask user for total games they wish to play
    // Loop through the game until the user has played the total amount of games they wish to play
    do { 
        std::cout << "How many games would you like to play?: ";
        std::cin >> userInput;
        counter = 0;

        while (counter < userInput) { //Change to while isfinished == false  
            srand(time(0));
            std::this_thread::sleep_for(std::chrono::seconds(rand() % 4)); // Replace sleep with std::this_thread::sleep_for
            int out1 = rand() % 10;
            std::this_thread::sleep_for(std::chrono::seconds(rand() % 3)); // Replace sleep with std::this_thread::sleep_for
            int out2 = rand() % 10;
            std::this_thread::sleep_for(std::chrono::seconds(rand() % 4)); // Replace sleep with std::this_thread::sleep_for
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
        std::cin >> userContinue;
    } while (userContinue == 'Y' || userContinue == 'y');

    std::cout << "Thanks for playing! Wins = " << totalWins << " | Losses = " << totalLosses << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(10)); // Replace sleep with std::this_thread::sleep_for
    std::cout << "Goodbye!" << std::endl;   
}