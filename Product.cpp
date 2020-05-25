#include "Product.h"
#include <iostream>
#include <cstring>
#include "SerialId.h"
using namespace std;

Product::Product()
{
	this->productName = " ";
	this->productCategory = " ";
	SerialId::generate(this->serialId);
	this->price = 0.0;
}

Product::Product(string productName, string productCategory, double price)
{
	this->set(&this->productName, productName);
	this->set(&this->productCategory, productCategory);
	SerialId::generate(this->serialId);
	this->setProductPrice(price);
}


bool Product::operator==(const Product& other) const
{
	if (this == &other)
	{
		return true;
	}

	int equalAttributes = 4;
	if (this->productName._Equal(other.productName))
	{
		equalAttributes--;
	}

	if (this->productCategory._Equal(other.productCategory))
	{
		equalAttributes--;
	}

	if (this->serialId._Equal(other.serialId))
	{
		equalAttributes--;
	}

	if (this->price == other.price)
	{
		equalAttributes--;
	}

	if (equalAttributes == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string Product::getProductName() const
{
	return this->productName;
}

string Product::getProductCategory() const
{
	return this->productCategory;
}

string Product::getSerialId() const
{
	return this->serialId;
}

double Product::getPrice() const
{
	return this->price;
}


void Product::set(string* field, string newValue)
{
	*field = newValue;
}

void Product::setProductName(string productName)
{
	this->set(&this->productName, productName);
}

void Product::setProductCategory(string productCategory)
{
	this->set(&this->productCategory, productCategory);
}

void Product::setProductPrice(double price)
{
	if (price <= 0)
	{
		cout << "Error...Incorrect price." << endl;
		return;
	}

	this->price = price;
}

ostream& operator<<(ostream& cout, const Product& other)
{
	if (other.productName._Equal(" "))
	{
		cout << "Empty product" << endl;
		return cout;
	}

	cout << "| " << other.productName;
	cout << " | " << other.productCategory;
	cout << " | " << other.serialId;
	cout << " | " << other.price << "$ |";
	return cout;
}
