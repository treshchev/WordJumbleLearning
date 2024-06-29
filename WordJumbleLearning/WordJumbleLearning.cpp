//Copyright Vladislav Treshchev. All rights had been reserved
// Game Word JUmble
//Classic game-puzzle, in which the user guesses the words, with or without hints

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main()
{
	enum fields
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

	std::cout << "\t\t\tWelcome to Word Jumble!\n\n";
	std::cout << "Unscramble the letters to make a word.\n";
	std::cout << "Enter 'hint' for a hint.\n";
	std::cout << "Enter 'quit' to quit the game.\n\n";
	std::cout << "The jumble is: " << Jumble;
	std::string Guess;
	std::cout << "\n\nYour guess: ";
	std::cin >> Guess;

	while ((Guess != TheWord) && (Guess != "quit"))
	{
		if (Guess == "hint")
		{
			std::cout << TheHint;
		}
		else
		{
			std::cout << "Sorry, that's not it";
		}
		std::cout << "\n\nYour guess: ";
		std::cin >> Guess;
	}

	if (Guess == TheWord)
	{
		std::cout << "\nThat's it! You guessed it!\n";
	}
	std::cout << "\nThanks for playing!\n";
	return 0;


	/*enum difficulty
	{
		EASY,
		MEDIUM,
		HARD,
		NUM_DIFF_LEVELS
	};
	std::cout << "There are " << NUM_DIFF_LEVELS << " difficulty levels\n";
    */
}