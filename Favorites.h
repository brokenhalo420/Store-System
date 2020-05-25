#pragma once
#include <iostream>
#include "Product.h"
#include <vector>
using namespace std;

class Favorites
{
private:
	vector<Product> products;
public:
	Favorites();
	Favorites(const vector<Product>& other);
	bool operator==(const Favorites& other) const;
	void addProductToFavorites(const Product& other);
	void removeProductFromFavorites(const Product& other);
	const Product getProductInFavorites(string serialId) const;
	int getProductCount() const;
	friend ostream& operator<<(ostream& cout, const Favorites& other);

};

