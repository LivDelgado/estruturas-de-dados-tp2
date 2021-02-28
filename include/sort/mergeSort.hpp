#ifndef MERGE
#define MERGE

#include "return-to-earth/planet.hpp"

namespace sort {
    class MergeSort {
        public:
            MergeSort();
            ~MergeSort();

            returnToEarth::Planet* sort(returnToEarth::Planet* list, int numberOfLinesToSort);
    };
}

#endif
