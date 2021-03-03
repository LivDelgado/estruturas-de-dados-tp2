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
    int i;
    int j;
    partition(list, left, right, &i, &j);
    if (left < j) 
        quickSort(list, left, j);
    if (i < right)
        quickSort(list, i, right);
}

void QuickSort::partition(returnToEarth::Base* list, int left, int right, int *i, int *j) {
    returnToEarth::Base pivot;
    *i = left;
    *j = right;
    pivot = list[(*i + *j)/2];

    do {
        while (pivot.getDistanceFromEarth() < list[*i].getDistanceFromEarth()) (*i)++;
        while (pivot.getDistanceFromEarth() > list[*j].getDistanceFromEarth()) (*j)--;

        if (*i <= *j) {
            std::swap(list[*i], list[*j]);
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}
