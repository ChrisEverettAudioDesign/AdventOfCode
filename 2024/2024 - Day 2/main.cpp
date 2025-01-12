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
	int numOfAbsFails = 0;
	int failLocation = 0;

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
			absResult = abs(reportInput[itr] - reportInput[itr+1]);
			
			if (absResult > 3 || absResult == 0  && numOfAbsFails <= 1)
			{
				numOfAbsFails++;
				failLocation = itr;				
				reportInput.erase(reportInput.begin() + failLocation);
				reportInput.resize(reportInput.size());
				itr = -1;
			}

			else if (numOfAbsFails > 1)
			{
				reportInput.clear();
				break;
			}
			else {}

		}
			
		if (is_sorted(reportInput.begin(), reportInput.end()) == true && numOfAbsFails <= 1)
		{
			numOfSafeReports++;
		}
		else if (is_sorted(reportInput.rbegin(), reportInput.rend()) == true && numOfAbsFails <= 1)
		{
			numOfSafeReports++;
		}
		else if (is_sorted(reportInput.begin(), reportInput.end()) == false && numOfAbsFails <= 1)
		{
			numOfSafeReports++;
		}
		else if (is_sorted(reportInput.rbegin(), reportInput.rend()) == false && numOfAbsFails <= 1)
		{
			numOfSafeReports++;
		}

		numOfAbsFails = 0;
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
