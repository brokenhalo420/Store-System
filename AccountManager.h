#pragma once
#include "Profile.h"
#include <vector>

class AccountManager
{
private:
	vector<Profile> allUsers;
public:
	void update(const Profile& other);
	AccountManager();
	AccountManager(const vector<Profile>& allUsers);
	

	void addUser(const Profile& other);
	void removeUser(const Profile& other);

	int getUserCount() const;

	const Profile getProfile(string username, string password) const;
	const vector<Profile> getList() const;

	friend ostream& operator<<(ostream& cout, const AccountManager& other);
};

