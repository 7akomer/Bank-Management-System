#pragma once


#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankUser.h"


    class clsLoginRegisterScreen :protected clsScreen
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

        static void _PrintLoginRegisterRecordLine(clsBankUser::stLoginRegisterRecord LoginRegisterRecord)
        {

            cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
            cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
            cout << "| " << setw(20) << left << _DecryptPassword(LoginRegisterRecord.Password);
            cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
        }

    public:

        static void ShowLoginRegisterScreen()
        {

            if (!CheckAccessRigths(clsBankUser::enPermissions::pLoginRegister))
            {
                return;
            }

            vector <clsBankUser::stLoginRegisterRecord> vLoginRegisterRecord = clsBankUser::GetLoginRegisterList();

            string Title = "\tLogin Register List Screen";
            string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

            _DrawScreenHeader(Title, SubTitle);

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
            cout << "| " << left << setw(20) << "UserName";
            cout << "| " << left << setw(20) << "Password";
            cout << "| " << left << setw(10) << "Permissions";
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            if (vLoginRegisterRecord.size() == 0)
                cout << "\t\t\t\tNo Logins Available In the System!";
            else

                for (clsBankUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
                {

                    _PrintLoginRegisterRecordLine(Record);
                    cout << endl;
                }

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

        }

    };




