#include<iostream>
#include<string>
#include<cstring>
#include"jamTree.h"
//#include"customer.h"

using namespace std;

jamTree::jamTree(){
	tree = new customer*[7];
	length = 7;
	filled = 0;
}
jamTree::~jamTree(){
	/*for(int i = 0; i < filled; i++){
		delete tree[i];
	}*/
	delete [] tree;
}

//Gets the parent node of node at index x
int jamTree::parent(int x){
	return(x-1)/2;
}
int jamTree::parentRight(int x){
	return (x-2)/2;
}
//gets right child of node at index x
int jamTree::right_child(int x){
	return(2*x+2);
}
//gets left child of node at index x
int jamTree::left_child(int x){
	return(2*x +1);
}
//If parent customer Jambucks is less than child, swap them
void jamTree::increaseKey(int ind){
		int parentI; // index of parent
		customer *temp; // temperoary customer for swapping
		if(ind != 0){
			if(ind %2 == 0){
				parentI = parentRight(ind);
			} else {
				parentI = parent(ind);
			}
			if(tree[parentI]->getJamBucks() < tree[ind]->getJamBucks()){
			/*	temp = tree[parentI];
				tree[parentI] = tree[ind];
				//tree[ind] =temp;//
				//tree[ind]->setPosition(tree[parentI]->getPosition());  //
				//tree[parentI]->setPosition(temp->getPosition());//
				tree[parentI] ->setPosition(tree[ind]->getPosition());
				tree[ind] = temp;
				tree[ind] ->setPosition(temp->getPosition());*/
				//cout << endl<<tree[parentI]->getName() << " "<< tree[parentI]->getPosition()<< " " << tree[ind]->getName() << " "<<tree[ind]->getPosition()<<endl;
				temp = tree[parentI];
				int pos = tree[ind]->getPosition();
				tree[parentI] = tree[ind];
				tree[ind] = temp;
				tree[parentI]->setPosition(tree[ind]->getPosition());
				tree[ind]->setPosition(pos);
				//cout << tree[parentI]->getName() <<" " << tree[parentI]->getPosition()<< " " << tree[ind]->getName() << " "<<tree[ind]->getPosition()<<endl;
				increaseKey(parentI);
			}
		}
}

void jamTree::decreaseKey(int ind){
	int childLeft = left_child(ind);
	int childRight = right_child(ind);
	customer *temp;
	if(childLeft < filled && childRight < filled){
		/*if(ind == 0){cout << tree[ind]->getName() << " " << tree[ind]->getJamBucks()<<endl;
			cout << tree[childLeft]->getName() << " " << tree[childLeft]->getJamBucks()<<endl;
			cout << tree[childRight]->getName() << " " << tree[childRight]->getJamBucks()<<endl;
		}*/
		if(tree[ind]->getJamBucks() < tree[childLeft]->getJamBucks() || tree[ind]->getJamBucks() < tree[childRight]->getJamBucks()){
			if(tree[childLeft]->getJamBucks() > tree[childRight]->getJamBucks()){
				/*temp = tree[ind];
				tree[ind] = tree[childLeft];
				tree[childLeft] = temp;
				tree[childLeft]->setPosition(tree[ind]->getPosition());
				tree[ind]->setPosition(temp->getPosition());*/	
				//cout << tree[ind]->getPosition()<<endl;
				//cout << endl<<tree[childLeft]->getName() << " " << tree[ind]->getName() << " "<<temp->getPosition()<<endl;
				temp = tree[ind];
				int pos = tree[childLeft]->getPosition();
				tree[ind] = tree[childLeft];
				tree[childLeft] = temp;
				tree[ind]->setPosition(tree[childLeft]->getPosition());
				tree[childLeft]->setPosition(pos);
				//cout << tree[childLeft]->getName() << " " << tree[ind]->getName() << " "<<temp->getPosition()<<endl;
				decreaseKey(childLeft);
			} else {
				/*temp = tree[ind];
				tree[ind] = tree[childRight];
				tree[childRight] = temp;
				tree[childRight]->setPosition(tree[ind]->getPosition());
				tree[ind]->setPosition(temp->getPosition());*/
				//cout << tree[ind]->getPosition() << endl;
				//cout << endl<<tree[childRight]->getName() << " " << tree[ind]->getName() << " "<<temp->getPosition()<<endl;
				temp = tree[ind];
				int pos = tree[childRight]->getPosition();
				tree[ind] = tree[childRight];
				tree[childRight] = temp;
				tree[ind]->setPosition(tree[childRight]->getPosition());
				tree[childRight]->setPosition(pos);
				//cout << tree[childRight]->getName() << " " << tree[ind]->getName() << " "<<temp->getPosition()<<endl;
				decreaseKey(childRight);
			}
		}
	} else if(childLeft < filled && tree[childLeft]->getJamBucks() > tree[ind]->getJamBucks()){
		/*temp = tree[ind];
		tree[ind] = tree[childLeft];
		tree[childLeft] = temp;
		tree[childLeft]->setPosition(tree[ind]->getPosition());
		tree[ind]->setPosition(temp->getPosition());*/
		//cout <<endl <<tree[childLeft]->getName() << " " << tree[ind]->getName() << " "<<temp->getPosition()<<endl;
		temp = tree[ind];
		int pos = tree[childLeft]->getPosition();
		tree[ind] = tree[childLeft];
		tree[childLeft] = temp;
		tree[ind]->setPosition(tree[childLeft]->getPosition());
		tree[childLeft]->setPosition(pos);
		//cout << tree[childLeft]->getName() << " " << tree[ind]->getName() << " "<<temp->getPosition()<<endl;
		decreaseKey(childLeft);
	} else if(childRight < filled && tree[childRight]->getJamBucks() > tree[ind]->getJamBucks()){
		/*temp = tree[ind];
		tree[ind] = tree[childRight];
		tree[childRight] = temp;
		tree[childRight]->setPosition(tree[ind]->getPosition());
		tree[ind]->setPosition(temp->getPosition());*/
		//cout << endl<<tree[childRight]->getName() << " " << tree[ind]->getName() << " "<<temp->getPosition()<<endl;
		temp = tree[ind];
		int pos = tree[childRight]->getPosition();
		tree[ind] = tree[childRight];
		tree[childRight] = temp;
		tree[ind]->setPosition(tree[childRight]->getPosition());
		tree[childRight]->setPosition(pos);
		//cout << tree[childRight]->getName() << " " << tree[ind]->getName() << " "<<temp->getPosition()<<endl;
		decreaseKey(childRight);
	}
//cout << tree[0]->getName() << " " << tree[0]->getJamBucks()<<endl<<endl;
}

void jamTree::insert(customer *client){
	if(length == filled){
		expandTree();
	}
	tree[filled] = client;
	client->setPosition(filled);
	filled++;
	//tree[filled-1] = client;
	//increaseKey(filled-1);
}
int jamTree::report(int amount)
{
	/*int all = 0;
	for (int j = 0; (j <filled)&&(j < amount); j++)
	{
		all += tree[j]->getJamBucks();
	}
	return all;
	//out << "#JAMBucks held by top " << amount << " users = " << all <<endl;*/
	int all = 0;
	vector<customer*> removed = surprise(amount,"none",0);
	for(unsigned int i = 0; i < removed.size();i++){
		all += remembered.at(i);
		removed.at(i)->setJamBucks(0);
		removed.at(i)->setJamBucks(remembered.at(i));
		removed.at(i)->forgetLastPurchase();
		increaseKey(removed.at(i)->getPosition());
	}
	removed.clear();
	return all;
}
vector<customer*> jamTree::surprise(int amount,string item, int price)
{
	/*vector<string> surprised;
	//out << "Top "<< amount<<" users surprised with "<< item <<" worth $"<< price<<" ";
	for (int j = 0; (j <filled) && (j < amount); j++)
	{
		//out << tree[j].nickName << " ";
		//out << tree[j].jamBucks << " ";
		surprised.push_back(tree[j]->getName());
		tree[j]->buy(price, item);
		tree[j]->setJamBucks(0);
		for(int m = j+1; m < filled; m++){
			increaseKey(m);

		}
	}
	for (int j = 0; (j < filled) && (j < amount); j++)
	{
		customer *middata;
		middata = tree[j];
		//tree.erase(tree.begin());
		tree[filled] = middata;
	}
	return surprised;
	//out << endl;*/
	vector<customer*> surprised;
	remembered.clear();
	for(int i = 0; i < amount && i < filled; i++){
		remembered.push_back(tree[0]->getJamBucks());
		//cout << tree[0]->getName() <<" " << tree[0]->getJamBucks()<<endl;
		surprised.push_back(tree[0]);
		//remembered.push_back(tree[0]->getJamBucks());
		tree[0]->buy(price,item);
		//remembered.push_back(tree[0]->getJamBucks());
		tree[0]->setJamBucks(0);	
		decreaseKey(0);
	}
	//cout << endl<<endl;
	return surprised;
}
void jamTree::expandTree(){
	int size = length*2;
	customer** newArr = new customer*[size];
	for(int i = 0; i < length; i++){
		newArr[i] = tree[i];
		//memcpy(newArr,tree,length*sizeof(customer*));
	}
	delete[] tree;
	tree = newArr;
	length *= 2;
}
