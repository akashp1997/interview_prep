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
    return pivot(arr, 0, mid-1);
}

int isPairSum(int arr[], int n, int sum) {
    int p = pivot(arr, 0, n);
    int i=p,j=p+1;
    while(j!=p) {
        if(i==j) return 0;
        if(j==n) j=0;
        if(i==0) i=n-1;
        if(arr[i]+arr[j]==sum) return 1;
        if(arr[i]+arr[j]>sum) i--;
        if(arr[i]+arr[j]<sum) j++;
    }
    return 0;
}

int main() {
    int arr[] = {4,5,6,7,8,9,10,1,2,3};
    int n=sizeof(arr)/sizeof(int);
    printf("%d\n", isPairSum(arr, n, 2));
    return 0;
}
