#ifndef BINOMIAL_TREE_H
#define BINOMIAL_TREE_H

class Binomial_Tree
{
public:
	struct Node;
	double call(double, double, double, double, double, double);
	double put(double, double, double, double, double, double);
};

#endif
