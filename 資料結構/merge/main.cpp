#include "merge.h"
#include <fstream>
#include <iostream>                                                                                                                                                                                        
#include <time.h>                                                                                                                                                                                          
#include <math.h>       
#include <cstring>
using namespace std;                                                                                                                                                                                       

int main(int argc, char** argv)
{

    int index=atoi(argv[1]);
    int size=pow(2, index); 
    double time=0; 


    //    cout<<number<<endl;
    int *arr= new int[size];

    for(int i=0;i<size;i++){
        arr[i]=rand()%(1000)+1;
    }

    auto arr_size = sizeof(arr) / sizeof(arr[0]);
    /*		cout << "Given array is \n";
            printArray(arr, number);
            cout<< endl;             
     */

    clock_t start,end;
    start=clock();
    mergeSort(arr, 0, size-1);
    end=clock();
    cout<<double(end-start)/CLOCKS_PER_SEC<<endl;

    /*		cout << "\nSorted array is \n";
            printArray(arr, arr_size);
     */
    //		cout<<endl;
    delete []arr;


    char *filename= new char[20];
    strcpy(filename, argv[2]);
    ofstream f;
    f.open("mergeresult.csv",ios_base::app);
    f << index << ",";
    f << size << ",";
    f << double(end-start)/CLOCKS_PER_SEC << endl;


    return 0;
}


