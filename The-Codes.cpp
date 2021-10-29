// Duc Tran
// The Codes

#include <iostream>
#include <ctime>

void GameIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are trapped in room number " << Difficulty;
    std::cout << " of a nuclear cellar...\n";
    std::cout << "Enter the correct codes to open the door...\n\n";
}

bool PlayGame(int Difficulty)
{
    GameIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiple to give: " << CodeProduct;
    std::cout << std::endl;

    // Store player guess
    int GuessCodeA, GuessCodeB, GuessCodeC;
    std::cin >> GuessCodeA >> GuessCodeB >> GuessCodeC;

    int GuessSum = GuessCodeA + GuessCodeB + GuessCodeC;
    int GuessProduct = GuessCodeA * GuessCodeB * GuessCodeC;

    // Check if the player guesses is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done human! Be prepared for the next challenge! ***";
        return true;
    }
    else
    {
        std::cout << "\n*** Don't think you can beat me that easy! Try again! ***";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // create new random sequence based on time of a day
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clear any errors
        std::cin.ignore();// Discard the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }

    }

    std::cout << "\n*** Good job human! Now get out of there before I change my mind! ***\n";
    return 0;
}