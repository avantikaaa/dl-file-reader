#include "../headers/dlFile.h"
#include <bits/stdc++.h>

using namespace std;

dlFile::dlFile(){
	//FileReader();
	;
}

//Instead of changing the degree, another array is used to index the degree which in turn is sorted on the basis of the corresponding degree
void dlFile::merge(int* rank, int left, int mid, int right){
	int l = left;
	int r = mid + 1;
	int n = right - left + 1;
	int tmp[n];

	int i = 0;
	while(l <= mid && r <= right){
		if(degree[rank[l]] > degree[rank[r]]){
			tmp[i] = rank[l];
			l++;
		}
		else{
			tmp[i] = rank[r];
			r++;
		}
		i++;
	}

	while(l <= mid){
		tmp[i] = rank[l];
		i++;
		l++;
	}
	while(r <= right){
		tmp[i] = rank[r];
		i++;
		r++;
	}

	for(i = 0; i < n; i++){
		rank[left + i] = tmp[i];
	}

	return;
}

void dlFile::mergeSort(int rank[], int left, int right){
	if(left >= right){
		return;
	}
	int mid = (left + right) / 2;
	mergeSort(rank, left, mid);
	mergeSort(rank, mid+1, right);
	merge(rank, left, mid, right);
}

int toInt(string n){
	stringstream convert(n);
	int tmp;
	convert >> tmp;
	if(convert.eof() && !convert.fail() && tmp >= 0){
		return tmp;
	}
	return -1;
}

bool dlFile::inputFile(ifstream& fin){
	if(fin.fail()){
		return false;
	}

	//process file.
	string line;

	//read "dl"
	getline(fin, line);
	//read "format=edgeList"
	getline(fin, line);

	//read "n=some integer"
	getline(fin, line);
	line += "=";
	string delimiter = "=";
	size_t pos = 0;
	// reads n
	pos = line.find(delimiter);
	line.erase(0, pos + delimiter.length());

	//read totalNodes
	pos = line.find(delimiter);
	totalNodes = toInt(line.substr(0, pos));

	degree = new double[totalNodes];

	//read labels
	getline(fin, line);
	getline(fin, labels);

	//read "data:"
	getline(fin, line);

	//read edges
	while(getline(fin, line)){
		line += " ";
		pos = 0;
		delimiter = " ";
		//node 1
		pos = line.find(delimiter);
		int n1 = toInt(line.substr(0, pos));
		line.erase(0, pos + delimiter.length());

		//node 2
		pos = line.find(delimiter);
		int n2 = toInt(line.substr(0, pos));
		line.erase(0, pos + delimiter.length());

		pos = line.find(delimiter);

		//weight of the edge
		stringstream convert(line.substr(0, pos));
		double w;
		convert >> w;

		edgeList.push_back(Edge(n1-1, n2-1, w));

		degree[n1-1] += w;
		degree[n2-1] += w;
	}

	return true;
}

bool dlFile::outputFile(ofstream& fout){
	int rank[totalNodes];
	for(int i = 0; i < totalNodes; i++){
		rank[i] = i;
	}

	//sort the nodes in descending order
	mergeSort(rank, 0, totalNodes - 1);
	//rank[i] = j => rank of j = i+1, or the node with 'i+1'th greatest degree is j

	int invRank[totalNodes];
	for(int i = 0; i < totalNodes; i++){
		invRank[rank[i]] = i;
	}
	// invRank[i] = j => rank of i = j

	//top part: following the format of the input
	fout << "dl" <<endl;
	fout << "format = edgelist1" <<endl;
	fout << "n=" << totalNodes <<endl;
	fout << "labels:" << endl;
	fout << labels << endl;
	fout << "data:" <<endl;


	//write back only the nodes with a rank < (total number of nodes) / 2
	int n = totalNodes / 2;
	for(int i = 0; i < edgeList.size(); i++){
		if(invRank[edgeList[i].getNode1()] < n && invRank[edgeList[i].getNode2()] < n){
			fout << edgeList[i].getNode1() << " " << edgeList[i].getNode2() << " " << edgeList[i].getWeight() << endl;
		}
	}

/*
TEST CODE TO MANUALLY CHECK THE VALIDITY OF OUTPUT
	string fileName;
//	cout << "Check output: ";
	cin >> fileName;
	ofstream file;
	file.open(fileName);

	for(int i = 0; i < totalNodes; i++){
		//file << i + 1 << "\t: " << degree[i] << "\t" << rank[i] << "\t" << invRank[i] << endl;
		file << rank[i] << "\t" << degree[rank[i]] << endl;
//		cout << invRank[i] << endl;
	}
	f.close()
*/

	return true;

}



dlFile::~dlFile(){
	delete[] degree;
}
