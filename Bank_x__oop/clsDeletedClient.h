#pragma once
#include <iostream>
#include <string>
#include "clsBankClient.h"
#include "clsScreen.h";
#include "clsInputValidate.h"
using namespace std;

class clsDeletedClient : protected clsScreen
{

private:

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

	static void deletedclient()
	{

		if (!CheckAccessRigths(clsBankUser::enPermissions::pDeleteClient))
		{
			return;
		}

		_DrawScreenHeader("\tDelete Client Screen");

		string accountnumber = "";

		cout << "\nplease enter account number : ";
		accountnumber = clsInputValidate::readstring();

		while (!clsBankClient::isclientexist(accountnumber))
		{
			cout << "\n account number is not found, choose another one : ";
			accountnumber = clsInputValidate::readstring();
		}

		clsBankClient client = clsBankClient::Find(accountnumber);
		client.print();


		char answer = 'n';
		answer = clsInputValidate::fureadyesorno("are you sure you want to deleted this client[y / n] : ");

		if (answer == 'y' || answer == 'Y')
		{
			if (client.deleted())
			{
				cout << "\nClient Deleted Successfully :-)\n";
				_PrintClient(client);


			}

			else
			{
				cout << "\nError Client Was not Deleted\n";
			}
		}

	}
};

