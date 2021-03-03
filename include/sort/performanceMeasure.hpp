#ifndef PERFORMANCE
#define PERFORMANCE

#include "sort/insertionSort.hpp"
#include "sort/mergeSort.hpp"
#include "sort/quickSort.hpp"
#include "sort/quickSortOptimized.hpp"
#include "sort/combSort.hpp"

#include "return-to-earth/base.hpp"

namespace sort {
    class PerformanceMeasure {
        private:
            void measurePerformanceInsertionSort(returnToEarth::Base* list, int numberOfLinesToSort);
            void measurePerformanceMergeSort(returnToEarth::Base* list, int numberOfLinesToSort);
            void measurePerformanceQuickSort(returnToEarth::Base* list, int numberOfLinesToSort);
            void measurePerformanceQuickSortOptimized(returnToEarth::Base* list, int numberOfLinesToSort);
            void measurePerformanceCombSort(returnToEarth::Base* list, int numberOfLinesToSort);

        public:
            void measurePerformanceForAllCases(returnToEarth::Base* list);
            void measurePerformance(returnToEarth::Base* list, int numberOfLinesToSort);
    };
}

#endif
