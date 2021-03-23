#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
#include<vector>
#include<string>
#include"item.h"

class customer{
	public:
		customer();
		~customer();
		customer(std::string id, std::string lastName, std::string nickname);
		void buy(int price,std::string _item);//adds item to history
		std::vector<item>* printHistory();//prints items in customers history when they input "history"
		int getJamBucks();
		std::string getID();
		std::string getName();
		void setNickName(std::string newName);
		void setJamBucks(int newAmount);
		int getPosition();
		void setPosition(int i);
		void forgetLastPurchase();
	private:
		std::string userid;
		std::string name;
		std::string nickName;
		std::vector<item> *history;
		int jamBucks;
		int position;
};

#endif
