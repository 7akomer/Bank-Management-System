#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsClientListScreen.h"
#include "clsAddNewClient.h"
#include "clsDeletedClient.h"
#include "clsUpdatedClient.h"
#include "clsFindClient.h"
#include "clsTransactionsMenue.h"
#include "clsManageUsersMenue.h"
#include "CurrentUser.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyMenue.h"

using namespace std;

class clsMainScreen : protected clsScreen
{

private:

	enum _enMainMenueOptions
	{elistclient = 1 , eaddclient = 2 , edeletedclient = 3 , eupdateclient = 4 ,
		efindclient = 5, eshowtransactionmenue = 6 , emanageusers = 7,eLoginRegister = 8, eCurrencyMenue=9, eexit = 10 };

	static short _readmainmenuescreen()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10] :";

		short choose = clsInputValidate::ReadShortNumberBetween(1,10,"\n\t\t\t\t     Enter Number between [1 to 10] :  ");

		return choose;
	}

	static  void _gobacktomainmenue()
	{
		cout << setw(37) << left << "" << "\n\t\t\t\t   Press any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenue();
	}

    static void _ShowAllClientsScreen()
    {
      //  cout << "\nClient List Screen Will be here...\n";
        clsClientListScreen::showclientlist();

    }

    static void _ShowAddNewClientsScreen()
    {
       // cout << "\nAdd New Client Screen Will be here...\n";

        clsAddNewClient::addnewclient();
    }

    static void _ShowDeleteClientScreen()
    {
        //cout << "\nDelete Client Screen Will be here...\n";
        clsDeletedClient::deletedclient();
    }

    static void _ShowUpdateClientScreen()
    {
       // cout << "\nUpdate Client Screen Will be here...\n";
        clsUpdatedClient::updateclient();
    }

    static void _ShowFindClientScreen()
    {
       // cout << "\nFind Client Screen Will be here...\n";
        clsFindClient::FindClient();

    }

    static void _ShowTransactionsMenue()
    {
       // cout << "\nTransactions Menue Will be here...\n";

        clsTransactionsMenue::ShowTransactionsMenue();

    }

    static void _ShowManageUsersMenue()
    {
       // cout << "\nUsers Menue Will be here...\n";

        claManageUsersMenue::ShowManageUsersMenue();

    }

   
    static void _ShowLoginRegister()
    {
       // cout << "hello my name is login scteen ";
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
  
    }

    static void _ShowCurrancyExchangeMenue()
    {
       // cout << "hello im Currency Exchange Screen...\n";
        clsCurrencyMenue::ShowCurrencyExchangeMenue();
    }

    static void _Logout()
    {
        CurrentUser = clsBankUser::Find("", "");

    }


    static void _PerformMainMenueOption(_enMainMenueOptions mainmenueoption)
    {
        switch (mainmenueoption)
        {
        case _enMainMenueOptions::elistclient:
        {
            system("cls");
            system("color 1");
            _ShowAllClientsScreen();
            _gobacktomainmenue();

            break;

        }

        case _enMainMenueOptions::eaddclient:
        {
            system("cls");
            _ShowAddNewClientsScreen();
            _gobacktomainmenue();
            break;

        }


        case _enMainMenueOptions::edeletedclient:
        {
            system("cls");
            _ShowDeleteClientScreen();
            _gobacktomainmenue();
            break;
        }

        case _enMainMenueOptions::eupdateclient:
        {
            system("cls");
            _ShowUpdateClientScreen();
            _gobacktomainmenue();
            break;
        }

        case _enMainMenueOptions::efindclient:
        {
            system("cls");
            _ShowFindClientScreen();
            _gobacktomainmenue();
            break;
        }

        case _enMainMenueOptions::eshowtransactionmenue:
        {
            system("cls");
            _ShowTransactionsMenue();
            ShowMainMenue();
            break;
        }

        case _enMainMenueOptions::emanageusers:
        {
            system("cls");
           _ShowManageUsersMenue();
           ShowMainMenue();
            break;
        }

        case _enMainMenueOptions::eLoginRegister:
        {
            system("cls");
            system("color 1");
            _ShowLoginRegister();
            _gobacktomainmenue();
            break;
        }

        case _enMainMenueOptions::eCurrencyMenue:
        {
            system("cls");
            system("color 5");
            _ShowCurrancyExchangeMenue();
            ShowMainMenue();
            break;
        }

        case _enMainMenueOptions::eexit:
        {
            system("cls");
            _Logout();
       
            break;
        }

        }
}



public:
    static void ShowMainMenue()
    {

        system("cls");
        system("color 5");
        

        _DrawScreenHeader("\t      Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t     Main Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenueOption((_enMainMenueOptions)_readmainmenuescreen());
    }

};

