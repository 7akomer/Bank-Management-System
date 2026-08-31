#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen :protected clsScreen
{

private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

public:

    static void ShowFindCurrencyScreen()
    {

        _DrawScreenHeader("\t  Find Currency Screen");

        cout << "\n  [1] Code / [2] Country \n\n  Find By ?[1 or 2] :";
        short Answer = 1;

       Answer =  clsInputValidate::ReadIntNumberBetween(1, 2, "\n  Enter [1 or 2]:");
       

        if (Answer == 1)
        {
            string CurrencyCode;
            cout << "\nPlease Enter CurrencyCode: ";
            CurrencyCode = clsInputValidate::readstring();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
        }
        else
        {
            string Country;
            cout << "\nPlease Enter Country Name: ";
            Country = clsInputValidate::readstring();
            clsCurrency Currency = clsCurrency::FindByCountry(Country);
            _ShowResults(Currency);
        }






    }

};


