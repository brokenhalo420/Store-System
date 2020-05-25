#pragma once
#include <iostream>
using namespace std;

class Product
{
private:
	string productName;
	string productCategory;
	string serialId;
	double price;
	void set(string* field, string newValue);
public:
	Product();
	Product(string productName,string productCategory, double price);
	bool operator==(const Product& other) const;
	string getProductName() const;
	string getProductCategory() const;
	string getSerialId() const;
	double getPrice() const;
	void setProductName(string productName);
	void setProductCategory(string productCategory);
	void setProductPrice(double price);
	friend ostream& operator<<(ostream& cout, const Product& other);
};

