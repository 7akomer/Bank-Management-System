#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUtil.h"

class clsTotalBalance :protected clsScreen
{

private:
	
	static void PrintClientRecordBalanceLine(clsBankClient Client)
	{

		cout << setw(25) << left << "" << "| " << setw(15) << left << Client.getaccountnumber();
		cout << "| " << setw(40) << left << Client.fullname();
		cout << "| " << setw(12) << left << Client.accountbalance;

	}

public:

	static void showtotalbalance()
	{
		vector <clsBankClient> vClients = clsBankClient::getclientlist();


		string Title = "\t  Balances List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		double totalbalance = clsBankClient::gettotalbalance();

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient Client : vClients)
			{
				PrintClientRecordBalanceLine(Client);
				cout << endl;
			}
		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;
		cout << "\t\t\t\t\t   Total Balances = " << totalbalance << endl;
		cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(totalbalance) << ")";

	}

};

