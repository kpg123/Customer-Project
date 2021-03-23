#ifndef JAMTREE_H
#define JAMTREE_H
#include<iostream>
#include<string>
#include"customer.h"

class jamTree{
	public:
		jamTree();
		~jamTree();
		int parent(int x);
		int parentRight(int x);
		int left_child(int x);
		int right_child(int x);
		void insert(customer* client);
		int report(int amount);
		std::vector<customer*> surprise(int amount,std::string item, int price);
		void minHeapify();
		void expandTree();
		void increaseKey(int x);
		void decreaseKey(int ind);
	private:
		customer **tree;
		int length;
		int filled;
		std::vector<int> remembered;

};
#endif
