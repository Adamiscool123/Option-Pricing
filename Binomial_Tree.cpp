#include <iostream>
#include <cmath>
#include <queue>

struct Node
{
	double value;

	Node *left;

	Node *right;

	Node(double stock_price)
	{
		value = stock_price;

		left = nullptr;

		right = nullptr;
	}
};

double call(double s, double k, double t, double r, double o, double N)
{
	double triangle_t = s / N;

	Node *root = new Node(s);

	std::queue<Node *> q;

	q.push(root);

	for (int i = 0; i < N; i++)
	{
		double u = std::exp(r * triangle_t);

		double d = 1 / u;

		u = s * u;

		d = s * d;

		Node *parent = q.front();
		q.pop();

		parent->left = new Node(d);
		q.push(parent->left);

		parent->right = new Node(u);
		q.push(parent->right);
	}

	for (int i = 0; i < N; i++)
	{
		
	}
}
