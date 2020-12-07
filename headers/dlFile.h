#ifndef dlFile_h
#define dlFile_h

#include "FileReader.h"
#include "Edge.h"
#include <vector>
#include <string>

using namespace std;

class dlFile: public FileReader{
private:
	vector<Edge> edgeList;
	int totalNodes;
	double* degree;
	string labels;
	//int* rank;
	void merge(int* rank, int left, int mid, int right);
	void mergeSort(int* rank, int left, int right);

public:
	dlFile();
	bool inputFile(ifstream& fin);
	bool outputFile(ofstream& fout);
	~dlFile();
};


#endif