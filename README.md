# Elementary Sorts VS Advanced Sorts
CSCE 4110.001
Due Dec 1, 2026

## Team Members:
* Emmanuel Rojas
* Osa Ibie-Idusuyi
* Agraj Gautam

## Description:
The goal of this program is to allow the user to compare the elementary sorts (bubble, selection, insertion) with advanced sorts (merge, quick) and see how much work each one does with a fixed array or randomly generated array with n elements. The program also allows the user to input their arrays so they can compare different situations using a variety of options. 

## Features:
* A sorts class containing all the appropriate sorting algorithms we will be comparing: bubble, selection, insertion, merge, quick
* User input to allow the changes to the fixed array and randomly generated array using seperate vectors
* A menu to provide the user with all the options they may do wihtin the program via switch case and while loop.

## Menu Functions:
* Display current arrays (default arrays if not changed with user input)
* Input new fixed array
* Input new n for randomly generated array
* Display results for all Algorithms to compare
* Correctness check all algorithms with current arrays
* Exit

## Extra Notes:
* N/A

## How to run:
* Compile the ElemVsAdv.cpp file, make sure sorts.h and sorts.cpp are in the same folder:
* g++ ElemVsAdv.cpp sorts.cpp -o final
* Run executable
