// Final Project - CSCE 4110.001
// Sorts Class (contains all sorting algorithms)
// Emmanuel Rojas, Osa Ibie-Idusuyi, Agraj Gautam 

#include "Sorts.h"
using namespace std;

// Initialize
long long Sorts::quickSwaps = 0;
long long Sorts::quickComparisons = 0;
long long Sorts::mergeComparisons = 0;

// Reset Advanced Sort Counters
void Sorts::resetMetrics() {
    mergeComparisons = 0;
    quickComparisons = 0;
    quickSwaps = 0;
}

// Bubble Sort provided by Dr. Sayed Khushal Shah (Activity 3 tutorial)
void Sorts::bubbleSort(vector<int>& a, int& comparisons, int& swaps, bool correctness) {
    int n = a.size(); 

    // Correctness check: Before
    if (correctness) {
        cout << "\n-----  Bubble Correctness Check  -----\n";
        cout << "Original Array: ";
        for (int num : a) cout << num << " ";
        cout << "\n";
    }

    for (int pass = 0; pass < n - 1; pass++) { 
        bool swapped = false; 
        for (int j = 0; j < n - 1 - pass; j++) { 
            comparisons++; 
            if (a[j] > a[j + 1]) { 
                swap(a[j], a[j + 1]); 
                swaps++; 
                swapped = true; 
            } 
        } 
        if (!swapped) break; 
    } 

    // Correctness check: After
    if (correctness) {
        cout << "Resulted Array:  ";
        for (int num : a) cout << num << " ";
        cout << "\n---------------------------------------\n";
    }
}

// Selection Sort provided by Dr. Sayed Khushal Shah (Activity 3 tutorial)
void Sorts::selectionSort(vector<int>& a, int& comparisons, int& swaps, bool correctness) {
    int n = a.size(); 

    // Correctness check: Before
    if (correctness) {
        cout << "\n----  Selection Correctness Check  ----\n";
        cout << "Original Array: ";
        for (int num : a) cout << num << " ";
        cout << "\n";
    }

    for (int i = 0; i < n - 1; i++) { 
        int minIndex = i; 
        for (int j = i + 1; j < n; j++) { 
            comparisons++; 
            if (a[j] < a[minIndex]) minIndex = j; 
        } 
        if (minIndex != i) { 
            swap(a[i], a[minIndex]); 
            swaps++; 
        } 
    } 

    // Correctness check: After
    if (correctness) {
        cout << "Resulted Array:  ";
        for (int num : a) cout << num << " ";
        cout << "\n---------------------------------------\n";
    }
}

// Insertion Sort provided by Dr. Sayed Khushal Shah (Activity 3 tutorial)
void Sorts::insertionSort(vector<int>& a, int& comparisons, int& shifts, bool correctness) {
    
    // Correctness check: Before
    if (correctness) {
        cout << "\n----  Insertion Correctness Check  ----\n";
        cout << "Original Array: ";
        for (int num : a) cout << num << " ";
        cout << "\n";
    }
    
    for (int i = 1; i < a.size(); i++) { 
        int key = a[i]; 
        int j = i - 1; 
        while (j >= 0) { 
            comparisons++; 
            if (a[j] <= key) break; 
            a[j + 1] = a[j]; 
            shifts++; 
            j--; 
        } 
        a[j + 1] = key; 
    } 

    // Correctness check: After
    if (correctness) {
        cout << "Resulted Array: ";
        for (int num : a) cout << num << " ";
        cout << "\n---------------------------------------\n";
    }
}

// Merge Parts provided by Dr. Sayed Khushal Shah (Activity 4 tutorial)
void Sorts::merge(vector<int>& a, int left, int mid, int right) { 
    vector<int> temp; 
    int i = left, j = mid + 1; 
 
    while (i <= mid && j <= right) { 
        mergeComparisons++; 
        if (a[i] <= a[j]) temp.push_back(a[i++]); 
        else temp.push_back(a[j++]); 
    } 
    while (i <= mid) temp.push_back(a[i++]); 
    while (j <= right) temp.push_back(a[j++]); 
 
    for (int k = 0; k < (int)temp.size(); k++){
        a[left + k] = temp[k]; 
    }
} 

// Merge Sort provided by Dr. Sayed Khushal Shah (Activity 4 tutorial)
void Sorts::mergeSort(vector<int>& a, int left, int right) { 
    if (left >= right) return; 
    int mid = left + (right - left) / 2; 
    mergeSort(a, left, mid); 
    mergeSort(a, mid + 1, right); 
    merge(a, left, mid, right); 
}

// Merge Sort Correctness Check
void Sorts::mergeCorrectness(vector<int>& a, bool correctness) { 
    
    // Correctness check: Before
    if (correctness) {
        cout << "\n------  Merge Correctness Check  ------\n";
        cout << "Original Array: ";
        for (int num : a) cout << num << " ";
        cout << "\n";
    }

    // Verify
    if (!a.empty()) {
        mergeSort(a, 0, a.size() - 1);
    }

    // Correctness check: After
    if (correctness) {
        cout << "Resulted Array: ";
        for (int num : a) cout << num << " ";
        cout << "\n---------------------------------------\n";
    }
}

// Partiton Arrray provided by Dr. Sayed Khushal Shah (Activity 4 tutorial)
int Sorts::partition(vector<int>& a, int low, int high) { 
    int mid = low + (high - low) / 2; // middle element
    swap(a[mid], a[high]); // middle out of the way to end

    int pivot = a[high]; // middle is pivot
    int i = low - 1; 
 
    for (int j = low; j < high; j++) { 
        quickComparisons++; 
        if (a[j] <= pivot) { 
            i++; 
            swap(a[i], a[j]); 
            quickSwaps++; 
        } 
    } 
 
    swap(a[i + 1], a[high]); 
    quickSwaps++; 

    return i + 1; 
} 

// Quick Sort provided by Dr. Sayed Khushal Shah (Activity 4 tutorial)
void Sorts::quickSort(vector<int>& a, int low, int high) { 
    if (low < high) { 
        int p = partition(a, low, high); 
        quickSort(a, low, p - 1); 
        quickSort(a, p + 1, high); 
    } 
}

void Sorts::quickCorrectness(vector<int>& a, bool correctness) {
    
    // Correctness check: Before
    if (correctness) {
        cout << "\n------  Quick Correctness Check  ------\n";
        cout << "Original Array: ";
        for (int num : a) cout << num << " ";
        cout << "\n";
    }

    // Verify
    if (!a.empty()) {
        quickSort(a, 0, a.size() - 1);
    }

    // Correctness check: After
    if (correctness) {
        cout << "Resulted Array: ";
        for (int num : a) cout << num << " ";
        cout << "\n---------------------------------------\n";
    }
}