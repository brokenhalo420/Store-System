#include "User.h"
#include <iostream>
#include <cstring>
using namespace std;

User::User()
{
	this->firstName = " ";
	this->lastName = " ";
	this->email = " ";
	this->username = " ";
	this->password = " ";
	this->adminPermissions = false;
}

User::User(string firstName, string lastName, string email, string username, string password, bool adminPermissions)
{
	this->set(&this->firstName, firstName);
	this->set(&this->lastName, lastName);
	this->set(&this->email, email);
	this->set(&this->username, username);
	this->set(&this->password, password);
	this->adminPermissions = adminPermissions;
}


bool User::operator==(const User& other) const
{
	if (this == &other)
	{
		return true;
	}

	int equal = 6;
	if (this->firstName._Equal(other.firstName))
	{
		equal--;
	}

	if (this->lastName._Equal(other.lastName))
	{
		equal--;
	}

	if (this->email._Equal(other.email))
	{
		equal--;
	}

	if (this->username._Equal(other.username))
	{
		equal--;
	}

	if (this->password._Equal(other.password))
	{
		equal--;
	}

	if (this->adminPermissions == other.adminPermissions)
	{
		equal--;
	}

	if (equal ==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string User::getFirstName() const
{
	return this->firstName;
}

string User::getLastName() const
{
	return this->lastName;
}

string User::getEmail() const
{
	return this->email;
}

string User::getUsername() const
{
	return this->username;
}

string User::getPassword() const
{
	return this->password;
}

bool User::getAdminPermissions() const
{
	return this->adminPermissions;
}

void User::setFirstName(string firstName)
{
	this->set(&this->firstName, firstName);
}

void User::setLastName(string lastName)
{
	this->set(&this->lastName, lastName);
}

void User::setEmail(string email)
{
	this->set(&this->email, email);
}

void User::setUsername(string username)
{
	this->set(&this->username, username);
}

void User::setPassword(string newPassword, string oldPassword)
{
	if (this->password._Equal(oldPassword))
	{
		this->password = newPassword;
	}
	else
	{
		cout << "You got the wrong password buddy..." << endl;
		return;
	}
}

void User::setAdminPermissions(bool value)
{
	this->adminPermissions = value;
}

void User::set(string* field, string newValue)
{
	*field = newValue;
}

ostream& operator<<(ostream& cout, const User& other)
{
	if (other.firstName._Equal(" "))
	{
		cout << "Empty user";
		return cout;
	}
	string password_hidden;
	for (int i = 0; i < other.password.size(); i++)
	{
		password_hidden.append("*");
	}
	cout << "First Name: " << other.firstName << endl;
	cout << "Last Name: " << other.lastName << endl;
	cout << "Email: " << other.email << endl;
	cout << "Username: " << other.username << endl;
	cout << "Password: " << password_hidden << endl;
	return cout;
}