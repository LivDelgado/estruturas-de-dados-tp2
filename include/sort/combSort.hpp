#ifndef COMB
#define COMB

#include "return-to-earth/base.hpp"

namespace sort {
    class CombSort {
        private:
            int getNextGap(int gap);

        public:
            CombSort();
            ~CombSort();

            returnToEarth::Base* sort(returnToEarth::Base* list, int numberOfLinesToSort);
    };
}

#endif
