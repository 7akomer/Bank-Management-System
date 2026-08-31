#pragma once

#include <iostream>
#include <string>
#include "clsPerson.h"
#include <vector>
#include "clsString.h"
#include <fstream>
#include "CurrentUser.h"
using namespace std;

class clsBankClient : public clsPerson
{
private:

	enum enMode { Emptymode = 0, Updatemode = 1,addnewmode = 2 };
	enMode _Mode;

	string _accountnumber;
	double _accountbalance;
	string _pincode;
	bool _markedfordeleted = false;
	

	static clsBankClient _convertlinetoclientobject(string line, string seperater = "#//#")
	{
		vector <string> vclientdata;

		vclientdata = clsString::Split(line, seperater);

		return clsBankClient(enMode::Updatemode, 
			vclientdata[0], vclientdata[1], vclientdata[2], vclientdata[3], vclientdata[4], vclientdata[5], stod(vclientdata[6]));
	}

	static string _convertclientobjecttoline(clsBankClient client, string seperater = "#//#")
	{
		string record = "";

		record += client.firstname + seperater;
		record += client.lastname + seperater;
		
		record += client.email + seperater;
		record += client.phone + seperater;
		record += client.getaccountnumber() + seperater;
		record += client.pincode + seperater;
		record += to_string(client.accountbalance);

		return record;

	}

	struct stTrnsferLogRecord;

	static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTrnsferLogRecord TrnsferLogRecord;

		vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
		TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
		TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
		TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
		TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
		TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
		TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
		TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

		return TrnsferLogRecord;

	}

	 static string _PrepareTransferRecord(clsBankClient Client1,clsBankClient Client2,double amount)
	{
		string Seperator = "#//#";
		string TransferRecord = "";
		TransferRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferRecord += Client1.getaccountnumber() + Seperator;
		TransferRecord += Client2.getaccountnumber() + Seperator;
		TransferRecord += to_string(amount) + Seperator;
		TransferRecord +=  to_string(Client1.accountbalance) + Seperator;
		TransferRecord += to_string(Client2.accountbalance) + Seperator;
		TransferRecord += CurrentUser.UserName;

		return TransferRecord;
	}

	static clsBankClient _getemptyclientobject()
	{
		return clsBankClient(enMode::Emptymode, "", "", "", "", "", "", 0);
	}

	static void _saveclientdatatofile(vector <clsBankClient> vclient)
	{
		fstream myfile;
		string line;
		myfile.open("myfile.txt", ios::out);

		if (myfile.is_open())
		{
			for (clsBankClient& c : vclient)
			{
				if (c.getmarkedfordeleted() == false)
				{
					line = _convertclientobjecttoline(c);
					myfile << line << endl;
				}
			}
		}
		
	}

	void _update()
	{
		vector<clsBankClient> _vclient;
		_vclient = _lodclientdatafromfile();

		for (clsBankClient& _c : _vclient)
		{
			if (_c.getaccountnumber() == getaccountnumber())
			{
				_c = *this;
				break;
			}
		}

		_saveclientdatatofile(_vclient);


	}

	static vector <clsBankClient>  _lodclientdatafromfile()
	{
		fstream myfile;
		vector <clsBankClient> vclient;

		myfile.open("myfile.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsBankClient clients =  clsBankClient::_convertlinetoclientobject(line);

				vclient.push_back(clients);
			}
			myfile.close();
		}
		return vclient;
	}

	void _addnew()
	{
		_adddatalinetofile(_convertclientobjecttoline(*this));
	}

	void _adddatalinetofile(string stdataline)
	{
		fstream myfile;
		myfile.open("myfile.txt", ios::out | ios::app);
		
		if (myfile.is_open())
		{
			myfile << stdataline << endl;
			myfile.close();
			}
	}

public:

	clsBankClient(enMode Mode, string firstname, string lastname, string email, string phone, string accountnumber, string pincode, float accountbalance) :
		clsPerson(firstname, lastname, email, phone)
	{
		_Mode = Mode;
		_accountnumber = accountnumber;
		_accountbalance = accountbalance;
		_pincode = pincode;
	}

	struct stTrnsferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float Amount;
		float srcBalanceAfter;
		float destBalanceAfter;
		string UserName;

	};


	string getaccountnumber()
	{
		return _accountnumber;
	}

	void setaccountbalance(float accountbalance)
	{
		_accountbalance = accountbalance;
	}
	float getaccountbalance()
	{
		return _accountbalance;
	}

	__declspec(property(get = getaccountbalance, put = setaccountbalance)) float accountbalance;

	void setpincode(string pincode)
	{
		_pincode = pincode;
	}
	string getpincode()
	{
		return _pincode;
	}

	__declspec(property(get = getpincode, put = setpincode)) string pincode;

	bool getmarkedfordeleted()
	{
		return _markedfordeleted;
	}


	bool IsEmpty()
	{
		return (_Mode ==enMode::Emptymode);
	}


/*      
      //  áÇ áÃæÇãÑ ÇáØÈÇÚÉ Ýí ÇáÈÇßÃäÏ
	void print()
	{

		cout << "\nClient Card:\n";
		cout << "--------------------------------------\n\n";
		cout << "Firsname      : " << firstname << endl;
		cout << "Lastname      : " << lastname << endl;
		cout << "Fullname      : " << fullname() << endl;
		cout << "Email         : " << email << endl;
		cout << "Phone         : " << phone << endl;
		cout << "AccountNumber : " << _accountnumber<<endl;
		cout << "Password      : " << _pincode<<endl;
		cout << "Balance       : " << _accountbalance<<endl;
		cout << "\n--------------------------------------\n\n";


	}*/

	static clsBankClient Find(string accountnumber)
	{
		fstream myfile;

		myfile.open("myfile.txt", ios::in);

		if (myfile.is_open())
		{
			string line;

			while (getline(myfile, line))
			{
				clsBankClient client = _convertlinetoclientobject(line);
				if (client.getaccountnumber() == accountnumber)
				{
					myfile.close();
					return client;
				}
			}
			myfile.close();

		}

		return _getemptyclientobject();
	}

	static  clsBankClient Find(string accountnumber, string pincode)
	{
		fstream myfile;

		myfile.open("myfile.txt", ios::in);

		if (myfile.is_open())
		{
			string line;

			while (getline(myfile, line))
			{
				clsBankClient client = _convertlinetoclientobject(line);
				if (client.getaccountnumber() == accountnumber && client.pincode == pincode)
				{
					myfile.close();
					return client;
				}
			}
			myfile.close();

		}
		return _getemptyclientobject();
	}

	static bool isclientexist(string accountnumber)
	{
		clsBankClient client = clsBankClient::Find(accountnumber);

		return (!client.IsEmpty());
	}

	enum enSaveresults{svFaildemptyobgect = 0 , svSucceeded = 1,svFildaccountnumberexists};

	enSaveresults save()
	{

		switch (_Mode)
		{
		case enMode::Emptymode:
		{
			return enSaveresults::svFaildemptyobgect;
		}

		case enMode::Updatemode:
		{
			_update();

			return enSaveresults::svSucceeded;
		}

		case enMode::addnewmode:
		{

			_addnew();
			_Mode = enMode::addnewmode;
			return enSaveresults::svSucceeded;
		}
		}

		
	}

	static clsBankClient getaddnewclientobject(string accountnumber)
	{
		return clsBankClient(enMode::addnewmode, "", "", "", "", accountnumber, "", 0);
	}

	bool deleted()
	{
		vector <clsBankClient> _vclient;

		_vclient = _lodclientdatafromfile();

		for (clsBankClient& c : _vclient)
		{
			if (c.getaccountnumber() == _accountnumber)
			{
				c._markedfordeleted = true;
				break;
			}
		}
		_saveclientdatatofile(_vclient);

		*this = _getemptyclientobject();

		return true;
	 }

	static vector <clsBankClient> getclientlist()
	{
		return _lodclientdatafromfile();
	}

	static double gettotalbalance()
	{
		vector <clsBankClient> client = clsBankClient::_lodclientdatafromfile();
		double sumofbalance = 0;
		for (clsBankClient& sum : client)
		{
			sumofbalance += sum.accountbalance;
		}

		return sumofbalance;
	}

	void Deposit(double amount)
	{
		_accountbalance += amount;
		save();
	}

	bool Withdraw(double amount)
	{
		if (amount > _accountbalance)
		{
			return false;
		}
		else
		{
			_accountbalance -= amount;
			save();
			return true;
		}
	}

	bool Transferfrom(double amount)
	{
		if (this->accountbalance < amount)
		{
			return false;
		}
		else
		{
			this->accountbalance -= amount;
			save();
			return true;
		}
	}

	bool Transferto(double amount)
	{
		this->accountbalance += amount;
		save();
		return true;
	}

	static void RegisterTransfer(clsBankClient Client1,clsBankClient Client2,double amount)
	{

		string stDataLine = _PrepareTransferRecord(Client1,Client2,amount);

		fstream MyFile;
		MyFile.open("TransferRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	static  vector <stTrnsferLogRecord> GetTransfersLogList()
	{
		vector <stTrnsferLogRecord> vTransferLogRecord;

		fstream MyFile;
		MyFile.open("TransferRegister.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			stTrnsferLogRecord TransferRecord;

			while (getline(MyFile, Line))
			{

				TransferRecord = _ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferRecord);

			}

			MyFile.close();

		}

		return vTransferLogRecord;

	}


};

