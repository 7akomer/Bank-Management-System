#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "CurrentUser.h"
#include "clsRegisterLogin.h"

class clsLoginScreen :protected clsScreen
{

private:

    static string _EncryptPassword(string text)
    {

        int i = 0, contor = 32;
        string num = "";

        while (i < text.length())

        {
            while (text[i] == char(contor))
            {
                num = num + char(contor + 2);
                i++;
                contor = 32;
            }
            contor++;

        }

        return num;
    }

    static  bool _Login()
    {
        bool LoginFaild = false;
        short counterlogin = 0;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                counterlogin++;
                if (counterlogin < 3)
                {
                    system("cls");
                    system("color 3");
                    _DrawScreenHeader("\t     Login Screen");

                    cout << "\n\t\t\t\t\tInvlaid Username/Password!\n";
                    cout << "\t\t\t\t\tYou Have " << 3 - counterlogin << " Trials To Login!\n\n";
                }
                if (counterlogin == 3)
                {
                    system("cls");
                    system("color 3");
                    _DrawScreenHeader("\t     Login Screen");

                    cout << "\n\t\t\t\tYou are Loced after 3 faild trails, Please Try again later!\n\n";
                    return false;
                }
            }

          

            cout << "\n\t\t\t\t\tEnter Username: ";
            cin >> Username;

            cout << "\n\t\t\t\t\tEnter Password: ";
            cin >> Password;

            Password = _EncryptPassword(Password);
            
            CurrentUser = clsBankUser::Find(Username,Password);

            LoginFaild = CurrentUser.IsEmpty();

           

        } while (LoginFaild);

        //clsRegisterLogin::SaveLoginToFile();
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
       
        return true;

    }

public:


    static bool ShowLoginScreen()
    {
       
        system("cls");
        system("color 3");
        _DrawScreenHeader("\t     Login Screen");

        return _Login();

    }

};


