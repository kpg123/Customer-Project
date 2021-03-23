#include<iostream>
#include<string>
#include<cmath>
#include"customerBST.h"

using namespace std;

customerBST::customerBST(){
	length = 0;
}
void customerBST::insert(customer* newCustomer){
	//customers.push_back(newCustomer);
	if(length == 0){
		customers.push_back(newCustomer);
		length++;
		return;
	} else if (length == 1){
		if(customers.at(0)->getID().compare(newCustomer->getID()) < 0){
			customers.push_back(newCustomer);
		} else {
			customers.insert(customers.begin(),newCustomer);
		}
		length++;
		return;
	}
	//int mid = round(length/2.0);
	int low = 0;
	int high = length;
	bool found = false;
	while(!found){
		int mid = round((high+low)/2.0);
		/*for(int i = 0; i < length; i++){
			cout << mid <<" "<<length <<" "<< customers.at(i)->getID() << endl;
		}*/
		/*if(mid >= -1){
			customers.push_back(newCustomer);
			found = true;
		}else if(mid == 0 || (customers.at(mid-1)->getID().compare(newCustomer->getID()) <0  && (customers.at(mid)->getID().compare( newCustomer->getID()) >0))){
			found = true;
			customers.insert(customers.begin() + mid,newCustomer);
		} else if(customers.at(mid)->getID().compare(newCustomer->getID()) < 0){
			mid = mid + round(mid/2.0);
		} else {
			mid = (mid/2.0);
		}*/
		if(mid == length){
			customers.push_back(newCustomer);
			found =true;
			length++;
		}else if(newCustomer->getID() == customers.at(mid)->getID()){
			return;
		}else if(newCustomer->getID() > customers.at(mid-1)->getID() && newCustomer->getID() < customers.at(mid)->getID()){
			customers.insert(customers.begin() + mid, newCustomer);
			length++;
			found = true;
		} else if(customers.at(mid)->getID().compare(newCustomer->getID()) < 0){
			low = mid+1;
		} else {
			high = mid-1;
		}
	}
}
std::vector<customer*> customerBST::getTree(){
	return customers;
}
int customerBST::getLength(){
	return length;
}
bool customerBST::changeName(string id, string newName){
	//int mid = length/2;
	bool found = false;
	/*while(!found){
		if(customers.at(mid)->getID() == id){
			customers.at(mid)->setNickName(newName);
			found = true;
		} else if(id > customers.at(mid)->getID()){
			mid = mid + mid/2;
		} else if(id < customers.at(mid)->getID()){
			mid = mid/2;
		} else {
			found = true;
		}
	}*/
	int high = length;
	int low = 0;
	while(!found){
		int mid = round((high + low)/2.0);
		if(mid == length){return false;}
		if(id == customers.at(mid)->getID()){
			customers.at(mid)->setNickName(newName);
			return true;
		}else if(id == customers.at(length-1)->getID()){
			customers.at(length-1)->setNickName(newName);
			return true;
		}else if(customers.at(mid)->getID().compare(id) < 0){
			low = mid+1;
		} else {
			high = mid-1;
		}
	}
	return false;
}

customer* customerBST::getCustomer(string id){
	//int mid = length/2;
	bool found = false;
	/*while(!found){
		if(customers.at(mid)->getID() == id){
			return customers.at(mid);
			found = true;
		} else if(id > customers.at(mid)->getID()){
			mid = mid + mid/2;
		} else if(id < customers.at(mid)->getID()){
			mid = mid/2;
		} else {
			found = true;
		}
	}
	return nullptr;*/
	int high = length;
	int low = 0;
	while(!found){
		//cout<< customers.at(mid)->getID << " " << id << endl;
		int mid = round((high + low)/2.0);
		//cout<<length<<" "<< mid <<" "<<customers.at(mid)->getID() << " " << id << " " << customers.at(low)->getID()<< "-" <<customers.at(high-1)->getID() << endl;
		if(mid >= length){return nullptr;}
		if(id == customers.at(mid)->getID()){
			return customers.at(mid);
		}else if(id == customers.at(length-1)->getID()){
			return customers.at(length-1);
		}else if(customers.at(mid)->getID().compare(id) < 0){
			low = mid+1;
		} else {
			high = mid-1;
		}
	}
	return nullptr;
}

void customerBST::printAt(int i){
	cout << customers.at(i)->getName() << " " << customers.at(i)->getID() << " " << customers.at(i)->getPosition()<<endl;
}
