
#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item
{
	private:
		string name;
		int unit;
		int quantity;
		double price;

	public:
		Item();
		Item(string, int, int, double);
		void setName(string);
		void setUnit(int);
		void setQuantity(int);
		void setPrice(double);
		string getName();
		int getUnit();
		int getQuantity();
		double getPrice();
		double totalPrice();
};

#endif