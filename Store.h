#pragma once
#include "Database.h"
#include "AccountManager.h"
#include "Profile.h"
#include <iostream>
using namespace std;


class Store
{
private:
	Profile myProfile;
	Database myData;
	AccountManager myAccounts;
	bool isLogged;
	void updateManager();
public:

	Store();
	Store(const Database& database, const AccountManager& myAccounts);

	const Profile& getProfile() const;
	const Database& getData() const;
	void setProfile(const Profile& other);
	void setData(const Database& other);

	void login(string username, string password);
	void logout();
	void registration(const Profile& other);

	void addProduct(const Product& other, int quantity);
	void removeProduct(string serialId);
	void removeProductQuantity(string serialId,int quantity);
	void removeUser(const Profile& other);

	void addToShoppingCart(const Product& newProduct, int quantity);
	void removeFromShoppingCart(const Product& removal);

	void addToFavorites(const Product& newProduct);
	void removeProductFromFavorites(const Product& removal);

	//for testing purposes only
	friend ostream& operator<<(ostream& cout, const Store& other);
};

