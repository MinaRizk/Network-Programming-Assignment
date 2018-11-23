#include<iostream>
#include<string.h>
#include<string>
#include<fstream>

using namespace std;

string divisor(string Message, string Genrator)
{
	int MS = Message.length();
	int GS = Genrator.length();
	//Division
	for (int i = 0, k = 0; i < MS - GS + 1; i++)
		if (Message[i] == '1')
		{
			k = i;
			for (int j = 0; j < GS; k++, j++)
				//Message[k] = Message[k] ^ Genrator[j];
				if ((Message[k] == '1' && Genrator[j] == '1') || (Message[k] == '0' && Genrator[j] == '0'))
					Message[k] = '0';
				else
					Message[k] = '1';
		}
	// returning the remindar
	string s = "";
	for (int i = MS - GS + 1; i < MS; i++)
		s += Message[i];
	//cout << endl << s << endl;
	return s;
}
string generator(string msg, string generator)
{
	//get generator bits number
	int generatorBits = generator.length();
	//make a copy to the message to add zeros to it
	string msgCopy = msg;
	//adding zeros to the message copy equal to the generator lenght-1
	for (int i = 0; i < generator.length() - 1; i++)
	{
		msgCopy += "0";
	}
	//get the remainder
	string remainder = divisor(msgCopy, generator);
	//adding the remainder to the message
	msg += remainder;
	return msg;
}
bool Verifier(string  Message, string Genrator)
{
	string remainder = "";
	remainder = divisor(Message, Genrator);
	for (int i = 0; i<remainder.length(); i++)
		//cout << Message[i];
		if (remainder[i] != '0')
			return false;
	return true;
}
string Crc(string Message, string Genrator) { string s; return s; }
string Alter(string Message) { string s; return s; }
string CheckInputErrors(string InputLine) { string s; return s; }
void alter(string& message, unsigned int bitNo)
{
	if (message[bitNo - 1] == '0')
		message[bitNo - 1] = '1';
	else
		message[bitNo - 1] = '0';
}

void main(void)
{

	/***
	***input is taken here and is checked for error
	and a dynamic allocation happens to call function verifier
	******/


	//
	//

	/****
	***then function is called and output is outputed********
	******************/

	//
	//



	/*******
	******this coming part is just for testing*******
	**************/

	string message, Generator;
	bool isCorrect;
	ifstream file("crc.txt");
	if (file.is_open())
	{
		file >> message;
		file >> Generator;
		string genOutput = generator(message, Generator);
		cout << "Transmitted message is " + genOutput << endl;
		cout << "Input is " + message << endl;
		cout << "Do you want to alter the message?(y/n)" << endl;
		string choice;
	alter:
		cin >> choice;
		if (choice == "y"||choice=="Y")
		{
			loop:
			cout << "Enter the number of bit to alter:" << endl;
			unsigned int bitNo;
			try
			{
				cin >> bitNo;
			}
			catch(string e)
			{
				cout << "Enter a valid number" << endl;
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				goto loop;
			}
			if (bitNo > 0 && bitNo <= genOutput.length())
			{
				alter(genOutput, bitNo);
				isCorrect = Verifier(genOutput, Generator);
			}
			else
			{
				cout << "The bit number is invalid" << endl;
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				goto loop;
			}
		}
		else if (choice == "n" || choice == "N")
		{
			isCorrect = Verifier(genOutput, Generator);
		}
		else
		{
			cout << "Enter a (y/n):" << endl;
			goto alter;
		}
		cout << "Received message is " + genOutput << endl;
		if (isCorrect == true)
			cout << "Message is received correctly" << endl;
		else
			cout << "Message is received with errors" << endl;
	}
	else
	{
		cout << "error in opening file" << endl;
	}
	file.close();
	/*
	while (1)
	{
		//Get message
		
		cout << "\n Enter message : ";
		cin >> message;

		//Get Generator
		cout << "\n Enter Generator : ";
		cin >> Generator;

		//call generator
		cout << endl << generator(message, Generator);
		//call function
		cout << endl << Verifier(message, Generator) << endl;
		//	getch();
	}
	*/
	system("pause");


	/***********
	*******end of testing******
	****************/

}