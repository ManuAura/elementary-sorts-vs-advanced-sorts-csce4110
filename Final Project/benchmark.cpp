
#include "benchmark.h"
#include "sorts.h"
#include "utils.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

namespace Benchmark {

    // Benchmark configuration
    const int TERMINAL_TRIALS = 3;
    const int CSV_TRIALS = 1;

    // Store results for one algorithm
    struct BenchmarkResult {
        string algorithm;
        int inputSize;
        long long comparisons;
        long long swaps;
        long long shifts;
        double executionTime;
    };

    // Generate random data
    vector<int> generateRandomData(int n) {

        vector<int> data;
        data.reserve(n);

        // Reproducible random data
        mt19937 generator(42 + n);
        uniform_int_distribution<int> distribution(0, n);

        for (int i = 0; i < n; i++) {
            data.push_back(distribution(generator));
        }

        return data;
    }

    // Calculate median execution time
    double calculateMedian(vector<double> times) {

        sort(times.begin(), times.end());

        int size = static_cast<int>(times.size());

        if (size % 2 == 0) {
            return (times[size / 2 - 1] + times[size / 2]) / 2.0;
        }

        return times[size / 2];
    }

    // Run one sorting algorithm
    BenchmarkResult runAlgorithm(
        const string& algorithm,
        const vector<int>& original,
        int trials
    ) {

        vector<double> executionTimes;

        long long comparisons = 0;
        long long swaps = -1;
        long long shifts = -1;

        for (int trial = 0; trial < trials; trial++) {

            // Each algorithm gets its own copy
            vector<int> data = original;

            int compCount = 0;
            int swapCount = 0;

            // Reset sorting metrics
            Sorts::resetMetrics();

            // Start timer
            chrono::steady_clock::time_point start =
                chrono::steady_clock::now();

            // Execute selected algorithm
            if (algorithm == "Bubble Sort") {

                Sorts::bubbleSort(
                    data, compCount, swapCount, false
                );

            }
            else if (algorithm == "Selection Sort") {

                Sorts::selectionSort(
                    data, compCount, swapCount, false
                );

            }
            else if (algorithm == "Insertion Sort") {

                Sorts::insertionSort(
                    data, compCount, swapCount, false
                );

            }
            else if (algorithm == "Merge Sort") {

                Sorts::mergeSort(
                    data, 0, static_cast<int>(data.size()) - 1
                );

            }
            else if (algorithm == "Quick Sort") {

                Sorts::quickSort(
                    data, 0, static_cast<int>(data.size()) - 1
                );

            }

            // Stop timer
            chrono::steady_clock::time_point end =
                chrono::steady_clock::now();

            chrono::duration<double, micro> elapsed = end - start;

            executionTimes.push_back(elapsed.count());

            // Capture metrics
            if (algorithm == "Bubble Sort") {
                comparisons = compCount;
                swaps = swapCount;
            }
            else if (algorithm == "Selection Sort") {
                comparisons = compCount;
                swaps = swapCount;
            }
            else if (algorithm == "Insertion Sort") {
                comparisons = compCount;
                shifts = swapCount;
            }
            else if (algorithm == "Merge Sort") {
                comparisons = Sorts::getMergeComparisons();
            }
            else if (algorithm == "Quick Sort") {
                comparisons = Sorts::getQuickComparisons();
                swaps = Sorts::getQuickSwaps();
            }
        }

        BenchmarkResult result;

        result.algorithm = algorithm;
        result.inputSize = static_cast<int>(original.size());
        result.comparisons = comparisons;
        result.swaps = swaps;
        result.shifts = shifts;
        result.executionTime = calculateMedian(executionTimes);

        return result;
    }

    

}
