#pragma once
#include <iostream>
#include <string>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;
class clsAddNewClient :protected clsScreen
{
	static void _readclientinfo(clsBankClient& client)
	{
		cout << "enter firstname : ";
		client.firstname = clsInputValidate::readstring();

		cout << "\nenter lastname : ";
		client.lastname = clsInputValidate::readstring();

		cout << "\nenter email : ";
		client.email = clsInputValidate::readstring();

		cout << "\nenter phone number : ";
		client.phone = clsInputValidate::readstring();

		cout << "\nenter pincode : ";
		client.pincode = clsInputValidate::readstring();


		client.accountbalance = clsInputValidate::fureadfloatnumber("\nenter account balance : ");



	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.firstname;
		cout << "\nLastName    : " << Client.lastname;
		cout << "\nFull Name   : " << Client.fullname();
		cout << "\nEmail       : " << Client.email;
		cout << "\nPhone       : " << Client.phone;
		cout << "\nAcc. Number : " << Client.getaccountnumber();
		cout << "\nPassword    : " << Client.pincode;
		cout << "\nBalance     : " << Client.accountbalance;
		cout << "\n___________________\n";

	}


public:


	static void addnewclient()
	{

		if (!CheckAccessRigths(clsBankUser::enPermissions::pAddNewClient))
		{
			return;
		}

		_DrawScreenHeader("\t  Add New Client Screen");

		string accountnumber = "";

		cout << "\nplease enter account number : ";
		accountnumber = clsInputValidate::readstring();

		while (clsBankClient::isclientexist(accountnumber))
		{
			cout << "\naccount number is already used, choose another one : ";
			accountnumber = clsInputValidate::readstring();
		}

		clsBankClient BankClient = clsBankClient::getaddnewclientobject(accountnumber);
		_readclientinfo(BankClient);

		clsBankClient::enSaveresults saveresult;
		saveresult = BankClient.save();
		switch (saveresult)
		{
		case clsBankClient::enSaveresults::svSucceeded:
		{
			cout << "\naccount added seccessfully :-)\n";
			
			_PrintClient(BankClient);
			break;
		}

		case clsBankClient::enSaveresults::svFaildemptyobgect:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}

		case  clsBankClient::enSaveresults::svFildaccountnumberexists:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;
		}
		}

	}

};

