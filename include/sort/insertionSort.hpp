#ifndef INSERTION
#define INSERTION

#include "return-to-earth/base.hpp"

namespace sort {
    class InsertionSort {
        public:
            InsertionSort();
            ~InsertionSort();

            returnToEarth::Base* sort(returnToEarth::Base* list, int numberOfLinesToSort);
    };
}

#endif
