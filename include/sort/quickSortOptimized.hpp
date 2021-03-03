#ifndef FASTEST_QUICK
#define FASTEST_QUICK

#include "return-to-earth/base.hpp"

namespace sort {
    class QuickSortOptimized {
        private:
            void quickSort(returnToEarth::Base* list, int left, int right);
            void partition(returnToEarth::Base* list, int left, int right, int *i, int *j);
            returnToEarth::Base getPivot(returnToEarth::Base* list, int left, int right);

        public:
            QuickSortOptimized();
            ~QuickSortOptimized();

            returnToEarth::Base* sort(returnToEarth::Base* list, int numberOfLinesToSort);
    };
}

#endif
