#ifndef MERGE
#define MERGE

#include "return-to-earth/planet.hpp"

namespace sort {
    class MergeSort {
        private:
            returnToEarth::Planet* mergeSort(returnToEarth::Planet* list, int left, int right);
            returnToEarth::Planet* merge(returnToEarth::Planet* list, int left, int middle, int right);

        public:
            MergeSort();
            ~MergeSort();

            returnToEarth::Planet* sort(returnToEarth::Planet* list, int numberOfLinesToSort);
    };
}

#endif
