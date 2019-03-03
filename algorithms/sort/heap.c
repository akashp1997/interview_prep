#include <stdio.h>
#include <time.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*l+1;
    int r = 2*l+2;
    if(l<n && arr[l]>arr[largest]) {
        largest = l;
    }
    /*if(r<n && arr[r]>arr[largest]) {
        largest = r;
    }
    if(largest!=i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }*/
}

void heapSort(int arr[], int n) {
    for(int i=n/2-1;i>=0;i--) {
        heapify(arr, n, i);
    }
    /*for(int i=n-1;i>=0;i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }*/
}



int main() {
    clock_t t = clock();
    int arr[] = {901,545,538,101,868,863,189,637,70,17,612,542,473,912,305,797,177,140,887,954,338,311,814,218,807,803,891,413,875,485,188,856,562,270,627,143,559,963,621,995,219,250,820,443,252,156,70,44,67,406,871,666,120,287,435,313,337,742,493,146,732,123,365,515,895,841,368,96,251,404,838,367,432,255,392,250,128,469,7,993,169,195,545,135,917,331,675,813,875,815,725,131,408,474,105,871,204,591,722,848};
    int n = sizeof(arr)/sizeof(int);
    heapSort(arr, n);
    printf("\n%f seconds\n", ((float)(clock()-t))/CLOCKS_PER_SEC);
    for(int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
}
