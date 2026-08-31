#pragma once
#include <iostream>
#include <string>
using namespace std;
class clsPerson
{
private:

	string _firstname;
	string _lastname;
	string _email;
	string _phone;


public:

	clsPerson(string firstname, string lastname, string email, string phone)
	{
		_firstname = firstname;
		_lastname = lastname;
		_email = email;
		_phone = phone;
	}


	void setfirstname(string firstname)
	{
		_firstname = firstname;
	}
	string getfirstname()
	{
		return _firstname;

	}

	__declspec(property(get = getfirstname, put = setfirstname)) string firstname;

	void setlastname(string lastname)
	{
		_lastname = lastname;
	}
	string getlastname()
	{
		return _lastname;
	}

	__declspec(property(get = getlastname, put = setlastname)) string lastname;

	void setemail(string email)
	{
		_email = email;
	}
	string getemail()
	{
		return _email;
	}

	__declspec(property(get = getemail, put = setemail)) string email;

	void setphone(string phone)
	{
		_phone = phone;
	}
	string getphone()
	{
		return _phone;
	}

	__declspec(property(get = getphone, put = setphone)) string phone;

	string fullname()
	{
		return _firstname + " " + _lastname;
	}

	void print()
	{
		cout << "\nClient Card:";
		cout << "--------------------------------------\n\n";
		cout << "Firsname : " << _firstname << endl;
		cout << "Lastname : " << _lastname << endl;
		cout << "Fullname : " << fullname() << endl;
		cout << "Email    : " << _email << endl;
		cout << "Phone    : " << _phone << endl;
		cout << "\n--------------------------------------\n\n";

	}

};