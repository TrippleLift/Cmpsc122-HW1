// AC1.4.cpp
// Author: Joseph Chang
// Class: CMPSC 122

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//functions prototype
void randomize(vector<int> &);
int countEven(vector<int>, vector<int>);

int main()
{
	//create two vector
	vector <int> vector1(30);
	vector <int> vector2(30);
	int count;
	
	//randomize the random fucntion
	srand(time(0));

	//call the randomize fucntion
	randomize(vector1);
	randomize(vector2);

	//call the count even fucntion
	count = countEven(vector1, vector2);

	//print every number to test
	//for (int i = 0; i<vector1.size(); i++)
	//	cout << vector1[i] << " " << vector2[i] << endl;

	//print the result
	cout << "The Vectors contain " << count
		<< " cells where both values are even\n";

	system("pause");
	return 0;
}

//put random from 0 to 100 into the 30 space vector
void randomize(vector<int> &vec)
{
	for (int i = 0; i<vec.size(); i++)
	{
		vec[i] = (rand() % 100) + 1;
	}
}

//count how many time which two vectors have even number at the same time
int countEven(vector<int> vec1, vector<int> vec2)
{
	int count = 0;
	for (int i = 0; i<vec1.size(); i++)
	{
		if ((vec1[i] % 2) == 0 && (vec2[i] % 2) == 0)
			count++;
	}

	return count;
}

