//Copyright Vladislav Treshchev. All rights had been reserved
// Game Word JUmble
//Classic game-puzzle, in which the user guesses the words, with or without hints

#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <ctime> 

int main()
{

	enum Fields
	{
		WORD,
		HINT,
		NUM_FIELDS
	};

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
	std::cout << "\t\t\tWelcome to Word Jumble!\n\n";
	std::cout << "Unscramble the letters to make a word.\n";
	std::cout << "Enter 'hint' for a hint.\n";
	std::cout << "Enter 'quit' to quit the game.\n\n";
	int Score = 0;
	bool usedHint = false;
	int NumRounds = (rand() % NUM_WORDS + 1);
	std::cout << "\n\nYou need to guess: " << NumRounds << " words!\n\n";

	for (int Round = 1; Round <= NumRounds; Round++)  // Цикл по раундам
	{
		std::string GuessAnswer;

		srand(static_cast<unsigned int>(time(0)));
		int Choice = (rand() % NUM_WORDS);
		std::string TheWord = WORDS[Choice][WORD]; // The word to guess
		std::string TheHint = WORDS[Choice][HINT]; // The hint for the word

		std::string Jumble = TheWord; // The mixed version of the word
		int Length = Jumble.size();



		for (int i = 0; i < Length; i++)
		{
			int Index_1 = (rand() % Length);
			int Index_2 = (rand() % Length);

			int Temp = Jumble[Index_1];
			Jumble[Index_1] = Jumble[Index_2];
			Jumble[Index_2] = Temp;
		}

		std::cout << "The jumble is: " << Jumble;
		std::cout << "\n\nYour guess: ";
		std::cin >> GuessAnswer;


		std::cout << "\nRound  " << Round << ": \n";

		while ((GuessAnswer != TheWord) && (GuessAnswer != "quit"))
		{
			usedHint = false;

			if (GuessAnswer == "hint")
			{
				std::cout << TheHint;
				usedHint = true;
			}
			else
			{
				std::cout << "Sorry, that's not it";
			}
			std::cout << "\n\nYour guess: ";
			std::cin >> GuessAnswer;
		}

		if (GuessAnswer == TheWord)
		{
			std::cout << "\nThat's it! You guessed it!\n";

			if (usedHint)
			{
				Score = 0;
				std::cout << "\nYou got " << Score << " points because you used the hint.\n";
			}
			else
			{
				Score = Score + TheWord.size();
			}
		}

	}
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