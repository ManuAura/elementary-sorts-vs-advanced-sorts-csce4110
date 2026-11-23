
#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <vector>
#include <string>

namespace Benchmark {

    // Display benchmark comparison in terminal
    void compareAlgorithms();

    // Export detailed benchmark results to CSV
    void exportBenchmarkCSV(
        const std::string& filename = "benchmark_results.csv"
    );

}

#endif
