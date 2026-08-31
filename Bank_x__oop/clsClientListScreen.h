#pragma once
#include <iostream>
#include "clsBankClient.h"
#include <iomanip>
#include "clsUtil.h"
#include "clsScreen.h"

using namespace std;

class clsClientListScreen : protected clsScreen
{
private:

	static void PrintClientRecordLine(clsBankClient Client)
	{


		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.getaccountnumber();
		cout << "| " << setw(20) << left << Client.fullname();
		cout << "| " << setw(12) << left << Client.phone;
		cout << "| " << setw(20) << left << Client.email;
		cout << "| " << setw(10) << left << Client.pincode;
		cout << "| " << setw(12) << left << Client.accountbalance;

	}

public:
	
    static	void showclientlist()
	{

		if (!CheckAccessRigths(clsBankUser::enPermissions::pListClients))
		{
			return;
		}


		vector <clsBankClient> vClients = clsBankClient::getclientlist();

		string Title = "\t  Client List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);



		
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (vClients.size() == 0)
		{
			cout << "\t\t\t\tNo Clients Available In the System!";
		}

		else
		{
			for (clsBankClient& print : vClients)
			{
				PrintClientRecordLine(print);
				cout << endl;
			}


			cout << setw(8) << left << "" << "\n\t_______________________________________________________";
			cout << "_________________________________________\n" << endl;


		}


	}
};

