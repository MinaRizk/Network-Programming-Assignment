#include<iostream>
#include<string.h>
#include<string>

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
	system("pause");


	/***********
	*******end of testing******
	****************/

}