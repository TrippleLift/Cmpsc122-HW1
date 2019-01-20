// AC1.2.cpp
// Author: Joseph Chang
// Class: CMPSC 122

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//functions prototype
int computer();
int userFunc();
bool compare(int, int);
string textGenerating(int);

int main()
{
	bool draw;
	int comp, user;

	//call functions to play and check if it needs to replay
	do
	{
		//computer play first, then user play
		comp = computer();
		user = userFunc();
		cout << "You play " << textGenerating(user) << ", and the computer play "
			<< textGenerating(comp) << ", so ";

		draw = compare(comp, user);

	} while (draw);

	system("pause");
	return 0;
}

//play rock paper scissors randomly
int computer()
{
	unsigned seed = time(0);
	srand(seed);

	string comp;

	int randNum = (rand() % 3) + 1;

	return randNum;
}

//ask user to enter their play
int userFunc()
{
	int user;

	//make sure that user enter a valid play
	do
	{
		cout << "Please enter a number between 1 & 3. (1 for rock, 2 for paper, 3 for scissors)\n";
		cin >> user;

		if (user < 1 || user > 3)
			cout << "Invalid answer, try again.\n";

	} while (user < 1 || user > 3);

	return user;
}

//print the result which indicate who win, and return if it needs to play again.
bool compare(int comp, int user)
{
	bool draw = false;
	int sub = 0; //subtraction
	sub = comp - user;

	if (sub == 0)
	{
		cout << "it is a draw, play again.\n";
		draw = true;
	}
	else if (sub == 1 || sub == -2)
	{
		cout << "the computer wins.\n";
	}
	else
	{
		cout << "you win.\n";
	}

	return draw;
}

//generate the text of "rock paper scissors" in the result
string textGenerating(int num)
{
	switch (num)
	{
	case 1:
		return "rock";
	case 2:
		return "paper";
	case 3:
		return "scissors";
	}
}

