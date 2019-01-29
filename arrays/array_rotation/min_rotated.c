#include <stdio.h>

int pivot(int arr[], int low, int high) {
    if(high<low) return -1;
    if(low==high) return arr[low];
    int mid = (low+high)/2;
    if(mid<high && arr[mid]>arr[mid+1]) return arr[mid+1];
    if(mid>low && arr[mid]<arr[mid-1]) return arr[mid];
    if(arr[low]>=arr[mid]) return pivot(arr, 0, mid-1);
    return pivot(arr, mid+1, high);
}

int main() {
    int arr[] = {4,5,6,7,8,9,10,1,2,3};
    int n=sizeof(arr)/sizeof(int);
    printf("%d\n", pivot(arr, 0, n));
    return 0;
}
