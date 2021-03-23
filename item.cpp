#include<iostream>
#include<string>
#include"item.h"

using namespace std;

item::item(){
	price = 0;
}
item::item(int _price, string _name){
	price = _price;
	name = _name;
}
string item::getName(){
	return name;
}
int item::getPrice(){
	return price;
}
string item::print(){
	string x = to_string(price);
	return "{" +name +", $"+ x + "} ";
}

ostream& operator<<(std::ostream& os, const item & i) {

	os << "Item: " << i.name << " " << "Price: " << i.price;
	return os;

}
