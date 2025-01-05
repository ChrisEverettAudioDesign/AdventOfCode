#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <string>


using namespace std;

void listStorage()
{
	ifstream inputFile("inputfile.txt");
	vector<int> leftList;
	vector<int> rightList;
	vector<int> coordinateSum;


	// char symbolInput; - since changing to an int vector there was no need for this.
	// int characterPostion = 0; - since changing to an int vector there was no need for this.

	int coordinateGlobalSum = 0;
	const int lineCount = 1000;
	int symbolInputLeft;
	int symbolInputRight;
	
	// changing the while loop to a for loop and adding the line count int gave the correct answer.

	for(int i = 0; i < lineCount; i++)
	{
		inputFile >> symbolInputLeft;
		inputFile >> symbolInputRight;

		leftList.push_back(symbolInputLeft);
		rightList.push_back(symbolInputRight);

	}
	
	sort(leftList.begin(), leftList.end());
	sort(rightList.begin(), rightList.end());

	// The old way of sorting when the vector was a character - I missunderstood the problem.  But im still not sure at why the above sort worked.

	/*sort(leftList.begin() + leftList.size() - 5, leftList.end());
	sort(rightList.begin() + rightList.size() - 5, rightList.end());*/
	

	inputFile.close();

	for (int i = 0; i < lineCount; i++)
	{
		coordinateGlobalSum += abs(leftList[i] - rightList[i]);
	}

	cout << leftList.size() << endl;
	cout << rightList.size() << endl;

	cout << coordinateGlobalSum << endl;
}




int main()
{
	
	listStorage();
	
	return 0;
}



//  Old way of getting information from the file.

	/*while (inputFile.get(symbolInput))
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
				sort(leftList.begin() + leftList.size() - 5, leftList.end());
				sort(rightList.begin() + rightList.size() - 5, rightList.end());

			}
			else {}
			characterPostion++;

	}*/

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