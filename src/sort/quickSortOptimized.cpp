#include "sort/quickSortOptimized.hpp"

using namespace sort;

QuickSortOptimized::QuickSortOptimized() {}

QuickSortOptimized::~QuickSortOptimized() {}

returnToEarth::Planet* QuickSortOptimized::sort(returnToEarth::Planet* list, int numberOfLinesToSort) {
    returnToEarth::Planet* orderedList = list;

    quickSort(list, 0, numberOfLinesToSort - 1);

    return orderedList;
}

void QuickSortOptimized::swap(returnToEarth::Planet* a, returnToEarth::Planet* b) {
	returnToEarth::Planet aux = *a;
	*a = *b;
	*b = aux;
} 

void QuickSortOptimized::quickSort(returnToEarth::Planet* list, int left, int right) {
    int pivot;

    if (left < right) {
        pivot = partition(list, left, right);
        quickSort(list, left, pivot-1);
        quickSort(list, pivot+1, right);
    }
}

int QuickSortOptimized::partition(returnToEarth::Planet* list, int left, int right) {
    returnToEarth::Planet pivot = list[(left+right)/2];
    int i = (left - 1);
 
    for (int j = left; j <= right - 1; j++) {
        if (list[j].getDistanceFromEarth() >= pivot.getDistanceFromEarth())
        {
            i++;
            swap(&list[i], &list[j]);
        }
    }
    swap(&list[i + 1], &list[right]);

    return (i + 1);
}