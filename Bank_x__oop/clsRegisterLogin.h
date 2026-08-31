#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include "fstream"
#include "ctime"
#include "CurrentUser.h"
#include "clsBankUser.h"
using namespace std;

class clsRegisterLogin
{

private:

	static string _ConvertObjectToRecord()
	{
		string lines = "";
		string mark = "#//#";

		lines += CurrentUser.UserName + mark;
		lines += CurrentUser.Password + mark;
		lines += to_string( CurrentUser.Permissions);

		return lines;
	}

	static void _Savelogintofile()
	{
		fstream Register;
		Register.open("Register_Login.txt", ios::out | ios::app);

		if (Register.is_open())
		{
			Register <<_DatePrint() << _ConvertObjectToRecord() <<endl;

			Register.close();
		}

	}

	static string _DatePrint()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		string datatime = "";
		datatime += to_string(now->tm_wday) + "-";
		datatime += to_string(now->tm_mon + 1) + "-";
		datatime += to_string(now->tm_year + 1900) + "   ";
		datatime += to_string(now->tm_hour) + " : ";
		datatime += to_string(now->tm_min) + " : ";
		datatime +=to_string(now->tm_sec)+" -  ";

		return datatime;

	}

public:

	static void SaveLoginToFile()
	{
		_Savelogintofile();
	}



};

