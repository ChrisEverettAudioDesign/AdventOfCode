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
	bool absFail = false;
	

	// Count the number of intergers in the line.
	while (getline(inputFile, line))
	{
		istringstream inputString(line);
		while (inputString >> num)
		{
			reportInput.push_back(num);
		}

		for (int itr = 0; itr < reportInput.size() - 1; itr++)
		{
			int absResult = 0;
			absFail = false;
			absResult = abs(reportInput[itr] - reportInput[itr+1]);
			
			if (absResult > 3 || absResult == 0)
			{
				absFail = true;
				break;
			}
		}

		if (is_sorted(reportInput.begin(), reportInput.end()) == true && absFail == false)
		{
			numOfSafeReports++;
		}
		else if (is_sorted(reportInput.rbegin(), reportInput.rend()) == true && absFail == false)
		{
			numOfSafeReports++;
		}
		else
		{ }

		reportInput.clear();
		
	}

	cout << numOfSafeReports << endl;
								
	inputFile.close();

}





int main()
{
	safeReports();
	return 0;
}
