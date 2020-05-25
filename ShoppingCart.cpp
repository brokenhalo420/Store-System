#include "ShoppingCart.h"
#include <vector>
#include <map>

ShoppingCart::ShoppingCart()
{
	this->myCart = vector<pair<Product, int> >();
}

ShoppingCart::ShoppingCart(const vector<pair<Product, int> >& other)
{
	this->myCart = other;
}

bool ShoppingCart::operator==(const ShoppingCart& other) const
{
	if (this->myCart == other.myCart || this==&other)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ShoppingCart::addProductToCart(const pair<Product, int>& other)
{
	for (vector<pair<Product, int> >::iterator product = this->myCart.begin(); product != this->myCart.end(); product++)
	{
		if ((*product).first == other.first)
		{
			(*product).second += other.second;
			return;
		}
	}

	this->myCart.push_back(other);

}

void ShoppingCart::removeProductFromCart(const Product& other)
{
	for (vector<pair<Product, int> >::iterator product = this->myCart.begin(); product != this->myCart.end(); product++)
	{
		if ((*product).first == other)
		{
			this->myCart.erase(product);
			return;
		}
	}

	cout << "This product isn't added to the Cart" << endl;
	return;
}

void ShoppingCart::removeProductQuantity(const Product& other, int quantity)
{
	for (vector< pair<Product, int> >::iterator it = this->myCart.begin(); it != this->myCart.end(); it++)
	{
		if ((*it).first == other)
		{
			if (quantity > (*it).second)
			{
				(*it).second = 0;
				return;
			}
			else
			{
				(*it).second -= quantity;
				return;
			}
		}
	}

	cout << "No such product in the shopping cart" << endl;
	return;
}

int ShoppingCart::getProductCount() const
{
	return this->myCart.size();
}

int ShoppingCart::getProductQuantity(const Product& other) const
{

	for (pair<Product,int> it : this->myCart)
	{
		if (it.first == other)
		{
			return it.second;
		}
	}

	cout << "No such product exists";
	return NULL;
}

const Product ShoppingCart::getProductInCart(string serialId) const
{
	for (pair<Product, int> it : this->myCart)
	{
		if (it.first.getSerialId()._Equal(serialId))
		{
			
			return it.first;
		}
	}

	cout << "No such product has been added to the Cart" << endl;
	
	return Product();
}

const pair<Product, int> ShoppingCart::getElement(string serialId) const
{
	for (pair<Product, int> it : this->myCart)
	{
		if (it.first.getSerialId()._Equal(serialId))
		{
			return it;
		}
	}

	cout << "No such product exists" << endl;
	pair<Product, int> temp;
	return temp;
}

ostream& operator<<(ostream& cout, const ShoppingCart& other)
{
	if (other.myCart.size() == 0)
	{
		cout << "Cart is empty..." << endl;
		return cout;
	}

	cout << "----------------------------------------------------- " << endl;
	cout << "| Product | Category | Serial ID | Price | Quantity | " << endl;
	cout << "----------------------------------------------------- " << endl;
	for (pair<Product, int> it : other.myCart)
	{
		cout << it.first << " " << it.second << endl;
	}
	cout << "----------------------------------------------------- " << endl;
	return cout;
}