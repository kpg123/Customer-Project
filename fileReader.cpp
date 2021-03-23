#include<iostream>
#include<vector>
#include<fstream>
#include"fileReader.h"

using namespace std;

fileReader::fileReader(){
	file = "default.txt";
	myfile.open(file);
	outputName = "output.txt";
}
fileReader::fileReader(string _file,string output){
	file = _file;
	myfile.open(file);
	outputName = output;
}
vector<string> fileReader::getInstruction(){
	string line;
	vector<string> instructions;
	while(getline(myfile,line)){
		instructions.push_back(line);
	}
	myfile.close();
	return instructions;
}
void fileReader::outputToFile(vector<string> output){
	outputFile.open(outputName);
	for(unsigned long i = 0; i < output.size(); i++){
		outputFile << output.at(i) << "\n";
	}
	outputFile.close();
}
