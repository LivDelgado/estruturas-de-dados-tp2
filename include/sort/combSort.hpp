#ifndef COMB
#define COMB

#include "return-to-earth/base.hpp"

namespace sort {
    class CombSort {
        private:
            int getNextGap(int gap);
            void swap(returnToEarth::Base* a, returnToEarth::Base* b);

        public:
            CombSort();
            ~CombSort();

            returnToEarth::Base* sort(returnToEarth::Base* list, int numberOfLinesToSort);
    };
}

#endif
