// AC1.1.cpp
// Author: Joseph Chang
// Class: CMPSC 122

#include <iostream>

using namespace std;

int *modifliedArray(const int *, int);

int main()
{
	const int size = 30;
	//create the original array
	int array[size];
	for (int i = 1; i <= 30; i++)
	{
		array[i - 1] = i;
	}

	//create a pointer
	int *mod = nullptr;

	//copy the array and modify it
	mod = modifliedArray(array, size);

	//print the array to check it
	for (int i = 0; i<size + 1; i++)
	{
		cout << mod[i] << " ";
	}
	system("pause");
	return 0;
}

//modifly the array
int *modifliedArray(const int *arr, int size)
{
	if (size <= 0)
		return nullptr;

	int *newArray = nullptr;

	newArray = new int[size + 1];

	newArray[0] = 0;

	for (int i = 1; i<size + 1; i++)
		newArray[i] = arr[i - 1];

	return newArray;
}



