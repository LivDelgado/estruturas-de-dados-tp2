#include "sort/mergeSort.hpp"

using namespace sort;

MergeSort::MergeSort() {}

MergeSort::~MergeSort() {}

returnToEarth::Planet* MergeSort::sort(returnToEarth::Planet* list, int numberOfLinesToSort) {
    int i, j;

    returnToEarth::Planet* orderedList = list;
    returnToEarth::Planet aux;
    
    for (i = 1; i < numberOfLinesToSort; i++) {
        aux = orderedList[i];
        j = i - 1;
    
        while (
            (j >= 0) && 
            (aux.getDistanceFromEarth() > (&orderedList[j])->getDistanceFromEarth())
        ) {
            orderedList[j+1] = orderedList[j];
            j--;
        }
        orderedList[j+1] = aux;
    }

    return orderedList;
}
