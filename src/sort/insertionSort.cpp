#include "sort/insertionSort.hpp"

using namespace sort;

InsertionSort::InsertionSort() {}

InsertionSort::~InsertionSort() {}

returnToEarth::Base* InsertionSort::sort(returnToEarth::Base* list, int numberOfLinesToSort) {
    int i, j;

    returnToEarth::Base* orderedList = list;
    returnToEarth::Base aux;
    
    for (i = 1; i < numberOfLinesToSort; i++) {
        aux = orderedList[i];
        j = i - 1;
    
        while (
            (j >= 0) && 
            (aux.getDistanceFromEarth() >= (&orderedList[j])->getDistanceFromEarth())
        ) {
            orderedList[j+1] = orderedList[j];
            j--;
        }
        orderedList[j+1] = aux;
    }

    return orderedList;
}
