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
	int numberCount = 0;
	int num = 0;
	int numOfSafeReports = 0;
	

	// Count the number of intergers in the line.
	while (getline(inputFile, line))
	{
		istringstream inputString(line);
		while (inputString >> num)
		{
			reportInput.push_back(num);
		}

		for (int itr = 0; itr <= reportInput.size(); itr++)
		{
			if (abs(reportInput.at(itr) - reportInput.at(itr + 1)) > 3 || abs(reportInput.at(itr) - reportInput.at(itr + 1)) == 0)
			{
				break;
			}

		}
		

	}



		

		
		
		/*
			Analyze Numbers
			All are increasing or decreasing
			All levels should increase between 1 and 3
		*/
								
	inputFile.close();





}





int main()
{
	safeReports();
	return 0;
}
