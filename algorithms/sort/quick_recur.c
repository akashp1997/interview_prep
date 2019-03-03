#include <stdio.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for(int j=low;j<high;j++) {
        if(arr[j]<=pivot) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}

void quickSort(int arr[], int low, int high) {
    if(low<high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int main() {
    clock_t t = clock();
    int arr[] = {901,545,538,101,868,863,189,637,70,17,612,542,473,912,305,797,177,140,887,954,338,311,814,218,807,803,891,413,875,485,188,856,562,270,627,143,559,963,621,995,219,250,820,443,252,156,70,44,67,406,871,666,120,287,435,313,337,742,493,146,732,123,365,515,895,841,368,96,251,404,838,367,432,255,392,250,128,469,7,993,169,195,545,135,917,331,675,813,875,815,725,131,408,474,105,871,204,591,722,848};
    int n = sizeof(arr)/sizeof(int);
    quickSort(arr, 0, n-1);
    printf("\n%f seconds\n", ((float)(clock()-t))/CLOCKS_PER_SEC);
    for(int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
