#ifndef QUICK
#define QUICK

#include "return-to-earth/planet.hpp"

namespace sort {
    class QuickSort {
        private:
            void quickSort(returnToEarth::Planet* list, int left, int right);
            int partition(returnToEarth::Planet* list, int left, int right);

            void swap(returnToEarth::Planet* a, returnToEarth::Planet* b);

        public:
            QuickSort();
            ~QuickSort();

            returnToEarth::Planet* sort(returnToEarth::Planet* list, int numberOfLinesToSort);
    };
}

#endif
