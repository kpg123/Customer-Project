#include<iostream>
#include<vector>
#include"customer.h"

using namespace std;

customer::customer(){
	userid = -1;
	name = "";
	nickName = "";
	history = new vector<item>();
	jamBucks = 0;
	position = 0;
}
customer::~customer(){
	delete history;
	//std::vector<item>().swap(*history);
}

customer::customer(string id, string lastName, string nickname){
	userid = id;
	name = lastName;
	nickName = nickname;
	history = new vector<item>();
	jamBucks = 0;
	position = 0;

}
void customer::buy(int _price,std::string _item){
	item boughtItem(_price,_item);
	if(_price < 100){
		jamBucks = jamBucks + 5;
	}
	else if (_price >= 100){
		int quo = _price / 100;
		jamBucks = jamBucks + ((10 * quo) + 5);

	}
	history->push_back(boughtItem);


}
void customer::setPosition(int i){
	position = i;
}
int customer::getPosition(){
	return position;
}


vector<item>* customer::printHistory(){
	//vector<item>::iterator it;
	//cout << "Customer History: " << endl;
	/*it = history->begin();
	while(it != history->end()){
  		cout << *it << " ";
  		it++;
	}
	cout << endl << endl;*/
	if(history->empty()){return nullptr;}
	return history;
}

string customer::getID(){
	return userid;
}

int customer::getJamBucks(){
	return jamBucks;
}

string customer::getName(){
	return nickName;
}

void customer::setNickName(string newName){
	nickName = newName;
}

void customer::forgetLastPurchase(){
	history->pop_back();
}

void customer::setJamBucks(int newAmount){
	jamBucks = newAmount;
}
