#include "sort/performanceMeasure.hpp"

#include <iostream>
#include <time.h>

#define NUMBER_OF_CASES 8

using namespace sort;

void PerformanceMeasure::measurePerformanceForAllCases(returnToEarth::Base* list) {
    int arrayOfLinesToCalculate [NUMBER_OF_CASES] = {100, 500, 1000, 5000, 10000, 50000, 100000, 200000};
    for (int i = 0; i < NUMBER_OF_CASES; i++) {
        this->measurePerformance(list, arrayOfLinesToCalculate[i]);
    }
}

void PerformanceMeasure::measurePerformance(returnToEarth::Base* list, int numberOfLinesToSort) {
    std::cout << "Para " << numberOfLinesToSort << " linhas: " << std::endl;
    this->measurePerformanceInsertionSort(list, numberOfLinesToSort);
    this->measurePerformanceMergeSort(list, numberOfLinesToSort);
    this->measurePerformanceQuickSort(list, numberOfLinesToSort);
    this->measurePerformanceQuickSortOptimized(list, numberOfLinesToSort);
    this->measurePerformanceCombSort(list, numberOfLinesToSort);
    std::cout << "----------------------------------------------" << std::endl;
}


void PerformanceMeasure::measurePerformanceInsertionSort(returnToEarth::Base* list, int numberOfLinesToSort) {
    clock_t t;
    InsertionSort* sorter = new InsertionSort();
    t = clock();
    sorter->sort(list, numberOfLinesToSort);
    t = clock() - t;

    std::cout << "Insertion sort: " << ((double)t)/((CLOCKS_PER_SEC/1000)) << std::endl;
}

void PerformanceMeasure::measurePerformanceMergeSort(returnToEarth::Base* list, int numberOfLinesToSort) {
    clock_t t;
    MergeSort* sorter = new MergeSort();
    t = clock();
    sorter->sort(list, numberOfLinesToSort);
    t = clock() - t;

    std::cout << "Merge sort: " << ((double)t)/((CLOCKS_PER_SEC/1000)) << std::endl;
}

void PerformanceMeasure::measurePerformanceQuickSort(returnToEarth::Base* list, int numberOfLinesToSort) {
    clock_t t;
    QuickSort* sorter = new QuickSort();
    t = clock();
    sorter->sort(list, numberOfLinesToSort);
    t = clock() - t;

    std::cout << "Quick sort: " << ((double)t)/((CLOCKS_PER_SEC/1000)) << std::endl;
}

void PerformanceMeasure::measurePerformanceQuickSortOptimized(returnToEarth::Base* list, int numberOfLinesToSort) {
    clock_t t;
    QuickSortOptimized* sorter = new QuickSortOptimized();
    t = clock();
    sorter->sort(list, numberOfLinesToSort);
    t = clock() - t;

    std::cout << "Quick sort adaptado: " << ((double)t)/((CLOCKS_PER_SEC/1000)) << std::endl;
}

void PerformanceMeasure::measurePerformanceCombSort(returnToEarth::Base* list, int numberOfLinesToSort) {
    clock_t t;
    CombSort* sorter = new CombSort();
    t = clock();
    sorter->sort(list, numberOfLinesToSort);
    t = clock() - t;

    std::cout << "Comb sort: " << ((double)t)/((CLOCKS_PER_SEC/1000)) << std::endl;
}

clock_t t;
