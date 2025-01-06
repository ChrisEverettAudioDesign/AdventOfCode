#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <string>


using namespace std;

void listStorage()
{
	// LEARNINGS = I HAD A FULL ON MAJOR CONFUSION - I was taking the example too literally - I was treating like numbers like individual numbers rather than the full 5 digit int.
	// Any code that I do needs to follow the theory of -  "it's important to write code that works for any dataset, not just the example one" - Gergs 6th Jan 2025.

	// char symbolInput; - since changing to an int vector there was no need for this.
	// int characterPostion = 0; - since changing to an int vector there was no need for this.

	ifstream inputFile("inputfile.txt");
	vector<int> leftList;
	vector<int> rightList;
	vector<int> coordinateSum;

	int coordinateGlobalSum = 0;
	const int lineCount = 1000;
	int symbolInputLeft = 0;
	int symbolInputRight = 0;
	int singularityScore = 0;
	
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

	inputFile.close();

	for (int leftIndex = 0; leftIndex < leftList.size(); leftIndex++)
	{
		int foundCount = 0;
		int leftSideCurrentNumber = leftList[leftIndex];
		

		for (int rightIndex = 0; rightIndex < rightList.size(); rightIndex++)
		{
			int rightSideCurrentNumber = rightList[rightIndex];

			if (leftSideCurrentNumber == rightSideCurrentNumber)
			{
				foundCount += 1;
			}	
		}
		
		singularityScore += leftSideCurrentNumber * foundCount;


		//singularityScore = count(rightList.begin(), rightList.end(), leftList.at(i));
	}


	for (int i = 0; i < lineCount; i++)
	{
		coordinateGlobalSum += abs(leftList[i] - rightList[i]);
	}

	cout << leftList.size() << endl;
	cout << rightList.size() << endl;

	cout << coordinateGlobalSum << endl;
	cout << singularityScore << endl;
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

	// The old way of sorting when the vector was a character - I missunderstood the problem.

	/*sort(leftList.begin() + leftList.size() - 5, leftList.end());
	sort(rightList.begin() + rightList.size() - 5, rightList.end());*/

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