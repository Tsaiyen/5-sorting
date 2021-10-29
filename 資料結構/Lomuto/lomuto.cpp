#include <cstdlib>
#include <iostream>
#include <math.h>
#include <time.h>
#include "lomuto.h"
using namespace std;

// This function takes last element
// as pivot, places
// the pivot element at its correct
// position in sorted array, and
// places all smaller (smaller than pivot)
// to left of pivot and all greater
// elements to right of pivot
int partition(int arr[], int low, int high)
{
    // pivot
    int pivot = arr[high];

    // Index of smaller element
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller
        // than or equal to pivot
        if (arr[j] <= pivot) {

            // increment index of
            // smaller element
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
int partition_r(int arr[], int low, int high)
{
    // Generate a random number in between
    // low .. high
    srand(time(NULL));
    int random = low + rand() % (high - low);

    // Swap A[random] with A[high]
    swap(arr[random], arr[high]);

    return partition(arr, low, high);
}

/* The main function that implements
   QuickSort
   arr[] --> Array to be sorted,
   low --> Starting index,
   high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high) {

        /* pi is partitioning index,
           arr[p] is now
           at right place */
        int pi = partition_r(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver Code
//int main(int argc,int **argv)
/*int main()
{
    int index;
    cin>> index;     
  //int index=atoi(argv[1]);
    
    int size=pow(2, index); 
//    int n = sizeof(arr) / sizeof(arr[0]);
    double time=0; 
    int *arr= new int[size];

    for(int i=0;i<size;i++){
        arr[i]=rand()%(1000)+1;
    }   

    clock_t start,end;
    start=clock();
    quickSort(arr, 0, size-1);
    end=clock();
    cout<<double(end-start)/CLOCKS_PER_SEC<<endl;

//    printf("Sorted array: \n");
//    printArray(arr, size); 
    delete []arr;


    char *filename= new char[20];
    strcpy(filename, argv[2]);
    ofstream f;
    f.open("mergeresult.csv",ios_base::app);
    f << index << ",";
    f << size << ",";
    f << double(end-start)/CLOCKS_PER_SEC << endl;


    	int arr[] = { 10, 7, 8, 9, 1, 5 };
        int n = sizeof(arr) / sizeof(arr[0]);
        clock
        quickSort(arr, 0, n - 1);
        printf("Sorted array: \n");
        printArray(arr, n);
     
    return 0;
}
*/

