#ifndef FILEREADER_H
#define FILEREADER_H
#include<iostream>
#include<fstream>
#include<vector>

class fileReader{
	public:
		fileReader();
		fileReader(std::string _file,std::string output);
		std::vector<std::string> getInstruction();
		void outputToFile(std::vector<std::string> output);
	private:
		std::string file;
		std::ifstream myfile;
		std::string outputName;
		std::ofstream outputFile;

};

#endif
