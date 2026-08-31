#pragma once
#include <iostream>
#include <string>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsUpdatedClient : protected clsScreen
{

private:
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
	static void updateclient()
	{

		if (!CheckAccessRigths(clsBankUser::enPermissions::pUpdateClients))
		{
			return;
		}

		_DrawScreenHeader("\tUpdate Client Screen");

		string accountnumber = "";

		cout << " pleas enter your account number : ";
		accountnumber = clsInputValidate::readstring();

		while (!clsBankClient::isclientexist(accountnumber))
		{
			cout << "\n account number is not found, choose another one : ";
			accountnumber = clsInputValidate::readstring();
		}

		clsBankClient client = clsBankClient::Find(accountnumber);

		_PrintClient(client);

		cout << " \nupdate client info:";
		cout << " \n_________________________\n\n";

		_readclientinfo(client);

		clsBankClient::enSaveresults saveresults;

		saveresults = client.save();

		switch (saveresults)
		{
		case clsBankClient::enSaveresults::svSucceeded:
		{
			cout << "\n Account update successfully :-)";
			client.print();
			break;
		}

		case clsBankClient::enSaveresults::svFaildemptyobgect:
		{
			cout << "/n Error account was not saved because it's empty";
			break;
		}
		}




	}

};

