#include"Store.h"
#include "SerialId.h"
#include <iostream>
using namespace std;

int main()
{
	
	//Serial Id generator
	cout << "Serial Id generator: " << endl;
	string serial;
	string another;
	SerialId::generate(serial);
	SerialId::generate(another);
	cout << serial << endl;
	cout << another << endl;
	cout << "[END]-----------------------------------" << endl << endl;

	//Product class
	cout << "Product class: " << endl;
	Product spoon;
	Product hairbrush("Hairbrush", "Accesories", 12.5);
	Product comb(hairbrush);
	Product brush = hairbrush;
	Product utensil;
	utensil = hairbrush;
	cout<< (hairbrush == brush) <<endl;
	cout << hairbrush.getProductName() << " " << hairbrush.getProductCategory();
	cout<<" "<<hairbrush.getSerialId()<< " " << hairbrush.getPrice()<<endl;
	cout << hairbrush << endl;
	cout << "[END]-----------------------------------" << endl << endl;


	//User class
	cout << "User class: " << endl;
	User myUser;
	User guest("Guest", "Guest", "example@class.com", "guest", "guest", false);
	User copy_guest(guest);
	User copy;
	copy = copy_guest;
	User* ptr = &guest;

	cout << (myUser == guest) << endl;
	cout << (copy_guest == guest) << endl;
	cout << (copy == guest) << endl;
	cout << (*ptr == guest) << endl;
	cout << "[END]-----------------------------------" << endl << endl;

	//Shopping Cart class
	cout << "Shopping Cart class: " << endl;
	ShoppingCart testCart;
	vector< pair<Product, int> > my_list;
	pair<Product, int> myPair;
	Product test_product_cart("Towel", "Utensils", 5.99);
	myPair.first = test_product_cart;
	myPair.second = 25;
	testCart.addProductToCart(myPair);
	cout << "first print after adding our pair" << endl;
	cout<<testCart;
	cout <<"Product count: "<< testCart.getProductCount() << endl;
	cout << "Towel quantity: " << testCart.getProductQuantity(test_product_cart)<<endl;

	testCart.removeProductQuantity(test_product_cart, 5);
	cout << "Towel quantity after removing a few quantities: " << testCart.getProductQuantity(test_product_cart) << endl;

	cout << "Received product: \n" << testCart.getProductInCart("wfee") << endl;
	cout << "Received product from getElement() method" << endl;
	pair<Product, int> receive;
	receive = testCart.getElement("dcdcd");
	cout <<"Received: "<< receive.first << " Q: " << receive.second << endl;
	cout<<"\nPrinting cart after removing a pair"<<endl;
	testCart.removeProductFromCart(test_product_cart);
	cout << testCart;
	cout << endl;
	cout << "[END]-----------------------------------" << endl << endl;


	//Favorites class
	cout << "Favorites class: " << endl;
	Favorites testFaves;
	Product test_product_fav("Towel", "Utensils", 5.99);
	testFaves.addProductToFavorites(test_product_fav);
	cout << "first print after adding our pair" << endl;
	cout << testFaves;
	cout << "_______________" << endl;
	cout << "Product count: " << testFaves.getProductCount() << endl;
	cout << "Received product: " << testFaves.getProductInFavorites("wfee") << endl;
	cout << "\nPrinting cart after removing a pair" << endl;
	testFaves.removeProductFromFavorites(test_product_fav);
	cout << testFaves;
	cout << endl;
	cout << "[END]-----------------------------------" << endl << endl;

	//Profile Class
	cout << "Profile class: " << endl;
	Product profile_product("Deodorant", "Healthcare", 4.99);
	ShoppingCart profile_cart;
	pair<Product, int> profile_pair(profile_product, 12);
	profile_cart.addProductToCart(profile_pair);
	Favorites profile_favorites;
	profile_favorites.addProductToFavorites(profile_product);
	Profile my_profile(guest.getFirstName(),guest.getLastName(), guest.getEmail(),guest.getUsername(),guest.getPassword(), guest.getAdminPermissions(), profile_cart, profile_favorites);
	cout << "Shopping cart in Profile: " << endl << my_profile.getCart();
	cout << "\nFavorites in Profile:\n" << my_profile.getFavorites() << endl;

	cout << "\nAdding products" << endl;
	my_profile.addToCart(test_product_cart, 2);
	my_profile.addToFavorites(test_product_fav);
	cout << "\nFull Profile:" << endl;
	cout << my_profile;

	cout << "Shopping cart in Profile: " << endl << my_profile.getCart();
	cout << "\nFavorites in Profile:\n" << my_profile.getFavorites() << endl;

	cout << "\nRemoving products" << endl;
	my_profile.removeFromCart(test_product_cart);
	my_profile.removeFromFavorites(test_product_fav);
	cout << "\nFull Profile:" << endl;
	cout << my_profile;

	cout << "Shopping cart in Profile: " << endl << my_profile.getCart();
	cout << "\nFavorites in Profile: " << my_profile.getFavorites() << endl;
	cout << "\nFull Profile:" << endl;
	cout << my_profile <<endl;
	cout << "[END]-----------------------------------" << endl << endl;

	//Account Manager class
	cout << "Account Manager class: " << endl;
	AccountManager my_manager;
	cout << "Printing empty manager:\n" << my_manager << endl;
	cout << "User count: " << my_manager.getUserCount()<<endl;

	my_manager.addUser(my_profile);
	cout << "Added new User:\n" << my_manager << endl;
	cout << "User count: " << my_manager.getUserCount()<<endl;

	cout << "getProfile() method testing:\n";
	Profile profile_test= my_manager.getProfile("guest", "none");
	cout << profile_test << endl;


	vector<Profile> profile_list = my_manager.getList();
	if (profile_list.size() != 0)
	{
		for (Profile it : profile_list)
		{
			cout << it;
		}
	}
	else
	{
		cout << "Empty pointer or vector list..." << endl;
	}

	my_manager.removeUser(my_profile);
	cout << "Removed a user:\n" << my_manager << endl;
	cout << "User count: " << my_manager.getUserCount()<<endl;
	cout << "[END]-----------------------------------" << endl << endl;

	//Database class 
	cout << "Database class:\n";
	Database my_storage;
	cout << "Printing empty database:\n" << my_storage << endl;
	cout << "Product count: " << my_storage.getProductCount() << endl;

	my_storage.addProduct(test_product_cart, 150);
	cout << "Added new Product:\n" << my_storage << endl;
	cout << "Product count: " << my_storage.getProductCount() << endl;
	cout << "Product quantity: " << my_storage.getProductQuantity(test_product_cart) << endl;


	cout << "getProduct() method testing:\n";
	Product product_test = my_storage.getProduct(test_product_cart.getSerialId());
	cout << product_test << endl;

	cout << "Removing a few product quantities:" << endl;
	my_storage.removeProductQuantity(test_product_cart.getSerialId(), 15);
	cout << "New product count: " << my_storage;


	my_storage.removeProduct(test_product_cart.getSerialId());
	cout << "Removed a product:\n" << my_storage << endl;
	cout << "Product count: " << my_storage.getProductCount() << endl;
	cout << "[END]-----------------------------------" << endl << endl;

	//Store class
	cout << "Store Class:\n";
	Store my_store(my_storage,my_manager);
	my_store.addProduct(test_product_cart, 150);
	Profile profile_returned = my_store.getProfile();
	cout << "Profile in Store:\n" <<profile_returned<< endl;
	Database data_returned = my_store.getData();
	cout << "Database in Store:\n" << data_returned << endl;

	cout << "Printing the store:\n" << my_store << endl;

	cout << "Testing the login method" << endl;
	my_store.login(my_profile.getUsername(), my_profile.getPassword());
	cout << endl;

	cout << "Testing the log out method" << endl;
	my_store.logout();
	cout << endl;

	cout << "testing the registration and login/logout methods again\n" << endl;
	my_store.registration(my_profile);
	my_store.login(my_profile.getUsername(), my_profile.getPassword());
	cout << endl;
	
	cout << "adding a product to the database" << endl;
	my_store.addProduct(test_product_fav,150);
	cout << "[MY STORE]\n" << my_store << endl;
	my_store.removeProductQuantity(test_product_fav.getSerialId(), 50);
	cout << "[MY STORE]\n" << my_store << endl;

	my_store.addToShoppingCart(test_product_cart,12);
	cout << "[MY STORE]\n" << my_store << endl;

	my_store.removeFromShoppingCart(test_product_cart);
	cout << "[MY STORE]\n" << my_store << endl;

	my_store.addToFavorites(test_product_fav);
	cout << "[MY STORE]\n" << my_store << endl;

	my_store.removeProductFromFavorites(test_product_fav);
	cout << "[MY STORE]\n" << my_store << endl;

	my_store.removeProduct(test_product_fav.getSerialId());
	cout << "[MY STORE]\n" << my_store << endl;

	my_store.logout();
	cout << "[MY STORE]\n" << my_store << endl;

	my_store.removeUser(my_profile);
	cout << "[MY STORE]\n" << my_store << endl;



	system("pause");
	return 0;
}