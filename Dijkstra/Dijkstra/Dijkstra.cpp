// Dijkstra.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

#include <stdlib.h>
#include <iostream>
#include "Tree.h"
#include "Vertex.h"
#include <list>
#include <utility>
#include <map>
#include <unordered_map>
#include <vector>

const int infinity = 10000;

typedef std::pair<Vertex*, Vertex*> Key;
typedef std::map< Key, int> Mapa;
Mapa distances;
int size = 5;

Vertex* initVertices() {
	Vertex* vertices = new Vertex[7];

	for (int i = 0; i < size; i++) {
		Vertex vert;
		vert.number = i;
		vertices[i] = vert;
	}

	//0 to 1
	vertices[0].adjacents.push_back(&vertices[1]);
	distances[std::make_pair(&vertices[0], &vertices[1])] = 10;

	//0 to 2
	vertices[0].adjacents.push_back(&vertices[2]);
	distances[std::pair<Vertex*, Vertex*>(&vertices[0], &vertices[2])] = 3;

	//1 to 2
	vertices[1].adjacents.push_back(&vertices[2]);
	distances[std::pair<Vertex*, Vertex*>(&vertices[1], &vertices[2])] = 1;


	//2 to 1
	vertices[2].adjacents.push_back(&vertices[1]);
	distances[std::pair<Vertex*, Vertex*>(&vertices[2], &vertices[1])] = 4;

	//1 to 3
	vertices[1].adjacents.push_back(&vertices[3]);
	distances[std::pair<Vertex*, Vertex*>(&vertices[1], &vertices[3])] = 2;

	//2 to 3
	vertices[2].adjacents.push_back(&vertices[3]);
	distances[std::pair<Vertex*, Vertex*>(&vertices[2], &vertices[3])] = 8;

	//2 to 4
	vertices[2].adjacents.push_back(&vertices[4]);
	distances[std::pair<Vertex*, Vertex*>(&vertices[2], &vertices[4])] = 2;

	//3 to 4
	vertices[3].adjacents.push_back(&vertices[4]);
	distances[std::pair<Vertex*, Vertex*>(&vertices[3], &vertices[4])] = 7;

	//4 to 3
	vertices[4].adjacents.push_back(&vertices[3]);
	distances[std::pair<Vertex*, Vertex*>(&vertices[4], &vertices[3])] = 9;


	return vertices;
}

int getDistance(Vertex* a, Vertex* b) {
	int distance = (distances[std::pair<Vertex*, Vertex*>(a, b)] == 0) ? distances[std::pair<Vertex*, Vertex*>(b, a)] : distances[std::pair<Vertex*, Vertex*>(a, b)];
	return distance;
}

Vertex* extractMin(std::vector<Vertex*> *toVisit) {

	int min = infinity;
	int minIndex = infinity;
	Vertex* minVertex = NULL;
	
	for (int i = 0; i < toVisit->size(); i++) {
		if (toVisit->at(i)->distance < min) {
			minVertex = toVisit->at(i);
			minIndex = i;
		}
	}
	toVisit->erase(toVisit->begin() + minIndex);
	return minVertex;
}



int main()
{
	Vertex* vertices = initVertices();
	std::vector<Vertex*> toVisit;
	std::vector<Vertex*> visited;

	int startIndex = 0;


	//Init toVisit
	for (int i = 0; i < size; i++) {
		if (i == startIndex) {
			vertices[i].distance = 0;
			toVisit.push_back(&vertices[i]);
		}
		else {
			vertices[i].distance = infinity;
			toVisit.push_back(&vertices[i]);
		}
	}

	//Dijkstra
	while (toVisit.size() != 0) {
		Vertex* U = extractMin(&toVisit);
		visited.push_back(U);

		for (int i = 0; i < U->adjacents.size(); i++) {
			Vertex* V = U->adjacents[i];
			int newDelta = U->distance + getDistance(U, V);
			if (newDelta < V->distance) {
				V->distance= newDelta;
			}
		}
	}


	//Print results
	for (int i = 0; i < size; i++) {
		std::cout << vertices[i].number << " : " << vertices[i].distance << std::endl;
	}


	system("pause");
    return 0;
}

