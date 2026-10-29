// Final Project - CSCE 4110.001
// Elementary Sorts VS Advanced Sorts
// Emmanuel Rojas, Osa Ibie-Idusuyi, Agraj Gautam 

#include "sorts.h"  // all sorting algorithms
#include <iostream> // cin cout
#include <vector>   // vector, size, push_back
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
using namespace std;

/* PROTOTYPE FUNCTIONS */
void menu(); // menu
void verify(const vector<int>& a); // verification of sorts

/* MAIN */
int main(){

    // Variables
    int input; // user input
    int arrChoice; // which array to use the algorithm on.
    int n = 100; // for generating random number array (n elements; default = 100)
    int compCount; // comparisons || NOTE USE THESE TO RESET before 
    int swapCount; // swaps/shifts
    vector<int> fixedArr {2, 1, 4, 3, 6, 5, 8, 7, 10, 9}; // fixed array (10 elements)
    vector<int> randArr; // random array (n elements)

    srand(time(0)); // for random array

    // Set default for random array
    for (int i = 0; i < n; i++){
        randArr.push_back(rand() % (n + 1)); // random from 0 - 100
    }

    while(true){

        // Prompt main menu
        menu();
        cin >> input;

        // Validate input
        if (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid input, please enter a number." << endl;
            continue; // failure
        }

        // Choose selection
        switch (input){

            // 1) Display current arrays
            case 1: {

                // display
                cout << "\n---------  Current Arrays  ---------\n";
                cout << "Current fixed array: [ ";
                for (int i = 0; i < fixedArr.size(); i++){
                    cout << fixedArr[i] << " ";
                }
                cout << "]\n";
                cout << "Current n elements for random array: " << n << "\n";

                break; // success

            }

            // 2) Input new fixed array (user input)
            case 2: {

                // temp variables
                int element;
                vector<int> temp(10);
                bool failure = false;

                // prompt new array
                cout << "\n-------  Input new fixed array  -------\n";
                for (int i = 0; i < 10; i++){
                    cout << "Enter integer value for element " << i + 1 << ": ";
                    cin >> element; 

                    // validate input
                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "\nInvalid input, returning to menu. No changes made." << endl;
                        failure = true;
                        break; // failure
                    }

                    temp[i] = element;
                }

                // if valid
                if (!failure){

                    // change fixed array
                    fixedArr = temp;

                    // confirm change
                    cout << "New fixed array: [ ";
                    for (int i = 0; i < fixedArr.size(); i++){
                        cout << fixedArr[i] << " ";
                    }
                    cout << "]\n";
                }

                break; // success

            }

            // 3) Generate new array of random numbers 
            case 3: {

                // temp variables
                int number;
                vector<int> temp;

                // prompt new number
                cout << "\n----  Generate new random numbers  ----\n";
                cout << "Enter integer number of elements (under 10,000): ";
                cin >> number;

                // validate input
                if (cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "\nInvalid input, returning to menu. No changes made." << endl;
                    break; // failure
                }

                // between 0 - 10,000?
                if (number < 1 || number > 10000) {
                    cout << "\nInput out of range, returning to menu. No changes made.\n";
                    break; // failure
                }

                // change random array
                n = number;
                for (int i = 0; i < n; i++){
                    temp.push_back(rand() % (n + 1)); // random from 0 - new n + 1
                }
                randArr = temp;

                // confirm change
                cout << "New n elements for random array is now " << n << "\n";

                break; // success

            }

            // 4) Generate outputs for all algorithms
            case 4: {

                // fixed array or randomly generated array?
                cout << "\nWhich array would you like to use?\n"
                     << " 1. Fixed array\n"
                     << " 2. Randomly generated array (n elements)\n"
                     << "Enter Choice: ";
                cin >> arrChoice;

                // validate input
                if (cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "\nInvalid input, going back to menu." << endl;
                    break; // failure
                }

                switch (arrChoice){
                    
                    // a) fixed array
                    case 1: {

                        // output original order
                        cout << "\nSorting the fixed array: [ ";
                        for (int i = 0; i < fixedArr.size(); i++){
                            cout << fixedArr[i] << " ";
                        }
                        cout << "]\n";

                        // RESET ALL COUNTERS
                        compCount = 0;
                        swapCount = 0;
                        Sorts::resetMetrics();

                        // copy vectors for algorithms
                        vector<int> bubble = fixedArr;
                        vector<int> selection = fixedArr;
                        vector<int> insertion = fixedArr;
                        vector<int> merge = fixedArr;
                        vector<int> quick = fixedArr;

                        // Bubble Sort work
                        Sorts::bubbleSort(bubble, compCount, swapCount, false);
                        cout << "\n------  Bubble Sort Work  ------\n"
                             << "Comparisons = " << compCount
                             << "\nSwaps = " << swapCount
                             << "\n";
                        
                        // RESET for selection
                        compCount = 0;
                        swapCount = 0;

                        // Selection Sort work
                        Sorts::selectionSort(selection, compCount, swapCount, false);
                        cout << "\n-----  Selection Sort Work  -----\n"
                             << "Comparisons = " << compCount
                             << "\nSwaps = " << swapCount
                             << "\n";

                        // RESET for insertion
                        compCount = 0;
                        swapCount = 0;

                        // Insertion Sort work
                        Sorts::insertionSort(insertion, compCount, swapCount, false);
                        cout << "\n-----  Insertion Sort Work  -----\n"
                             << "Comparisons = " << compCount
                             << "\nSwaps = " << swapCount
                             << "\n";

                        // Merge Sort work
                        Sorts::mergeSort(merge, 0, (int)merge.size() - 1);
                        cout << "\n-------  Merge Sort Work  -------\n"
                             << "Comparisons = " << Sorts::getMergeComparisons()
                             << "\nSwaps = Merge does not use swaps"
                             << "\n";

                        // Quick Sort work
                        Sorts::quickSort(merge, 0, (int)merge.size() - 1);
                        cout << "\n-------  Quick Sort Work  -------\n"
                             << "Comparisons = " << Sorts::getQuickComparisons()
                             << "\nSwaps = " << Sorts::getQuickSwaps()
                             << "\n";

                        // output sorted array
                        cout << "\nSorted Array: [ ";
                        for (int i = 0; i < bubble.size(); i++){
                            cout << bubble[i] << " ";
                        }
                        cout << "]\n";

                        break; // success

                    }

                    // b) randomized array (n elements)
                    case 2: {

                        // Output n elements
                        cout << "\nSorting randomized array with " << n << " elements.\n";

                        // RESET ALL COUNTERS
                        compCount = 0;
                        swapCount = 0;
                        Sorts::resetMetrics();

                        // copy vectors for algorithms
                        vector<int> bubble = randArr;
                        vector<int> selection = randArr;
                        vector<int> insertion = randArr;
                        vector<int> merge = randArr;
                        vector<int> quick = randArr;

                        // Bubble Sort work
                        Sorts::bubbleSort(bubble, compCount, swapCount, false);
                        cout << "\n------  Bubble Sort Work  ------\n"
                             << "Comparisons = " << compCount
                             << "\nSwaps = " << swapCount
                             << "\n";
                        
                        // RESET for selection
                        compCount = 0;
                        swapCount = 0;

                        // Selection Sort work
                        Sorts::selectionSort(selection, compCount, swapCount, false);
                        cout << "\n-----  Selection Sort Work  -----\n"
                             << "Comparisons = " << compCount
                             << "\nSwaps = " << swapCount
                             << "\n";

                        // RESET for insertion
                        compCount = 0;
                        swapCount = 0;

                        // Insertion Sort work
                        Sorts::insertionSort(insertion, compCount, swapCount, false);
                        cout << "\n-----  Insertion Sort Work  -----\n"
                             << "Comparisons = " << compCount
                             << "\nSwaps = " << swapCount
                             << "\n";

                        // Merge Sort work
                        Sorts::mergeSort(merge, 0, (int)merge.size() - 1);
                        cout << "\n-------  Merge Sort Work  -------\n"
                             << "Comparisons = " << Sorts::getMergeComparisons()
                             << "\nSwaps = Merge does not use swaps"
                             << "\n";

                        // Quick Sort work
                        Sorts::quickSort(merge, 0, (int)merge.size() - 1);
                        cout << "\n-------  Quick Sort Work  -------\n"
                             << "Comparisons = " << Sorts::getQuickComparisons()
                             << "\nSwaps = " << Sorts::getQuickSwaps()
                             << "\n";

                             break; // success

                    }

                    // invalid input
                    default: {

                        cout << "\nInvalid input, please choose an option.\n";
                        break; // failure

                    }
                }

                break; // success

            }

            // 5) Correctness Check
            case 5: {

                // fixed array or randomly generated array?
                cout << "\nWhich array would you like to check correctness?\n"
                     << " 1. Fixed array\n"
                     << " 2. Randomly generated array (n elements)\n"
                     << "Enter Choice: ";
                cin >> arrChoice;

                // validate input
                if (cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "\nInvalid input, going back to menu." << endl;
                    break; // failure
                }

                switch (arrChoice){

                    // a) fixed array
                    case 1: {

                        // header
                        cout << "\n## CORRECTNESS CHECK ON FIXED ARRAY ##\n";

                        // RESET ALL COUNTERS (uneeded here, but included anyway)
                        compCount = 0;
                        swapCount = 0;
                        Sorts::resetMetrics();

                        // copy vectors for algorithms
                        vector<int> bubble = fixedArr;
                        vector<int> selection = fixedArr;
                        vector<int> insertion = fixedArr;
                        vector<int> merge = fixedArr;
                        vector<int> quick = fixedArr;

                        // Output algorithm checks
                        Sorts::bubbleSort(bubble, compCount, swapCount, true);
                        compCount = 0;
                        swapCount = 0;
                        Sorts::selectionSort(selection, compCount, swapCount, true);
                        compCount = 0;
                        swapCount = 0;
                        Sorts::insertionSort(insertion, compCount, swapCount, true);
                        Sorts::mergeCorrectness(merge, true);
                        Sorts::quickCorrectness(quick, true);
                        
                        break; // success

                    }

                    // b) randomized array (n elements)
                    case 2: {

                        // header
                        cout << "\n## CORRECTNESS CHECK ON RANDOMIZED ARRAY ##\n";

                        // RESET ALL COUNTERS (uneeded here, but included anyway)
                        compCount = 0;
                        swapCount = 0;
                        Sorts::resetMetrics();

                        // copy vectors for algorithms
                        vector<int> bubble = fixedArr;
                        vector<int> selection = fixedArr;
                        vector<int> insertion = fixedArr;
                        vector<int> merge = fixedArr;
                        vector<int> quick = fixedArr;

                        // Output algorithm checks
                        Sorts::bubbleSort(bubble, compCount, swapCount, false);
                        cout << "\n-----  Bubble Correctness Check  -----\n"
                             << "Sorting " << n << " elements...\n"
                             << "Status: ";
                        verify(bubble);
                        cout << "---------------------------------------\n";

                        compCount = 0;
                        swapCount = 0;

                        Sorts::selectionSort(selection, compCount, swapCount, false);
                        cout << "\n----  Selection Correctness Check  ----\n"
                             << "Sorting " << n << " elements...\n"
                             << "Status: ";
                        verify(selection);
                        cout << "---------------------------------------\n";

                        compCount = 0;
                        swapCount = 0;

                        Sorts::insertionSort(insertion, compCount, swapCount, false);
                        cout << "\n----  Insertion Correctness Check  ----\n"
                             << "Sorting " << n << " elements...\n"
                             << "Status: ";
                        verify(insertion);
                        cout << "---------------------------------------\n";

                        Sorts::mergeCorrectness(merge, false);
                        cout << "\n------  Merge Correctness Check  ------\n"
                             << "Sorting " << n << " elements...\n"
                             << "Status: ";
                        verify(merge);
                        cout << "---------------------------------------\n";

                        Sorts::quickCorrectness(quick, false);
                        cout << "\n------  Quick Correctness Check  ------\n"
                             << "Sorting " << n << " elements...\n"
                             << "Status: ";
                        verify(quick);
                        cout << "---------------------------------------\n";

                        break; // success

                    }

                    // invalid input
                    default: {

                        cout << "\nInvalid input, please choose an option.\n";
                        break; // failure

                    }
                }

                break; // success

            }

            // 0) Exit
            case 0: {

                cout << "\nExiting program. Goodbye!\n";
                cout << "\n";
                return 0;

            }

            // Invalid input
            default: {

                cout << "\nInvalid input, please choose an option.\n";
                break; // failure

            }
        }
    }
}

/* FUNCTION DEFINITIONS */
// Display Menu
void menu(){

    cout << "\n===============  Menu  ===============\n"
         << " 1. View current arrays\n"
         << " 2. Input new fixed array\n"
         << " 3. Input n elements of random array\n"
         << " 4. Display all algorithm results\n"
         << " 5. Correctness check\n"
         << " 0. Exit program\n"
         << "======================================\n"
         << "Enter Choice: ";

}

// Verify sort (for n elements)
void verify(const vector<int>& a) {
    
    for (int i = 0; i < (int)a.size() - 1; i++) {
        
        if (a[i] > a[i + 1]) { // if previous element is larger, FAIL
            cout << "Not Sorted." << endl;
            return;
        }
    }
    // if success
    cout << "Successfully Sorted." << endl;
}