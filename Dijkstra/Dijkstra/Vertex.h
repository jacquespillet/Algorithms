#pragma once
#include<vector>
#include<list>
class Vertex
{
public:
	Vertex(){}
	~Vertex(){}
	std::vector<Vertex*> adjacents;
	int number;
	int delta = 10000;
	int distance = 10000;

private:
};

