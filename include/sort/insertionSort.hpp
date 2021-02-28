#ifndef INSERTION
#define INSERTION

#include "return-to-earth/listOfPlanets.hpp"

namespace sort {
    class InsertionSort {
        public:
            InsertionSort();
            ~InsertionSort();

            returnToEarth::Planet* sort(returnToEarth::Planet* list, int numberOfLinesToSort);
    };
}

#endif
