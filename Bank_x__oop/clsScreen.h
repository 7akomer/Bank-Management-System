#pragma once

#include <iostream>
#include "clsBankUser.h"
#include "CurrentUser.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title,string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

string username = "";
username = CurrentUser.UserName;

if (username != "")
        {
           
        clsDate date;
        cout << "\t\t\t\t\t";
        date.Print();

         cout << "\t\t  User: " << username << endl << endl;
        }
else
{
    clsDate date;
    cout << "\t\t\t\t\t";
    date.Print();
    cout << endl;

}
    }
    

    

    static bool CheckAccessRigths(clsBankUser::enPermissions permission)
    {
        if (!CurrentUser.CheckAccessPermission(permission))
        {
            system("color 4");
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }
        
    



};
