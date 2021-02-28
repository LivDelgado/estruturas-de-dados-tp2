#include "sort/quickSortOptimized.hpp"

using namespace sort;

QuickSortOptimized::QuickSortOptimized() {}

QuickSortOptimized::~QuickSortOptimized() {}

returnToEarth::Planet* QuickSortOptimized::sort(returnToEarth::Planet* list, int numberOfLinesToSort) {
    returnToEarth::Planet* orderedList = list;

    quickSort(list, 0, numberOfLinesToSort - 1);

    return orderedList;
}

void QuickSortOptimized::quickSort(returnToEarth::Planet* list, int left, int right) {
    int stack[right - left + 1]; 

	int top = -1; 

	stack[++top] = left; 
	stack[++top] = right; 

	while (top >= 0) {
		right = stack[top--]; 
		left = stack[top--]; 

		// Set pivot element at its correct position 
		// in sorted array 
		int pivot = partition(list, left, right); 

		// If there are elements on left side of pivot, 
		// then push left side to stack 
		if (pivot - 1 > left) { 
			stack[++top] = left; 
			stack[++top] = pivot - 1; 
		} 

		// If there are elements on right side of pivot, 
		// then push right side to stack 
		if (pivot + 1 < right) { 
			stack[++top] = pivot + 1; 
			stack[++top] = right;
		} 
	} 
}


void QuickSortOptimized::swap(returnToEarth::Planet* a, returnToEarth::Planet* b) { 
	returnToEarth::Planet t = *a; 
	*a = *b; 
	*b = t; 
} 

int QuickSortOptimized::partition(returnToEarth::Planet* list, int l, int h) { 
	returnToEarth::Planet x = list[h]; 
	int i = (l - 1); 

	for (int j = l; j <= h - 1; j++) { 
		if (list[j].getDistanceFromEarth() >= x.getDistanceFromEarth()) { 
			i++; 
			swap(&list[i], &list[j]); 
		} 
	} 
	swap(&list[i + 1], &list[h]); 

	return (i + 1); 
} 
