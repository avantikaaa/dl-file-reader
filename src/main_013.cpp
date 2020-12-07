#include <iostream>
#include "../headers/dlFile.h"
#include <fstream>

using namespace std;

int main(){
	ifstream fin;
	string fileIn;
	string fileOut;

//	cout << "Input File Name: ";
	cin >> fileIn;
	fin.open(fileIn);
	
	ofstream fout;
//	cout << "Output File Name: ";
	cin >> fileOut;
	fout.open(fileOut);

	dlFile dl;
	if(dl.inputFile(fin)){
		dl.outputFile(fout);
	}
	fin.close();
	fout.close();

	return 0;
}