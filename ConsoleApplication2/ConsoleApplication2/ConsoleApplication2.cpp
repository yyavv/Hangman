#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

char play;
int canswer = 0, wanswer = 0, hintuse = 0, gamewon = 0, gamelost = 0;

void wordGenerator(string &word, string &category)
{
	ifstream files("wordList.txt");
	int wordnumber = (int) count(istreambuf_iterator<char>(files), istreambuf_iterator<char>(), '\n') + 1;
	files.close();
	
	ifstream file("wordList.txt");

	int random = rand() % wordnumber + 1;
	int i = 1;

	while (file >> word >> category)
	{	
		if (random == i++)
		{
			break;
		}
	}
}

void draw(int x)
{
	switch (x)
	{
	case 8:
		cout << "     -----------" << endl
			 << "      |        |" << endl;
		cout << "      |        0" << endl
			 << "      |      \\   /" << endl
			 << "      |        |" << endl
			 << "      |        |" << endl;
		cout << "      |        |" << endl
			 << "      |      /   \\" << endl
			 << "      |      " << endl;
		cout << "------------";
		break;
	
	case 7:
		cout << "     -----------" << endl
			 << "      |        |" << endl;
		cout << "      |        0" << endl
			 << "      |      \\   /" << endl
			 << "      |        |" << endl
			 << "      |        |" << endl;
		cout << "      |        |" << endl
			 << "      |         " << endl
			 << "      |         " << endl;
		cout << "------------";
		break;
	case 6:
		cout << "     -----------" << endl
	  		 << "      |        |" << endl;
		cout << "      |        0" << endl
			 << "      |      \\   /" << endl
			 << "      |         " << endl
			 << "      |         " << endl;
		cout << "      |         " << endl
			 << "      |         " << endl
			 << "      |         " << endl
			 << "      |         " << endl;
		cout << "------------";
		break;
	
	case 5:
		cout << "     -----------" << endl
			 << "      |        |" << endl;
		cout << "      |        0" << endl
			 << "      |         " << endl
			 << "      |         " << endl
			 << "      |         " << endl;
		cout << "      |         " << endl
			 << "      |         " << endl
			 << "      |         " << endl
			 << "      |         " << endl;
		cout << "------------";
		break;
	case 4:
		cout << "     -----------" << endl
			 << "      |        |" << endl;
	case 3:
		cout << "      |      " << endl
			 << "      |      " << endl
			 << "      |      " << endl
			 << "      |      " << endl;
	case 2:
		cout << "      |      " << endl
			 << "      |      " << endl
			 << "      |      " << endl
			 << "      |      " << endl;
	case 1:
		cout << "------------";
		break;

	default:
		break;
	}
}

void game()
{
	string word, category, guessWord, cword;
	wordGenerator(word, category);
	guessWord = word;
	cword = word;
	for (int i = 0; i < guessWord.length(); i++)
		guessWord[i] = '_';

	bool hint = false;
	char guess;
	int x = 0;

	cout << "\t\t\t\t\t\tWELCOME TO THE HANGMAN GAME" << endl;

	draw(8);

	Sleep(2000);

	system("cls");

	while (true)
	{
		int count = 0;

		draw(x);

		cout << endl;
		cout << "\t\t\t\t" << category;

		if (x >= 3 && !hint)
		{
			cout << "\t\t\t\t\t\t\tFor hint press 9";
		}

		cout << endl << endl << "\t\t\t\t";

		for (int i = 0; i < guessWord.length(); i++) cout << guessWord[i] << "  ";

		cout << endl << endl;

		cout << "LETTER GUESS: ";
		cin >> guess;

		if (guess == '9')
		{
			hintuse++;
			int number = rand() % word.length();
			while (guessWord[number] != '_')
			{
				number = rand() % word.length();
			}

			guess = word[number];
		}

		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] == guess)
			{
				canswer++;
				count++;
				guessWord[i] = guess;
				word[i] = NULL;
			}
		}

		if (count == 0) { wanswer++; x++; }

		if (x == 8)
		{
			gamelost++;
			system("cls");
			cout << "YOU LOST!";
			cout << endl << endl;
			draw(x);
			cout << endl << endl;
			cout << "ANSWER: " << cword;
			break;
		}

		if (guessWord == cword)
		{
			gamewon++;
			system("cls");
			cout << "YOU WIN!";
			cout << endl << endl;
			draw(x);
			cout << endl << endl;
			cout << "ANSWER: " << cword;
			break;
		}

		system("cls");
	}
}

int main()
{
	srand(time(0));

	play = '1';

	while (play == '1')
	{
		game();
		
		cout << "\n\n\nPress 1 To Play Again: ";
		cin >> play;
		cout << play;
	}

	system("cls");

	cout << "Total Correct Answers: " << canswer << endl;
	cout << "Total Wrong Answers: " << wanswer << endl;
	cout << "Total Hint Used: " << hintuse << endl;
	cout << "Total Games Won: " << gamewon << endl;
	cout << "Total Games Lost: " << gamelost << endl;
}