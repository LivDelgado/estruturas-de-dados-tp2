#ifndef QUICK_NEW
#define QUICK_NEW

#include "return-to-earth/base.hpp"

namespace sort {
    class QuickSort {
        private:
            void quickSort(returnToEarth::Base* list, int left, int right);
            void partition(returnToEarth::Base* list, int left, int right, int *i, int *j);

        public:
            QuickSort();
            ~QuickSort();

            returnToEarth::Base* sort(returnToEarth::Base* list, int numberOfLinesToSort);
    };
}

#endif
