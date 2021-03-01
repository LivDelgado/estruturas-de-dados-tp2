#ifndef PERFORMANCE
#define PERFORMANCE

#include "sort/insertionSort.hpp"
#include "sort/mergeSort.hpp"
#include "sort/quickSort.hpp"
#include "sort/quickSortOptimized.hpp"
#include "sort/combSort.hpp"

#include "return-to-earth/planet.hpp"

namespace sort {
    class PerformanceMeasure {
        private:
            void measurePerformanceInsertionSort(returnToEarth::Planet* list, int numberOfLinesToSort);
            void measurePerformanceMergeSort(returnToEarth::Planet* list, int numberOfLinesToSort);
            void measurePerformanceQuickSort(returnToEarth::Planet* list, int numberOfLinesToSort);
            void measurePerformanceQuickSortOptimized(returnToEarth::Planet* list, int numberOfLinesToSort);
            void measurePerformanceCombSort(returnToEarth::Planet* list, int numberOfLinesToSort);

        public:
            void measurePerformanceForAllCases(returnToEarth::Planet* list);
            void measurePerformance(returnToEarth::Planet* list, int numberOfLinesToSort);
    };
}

#endif
