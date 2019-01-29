#include <stdio.h>

int pivot(int arr[], int n) {
    int low=0,high=n, mid;
    while(low<high) {
        mid = (low+high)/2;
        if(mid<high && arr[mid]>arr[mid+1]) {
            return mid;
        }
        if(mid>low && arr[mid]<arr[mid-1]) {
            return mid-1;
        }
        if(arr[mid]>arr[low]) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return -1;
}

int binarySearch(int arr[], int low, int high, int key) {
    if(high<low) return -1;
    int mid = (low+high)/2;
    if(arr[mid]==key) return mid;
    if(arr[mid]>key) return binarySearch(arr, low, mid-1, key);
    return binarySearch(arr, mid+1, high, key);
}

int pivotedBinarySearch(int arr[], int n, int key) {
    int p = pivot(arr, n);
    if(arr[p]==key) return p;
    if(arr[n-1]<key) {
        return binarySearch(arr, 0, p-1, key);
    }
    return binarySearch(arr, p+1, n, key);
}

int main() {
    int arr[] = {4,5,6,7,8,9,10,1,2,3};
    int n=sizeof(arr)/sizeof(int);
    printf("%d", pivotedBinarySearch(arr, n, 10));
    return 0;
}
