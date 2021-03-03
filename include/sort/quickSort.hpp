#ifndef QUICK
#define QUICK

#include "return-to-earth/base.hpp"

namespace sort {
    class QuickSort {
        private:
            void quickSort(returnToEarth::Base* list, int left, int right);
            int partition(returnToEarth::Base* list, int left, int right);

        public:
            QuickSort();
            ~QuickSort();

            returnToEarth::Base* sort(returnToEarth::Base* list, int numberOfLinesToSort);
    };
}

#endif
