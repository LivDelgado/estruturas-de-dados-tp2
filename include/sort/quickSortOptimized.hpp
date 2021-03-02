#ifndef FASTEST_QUICK
#define FASTEST_QUICK

#include "return-to-earth/planet.hpp"

namespace sort {
    class QuickSortOptimized {
        private:
            void quickSort(returnToEarth::Planet* list, int left, int right);
            int partition(returnToEarth::Planet* list, int l, int h);

        public:
            QuickSortOptimized();
            ~QuickSortOptimized();

            returnToEarth::Planet* sort(returnToEarth::Planet* list, int numberOfLinesToSort);
    };
}

#endif
