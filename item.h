#ifndef ITEM_H
#define ITEM_H
#include<iostream>
#include<string>

class item{
	public:
		item();
		item(int _price, std::string _name);
		std::string getName();
		int getPrice();
		std::string print();
		friend std::ostream & operator<<(std::ostream &out, const item &i);
	private:
		int price;
		std::string name;
};
#endif
