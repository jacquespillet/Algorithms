// Bubble Sort.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>

int size = 10;

void createArray(int* elements) {
	elements[0] = 2;
	elements[1] = 8;
	elements[2] = 15;
	elements[3] = 1;
	elements[4] = 10;
	elements[5] = 5;
	elements[6] = 19;
	elements[7] = 17;
	elements[8] = 3;
	elements[9] = 6;
}

void printArray(int* elements) {
	for (int i = 0; i < size; i++) {
		std::cout << elements[i] << "  ";
	}
	std::cout << std::endl;
}

void bubbleSort(int *elements) {
	int index = 0;
	while (true) {
		for (int i = 0; i < size-1; i++) {
			if (elements[i] > elements[i + 1]) {
				int tmp = elements[i];
				elements[i] = elements[i + 1];
				elements[i + 1] = tmp;
			}
			printArray(elements);
		}
		index++;

		if (index == size) {
			break;
		}
	}
}


int main()
{
	int *elements = new int[size];
	createArray(elements);
	printArray(elements);
	bubbleSort(elements);
	system("pause");
	return 0;
}

