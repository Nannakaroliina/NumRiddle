#include <iostream>
#include <ctime>

void PrintIntroduction() 
{
    // Printing welcome messages to terminal
    std::cout << "\n\nYou see the world around you glazing slowly. Everything stops around you and the only way to save everyone is to go back in time and stop the glazing before it even starts. \n\n";

    std::cout << "Get ready for a challenge, brave one. You need to stop a mad man from making his dream true and find the Time Machine.\n\n";

    std::cout <<  "Time Machine is in government's secret lab and you need to get access it by hacking their security system. If you don't succeed, you will end up to timeless space for the rest of your life.\n\n";
    
    std::cout << "You need to enter correct answers to following codes to get access to the time machine...\n";
}
bool PlayGame(int Difficulty) 
{
    std::cout << "Your current level is " << Difficulty << std::endl;

    // Declaring variables
    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;

    // Using operators to get sum and multiply of our numbers
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeMult = CodeA * CodeB * CodeC;

    //Print out the sum and multiply results of our numbers
    std::cout << "\n~ There are 3 numbers in the codes.\n";
    std::cout << "~ The codes add-up to: " << CodeSum;
    std::cout << "\n~ The codes multiply to give: " << CodeMult << std::endl;

    // Declearing player guess variables to store input
    int GuessA, GuessB, GuessC;
    
    // Storing player guess
    std::cin >> GuessA >> GuessC >> GuessB;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessMult = GuessA * GuessB * GuessC;
    
    std::cout << "\nThe sum is " << GuessSum;
    std::cout << "\nThe multiply is " << GuessMult;

    // Check if user gives correct numbers
    if(GuessSum == CodeSum && GuessMult == CodeMult) 
    {
        std::cout << "\n\n~~ Well done! Keep going! ~~\n";
        return true;
    } else {
        std::cout << "\n\n~~ You failed... Be careful and try again! ~~\n";
        return false;
    }
}

int main() 
{
    srand(time(NULL));  // Create new random sequence based on time of day
    PrintIntroduction();

    int LevelDifficulty = 1;
    const int MaxDifficultyLevel = 5;

    // Loop game until difficulty level is as high as max difficulty
    while (LevelDifficulty <= MaxDifficultyLevel) 
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears errors
        std::cin.ignore(); // Discards the buffer

        // If player completes level, difficulty increases
        if (bLevelComplete)
        {
            LevelDifficulty++;
        }
    }

    std::cout << "\n ~~ Amazing! You made it! ~~";
    return 0;
}