//Copyright Vladislav Treshchev. All rights had been reserved
// Game Word JUmble
//Classic game-puzzle, in which the user guesses the words, with or without hints

#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <ctime> 

int main()
{

	// Define an enumeration for word and hint indices in the WORDS array
	enum Fields
	{
		WORD,
		HINT,
		NUM_FIELDS
	};

	// Array to store words and corresponding hints
	const int NUM_WORDS = 5;
	const std::string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{
			"wall", "Do you feel you're banging your head against something?"
		},
		{
			"glasses", "These might help you see the answer."
		},
		{
			"labored", "Going slowly, is it?"
		},
		{
			"persistent", "Keep at it."
		},
		{
			"jumble", "it's what the game is all about."
		}
	};

	// Display game intro messages
	std::cout << "\t\t\tWelcome to Word Jumble!\n\n";
	std::cout << "Unscramble the letters to make a word.\n";
	std::cout << "Enter 'hint' for a hint.\n";
	std::cout << "Enter 'quit' to quit the game.\n\n";

	// Initialize the player's score
	int Score = 0;
	// Flag to track if the player has used a hint in the current round
	bool usedHint = false;

	// Initialize random number generator
	srand(static_cast<unsigned int>(time(0)));

	// Determine the number of rounds for this game (1 to NUM_WORDS)
	int NumRounds = (rand() % NUM_WORDS + 1);

	// Display the number of rounds to the player
	std::cout << "\n\nYou need to guess: " << NumRounds << " words!\n\n";

	// Main game loop - iterates through each round
	for (int Round = 1; Round <= NumRounds; Round++)
	{
		// Variable to store the player's guess
		std::string GuessAnswer;

		// Choose a random word from the WORDS array for this round
		int Choice = (rand() % NUM_WORDS);
		std::string TheWord = WORDS[Choice][WORD]; // The Word to guess
		std::string TheHint = WORDS[Choice][HINT]; // The Hint to write

		// Create a jumbled version of the chosen word
		std::string Jumble = TheWord;
		int Length = Jumble.size();

		// Shuffle the letters of the jumbled word
		for (int i = 0; i < Length; i++)
		{
			int Index_1 = (rand() % Length);
			int Index_2 = (rand() % Length);

			int Temp = Jumble[Index_1];
			Jumble[Index_1] = Jumble[Index_2];
			Jumble[Index_2] = Temp;
		}

		// Display the jumbled word and prompt the player for their guess
		std::cout << "The jumble is: " << Jumble;
		std::cout << "\n\nRound  " << Round << "\n";
		std::cout << "\n\nYour guess: ";
		std::cin >> GuessAnswer;


		// Round loop: Continues until the player enters 'quit' or guesses correctly
		while (GuessAnswer != "quit")
		{
			// Reset the hint flag at the beginning of each round
			usedHint = false;

			// Check if the player requests a hint
			if (GuessAnswer == "hint")
			{
				std::cout << TheHint; // Display the hint
				usedHint = true; // Set hint flag since hint was used
			}
			// Check if the player guessed the word correctly
			else if (GuessAnswer == TheWord)
			{
				std::cout << "\nThat's it! You guessed it!\n";

				// Award points based on hint usage
				if (usedHint)
				{
					Score = 0;
					std::cout << "\nYou got " << Score << " points because you used the hint.\n";
				}
				else
				{
					Score = Score + TheWord.size();
				}

				break;  // Move to next round after correct guess
			}
			// Player guessed incorrectly 
			else
			{
				std::cout << "\nSorry, that's not it\n";

				// Deduct points if score is not already zero
				if (Score > 0)
				{
					Score = Score - 2;
					std::cout << "2 points were taken away from you, be careful!";
				}

				std::cout << "\nYour score: " << Score; // Display the current score
			}
			// Prompt for next guess 
			std::cout << "\nYour guess: ";
			std::cin >> GuessAnswer;
		}
		// End of round

		// Exit the game loop if the player enters 'quit' 
		if (GuessAnswer == "quit")
		{
			break;
		}
	}
	// End of game

	// Display the final score and a goodbye message
	std::cout << "\n\nYour score: " << Score;
	std::cout << "\nThanks for playing!\n";
	return 0;
}



/*enum difficulty
{
	EASY,
	MEDIUM,
	HARD,
	NUM_DIFF_LEVELS
};
std::cout << "There are " << NUM_DIFF_LEVELS << " difficulty levels\n";
*/