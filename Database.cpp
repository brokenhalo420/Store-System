#include "Database.h"
#include <cstring>
#include <iostream>
using namespace std;

Database::Database()
{
	this->allProducts = vector< pair<Product, int> >();
}

Database::Database(const vector< pair<Product, int> >& allProducts)
{
	this->allProducts = allProducts;
}

void Database::addProduct(const Product& other, int quantity)
{
	pair<Product, int> temp(other, quantity);
	for (pair<Product, int> it : this->allProducts)
	{
		if (it.first == temp.first)
		{
			it.second += quantity;
			return;
		}
	}
	
	this->allProducts.push_back(temp);
}

void Database::removeProduct(string serialId)
{

	for (vector< pair<Product, int> >::iterator it = this->allProducts.begin(); it != this->allProducts.end(); it++)
	{
		if ((*it).first.getSerialId()._Equal(serialId))
		{
			this->allProducts.erase(it);
			return;
		}
	}

	cout << "No such product exists in the database..." << endl;
	return;
}

void Database::removeProductQuantity(string serialId, int quantity)
{
	for (vector< pair<Product, int> >::iterator it = this->allProducts.begin(); it != this->allProducts.end(); it++)
	{
		if ((*it).first.getSerialId()._Equal(serialId))
		{
			if (quantity > (*it).second)
			{
				(*it).second = 0;
				return;
			}
			else
			{
				(*it).second -=quantity;
				return;
			}
		}
	}

	cout << "No such product exists in the database" << endl;
}

int Database::getProductCount() const
{
	return this->allProducts.size();
}

int Database::getProductQuantity(const Product& other) const
{
	for (pair<Product, int> it : this->allProducts)
	{
		if (it.first == other)
		{
			return it.second;
		}
	}

	cout << "No such product exists in our database." << endl;
	return 0;
}

const Product Database::getProduct(string serialId) const
{
	for (pair<Product, int> it : this->allProducts)
	{
		if (it.first.getSerialId()._Equal(serialId))
		{
			return it.first;
		}
	}

	cout << "No such product exists in our database" << endl;
	return Product();
}

const vector< pair<Product, int> > Database::getList() const
{
	return this->allProducts;
}

ostream& operator<<(ostream& cout, const Database& other)
{
	if (other.allProducts.size()==0)
	{
		cout << "Empty database" << endl;
		return cout;
	}

	cout << "----------------------------------------------------- " << endl;
	cout << "| Product | category | Serial ID | Price | Quantity | " << endl;
	cout << "----------------------------------------------------- " << endl;
	for (pair<Product, int> it : other.allProducts)
	{
		cout << it.first << " Q: " << it.second << endl;
	}
	cout << "----------------------------------------------------- " << endl;
	return cout;
}

