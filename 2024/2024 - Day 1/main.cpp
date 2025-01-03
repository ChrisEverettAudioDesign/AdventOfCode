#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>


using namespace std;


void listStorage()
{
	ifstream inputFile("inputfile.txt");
	vector<char> leftList;
	vector<char> rightList;
	vector<int> coordinateSum;

	char symbolInput;
	int characterPostion = 0;
	int globalCharacterPosition = 0;
	int coordinateGlobalSum = 0;

	while (inputFile.get(symbolInput))
	{
			
			if (characterPostion <= 4)
			{
				leftList.push_back(symbolInput);
			}
			else if (characterPostion >= 8 && characterPostion < 13)
			{
				rightList.push_back(symbolInput);
			}
			else if (characterPostion >= 13)
			{
				characterPostion = -1;

				sort (leftList.begin() + leftList.size() - 5, leftList.end());
				sort (rightList.begin() + rightList.size() - 5, rightList.end());
			}
			else {}
			characterPostion++;
			globalCharacterPosition++;  //mainly a debug variable can probably be ommited 
	}
	
	// This last sort function outside of the loop is because the last 5 numbers weren't being caught by the logic. (I haven't got a clue why) - FIXED
	// Because I left a space off the end string in line 1000 of the inputfile.txt the while loop wasn't reaching 13 for the final iteration of the loop.
	// Causing the logic to fail.

		//sort(leftList.begin() + leftList.size() - 5, leftList.end());
		//sort(rightList.begin() + rightList.size() - 5, rightList.end());

	inputFile.close();

	for (int i = 0; i < leftList.size(); i++)
	{
		int leftValue = leftList[i];
		int rightValue = rightList[i];
		int difference = abs(leftValue - rightValue);
		coordinateSum.push_back(difference);
	}

	// Below is the original way that I coded the "if left is lower than right value/vice versa" issue.  This was before I knew about abs being a THING?!	
	
		//for (int itr = 0; itr != rightList.size(); itr++)
		//{
		//	if (leftList.at(itr) < rightList.at(itr))
		//	{
		//		coordinateSum.push_back (rightList.at(itr) - leftList.at(itr));
		//	}
		//	else
		//	{
		//		coordinateSum.push_back(leftList.at(itr) - rightList.at(itr));
		//	}
		//	
		//}

	// Could the last 5 numbers not be getting added properly?

	cout << leftList.size() << endl;
	cout << rightList.size() << endl;

	coordinateGlobalSum = accumulate(coordinateSum.begin(), coordinateSum.end(), coordinateGlobalSum);
	
	


	cout << coordinateGlobalSum << endl;
}




int main()
{
	
	listStorage();
	
	return 0;
}