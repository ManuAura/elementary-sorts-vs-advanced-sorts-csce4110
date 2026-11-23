# Elementary Sorts VS Advanced Sorts
* CSCE 4110.001
* Due Dec 1, 2026

## Team Members:
* Emmanuel Rojas
* Osa Ibie-Idusuyi
* Agraj Gautam

## Description:
The goal of this program is to allow the user to compare the elementary sorts (bubble, selection, insertion) with advanced sorts (merge, quick) and see how much work each one does with a fixed array or randomly generated array with n elements. The program also allows the user to input their arrays so they can compare different situations using a variety of options.

## Project Structure

```text
project/
├── bin/
├── Final_Project/
│   ├── ElemVsAdv.cpp
│   ├── sorts.cpp
│   ├── sorts.h
│   ├── utils.cpp
│   ├── utils.h
│   ├── benchmark.cpp
│   └── benchmark.h
├── benchmark_results.csv
├── README.md
└── Makefile
```


## Features:
* A sorts class containing all the appropriate sorting algorithms we will be comparing: bubble, selection, insertion, merge, quick
* User input to allow the changes to the fixed array and randomly generated array using seperate vectors
* A menu to provide the user with all the options they may do wihtin the program via switch case and while loop.


## Sorting Algorithms

The project implements five sorting algorithms:

- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort

## Menu Functions

1. **Array Management**
   - Display current arrays.
   - Input a new fixed array.
   - Generate a random array by specifying its size (`n`).

2. **Sorting Algorithm Comparison**
   - Compare the results of all five sorting algorithms using the selected array.
   - Display performance metrics, including comparisons, swaps, and execution time where available.

3. **Correctness Verification**
   - Verify that all five sorting algorithms correctly sort the current arrays.

4. **Scalability Analysis**
   - Compare the performance of all five algorithms using randomly generated datasets of different sizes: 100, 1,000, and 10,000 elements.
   - Examine how comparisons, swaps, and execution time change as input size increases.
   - Export benchmark results to a CSV file for further analysis.

0. **Exit (0)**

## Extra Notes

- The scalability analysis generates separate random datasets for each input size and uses the same dataset when comparing the five algorithms at that size.
- Benchmark results are exported to `benchmark_results.csv`.
- The CSV file can be imported into Microsoft Excel to create charts and visualize algorithm performance as input size increases.
- Execution times are measured in microseconds.
- Benchmark measurements may vary depending on the computer and system load.


## How to Compile and Run

This project uses a Makefile to simplify compilation.

**Build the project:**

```bash
make
```

**Run the executable:**

```bash
./ElemVsAdv
```

**Build with AddressSanitizer and UndefinedBehaviorSanitizer:**

```bash
make debug
```

**Remove compiled files and the executable:**

```bash
make clean
```

Similarly, we can use g++ to compile the source files.

```bash
cd Final_Project
g++ *.cpp
```

To run the program:

Linux/MacOS
```bash
./a.out
```

Windows
```bash
a.exe
```

### Requirements

- C++17-compatible compiler (e.g., GCC or Clang).
- GNU Make.
- Terminal with ANSI color support.