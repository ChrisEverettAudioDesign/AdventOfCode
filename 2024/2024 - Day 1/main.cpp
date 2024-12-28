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
			else if (characterPostion == 13)
			{
				characterPostion = -1;
				sort (leftList.begin() + leftList.size() - 5, leftList.begin() + leftList.size());
				sort (rightList.begin() + rightList.size() - 5, rightList.begin() + rightList.size());
			}
			else {}
			characterPostion++;
			globalCharacterPosition++;  //mainly a debug variable can probably be ommited 
	}
	
	// This last sort function outside of the loop is because the last 5 numbers weren't being caught by the logic. (I haven't got a clue why)

	sort(leftList.begin() + leftList.size() - 5, leftList.begin() + leftList.size());
	sort(rightList.begin() + rightList.size() - 5, rightList.begin() + rightList.size());

	for (int itr = 0; itr != rightList.size(); itr++)
	{
		if (leftList.at(itr) < rightList.at(itr))
		{
			coordinateSum.push_back(rightList.at(itr) - leftList.at(itr));
		}
		else
		{
			coordinateSum.push_back(leftList.at(itr) - rightList.at(itr));
		}
		
	}

	// Could the last 5 numbers not be getting added properly?

	cout << leftList.size() << endl;
	cout << rightList.size() << endl;

	coordinateGlobalSum = accumulate(coordinateSum.begin(), coordinateSum.end(), coordinateGlobalSum);
	
	inputFile.close();


	cout << coordinateGlobalSum << endl;
}




int main()
{
	
	listStorage();
	
	return 0;
}