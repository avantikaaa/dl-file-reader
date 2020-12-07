#include "../headers/Edge.h"

Edge::Edge(int n1, int n2, double w){
	node1 = n1;
	node2 = n2;
	weight = w;
}

int Edge::getNode1(){
	return node1;
}

int Edge::getNode2(){
	return node2;
}

double Edge::getWeight(){
	return weight;
}