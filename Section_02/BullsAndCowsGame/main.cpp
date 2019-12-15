#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();


// the entry point for our app
int main()
{
	bool bPlayAgain = false;
	do {
	PrintIntro();
	PlayGame();
	bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);
	return 0; //exit app
}



// game intro
void PrintIntro() 
{
	constexpr int WORD_LENGHT = 5;
	cout << "Welcome to Bulls and Cows, traveller. It's a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGHT;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}

void PlayGame()
{
	// loop for the number of turns asking for guess
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		string Guess = GetGuess();
			cout << "Your guess was: " << Guess << endl;
		cout << endl;
		cout << endl;
	}
}

// player guess
string GetGuess() 
{
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again? y/n ";
	string Response = "";
	getline(cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
