#include "sort/mergeSort.hpp"

using namespace sort;

MergeSort::MergeSort() {}

MergeSort::~MergeSort() {}

returnToEarth::Base* MergeSort::sort(returnToEarth::Base* list, int numberOfLinesToSort) {
   return this->mergeSort(list, 0, numberOfLinesToSort-1);
}

returnToEarth::Base* MergeSort::mergeSort(returnToEarth::Base* list, int left, int right) {
    returnToEarth::Base* orderedList = list;

    if (left < right) {
        int middle = (left + right)/2;
        mergeSort(orderedList, left, middle);
        mergeSort(orderedList, middle+1, right);
        this->merge(orderedList, left, middle, right);
    }
    
    return orderedList;
}


returnToEarth::Base* MergeSort::merge(returnToEarth::Base* list, int left, int middle, int right) {
    int numberOfElementsInLeftArray = middle - left + 1;
    int numberOfElementsInRightArray = right - middle;

    returnToEarth::Base leftArray[numberOfElementsInLeftArray];
    returnToEarth::Base rightArray[numberOfElementsInRightArray];

    for (int i = 0; i < numberOfElementsInLeftArray; i++) {
        leftArray[i] = list[left + i];
    }
    for (int j = 0; j < numberOfElementsInRightArray; j++) {
        rightArray[j] = list[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < numberOfElementsInLeftArray && j < numberOfElementsInRightArray) {
        if (leftArray[i].getDistanceFromEarth() >= rightArray[j].getDistanceFromEarth()) {
            list[k] = leftArray[i];
            i++;
        } else {
            list[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < numberOfElementsInLeftArray) {
        list[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < numberOfElementsInRightArray) {
        list[k] = rightArray[j];
        j++;
        k++;
    }

    return list;
}
