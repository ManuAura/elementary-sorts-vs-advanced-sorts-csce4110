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

/* MAIN */
int main(){

    // Variables
    int input; // user input
    int n = 100; // for generating random number array (n elements; default = 100)
    int compCount = 0; // comparisons || NOTE USE THESE TO RESET before 
    int swapCount = 0; // swaps/shifts
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
                    cout << "\nInvalid input, returning to menu. No changes made.\n" << endl;
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