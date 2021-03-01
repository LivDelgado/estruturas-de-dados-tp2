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

		int pivot = partition(list, left, right); 

		if (pivot - 1 > left) { 
			stack[++top] = left; 
			stack[++top] = pivot - 1; 
		} 

		if (pivot + 1 < right) { 
			stack[++top] = pivot + 1; 
			stack[++top] = right;
		} 
	} 
}

void QuickSortOptimized::swap(returnToEarth::Planet* a, returnToEarth::Planet* b) {
	returnToEarth::Planet aux = *a;
	*a = *b;
	*b = aux;
} 

int QuickSortOptimized::partition(returnToEarth::Planet* list, int left, int right) {
	returnToEarth::Planet auxiliar = list[right];
	int i = (left - 1);

	for (int j = left; j <= right - 1; j++) {
		if (list[j].getDistanceFromEarth() >= auxiliar.getDistanceFromEarth()) {
			i++;
			swap(&list[i], &list[j]);
		}
	}

	swap(&list[i + 1], &list[right]);

	return (i+1);
}
