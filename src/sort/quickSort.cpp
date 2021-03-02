#include "sort/quickSort.hpp"

using namespace sort;

QuickSort::QuickSort() {}

QuickSort::~QuickSort() {}

returnToEarth::Planet* QuickSort::sort(returnToEarth::Planet* list, int numberOfLinesToSort) {
    returnToEarth::Planet* orderedList = list;
    quickSort(list, 0, numberOfLinesToSort - 1);
    return orderedList;
}

void QuickSort::quickSort(returnToEarth::Planet* list, int left, int right) {
    if (left < right) {
        int pivot = partition(list, left, right);
        quickSort(list, left, pivot - 1);
        quickSort(list, pivot + 1, right);
    }
}

int QuickSort::partition(returnToEarth::Planet list[], int left, int right) {
    returnToEarth::Planet pivot = list[(right-left)/2];
    int p = left;
 
    for (int i = left; i < right; i++) {
        if (list[i].getDistanceFromEarth() >= pivot.getDistanceFromEarth()) {
            std::swap(list[i], list[p]);
            p++;
        }
    }

    std::swap(list[p], list[right]);

    return p;
}
