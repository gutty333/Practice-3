/********************************************************************
	Flexible Encryption

	Write a modification of the encryption  program of Section 15.5 whose transform function uses an 
	integer  key to transform the character passed  to it. The function  transforms the character by 
	adding the key to it. The key should be represented as a member of the Encryption class, and the 
	class should  be modified  so that  it has a member  function  that sets the encryption  key. When 
	the program runs, the main function  should ask the user for the input file, the output file, and an 
	encryption  key.

	Show that with these modifications, the same program can be used for both encryption  and
	decryption.
*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Encryption
{
	protected:
		ifstream inFile;
		ofstream outFile;
		int key;


	public:
		Encryption(string, string);
		~Encryption();
		void encrypt();
		void setKey(int);
		virtual char transform(char) = 0;
};

// Constructor to open the files
Encryption::Encryption(string inputName, string outputName)
{
	inFile.open(inputName);
	outFile.open(outputName);

	if (!inFile)
	{
		cout << "File could not be open" << endl;
		exit(1);
	}

	if (!outFile)
	{
		cout << "File could not be open" << endl;
		exit(1);
	}
}

// Destructor
Encryption::~Encryption()
{
	inFile.close();
	outFile.close();
}

// Encrypt function, this will perform the operation of encrypting the file
void Encryption::encrypt()
{
	char ch, transCh;
	inFile.get(ch);

	while (!inFile.fail())
	{
		transCh = transform(ch);
		outFile.put(transCh);
		inFile.get(ch);
	}
}

// Mutator method
void Encryption::setKey(int x)
{
	key = x;
}

/*****************************************************************/
class SimpleEncryption : public Encryption
{
	public:
		SimpleEncryption(string, string);
		virtual char transform(char);
};

// Constructor, will pass arguments to parent class constructor
SimpleEncryption::SimpleEncryption(string inputName, string outputName) : Encryption(inputName, outputName)
{

}
// Transform based on the key
char SimpleEncryption::transform(char letter)
{
	return letter + key;
}

/*****************************************************************/
class SimpleDecryption : public Encryption
{
public:
	SimpleDecryption(string, string);
	virtual char transform(char);
};

// Constructor, will pass arguments to parent class constructor
SimpleDecryption::SimpleDecryption(string inputName, string outputName) : Encryption(inputName, outputName)
{

}
// Transform based on the key
char SimpleDecryption::transform(char letter)
{
	return letter - key;
}



int main()
{
	string inName, outName;

	cout << "Enter name of file to encrypt/decrypt: ";
	getline(cin, inName);

	cout << "Enter name of the new encrypted/decrypted file: ";
	getline(cin, outName);

	cout << "Enter a number that will represent the encrypt/decrypt key: ";
	int num;
	cin >> num;

	Encryption* testing = new SimpleEncryption(inName, outName);
	testing->setKey(num);
	cout << "Performing the encryption" << endl;
	testing->encrypt();
	testing = new SimpleDecryption(inName, outName);
	testing->setKey(num);
	cout << "Performing the decryption" << endl;
	testing->encrypt();

	return 0;
}
