#ifndef Edge_h
#define Edge_h

class Edge{
private:
	int node1;
	int node2;
	double weight;

public:
	Edge(int n1, int n2, double w);
	int getNode1();
	int getNode2();
	double getWeight();
};

#endif