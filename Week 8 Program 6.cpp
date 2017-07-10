/********************************************************************
File Reverser

Write a program that opens a text file and reads its contents into a stack of characters. The
program should then pop the characters from the stack and save them in a second text file.
The order of the characters saved in the second file should be the reverse of their order in
the first file.
*********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;


int main()
{
	ofstream outputFile("originalText.txt");

	// creating the original text file here
	outputFile << "Over 100 years ago, a natural predator of humanity appeared: the Titans, giant humanoid but mindless monsters whose sole purpose of existence seemed to be to devour humans. There was an insurmountable gap in power between them and mankind, and as a result, humanity was rapidly exterminated to the brink of extinction. The survivors responded by constructing three concentric walls: Wall Maria, Wall Rose and Wall Sina, which graced them with a century of peace. However, one day a Colossal Titan far larger than any other seen before breached the outer wall, allowing the smaller Titans to invade the human territory and forcing the survivors to retreat to the inner walls. Eren Jaeger, a boy whose mother was eaten during the invasion, vowed to wipe every last Titan off the face of the Earth, and joined the military determined to exact his revenge." << endl;
	outputFile.close();


	// Opening the text file to retrieve its characters
	ifstream readFile("originalText.txt");

	// stack container to store the characters
	stack <char> list;

	char temp;

	// Section that will read the file and store the characters into a stack
	if (!readFile)
	{
		cout << "Error opening the file" << endl;

	}
	else
	{
		while (readFile.get(temp))
		{
			list.push(temp);
		}
	}
	readFile.close();


	// Section that will traverse the stack and output the characters back to the new file
	ofstream newOutput("reversedText.txt");
	list.pop(); // removing the newline at the end of the file
	while (!list.empty())
	{
		newOutput << list.top();
		cout << list.top();
		list.pop();
	}
	newOutput.close();
	cout << endl;

	return 0;
}