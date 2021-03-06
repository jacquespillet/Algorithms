// MergeSort.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include<iostream>
#include<stdlib.h>

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

void merge(int *a, int *b, int low, int mid, int high) {
	for (int i = low; i <= high; i++) {
		b[i] = a[i];
	}

	int i = low; int j = mid + 1;
	for (int k = low; k <= high; k++) {
		if (i > mid) a[k] = b[j++];
		else if (j > high) a[k] = b[i++];
		else if (b[j] < b[i]) a[k] = b[j++];
		else a[k] = b[i++];
	}
}

void sort(int *a, int *b, int low, int high) {
	if (high <= low) return;

	int mid = low + (high - low) / 2;

	sort(a, b, low, mid);
	sort(a, b, mid + 1, high);
	merge(a, b, low, mid, high);
}

void printArray(int* elements) {
	for (int i = 0; i < size; i++) {
		std::cout << elements[i] << "  ";
	}
	std::cout << std::endl;
}

int main()
{
	int *elements = new int[size];
	int *aux = new int[size];

	createArray(elements);
	sort(elements, aux, 0, size - 1);
	printArray(elements);

	system("pause");
    return 0;
}

