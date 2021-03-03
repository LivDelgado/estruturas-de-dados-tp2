#ifndef MERGE
#define MERGE

#include "return-to-earth/base.hpp"

namespace sort {
    class MergeSort {
        private:
            returnToEarth::Base* mergeSort(returnToEarth::Base* list, int left, int right);
            returnToEarth::Base* merge(returnToEarth::Base* list, int left, int middle, int right);

        public:
            MergeSort();
            ~MergeSort();

            returnToEarth::Base* sort(returnToEarth::Base* list, int numberOfLinesToSort);
    };
}

#endif
