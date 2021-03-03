#include "sort/quickSort.hpp"

using namespace sort;

QuickSort::QuickSort() {}

QuickSort::~QuickSort() {}

returnToEarth::Base* QuickSort::sort(returnToEarth::Base* list, int numberOfLinesToSort) {
    returnToEarth::Base* orderedList = list;
    quickSort(list, 0, numberOfLinesToSort - 1);
    return orderedList;
}

void QuickSort::quickSort(returnToEarth::Base* list, int left, int right) {
    if (left < right) {
        int pivot = partition(list, left, right);
        quickSort(list, left, pivot - 1);
        quickSort(list, pivot + 1, right);
    }
}

int QuickSort::partition(returnToEarth::Base* list, int left, int right) {
    returnToEarth::Base pivot = list[(right-left)/2];
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
