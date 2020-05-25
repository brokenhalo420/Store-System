#pragma once
#include "User.h"
#include "ShoppingCart.h"
#include "Favorites.h"
#include <iostream>
using namespace std;

class Profile: public User
{
private:
	ShoppingCart myCart;
	Favorites myFavorites;
	
public:
	Profile();
	Profile(string firstName, string lastName, string email, string username, string password, bool adminPermissions,const ShoppingCart& myCart, const Favorites& myFavorites);
	bool operator==(const Profile& other) const;
	const ShoppingCart& getCart() const;
	const Favorites& getFavorites() const;
	void addToCart(const Product& other, int quantity);
	void addToFavorites(const Product& other);
	void removeFromCart(const Product& other);
	void removeFromFavorites(const Product& other);
	friend ostream& operator<<(ostream& cout, const Profile& other);
};

