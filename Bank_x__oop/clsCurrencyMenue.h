#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include <iomanip>
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"


class clsCurrencyMenue : protected clsScreen
{
private:

	enum _enMenueOption
	{
		eListCurrencies = 1,eFindCurrency = 2,eUpdateRate = 3,eCurrencyCalculator =4 , eMainMenue = 5
	};

	static short _ReadMenueOption()
	{

		 cout << setw(37) << left << "" << "Choose what do you you want to do? [1 to 5]:";
		short choose = clsInputValidate::ReadIntNumberBetween(1, 5, "\n\t\t\t\t     Enter Number between [1 to 5] : ");

		return choose;

	}

	static void _ShowListCurrenciesScreen()
	{
		//cout << "hello im list screen\n";
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "hello im Find Currency\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
	//	cout << "Hello im Update Rate\n";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculater()
	{
		//cout << "hello im Currency Calculater\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _GoBackToCurrencyMenue()
	{
	
	
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
	

		ShowCurrencyExchangeMenue();
	}

	static void _PerformCurrencyOption(_enMenueOption MenueOption)
	{
		switch (MenueOption)
		{
		case _enMenueOption::eListCurrencies:
		{
			system("cls");
			system("color 1");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyMenue();
			break;
		}

		case _enMenueOption::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyMenue();
			break;
		}
		case _enMenueOption::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyMenue();
			break;
		}

		case _enMenueOption::eCurrencyCalculator:
		{
			system("cls");
			system("color 6");
			_ShowCurrencyCalculater();
			_GoBackToCurrencyMenue();
			break;
		}

		case _enMenueOption::eMainMenue:
		{
			

			break;
		}
		}
	}


public:

	static void ShowCurrencyExchangeMenue()
	{
		system("cls");
		system("color 5");
		_DrawScreenHeader("   Currancy Exchange Main Screen");

		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "           Currncy Exchange Menue\n";
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currncies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerformCurrencyOption((_enMenueOption)_ReadMenueOption());





	}




};

