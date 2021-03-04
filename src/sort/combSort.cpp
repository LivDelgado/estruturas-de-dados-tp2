#include "sort/combSort.hpp"

using namespace sort;

CombSort::CombSort() {}

CombSort::~CombSort() {}

int CombSort::getNextGap(int gap) {
    gap = (gap*10)/13;
 
    if (gap < 1)
        gap = 1;
    return gap;
}

returnToEarth::Base* CombSort::sort(returnToEarth::Base* list, int numberOfLinesToSort) {
    int gap = numberOfLinesToSort;
    bool swapped = true;

    do {
        gap = getNextGap(gap);
        swapped = false;
 
        for (int i = 0; i < (numberOfLinesToSort - gap); i++) {
            if (list[i].getDistanceFromEarth() < list[i+gap].getDistanceFromEarth()){
                std::swap(list[i], list[i + gap]);
                swapped = true;
            }
        }
    } while (gap != 1 || swapped == true);

    return list;
}

