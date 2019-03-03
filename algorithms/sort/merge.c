#include <stdio.h>
#include <time.h>

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid-low+1;
    int n2 = high-mid;
    int l[n1], r[n2];
    for(int i=0;i<n1;i++) {
        l[i] = arr[low+i];
    }
    for(int j=0;j<n2;j++) {
        r[j] = arr[mid+1+j];
    }
    int i=0,j=0,k=low;
    while(i<n1 && j<n2) {
        if(l[i]<=r[j]) {
            arr[k] = l[i];
            i++;
        }
        else {
            arr[k] = r[j];
            j++;
        }
        k++;
    }
    while(i<n1) {
        arr[k] = l[i];
        i++;
        k++;
    }
    while(j<n2) {
        arr[k] = r[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int n) {
    for(int size=1;size<=n-1;size *= 2) {
        for(int low=0;low<n-1;low+=2*size) {
            int mid = low+size-1;
            int high = low+2*size-1>n-1?n-1:low+2*size-1;
            merge(arr, low, mid, high);
        }
    }
}

int main() {
    clock_t t = clock();
    int arr[] = {901,545,538,101,868,863,189,637,70,17,612,542,473,912,305,797,177,140,887,954,338,311,814,218,807,803,891,413,875,485,188,856,562,270,627,143,559,963,621,995,219,250,820,443,252,156,70,44,67,406,871,666,120,287,435,313,337,742,493,146,732,123,365,515,895,841,368,96,251,404,838,367,432,255,392,250,128,469,7,993,169,195,545,135,917,331,675,813,875,815,725,131,408,474,105,871,204,591,722,848};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr, n);
    printf("\n%f seconds\n", ((float)(clock()-t))/CLOCKS_PER_SEC);
    for(int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
