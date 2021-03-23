#ifndef CUSTOMERBST_H
#define CUSTOMERBST_H
#include<iostream>
#include<vector>
#include<string>
#include"customer.h"

class customerBST{
	public:
		customerBST();
		void insert(customer* newCustomer);
		bool changeName(std::string userId, std::string newName);
		int getLength();
		std::vector<customer*> getTree();
		customer* getCustomer(std::string id);
		void printAt(int index);
	private:
		std::vector<customer*> customers;
		int length;
};

#endif
