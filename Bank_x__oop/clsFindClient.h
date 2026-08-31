#pragma once
#include <iostream>
#include <string>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindClient : protected clsScreen
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

	static void FindClient()
	{

		if (!CheckAccessRigths(clsBankUser::enPermissions::pFindClient))
		{
			return;
		}

		_DrawScreenHeader("\tFind Client Screen");

		string accountnumber = "";

		cout << "\nPlease Enter Account Number: ";

		accountnumber = clsInputValidate::readstring();

		while (!clsBankClient::isclientexist(accountnumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			accountnumber = clsInputValidate::readstring();
		}

		clsBankClient Client1 = clsBankClient::Find(accountnumber);

		if (!Client1.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
		}
		else
		{
			cout << "\nClient Was not Found :-(\n";
		}

		_PrintClient(Client1);

	}

};

