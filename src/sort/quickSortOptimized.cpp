#include "sort/quickSortOptimized.hpp"
#include "sort/combSort.hpp"

#define MAX_PARTITION_SIZE 20

using namespace sort;

QuickSortOptimized::QuickSortOptimized() {}

QuickSortOptimized::~QuickSortOptimized() {}

returnToEarth::Planet* QuickSortOptimized::sort(returnToEarth::Planet* list, int numberOfLinesToSort) {
    returnToEarth::Planet* orderedList = list;
    quickSort(list, 0, numberOfLinesToSort - 1);
    return orderedList;
}

void QuickSortOptimized::quickSort(returnToEarth::Planet* list, int left, int right) {
    while (left < right)
    {
        if ((right - left) < MAX_PARTITION_SIZE) {
            CombSort* sorter = new CombSort();
            sorter->sort(list, right);
            break;
        } else {
            int pivot = partition(list, left, right);
            if ((pivot - left) < (right - pivot)) {
                quickSort(list, left, pivot - 1);
                left = pivot + 1;
            } else {
                quickSort(list, pivot + 1, right);
                right = pivot - 1;
            }
        }
    }
}

int QuickSortOptimized::partition(returnToEarth::Planet* list, int left, int right) {
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