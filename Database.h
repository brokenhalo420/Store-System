#pragma once
#include "Product.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Database
{
private:
	vector< pair<Product, int> > allProducts;
	
public:
	Database();
	Database(const vector< pair<Product, int> >& allProducts);

	void addProduct(const Product& other, int quantity);
	void removeProduct(string serialId);
	void removeProductQuantity(string serialId, int quantity);
	int getProductCount() const;
	int getProductQuantity(const Product& other) const;
	const Product getProduct(string serialId) const;
	const vector< pair<Product, int> > getList() const;
	friend ostream& operator<<(ostream& cout, const Database& other);
};

