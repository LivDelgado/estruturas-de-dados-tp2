#ifndef COMB
#define COMB

#include "return-to-earth/planet.hpp"

namespace sort {
    class CombSort {
        private:
            int getNextGap(int gap);
            void swap(returnToEarth::Planet* a, returnToEarth::Planet* b);

        public:
            CombSort();
            ~CombSort();

            returnToEarth::Planet* sort(returnToEarth::Planet* list, int numberOfLinesToSort);
    };
}

#endif
