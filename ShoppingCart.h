#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Product.h"
using namespace std;

class ShoppingCart
{
private:
	vector<pair<Product, int> > myCart;
public:
	ShoppingCart();
	ShoppingCart(const vector<pair<Product, int> >& other);
	bool operator==(const ShoppingCart& other) const;
	void addProductToCart(const pair<Product, int>& other);
	void removeProductFromCart(const Product& other);
	void removeProductQuantity(const Product& other, int quantity);
	int getProductCount() const;
	int getProductQuantity(const Product& other) const;
	const Product getProductInCart(string serialId) const;
	const pair<Product, int> getElement(string serialId) const;
	friend ostream& operator<<(ostream& cout, const ShoppingCart& other);
};

