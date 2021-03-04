#include "sort/quickSortOptimized.hpp"
#include "sort/combSort.hpp"

#define MAX_PARTITION_SIZE 20

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

    if ((right - left) < MAX_PARTITION_SIZE) {
        CombSort* sorter = new CombSort();
        sorter->sort(list, right-left);
        return;
    }

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
