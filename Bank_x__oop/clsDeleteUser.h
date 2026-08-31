#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankUser.h"
#include "clsInputValidate.h"

class clsDeleteUser :protected clsScreen
{

private:

    static string _DecryptPassword(string text)
    {

        int i = 0, contor = 32;
        string num = "";

        while (i < text.length())

        {
            while (text[i] == char(contor))
            {
                num = num + char(contor - 2);
                i++;
                contor = 32;
            }
            contor++;

        }

        return num;
    }
    static void _PrintUser(clsBankUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.firstname;
        cout << "\nLastName    : " << User.lastname;
        cout << "\nFull Name   : " << User.fullname();
        cout << "\nEmail       : " << User.email;
        cout << "\nPhone       : " << User.phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << _DecryptPassword(User.Password);
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:
    static void ShowDeleteUserScreen()
    {

        _DrawScreenHeader("\tDelete User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::readstring();
        while (!clsBankUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::readstring();
        }

        clsBankUser User1 = clsBankUser::Find(UserName);
        _PrintUser(User1);


        char Answer = clsInputValidate::fureadyesorno("\nAre you sure you want to delete this User [y/n]: ");
      

        if (Answer == 'y' || Answer == 'Y')
        {

            if (User1.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User1);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }
    }

};


