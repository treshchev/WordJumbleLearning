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
	}
	int Temp = Jumble[Index_1];
	Jumble[Index_1] = Jumble[Index_2];
	Jumble[Index_2] = Temp;
	


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