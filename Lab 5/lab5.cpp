#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

/*********************FileFilter Base Class********************************/
class FileFilter
{
	protected:
		ifstream inFile;
		ofstream outFile;

	public:
		FileFilter(string, string);
		~FileFilter();
		void doFilter(ifstream&, ofstream&);
		virtual char transform(char) = 0;
};

/*********************Encrypt Child Class********************************/
class Encrypt : public FileFilter
{
	private:
		int key;

	public:
		Encrypt(string, string, int);
		// We can also have a mutator for the key variable, but lets stick to the passing through constructor
		virtual char transform(char);
};

/*********************UpperCase Child Class********************************/
class UpperCase : public FileFilter
{
	public:
		UpperCase(string, string);
		virtual char transform(char);
};

/*********************Original Child Class********************************/
class Original : public FileFilter
{
	public:
		Original(string, string);
		virtual char transform(char);
};




// Constructors
FileFilter::FileFilter(string inName, string outName)
{
	inFile.open(inName);
	if (!inFile)
	{
		cout << "File could not be opened" << endl;
		exit(1);
	}
	outFile.open(outName);
	if (!outFile)
	{
		cout << "File could not be opened" << endl;
		exit(1);
	}
}
Encrypt::Encrypt(string inName, string outName, int encryptKey) : FileFilter(inName, outName)
{
	key = encryptKey;
}
UpperCase::UpperCase(string inName, string outName) : FileFilter(inName, outName){}
Original::Original(string inName, string outName) : FileFilter(inName, outName){}

// Destructor
FileFilter::~FileFilter()
{
	inFile.close();
	outFile.close();
}

// Filter function, responsible for altering the files
void FileFilter::doFilter(ifstream& inputFile, ofstream& outputFile)
{
	char ch, transCh;
	inputFile.get(ch);

	while (!inputFile.fail())
	{
		transCh = transform(ch);
		outputFile.put(transCh);
		inputFile.get(ch);
	}

	inputFile.close();
	outputFile.close();
}

// Encrypt Transform
char Encrypt::transform(char letter)
{
	return letter + key;
}

// UpperCase Transform
char UpperCase::transform(char letter)
{
	return toupper(letter);
}

// Original Transform
char Original::transform(char letter)
{
	return letter;
}


int main()
{
	string inFile, outFile;
	ifstream input;
	ofstream output;

	cout << "Enter the name of file to read: ";
	getline(cin, inFile);
	input.open(inFile);

	cout << "Enter the name of file to create an original copy: ";
	getline(cin, outFile);
	output.open(outFile);
	FileFilter* test = new Original(inFile, outFile);
	cout << "Here we are making a copy of the file" << endl;
	test->doFilter(input, output);


	cout << endl<< "Enter the name of file to create a copy with uppercase: ";
	getline(cin, outFile);
	input.open(inFile);
	output.open(outFile);
	test = new UpperCase(inFile, outFile);
	cout << "Here we are making the new file all uppercase" << endl;
	test->doFilter(input, output);


	cout << endl << "Enter the name of file to create with encryption: ";
	getline(cin, outFile);
	input.open(inFile);
	output.open(outFile);
	cout << "Enter a number to set encryption key: ";
	int num;
	cin >> num;
	test = new Encrypt(inFile, outFile, num);
	cout << "Here we are making the new file with encryption" << endl;
	test->doFilter(input, output);

	delete test;
	return 0;
}