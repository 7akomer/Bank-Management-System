#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"



class clsTransfer : protected clsScreen
{



    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.fullname();
        cout << "\nAcc. Number : " << Client.getaccountnumber();
        cout << "\nBalance     : " << Client.accountbalance;
        cout << "\n___________________\n";

    }
    static string _ReadAccountNumber(string text)
    {
        string AccountNumber = "";
        cout << text ;
        cin >> AccountNumber;
        return AccountNumber;
    }

public:


    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t   Transfer Screen");

        string AccountNumber1 = _ReadAccountNumber("\nPlease enter AccountNumber you will send from: ");


        while (!clsBankClient::isclientexist(AccountNumber1))
        {
            cout << "\nClient with [" << AccountNumber1 << "] does not exist.\n";
            AccountNumber1 = _ReadAccountNumber("\nPlease enter AccountNumber you will send from: ");
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber1);
        _PrintClient(Client1);


        string AccountNumber2 = _ReadAccountNumber("\nPlease enter AccountNumber you will send to: ");

        while (!clsBankClient::isclientexist(AccountNumber2))
        {
            cout << "\nClient with [" << AccountNumber2 << "] does not exist.\n";
            AccountNumber2 = _ReadAccountNumber("\nPlease enter AccountNumber you will send to: ");
        }

        clsBankClient Client2 = clsBankClient::Find(AccountNumber2);
        _PrintClient(Client2);


        double Amount = 0;
        cout << "\nPlease enter Transfer amount: ";
        Amount = clsInputValidate::ReadDblNumber();


        char Answer = clsInputValidate::fureadyesorno("\nAre you sure you want to perform this Transfer? [y/n]: ");


        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client1.Transferfrom(Amount))
            {
               
               
             
                if (Client2.Transferto(Amount))
                {
                    clsBankClient::RegisterTransfer(Client1, Client2, Amount);
                    cout << "\nAmount Transfer Successfully.\n";
                    _PrintClient(Client1);
                    _PrintClient(Client2);
                }

            }
            else
            {
                cout << "\nCannot Transfer, Insuffecient Balance!\n";
                cout << "\nAmout to Transfer is: " << Amount;
                cout << "\Sender Balance : " << Client1.accountbalance;

            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }

};

