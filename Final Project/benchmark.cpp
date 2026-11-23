
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


    // Run all five algorithms for one input size
    vector<BenchmarkResult> benchmarkDataset(
        const vector<int>& data,
        int trials
    ) {

        vector<BenchmarkResult> results;

        results.push_back(runAlgorithm("Bubble Sort", data, trials));
        results.push_back(runAlgorithm("Selection Sort", data, trials));
        results.push_back(runAlgorithm("Insertion Sort", data, trials));
        results.push_back(runAlgorithm("Merge Sort", data, trials));
        results.push_back(runAlgorithm("Quick Sort", data, trials));

        return results;
    }




    // Print benchmark table
    void printResults(const vector<BenchmarkResult>& results) {

        Utils::setColor(Utils::Color::BRIGHT_CYAN);

        cout << left
             << setw(19) << "Algorithm"
             << right
             << setw(13) << "Comparisons"
             << setw(13) << "Swaps"
             << setw(13) << "Shifts"
             << setw(16) << "Time (us)"
             << "\n";

        cout << string(74, '-') << "\n";

        Utils::resetColor();

        for (const BenchmarkResult& result : results) {

            Utils::setColor(Utils::Color::BRIGHT_WHITE);

            cout << left << setw(19) << result.algorithm;

            Utils::setColor(Utils::Color::BRIGHT_YELLOW);

            cout << right
                 << setw(13) << result.comparisons;

            if (result.swaps >= 0) {
                cout << setw(13) << result.swaps;
            }
            else {
                cout << setw(13) << "N/A";
            }

            if (result.shifts >= 0) {
                cout << setw(13) << result.shifts;
            }
            else {
                cout << setw(13) << "N/A";
            }

            cout << setw(16) << fixed << setprecision(2)
                 << result.executionTime;

            cout << "\n";

            Utils::resetColor();
        }

        cout << string(74, '-') << "\n";
    }



    // Terminal comparison
    void compareAlgorithms() {

        Utils::clearScreen();

        Utils::printHeader("ALGORITHM SCALABILITY COMPARISON");

        const vector<int> inputSizes = {100, 1000, 10000};

        Utils::setColor(Utils::Color::BRIGHT_WHITE);
        cout << "Comparing five sorting algorithms using random datasets.\n";
        cout << "Trials per algorithm: " << TERMINAL_TRIALS << "\n";
        cout << "Execution time: Median of all trials.\n\n";
        Utils::resetColor();

        for (int n : inputSizes) {

            Utils::setColor(Utils::Color::BRIGHT_CYAN);

            cout << "\nINPUT SIZE: " << n << " ELEMENTS\n";
            cout << string(74, '=') << "\n";

            Utils::resetColor();

            vector<int> data = generateRandomData(n);

            vector<BenchmarkResult> results =
                benchmarkDataset(data, TERMINAL_TRIALS);

            printResults(results);
        }

        Utils::setColor(Utils::Color::BRIGHT_GREEN);
        cout << "\n[SUCCESS] Benchmark comparison completed.\n";
        Utils::resetColor();
    }



    

}
