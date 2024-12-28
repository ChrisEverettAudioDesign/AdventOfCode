#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm> 


using namespace std;


void listStorage()
{
	ifstream inputFile("inputfile.txt");
	vector<char> leftList;
	vector<char> rightList;

	char symbolInput;
	int characterPostion = 0;
	int globalCharacterPosition = 0;




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
				sort (leftList.begin() + globalCharacterPosition, leftList.begin() + globalCharacterPosition + 5);
				sort (rightList.begin() + globalCharacterPosition, rightList.begin() + globalCharacterPosition + 5);
			}
			else {}
			characterPostion++;
			globalCharacterPosition++;
	}
	
	inputFile.close();

}




int main()
{
	
	listStorage();
	
	return 0;
}