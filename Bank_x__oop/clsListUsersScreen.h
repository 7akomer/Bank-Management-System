#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankUser.h"
#include <iomanip>

class clsListUsersScreen : protected clsScreen
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


    static void _PrintUserRecordLine(clsBankUser User)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
        cout << "| " << setw(25) << left << User.fullname();
        cout << "| " << setw(12) << left << User.phone;
        cout << "| " << setw(20) << left << User.email;
        cout << "| " << setw(10) << left << _DecryptPassword(User.Password);
        cout << "| " << setw(12) << left << User.Permissions;

    }

public:


    static void ShowUsersList()
    {

      

        vector <clsBankUser> vUsers = clsBankUser::GetUsersList();

        string Title = "\t  User List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsBankUser User : vUsers)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }


};

