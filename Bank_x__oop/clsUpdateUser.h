#pragma once
#include <iostream>
#include "clsBankUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsUpdateUser  : protected clsScreen
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

    static void _ReadUserInfo(clsBankUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.firstname = clsInputValidate::readstring();

        cout << "\nEnter LastName: ";
        User.lastname = clsInputValidate::readstring();

        cout << "\nEnter Email: ";
        User.email = clsInputValidate::readstring();

        cout << "\nEnter Phone: ";
        User.phone = clsInputValidate::readstring();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::readstring();
        User.Password = _EncryptPassword(User.Password);

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
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

    static int _ReadPermissionsToSet()
    {
        int Permissions = 0;
        char Answer = 'n';

        Answer = clsInputValidate::fureadyesorno("\nDo you want to give full access? [y/n] : ");

        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        Answer = clsInputValidate::fureadyesorno("\nShow Client List? [y/n] : ");

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pListClients;
        }

        Answer = clsInputValidate::fureadyesorno("\nAdd New Client? [y/n]: ");

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pAddNewClient;
        }

        Answer = clsInputValidate::fureadyesorno("\nDelete Client? [y/n]: ");

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pDeleteClient;
        }

        Answer = clsInputValidate::fureadyesorno("\nFind Client? [y/n]: ");

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pFindClient;
        }

        Answer = clsInputValidate::fureadyesorno("\nTransactions? [y/n]: ");

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pTranactions;
        }

        Answer = clsInputValidate::fureadyesorno("\nManage Users? [y/n]: ");

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pManageUsers;
        }


        Answer = clsInputValidate::fureadyesorno("\nLogin Register? [y/n] : ");

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pLoginRegister;
        }

        return Permissions;


        return Permissions;


    }

    public:


        static void ShowUpdateUserScreen()
        {

            _DrawScreenHeader("\tUpdate User Screen");

            string UserName = "";

            cout << "\nPlease Enter User UserName: ";
            UserName = clsInputValidate::readstring();

            while (!clsBankUser::IsUserExist(UserName))
            {
                cout << "\nAccount number is not found, choose another one: ";
                UserName = clsInputValidate::readstring();
            }

            clsBankUser User1 = clsBankUser::Find(UserName);

            _PrintUser(User1);

       

            char Answer = clsInputValidate::fureadyesorno("\nAre you sure you want to update this User [y/n]: ");
          

            if (Answer == 'y' || Answer == 'Y')
            {

                cout << "\n\nUpdate User Info:";
                cout << "\n____________________\n";


                _ReadUserInfo(User1);

                clsBankUser::enSaveResults SaveResult;

                SaveResult = User1.Save();

                switch (SaveResult)
                {
                case  clsBankUser::enSaveResults::svSucceeded:
                {
                    cout << "\nUser Updated Successfully :-)\n";

                    _PrintUser(User1);
                    break;
                }
                case clsBankUser::enSaveResults::svFaildEmptyObject:
                {
                    cout << "\nError User was not saved because it's Empty";
                    break;

                }

                }

            }

        }
};

