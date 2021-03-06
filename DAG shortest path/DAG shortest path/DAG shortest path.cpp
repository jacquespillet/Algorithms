// DAG shortest path.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include "Tree.h"
#include "Vertex.h"
#include <list>
#include <utility>
#include <map>
	
typedef std::pair<Vertex*, Vertex*> Key;
typedef std::map< Key, int> Mapa;
Mapa distances;

Vertex* initVertices() {
	Vertex* vertices = new Vertex[7];

	for (int i = 0; i < 7; i++) {
		Vertex vert;
		vert.number = i;
		vertices[i] = vert;
	}

	//0 to 1
	vertices[0].adjacents.push_back(&vertices[1]);
	distances[std::make_pair(&vertices[0], &vertices[1])] = 3;

	//0 to 2
	vertices[0].adjacents.push_back(&vertices[2]);
	distances[std::pair<Vertex*, Vertex*>(&vertices[0], &vertices[2])] = 1;

	//1 to 3
	vertices[1].adjacents.push_back(&vertices[3]);
	distances[std::pair<Vertex*, Vertex*>(&vertices[1], &vertices[3])] = 2;
	
	//1 to 4
	vertices[1].adjacents.push_back(&vertices[4]);
	distances[std::pair<Vertex*, Vertex*>(&vertices[1], &vertices[4])] = 5;
	
	//3 to 6
	vertices[3].adjacents.push_back(&vertices[6]);
	distances[std::pair<Vertex*, Vertex*>(&vertices[3], &vertices[6])] = 3;
	
	//4 to 6
	vertices[4].adjacents.push_back(&vertices[6]);
	distances[std::pair<Vertex*, Vertex*>(&vertices[4], &vertices[6])] = 4;
	
	//2 to 5
	vertices[2].adjacents.push_back(&vertices[5]);
	distances[std::pair<Vertex*, Vertex*>(&vertices[2], &vertices[5])] = 2;
	
	//5 to 4
	vertices[5].adjacents.push_back(&vertices[4]);
	distances[std::pair<Vertex*, Vertex*>(&vertices[5], &vertices[4])] = 3;
	
	//5 to 6
	vertices[5].adjacents.push_back(&vertices[6]);
	distances[std::pair<Vertex*, Vertex*>(&vertices[5], &vertices[6])] = 5;


	return vertices;
}

int getDistance(Vertex* a, Vertex* b) {
	int distance = (distances[std::pair<Vertex*, Vertex*>(a, b)] == 0) ? distances[std::pair<Vertex*, Vertex*>(b, a)] : distances[std::pair<Vertex*, Vertex*>(a, b)];
	return distance;
}

int main()
{

	Tree tree;

	Vertex * vertices = initVertices();
	tree.vertices = vertices;
	tree.run();
	
	vertices[0].delta = 0;

	for (int i = 6; i >=0 ; i--) {
		Vertex* currentVertex = tree.topologicalSort[i];
		std::cout << currentVertex->number << std::endl;
		for (int j = 0; j < currentVertex->adjacents.size(); j++) {
			Vertex* otherVertex = tree.topologicalSort[i]->adjacents[j];
			int newDelta = currentVertex->delta + getDistance(currentVertex, otherVertex);
			if (newDelta < otherVertex->delta) {
				otherVertex->delta = newDelta;
			} 
		}
	}
	
	for (int i = 0; i < 7; i++) {
		std::cout << vertices[i].number << " : " << vertices[i].delta << std::endl;
	}

	system("pause");
    return 0;
}

