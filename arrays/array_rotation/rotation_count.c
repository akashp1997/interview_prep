#include <stdio.h>

int pivot(int arr[], int low, int high) {
    if(low>high) return -1;
    if(low==high) return low;
    int mid = (low+high)/2;
    if(mid<high && arr[mid]>arr[mid+1]) {
        return mid;
    }
    if(mid>low && arr[mid]<arr[mid-1]) {
        return mid-1;
    }
    if(arr[low]<arr[mid]) {
        return pivot(arr, mid+1, high);
    }
    return pivot(arr, low, mid-1);
}

int main() {
    int arr[] = {4,5,6,7,8,9,10,1,2,3};
    int n=sizeof(arr)/sizeof(int);
    printf("%d\n", pivot(arr, 0, n)+1);
    return 0;
}
