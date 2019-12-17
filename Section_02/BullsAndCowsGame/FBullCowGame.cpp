#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "end";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	
	return;
}


bool FBullCowGame::IsGameWon() const {return false; }

bool FBullCowGame::CheckGuessValidity(FString) { return false; }

// receives a VALID guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// incriment the turn number
	MyCurrentTry++;
	// setup a return variable
	FBullCowCount BullCowCount;


	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
	// compare letters against the hidden word
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
	// if they match then
			if(Guess[i] == MyHiddenWord[i]) {
	// if they're in the same place
				if (i == j) {
					BullCowCount.Bulls++; // incriment bulls
				}
				else {
					BullCowCount.Cows++;// must be a cow
				}
			}
		}
	}
	return BullCowCount;
}