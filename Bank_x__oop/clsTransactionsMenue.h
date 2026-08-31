#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsDeposit.h"
#include "clsWithdraw.h"
#include "clsTotalBalance.h"
#include "clsTransfer.h"
#include "clsTransferLogScreen.h"

class clsTransactionsMenue : protected clsScreen
{

private:

	enum _enTransactionsMenueOptions
	{ _edeposit = 1 , _ewithdraw = 2 , _etotalbalance = 3 , _etransfer = 4, _eTransferLog = 5,_emainmenue = 6};

	static short _readtransactionmenueoption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6] :";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "\n\t\t\t\t     Enter Number between [1 to 6] : ");
		return Choice;

	}

    static void _ShowDepositScreen()
    {
       // cout << "\n Deposit Screen will be here.\n";

        clsDeposit::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
      //  cout << "\n Withdraw Screen will be here.\n";

        clsWithdraw::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
      //  cout << "\n Balances Screen will be here.\n";

        clsTotalBalance::showtotalbalance();
    }

    static void _ShowTransferScreen()
    {
       // cout << "Transfer will be here\n";
        clsTransfer::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
       // cout << "Transfer Log will Be Here";
        clsTransferLogScreen::ShowTransferLogScreen();
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionsMenue();

    }


    static void _PerformTransactionsMenueOption(_enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case _enTransactionsMenueOptions::_edeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case _enTransactionsMenueOptions::_ewithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case _enTransactionsMenueOptions::_etotalbalance:
        {
            system("cls");
            system("color 1");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case _enTransactionsMenueOptions::_etransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();

        }

        case _enTransactionsMenueOptions::_eTransferLog:
        {
            system("cls");
            system("color 1");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();

        }

        case _enTransactionsMenueOptions::_emainmenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }


    }


public:
    static void ShowTransactionsMenue()
    {


        system("cls");

        if (!CheckAccessRigths(clsBankUser::enPermissions::pTranactions))
        {
            return;
        }
        system("color 5");

        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((_enTransactionsMenueOptions)_readtransactionmenueoption());
    }

};

