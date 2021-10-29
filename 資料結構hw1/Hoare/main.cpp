#include <cstdlib>
#include <iostream>
#include <math.h>
#include <time.h>
#include "hoare.h"                                                                                                                                                                                         
#include <fstream>
#include <cstring>
using namespace std;


int main(int argc, char** argv)
{

    int index=atoi(argv[1]);
    int size=pow(2, index); 
    double time=0; 


    int *arr= new int[size];
    for(int i=0;i<size;i++){
        arr[i]=rand()%(1000)+1;
    }

    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    clock_t start,end;
    start=clock();
    quickSort(arr,0,size-1);
    end=clock();
    cout<<double(end-start)/CLOCKS_PER_SEC<<endl;

    /*      cout << "\nSorted array is \n";
            printArray(arr, arr_size);
     */
    //      cout<<endl;
    delete []arr;


    char *filename= new char[20];
    strcpy(filename, argv[2]);
    ofstream f;
    f.open("hoareresult.csv",ios_base::app);
    f << index << ",";
    f << size << ",";
    f << double(end-start)/CLOCKS_PER_SEC << endl;


    return 0;
}


