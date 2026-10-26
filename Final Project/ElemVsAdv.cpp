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
        randArr.push_back(rand() % (n + 1)); // random from 0 - n
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
            continue;
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

                break;

            }

            // 2) Input new fixed array (user input)
            case 2: {

                // temp variables
                int element;
                vector<int> temp(10);

                // prompt new array
                cout << "\n------- Input new fixed array -------\n";
                for (int i = 0; i < 10; i++){
                    cout << "Enter integer value for element " << i + 1 << ": ";
                    cin >> element; 
                    temp[i] = element;
                }

                fixedArr = temp; // change fixed array

                // confirm change
                cout << "New fixed array: [ ";
                for (int i = 0; i < fixedArr.size(); i++){
                    cout << fixedArr[i] << " ";
                }
                cout << "]\n";

                break;

            }

            // 0) Exit
            case 0: {

                cout << "\nExiting program. Goodbye!\n";
                return 0;

            }

            // Invalid input
            default: {

                cout << "\nInvalid input, please choose an option.\n";
                break;

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