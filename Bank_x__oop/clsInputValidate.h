#pragma once
#include <iostream>
#include <cmath>
#include "clsDate.h"
#include <string>
#include <fstream>
class clsInputValidate
{
public:
	static int fureadnumber(string text)
	{
		int number = 0;
		cout << text;
		cin >> number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "invalid number , enter a valid one : ";
			cin >> number;
		}


		return number;
	}

	static int fureadpositivenumber(string text)
	{
		int number = 0;
		do
		{
			cout << text;
			cin >> number;

			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "invalid number , enter a valid one : ";
				cin >> number;
			}


		} while (number <= 0);

		return number;
	}

	 static int fureadnegativenumber(string text)
	{
		int number = 0;
		do
		{
			cout << text;
			cin >> number;

			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "invalid number , enter a valid one : ";
				cin >> number;
			}


		} while (number >= 0);
		return number;

	}

	 static	int fureadlimitednumber(string text, int from, int to)
	{
		int number;
		do
		{
			cout << text;
			cin >> number;

			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "invalid number , enter a valid one : ";
				cin >> number;
			}


		} while (number < from || number > to);

		return number;
	}



	 static	short fureadshortnumber(string text)
	{
		short number = 0;
		cout << text;
		cin >> number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "invalid number , enter a valid one : ";
			cin >> number;
		}

		return number;
	}

	 static	short fureadshortpositivenumber(string text)
	{
		short number = 0;
		do
		{
			cout << text;
			cin >> number;

			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "invalid number , enter a valid one : ";
				cin >> number;
			}

		} while (number <= 0);

		return number;
	}

	 static	short fureadshortnegativenumber(string text)
	{
		short number = 0;
		do
		{
			cout << text;
			cin >> number;

			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "invalid number , enter a valid one : ";
				cin >> number;
			}

		} while (number >= 0);
		return number;

	}

	 static	short fureadshortlimitednumber(string text, int from, int to)
	{
		short number;
		do
		{
			cout << text;
			cin >> number;

			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "invalid number , enter a valid one : ";
				cin >> number;
			}


		} while (number < from || number > to);
		return number;
	}


	 static	float fureadfloatnumber(string text)
	{
		float number = 0;
		cout << text;
		cin >> number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "invalid number , enter a valid one : ";
			cin >> number;
		}

		return number;
	}

	 static	float fureadfloatpositivenumber(string text)
	{
		float number = 0;
		do
		{
			cout << text;
			cin >> number;

			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "invalid number , enter a valid one : ";
				cin >> number;
			}

		} while (number <= 0);

		return number;
	}

	 static float fureadfloatnegativenumber(string text)
	{
		float number = 0;
		do
		{
			cout << text;
			cin >> number;

			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "invalid number , enter a valid one : ";
				cin >> number;
			}

		} while (number >= 0);
		return number;

	}

	 static float fureadfloatlimitednumber(string text, int from, int to)
	{
		float number;
		do
		{
			cout << text;
			cin >> number;

		} while (number < from || number > to);
		return number;
	}


	 static	char fureadyesorno(string text)
	{
		char cheak = 'y';
		do
		{
			cout << text;
			cin >> cheak;



		} while (cheak != 'y' && cheak != 'n' && cheak != 'Y' && cheak != 'N');

		return cheak;
	}


	 static	void voprintfile(string filename)   //İæíÏ áØÈÇÚÉ ãÇÏÇÎá Çáãáİ Úáì ÇáÔÇÔÉ
	{

		fstream koko;

		koko.open(filename, ios::in);

		if (koko.is_open())
		{

			string line;

			while (getline(koko, line))
			{
				cout << line << endl;
			}
			koko.close();

		}

	}

	 static	int furandomnumber(int from, int to)
	{
		int random = rand() % (to - from + 1) + from;
		return random;
	}

	

	
	 static bool IsNumberBetween(int Number, int From, int To)
	 {
		 if (Number >= From && Number <= To)
			 return true;
		 else
			 return false;

	 }

	

	 static bool IsNumberBetween(double Number, double From, double To)
	 {
		 if (Number >= From && Number <= To)
			 return true;
		 else
			 return false;
	 }

	 static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	 {
		 //Date>=From && Date<=To
		 if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			 &&
			 (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			 )
		 {
			 return true;
		 }

		 //Date>=To && Date<=From
		 if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			 &&
			 (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			 )
		 {
			 return true;
		 }

		 return false;
	 }

	 static string readstring()
	 {
		 string  line;

		 getline(cin >> ws, line);
		 return line;
	 }

	 static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	 {
		 short Number;
		 while (!(cin >> Number)) {
			 cin.clear();
			 cin.ignore(numeric_limits<streamsize>::max(), '\n');
			 cout << ErrorMessage;
		 }
		 return Number;
	 }

	 static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	 {
		 int Number;
		 while (!(cin >> Number)) {
			 cin.clear();
			 cin.ignore(numeric_limits<streamsize>::max(), '\n');
			 cout << ErrorMessage;
		 }
		 return Number;
	 }

	 static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	 {
		 int Number = ReadShortNumber();

		 while (!IsNumberBetween(Number, From, To))
		 {
			 cout << ErrorMessage;
			 Number = ReadShortNumber();
		 }
		 return Number;
	 }

	 static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	 {
		 int Number = ReadIntNumber();

		 while (!IsNumberBetween(Number, From, To))
		 {
			 cout << ErrorMessage;
			 Number = ReadIntNumber();
		 }
		 return Number;
	 }

	 static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	 {
		 float Number;
		 while (!(cin >> Number)) {
			 cin.clear();
			 cin.ignore(numeric_limits<streamsize>::max(), '\n');
			 cout << ErrorMessage;
		 }
		 return Number;
	 }

	 static double ReadFloatNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	 {
		 float Number = ReadFloatNumber();

		 while (!IsNumberBetween(Number, From, To)) {
			 cout << ErrorMessage;
			 Number = ReadDblNumber();
		 }
		 return Number;
	 }

	 static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	 {
		 double Number;
		 while (!(cin >> Number)) {
			 cin.clear();
			 cin.ignore(numeric_limits<streamsize>::max(), '\n');
			 cout << ErrorMessage;
		 }
		 return Number;
	 }

	 static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	 {
		 double Number = ReadDblNumber();

		 while (!IsNumberBetween(Number, From, To)) {
			 cout << ErrorMessage;
			 Number = ReadDblNumber();
		 }
		 return Number;
	 }

	 static bool IsValideDate(clsDate Date)
	 {
		 return	clsDate::IsValidDate(Date);
	 }

	


};
	

