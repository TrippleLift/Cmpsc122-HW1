// AC1.3.cpp
// Author: Joseph Chang
// Class: CMPSC 122

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//create the struct and initialize it
struct monthlyBudget
{
	double value[9] = { 500, 150, 65,
		50, 250, 30,
		100, 75, 50 };

	string type[9] = { "Housing", "Utilities",
		"HouseholdExpenses",
		"Transportation", "Food",
		"Medical", "Insurance",
		"Clothing", "Miscellaneous" };
};

//fucntions prototype
monthlyBudget survey(monthlyBudget);
void report(monthlyBudget);
string textGen(int);

int main()
{
	//create the object
	monthlyBudget userBudget;

	//ask the user
	userBudget = survey(userBudget);
	
	//print the result
	report(userBudget);

	system("pause");
	return 0;
}

//ask the user to enter the information
monthlyBudget survey(monthlyBudget userBudget)
{
	double tempMoney;
	for (int i = 0; i<9; i++)
	{
		cout << "How much money you spent on "
			<< userBudget.type[i] << " this year?\n";
		cin >> tempMoney;
		userBudget.value[i] -= tempMoney;
	}

	return userBudget;
}

//print the result
void report(monthlyBudget userBudget)
{
	int sum = 0; // sum is the total budget
	string tempText;
	cout << "Budget report:\n";
	for (int i = 0; i<9; i++)
	{
		sum += userBudget.value[i];

		tempText = textGen(userBudget.value[i]);

		if (userBudget.value[i] < 0)
			userBudget.value[i] *= -1;

		cout << setw(18) << userBudget.type[i] << ":"
			<< setprecision(2) << fixed << setw(7)
			<< userBudget.value[i] << "$ " << tempText << endl;
	}

	tempText = textGen(sum);
	if (sum < 0)
		sum *= -1;

	cout << "Total budget: " << sum << "$ " << tempText << endl;
}

//generate the text which indicate it's under or over the budget
//this function is called by function report
string textGen(int num)
{
	string text;
	if (num>0)
	{
		text = "under";
	}
	else if (num<0)
	{
		text = "over";
	}
	else
	{
		text = "";
	}

	return text;
}

