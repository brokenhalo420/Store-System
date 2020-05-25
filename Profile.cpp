#include "Profile.h"
#include "String.h"
#include <iostream>
//#include "Storage.h"
using namespace std;

Profile::Profile():User()
{
	this->myCart = ShoppingCart();
	this->myFavorites = Favorites();
}

Profile::Profile(string firstName, string lastName, string email, string username, string password, bool adminPermissions, const ShoppingCart& myCart, const Favorites& myFavorites)
	:User(firstName,lastName,email,username,password,adminPermissions)
{
	this->myCart = myCart;
	this->myFavorites = myFavorites;
}

bool Profile::operator==(const Profile& other) const
{
	if ((User::operator==(other) && this->myCart == other.myCart && this->myFavorites == other.myFavorites) || this == &other)
	{
		return true;
	}
	else
	{
		return false;
	}
}

const ShoppingCart& Profile::getCart() const
{
	return this->myCart;
}

const Favorites& Profile::getFavorites() const
{
	return this->myFavorites;
}

void Profile::addToCart(const Product& other, int quantity)
{
	pair<Product, int> myPair(other, quantity);
	this->myCart.addProductToCart(myPair);
}

void Profile::addToFavorites(const Product& other)
{
	this->myFavorites.addProductToFavorites(other);
}

void Profile::removeFromCart(const Product& other)
{
	this->myCart.removeProductFromCart(other);
}

void Profile::removeFromFavorites(const Product& other)
{
	this->myFavorites.removeProductFromFavorites(other);
}

ostream& operator<<(ostream& cout, const Profile& other)
{
	if (other.firstName._Equal(" "))
	{
		cout << "Empty profile";
		return cout;
	}

	string password_hidden;
	for (int i = 0; i < other.password.size(); i++)
	{
		password_hidden.append("*");
	}

	cout << "----------------------------------------------------------------------------------------------- " << endl;
	cout << "First Name: " << other.firstName << endl;
	cout << "Last Name: " << other.lastName << endl;
	cout << "Email: " << other.email << endl;
	cout << "Username: " << other.username << endl;
	cout << "Password: " << password_hidden << endl << endl;
	cout << "Shopping Cart: " << endl;
	cout << other.myCart << endl;
	cout << "Favorites List: " << endl;
	cout << other.myFavorites<<endl;
	cout << "----------------------------------------------------------------------------------------------- " << endl;
	return cout;
}


