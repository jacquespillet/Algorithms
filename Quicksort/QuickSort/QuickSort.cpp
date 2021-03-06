// QuickSort.cpp : définit le point d'entrée pour l'application console.
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

int partition(int *elements, int low, int high) {
	int i = low, j = high + 1;

	while (true) {
		i++;
		while (elements[i] < elements[low]) {
			i++;
			if (i == high) break;
		}

		j--;
		while (elements[j] > elements[low]) {
			j--;
			if (j == low) break;
		}

		if (i >= j) break;

		int tmp = elements[i];
		elements[i] = elements[j];
		elements[j] = tmp;
		printArray(elements);
	}

	int tmp = elements[low];
	elements[low] = elements[j];
	elements[j] = tmp;
	return j;
}

void sort(int *elements, int low, int high) {
	if (high <= low) return;

	int j = partition(elements, low, high);
	printArray(elements);
	sort(elements, low, j - 1);
	sort(elements, j+1, high);
}

void quickSort(int *elements) {
	sort(elements, 0, size - 1);
}

int main()
{
	int *elements = new int[size];
	createArray(elements);
	quickSort(elements);
	printArray(elements);

	system("pause");
    return 0;
}

