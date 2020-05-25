#include "Store.h"
#include <iostream>
using namespace std;

Store::Store()
{
	this->myProfile = Profile();
	this->myData = Database();
	this->myAccounts = AccountManager();
	this->isLogged = false;
}

Store::Store(const Database& database, const AccountManager& myAccounts)
{
	this->myProfile = Profile();
	this->myData = database;
	this->myAccounts = myAccounts;
	this->isLogged = false;
}



const Profile& Store::getProfile() const
{
	return this->myProfile;
}

const Database& Store::getData() const
{
	return this->myData;
}

void Store::setProfile(const Profile& other)
{
	for (Profile it : this->myAccounts.getList())
	{
		if (it == other)
		{
			this->myProfile = other;
			return;
		}
	}
	cout << "This profile is not registered in the system" << endl;
	return;
}

void Store::setData(const Database& other)
{
	this->myData = other;
}

void Store::login(string username, string password)
{
	if (this->isLogged)
	{
		cout << "You are already logged in..." << endl;
		return;
	}

	for (Profile it : this->myAccounts.getList())
	{
		if (it.getUsername()._Equal(username) && it.getPassword()._Equal(password))
		{
			this->myProfile = it;
			this->isLogged = true;
			cout << "Welcome, " << this->myProfile.getFirstName() << endl;
			return;
		}
	}

	cout << "No user with this username and password found" << endl;
	return;
}

void Store::logout()
{
	if (this->isLogged)
	{
		this->updateManager();
		this->isLogged = false;
		this->myProfile = Profile();
		cout << "You've succesfully logged out" << endl;
		return;
	}
	cout << "You're not logged in..." << endl;
	return;
}

void Store::registration(const Profile& other)
{
	
	this->myAccounts.addUser(other);
}

void Store::addProduct(const Product& other, int quantity)
{
	this->myData.addProduct(other, quantity);
}

void Store::removeProduct(string serialId)
{
	this->myData.removeProduct(serialId);
}

void Store::removeProductQuantity(string serialId, int quantity)
{
	this->myData.removeProductQuantity(serialId, quantity);
}

void Store::removeUser(const Profile& other)
{
	this->myAccounts.removeUser(other);
}

void Store::addToShoppingCart(const Product& newProduct, int quantity)
{
	if (this->isLogged)
	{
		pair<Product, int> temp(newProduct, quantity);
		for (pair<Product, int> product : this->myData.getList())
		{
			if (temp.first == product.first)
			{
				if (temp.second <= product.second)
				{
					this->myProfile.addToCart(newProduct, quantity);
					this->updateManager();
					return;
				}
				else
				{
					cout << "Not enough quantity in storage to add" << endl;
					return;
				}
			}
		}
		cout << "No such product identified in the database" << endl;
		return;
	}
	else
	{
		cout << "You are not logged in" << endl;
		return;
	}
}

void Store::removeFromShoppingCart(const Product& removal)
{
	this->myProfile.removeFromCart(removal);
	this->updateManager();
}

void Store::addToFavorites(const Product& newProduct)
{
	this->myProfile.addToFavorites(newProduct);
	this->updateManager();
}

void Store::removeProductFromFavorites(const Product& removal)
{
	this->myProfile.removeFromFavorites(removal);
	this->updateManager();
}

ostream& operator<<(ostream& cout, const Store& other)
{
	//if (other.myAccounts.getUserCount() == 0 && other.myData.getProductCount() == 0)
	//{
	//	cout << "Empty Store" << endl;
	//	return cout;
	//}

	cout << "----------------------------------------------------- " << endl;
	cout << "Current Profile:\n" << other.myProfile << endl;
	cout << "----------------------------------------------------- " << endl;
	cout << "The DataBase:\n" << other.myData<<endl;
	cout << "----------------------------------------------------- " << endl;
	cout << "The Account Manager:\n" << other.myAccounts << endl;
	cout << "----------------------------------------------------- " << endl;
	cout << "Is a user logged in: " << other.isLogged << endl;
	cout << "----------------------------------------------------- " << endl;
	
	return cout;
}

void Store::updateManager()
{
	if (!isLogged)
	{
		return;
	}

	this->myAccounts.update(this->myProfile);
}