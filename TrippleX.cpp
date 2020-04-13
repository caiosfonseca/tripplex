// Includes are preprocessor directives
#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // An Expression followed by an semicolon ';' is an expression statement
    // Print welcome messages to the terminal
    std::cout << "You are a rogue breaking into a level " <<  Difficulty << " magical tower.\n";
    std::cout << "Enter the correct number to unlock the door.\n";
    std::cout << "     _                                    \n";
    std::cout << "    | |                                   \n";
    std::cout << "  __| |_   _ _ __   __ _  ___  ___  _ __  \n";
    std::cout << " / _` | | | | '_ \\ / _` |/ _ \\/ _ \\| '_ \\ \n";
    std::cout << "| (_| | |_| | | | | (_| |  __/ (_) | | | |\n";
    std::cout << " \\__,_|\\__,_|_| |_|\\__, |\\___|\\___/|_| |_|\n";
    std::cout << "                    __/ |                 \n";
    std::cout << "                   |___/                  \n\n";
}

bool PlayGame(int Difficulty)
{
    bool Result = false;
    PrintIntroduction(Difficulty);
    // These are declaration statement
    // Declaring our variables and sum/product

    const int CodeA = rand() % Difficulty + Difficulty + 1;
    const int CodeB = rand() % Difficulty + Difficulty + 1;
    const int CodeC = rand() % Difficulty + Difficulty + 1;
    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Printing the sum and product
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    // Store the sum and product of the player guess
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the guess is correct or not
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
       std::cout << "\n*** You passed level " << Difficulty << " ! ***\n\n";
       Result = true;
    }
    else
    {
        std::cout << "\n*** You entered a wrong code, try again *** \n\n";
    }
    return Result;
}

int main()
{
    srand(time(NULL)); // Changes the random seed

    // Initialize the level difficulty and the max level difficulty
    int LevelDifficulty = 1;
    const int MaxLevelDifficulty = 10; 

    while (LevelDifficulty <= MaxLevelDifficulty) // Loop the game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore();// Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
            // Increase the level difficulty
        }
        
    }

    std::cout << "\n*** Well done, you managed to finish the game *** \n\n";
    
    return 0;
}