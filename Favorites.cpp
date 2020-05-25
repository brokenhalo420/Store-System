#include "Favorites.h"
#include <iostream>
using namespace std;

Favorites::Favorites()
{
	this->products = vector<Product>();
}

Favorites::Favorites(const vector<Product>& other)
{
	this->products = other;
}

bool Favorites::operator==(const Favorites& other) const
{
	if (this->products == other.products || this == &other)
	{
		return true;
	}
	else
	{
		return false;
	}
}

const Product Favorites::getProductInFavorites(string serialId) const
{
	for (Product it : this->products)
	{
		if (it.getSerialId()._Equal(serialId))
		{
			return it;
		}
	}

	cout << "No such product is in the Favorites" << endl;
	return Product();

}

void Favorites::addProductToFavorites(const Product& other)
{
	for (Product it : this->products)
	{
		if (it == other)
		{
			cout << "This product has already been added" << endl;
			return;
		}
	}

	this->products.push_back(other);
}

void Favorites::removeProductFromFavorites(const Product& other)
{
	for(vector<Product>::iterator it= this->products.begin(); it!=this->products.end();it++)
	{
		if ((*it) == other)
		{
			this->products.erase(it);
			return;
		}
	}

	cout << "This product isn't added to the Favorites" << endl;
	return;
}

int Favorites::getProductCount() const
{
	return this->products.size();
}

ostream& operator<<(ostream& cout, const Favorites& other)
{
	if (other.products.size() == 0 )
	{
		cout << "Favorites is empty..." << endl;
		return cout;
	}

	cout << "------------------------------------------ " << endl;
	cout << "| Product | category | Serial ID | Price | " << endl;
	cout << "------------------------------------------ " << endl;
	for (Product it : other.products)
	{
		cout << it << endl;
	}
	cout << "------------------------------------------ " << endl;
	return cout;

}