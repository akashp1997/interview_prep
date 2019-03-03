#include <stdio.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    for(int i=1;i<n;i++) {
        int j = i;
        while(j>0) {
            if(arr[j]<arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            j--;
        }
    }
}

int main() {
    clock_t t = clock();
    int arr[] = {901,545,538,101,868,863,189,637,70,17,612,542,473,912,305,797,177,140,887,954,338,311,814,218,807,803,891,413,875,485,188,856,562,270,627,143,559,963,621,995,219,250,820,443,252,156,70,44,67,406,871,666,120,287,435,313,337,742,493,146,732,123,365,515,895,841,368,96,251,404,838,367,432,255,392,250,128,469,7,993,169,195,545,135,917,331,675,813,875,815,725,131,408,474,105,871,204,591,722,848};
    int n = sizeof(arr)/sizeof(int);
    insertionSort(arr, n);
    for(int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n%f seconds\n", ((float)(clock()-t))/CLOCKS_PER_SEC);
    return 0;
}
