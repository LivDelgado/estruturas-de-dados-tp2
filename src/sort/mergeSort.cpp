#include "sort/mergeSort.hpp"

using namespace sort;

MergeSort::MergeSort() {}

MergeSort::~MergeSort() {}

returnToEarth::Planet* MergeSort::sort(returnToEarth::Planet* list, int numberOfLinesToSort) {
   return this->mergeSort(list, 0, numberOfLinesToSort-1);
}

returnToEarth::Planet* MergeSort::mergeSort(returnToEarth::Planet* list, int left, int right) {
    returnToEarth::Planet* orderedList = list;

    if (left < right) {
        int half = (left + right)/2;
        mergeSort(orderedList, left, half);
        mergeSort(orderedList, half+1, right);
        orderedList = this->merge(orderedList, left, half, right);
    }
    
    return orderedList;
}


returnToEarth::Planet* MergeSort::merge(returnToEarth::Planet* list, int left, int half, int right) {
    int numberOfElementsInLeftArray = half - left + 1;
    int numberOfElementsInRightArray = right - half;

    returnToEarth::Planet leftArray[numberOfElementsInLeftArray];
    returnToEarth::Planet rightArray[numberOfElementsInRightArray];
    returnToEarth::Planet* orderedList = new returnToEarth::Planet[numberOfElementsInLeftArray + numberOfElementsInRightArray];

    int i = 0;
    for (i = 0; i < numberOfElementsInLeftArray; i++) {
        leftArray[i] = list[left+i];
    }
    for (i = 0; i < numberOfElementsInRightArray; i++) {
        rightArray[i] = list[half + 1 + i];
    }

    i = 0;
    int j = 0;
    int k = 0;
    while (i < numberOfElementsInLeftArray && j < numberOfElementsInRightArray) {
        if (leftArray[i].getDistanceFromEarth() <= rightArray[j].getDistanceFromEarth()) {
            orderedList[k] = leftArray[i];
            i++;
        } else {
            orderedList[k] = rightArray[i];
            j++;
        }
        k++;
    }


    if (k < numberOfElementsInLeftArray + numberOfElementsInRightArray) {
        for (; i < numberOfElementsInLeftArray; i++) {
            orderedList[k] = leftArray[i];
            k++;
        }
        for (; j < numberOfElementsInRightArray; j++) {
            orderedList[k] = rightArray[j];
            k++;
        }
    }

    return orderedList;
}
