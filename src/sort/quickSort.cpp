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
    int i, j;

    partition(list, left, right, &i, &j);
    if (left < j) {
        quickSort(list, left, j);
    }
    if (i < right) {
        quickSort(list, i, right);
    }
}

void QuickSort::partition(returnToEarth::Planet* list, int left, int right, int* i, int* j) {
    returnToEarth::Planet pivot;
    returnToEarth::Planet aux;

    *i = left;
    *j = right;

    int pivotPosition = (*i + *j)/2;
    pivot = list[pivotPosition];

    do {
        while (pivot.getDistanceFromEarth() <= list[*i].getDistanceFromEarth()) {
            (*i)++;
        }

        while (pivot.getDistanceFromEarth() >= list[*j].getDistanceFromEarth()) {
            (*j)--;
        }

        if (*i <= *j) {
            aux = list[*i];
            list[*i] = list[*j];
            list[*j] = aux;
            
            (*i)++;
            (*j)--;
        }
    } while(*i <= *j);
}
