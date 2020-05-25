#include "AccountManager.h"
#include <cstring>
#include<iostream>
using namespace std;

AccountManager::AccountManager()
{
	this->allUsers = vector<Profile>();
}

AccountManager::AccountManager(const vector<Profile>& allUsers)
{
	this->allUsers = allUsers;
}


void AccountManager::addUser(const Profile& other)
{
	for (Profile it : this->allUsers)
	{
		if (it == other)
		{
			cout << "User already exists in this database" << endl;
			return;
		}
	}

	this->allUsers.push_back(other);
	cout << "Succesfully added a user..." << endl;
	return;
}

void AccountManager::removeUser(const Profile& other)
{
	for (vector<Profile>::iterator it = this->allUsers.begin(); it != this->allUsers.end(); it++)
	{
		if ((*it) == other)
		{
			cout << "User removed..." << endl;
			this->allUsers.erase(it);
			return;
		}
	}

	cout << "User not found..." << endl;
	return;
}

int AccountManager::getUserCount() const
{
	return this->allUsers.size();
}

const Profile AccountManager::getProfile(string username, string password) const
{
	for (Profile it : this->allUsers)
	{
		if (it.getUsername()._Equal(username) && it.getPassword()._Equal(password))
		{
			return it;
		}
	}

	cout << "No user with such username and password found..." << endl;
	return Profile();
}

const vector<Profile> AccountManager::getList() const
{
	return this->allUsers;
}

ostream& operator<<(ostream& cout, const AccountManager& other)
{
	if (other.allUsers.size() == 0)
	{
		cout << "No users in database" << endl;
		return cout;
	}

	for (Profile it : other.allUsers)
	{
		cout << "--------------------------------------------------" << endl;
		cout << "|      Names      |  Username  |      Email      |" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "|  " << it.getFirstName() << " " << it.getLastName() << "  |  " << it.getUsername() << "  |  " << it.getEmail() << "  |" << endl;
	}
	cout << "-------------------------------------------------- " << endl;
	return cout;
}

void AccountManager::update(const Profile& other)
{
	for (vector<Profile>::iterator itr = this->allUsers.begin(); itr != this->allUsers.end(); itr++)
	{
		if ((*itr).getUsername()._Equal(other.getUsername()) && (*itr).getPassword()._Equal(other.getPassword()))
		{
			*itr = other;
			return;
		}
	}

	return;
}
