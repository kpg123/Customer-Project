#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include"fileReader.h"
#include"customer.h"
#include"jamTree.h"
#include"customerBST.h"
#include"binarySearch.cpp"
#include"item.h"

using namespace std;

int main(int argc, char** argv){

	//cout << argc <<endl;
	if(argc != 3) {
		cout << "Incorrect Input Format!\n"<<endl;
		return -1;
	}
	//cout << argv[1] << " " << argv[2] << endl;
	fileReader reader(argv[1],argv[2]);
	vector<customer*> deleted;
	vector<string> instructions = reader.getInstruction();
	//cout << instructions.at(0) << endl;
	vector<string> outputs;
	customerBST nameTree;
	jamTree JAMTree;
	for(unsigned long i = 0; i < instructions.size(); i++){
		string line = instructions.at(i);
		//cout << line << endl;
		vector<string> inputs;
		string parser;
		stringstream ss(line);
		while(ss >> parser){
			inputs.push_back(parser);
			//cout << inputs.at(0);
		}
	        //cout << inputs << endl;
		if(inputs.at(0) == "register"){
			customer* newCust = new customer(inputs.at(1),inputs.at(2),inputs.at(3));
			int x = nameTree.getLength();	
			nameTree.insert(newCust);
			deleted.push_back(newCust);
				if(x == nameTree.getLength()){
					outputs.push_back("user[" + inputs.at(1) + "] already registered ");
				} else {
					JAMTree.insert(newCust);
					outputs.push_back("user[" + inputs.at(1) + "] registered " + inputs.at(2) + " " + inputs.at(3));
				}
			//cout << outputs.at(0) << endl;
		} else if(inputs.at(0) == "update") {
			bool b = nameTree.changeName(inputs.at(1),inputs.at(2));
			if(b == true){
				outputs.push_back("user[" + inputs.at(1) + "] nickname updated to " + inputs.at(2));
			} else {
				outputs.push_back("user[" + inputs.at(1) + "] does not exist" );
			}
		} else if(inputs.at(0) == "buy") {
			std::vector<customer*> customers_;
			int posJamTree;
			//int posNameTree;
			//Get vector with customers
			customers_ = nameTree.getTree();
			//look through customerBST until User ID inputted is found and set this to
			//the position in the name Tree.
			//posNameTree = binarySearchString(nameTree.getTree(),inputs.at(1),nameTree.getLength());
			//Find the position of this customer in the jambucks Tree by calling get Position.
			//set as posJamTree
			//posJamTree = customers_[posNameTree]->getPosition();
			//customers_.at(posNameTree)->getPosition() << endl;
			customer* null = nameTree.getCustomer(inputs.at(1));
			if(null == nullptr){
				outputs.push_back("user[" + inputs.at(1) + "] does not exist" );
			} else {
				posJamTree = nameTree.getCustomer(inputs.at(1))->getPosition();
			///////posJamTree = customers_.at(posNameTree)->getPosition();
			//allow customer to buy whatever is inputted
			//customers_[posNameTree]->buy(stoi(inputs.at(3)), inputs.at(2));
			//Update customers location in JamTree based on amount of Jambucks.
				null->buy(stoi(inputs.at(3)),inputs.at(2));
				JAMTree.increaseKey(posJamTree);
				outputs.push_back("user[" + inputs.at(1) + "]" + " purchase of " + inputs.at(2) + " SUCCESSFUL!");
			}

		} else if(inputs.at(0) == "history") {
			//std::vector<customer*> customers_;
			//int posNameTree;
			//Get vector with customers
			//customers_ = JAMTree.getTree();
			//look through customerBST until User ID inputted is found and set this to
			//the posNameTree.
			//posNameTree = binarySearchString(nameTree.getTree(),inputs.at(1),nameTree.getLength());
			customer* null =  nameTree.getCustomer(inputs.at(1));
			if(null == nullptr){
				outputs.push_back("user[" + inputs.at(1) + "] does not exist" );
			} else {
				//posNameTree = null->getPosition();
				//cout << null->getPosition() << " " << customers_[null->getPosition()]->getPosition() << endl;
				vector<item> *hist = null->printHistory();//customers_[posNameTree]->printHistory();
				string str = "user[" + null->getID()+ "] purchase history => [ ";	
				if(hist != nullptr){
				for(unsigned int i = 0; i < hist->size();i++){
					string temp = hist->at(i).print();
					str += temp;
				}}
				outputs.push_back(str + "]");
			}
		} else if(inputs.at(0) == "report") {
			int x = stoi(inputs.at(1),nullptr,10);
			int jamAmount = JAMTree.report(x);
			//cout << jamAmount << " ";
			string temp = "#JAMBucks held by top " + inputs.at(1) + " users = ";
		       	temp+= to_string(jamAmount)+ " ";
			outputs.push_back(temp);
		} else if(inputs.at(0) == "surprise") {
			int y = stoi(inputs.at(1),nullptr,10);
			int x = stoi(inputs.at(3),nullptr,10);
			vector<customer*> surprised = JAMTree.surprise(y, inputs.at(2), x);
			string s = "Top " + inputs.at(1) + " users surprised with " + inputs.at(2) + " worth $" + inputs.at(3) + " ";
			for(unsigned int i = 0; i < surprised.size(); i++){
				s += surprised.at(i)->getName() + " ";
			}
			outputs.push_back(s);
		}
	}
	for(unsigned int i = 0; i < deleted.size();i++){
		delete deleted.at(i);
	}
	//cout << nameTree.getLength();
	//for(int i = 0; i < nameTree.getLength(); i++){cout << 1; nameTree.printAt(i);}
	//cout << outputs.at(0) << endl;
	reader.outputToFile(outputs);
}
