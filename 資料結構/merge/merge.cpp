// C++ program for Merge Sort
#include <iostream>
#include <time.h> 
#include <math.h>
#include "merge.h"
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[],int const left,int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new  int[subArrayOne],
    *rightArray = new  int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
         indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[],  int const begin,int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[],  int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

// Driver code
/*int main()
{

    int y;   
    cin >> y;
    int number=pow(2, y);
    double time=0; 
    cout<<number<<endl;
    for(int n=0;n<10;n++){  

        int *arr= new int[number];
        for(int i=0;i<number;i++){
            arr[i]=rand()%(1000)+1;
//            cout <<arr[i]<<",";

        }
//        cout <<endl;

        auto arr_size = sizeof(arr) / sizeof(arr[0]);
        cout << "Given array is \n";
        printArray(arr, number);
        cout<< endl;             

        clock_t start,end;


        start=clock();
        mergeSort(arr, 0, number-1);
        end=clock();
        time=time+(end-start);

        //    cout<<"a:"<<double(a)/CLOCKS_PER_SEC<<endl;
        //    cout<<"b:"<<double(b)/CLOCKS_PER_SEC<<endl;
        cout<<double(end-start)/CLOCKS_PER_SEC<<endl;


            cout << "\nSorted array is \n";
              printArray(arr, arr_size);
              cout<<endl;
         
        delete []arr;
    }
    cout<<endl;
    time=time/10;
    cout<<double(time)/CLOCKS_PER_SEC<<endl;

    return 0;
}
*/
