#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>



using namespace std;

void safeReports()
{

	ifstream inputFile("inputfile.txt");
	vector<int> reportInput;
	
	string line;

	const int lineCount = 1000;
	int lineLength = 0;
	int numOfSafeReports = 0;
	int itr = 0;

	// Count the number of intergers in the line.
	while (getline(inputFile, line))
	{
		lineLength = 0;
		istringstream inputString(line);
		while (inputString >> line)
		{
			lineLength++;
		}
	}


	for (int index = 0; index < lineCount; index++)
	{
		for (int length = 0; length < lineLength; length++)
		{
			int num = 0;
			inputFile >> num;
			reportInput.push_back(num);


		}

		
		
		/*
			Analyze Numbers
			All are increasing or decreasing
			All levels should increase between 1 and 3
		*/
	}
	
	inputFile.close();





}





int main()
{
	safeReports();
	return 0;
}
