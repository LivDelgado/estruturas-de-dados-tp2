#include "sort/quickSortOptimized.hpp"
#include "sort/combSort.hpp"

using namespace sort;

QuickSortOptimized::QuickSortOptimized() {}

QuickSortOptimized::~QuickSortOptimized() {}

returnToEarth::Base* QuickSortOptimized::sort(returnToEarth::Base* list, int numberOfLinesToSort) {
    returnToEarth::Base* orderedList = list;
    quickSort(list, 0, numberOfLinesToSort - 1);
    return orderedList;
}


void QuickSortOptimized::quickSort(returnToEarth::Base* list, int left, int right) {
    int i;
    int j;

    partition(list, left, right, &i, &j);
    if (left < j) 
        quickSort(list, left, j);
    if (i < right)
        quickSort(list, i, right);
}


void QuickSortOptimized::partition(returnToEarth::Base* list, int left, int right, int *i, int *j) {
    returnToEarth::Base pivot;
    *i = left;
    *j = right;
    pivot = getPivot(list, *i, *j);

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

returnToEarth::Base QuickSortOptimized::getPivot(returnToEarth::Base* list, int left, int right) {
    int indexA = left;
    int indexB = (right-left)/2;
    int indexC = right-1;

    if (list[indexA].getDistanceFromEarth() > list[indexB].getDistanceFromEarth()) {
        if (list[indexB].getDistanceFromEarth() > list[indexC].getDistanceFromEarth()) 
            return list[indexB];
        if (list[indexC].getDistanceFromEarth() > list[indexA].getDistanceFromEarth())
            return list[indexA];
        return list[indexC];
    }
    if (list[indexA].getDistanceFromEarth() > list[indexC].getDistanceFromEarth()) 
        return list[indexA];
    if (list[indexB].getDistanceFromEarth() > list[indexC].getDistanceFromEarth())
        return list[indexC];
    
    return list[indexB];
}
