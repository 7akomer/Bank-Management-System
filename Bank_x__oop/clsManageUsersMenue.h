#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include <iomanip>
#include "clsListUsersScreen.h"
#include "clsAddNewUser.h"
#include "clsDeleteUser.h"
#include "clsUpdateUser.h"
#include "clsFindUser.h"

class claManageUsersMenue : protected clsScreen

{

private:
	enum _enManageUsersOptions
	{eListUsers = 1 , eAddNewUser = 2 , eDeletedUser = 3
	,eUpdatedUser = 4 , eFindUser = 5 , eMainMenue = 6};

	static short _ReadUserMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6] : ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "\n\t\t\t\t     Enter Number between 1 to 6 : ");
		return Choice;
	}

    static void _GoBackToManageUsersMenue()
    {
        cout << "\n\n\t\t\tPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowManageUsersMenue();
    }

    static void _ShowListUsersScreen()
    {
       // cout << "\nList Users Screen Will Be Here.\n";
        clsListUsersScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
       // cout << "\nAdd New User Screen Will Be Here.\n";
        clsAddNewUser::ShowAddNewUserScreen();
    }

    static void _ShowDeleteUserScreen()
    {
        //cout << "\nDelete User Screen Will Be Here.\n";
        clsDeleteUser::ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        //cout << "\nUpdate User Screen Will Be Here.\n";

        clsUpdateUser::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        //cout << "\nFind User Screen Will Be Here.\n";
        clsFindUser::ShowFindUserScreen();
    }


    static void _PerformManageUsersMenueOption(_enManageUsersOptions ManageUsersOption)
    {

        switch (ManageUsersOption)
        {
        case _enManageUsersOptions::eListUsers:
        {
            system("cls");
            system("color 1");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case _enManageUsersOptions::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case _enManageUsersOptions::eDeletedUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case _enManageUsersOptions::eUpdatedUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case _enManageUsersOptions::eFindUser:
        {
            system("cls");

            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case _enManageUsersOptions::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }

public:

    static void ShowManageUsersMenue()
    {
        system("cls");

        if (!CheckAccessRigths(clsBankUser::enPermissions::pManageUsers))
        {
            return;
        }
        system("color 5");

        _DrawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption((_enManageUsersOptions)_ReadUserMenueOption());
    }

};

