#pragma once
#include <iostream>
using namespace std;

class User
{
protected:
	string firstName;
	string lastName;
	string email;
	string username;
	string password;
	bool adminPermissions;
	void set(string* field, string newValue);
public:
	User();
	User(string firstName, string lastName, string email, string username, string password, bool adminPermissions);
	bool operator==(const User& other) const;
	string getFirstName() const;
	string getLastName() const;
	string getEmail() const;
	string getUsername() const;
	string getPassword() const;
	bool getAdminPermissions() const;
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setUsername(string username);
	void setPassword(string newPassword, string oldPassword);
	void setAdminPermissions(bool value);
	friend ostream& operator<<(ostream& cout, const User& other);

};