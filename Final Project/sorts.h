// Final Project - CSCE 4110.001
// Sorts Class Header (contains all sorting algorithms)
// Emmanuel Rojas, Osa Ibie-Idusuyi, Agraj Gautam 

#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <iostream>

class Sorts {
private:

    // Advanced Sort counters
    static long long mergeComparisons;
    static long long quickComparisons;
    static long long quickSwaps;

    // Merge Sort
    static void merge(std::vector<int>& a, int left, int mid, int right);
    static void mergeSort(std::vector<int>& a, int left, int right);

    // Quick Sort
    static int partition(std::vector<int>& a, int low, int high);
    static void quickSort(std::vector<int>& a, int low, int high);


public:
   
    // Bubble Sort
    static void bubbleSort(std::vector<int>& a, int& comparisons, int& swaps, bool correctness = false);

    // Selection Sort
    static void selectionSort(std::vector<int>& a, int& comparisons, int& swaps, bool correctness = false);

    // Insertion Sort
    static void insertionSort(std::vector<int>& a, int& comparisons, int& shifts, bool correctness = false);

    // Merge Sort extra functions
    static void mergeCorrectness(std::vector<int>& a, bool correctness = false); // correctness check
    static long long getMergeComparisons() {return mergeComparisons;} // get merge comparison count

    // Quick Sort extra functions
    static void quickCorrectness(std::vector<int>& a, bool correctness = false); // correctness check
    static long long getQuickComparisons() { return quickComparisons; } // get quick comparison count
    static long long getQuickSwaps() { return quickSwaps; } // get quick swap count

    // Reset Adv Sort Counters 
    static void resetMetrics(); // all back to 0
};

#endif