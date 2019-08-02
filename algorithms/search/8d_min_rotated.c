#include <stdio.h>

int min(int arr[], int low, int high) {
    int mid;
    if(arr[low]<=arr[high]) {
        return low;
    }
    while(low<high) {
        mid = (low+high)/2;
        if(arr[mid]>=arr[high]) low = mid+1;
        else high = mid;
    }
    if(low==high) return low;
    return -1;
}

int main(int argc, char const *argv[]) {
    int arr[] = {3, 4, 5, 6, 1, 2};
    int n = sizeof(arr)/sizeof(int);
    printf("%d\n", min(arr, 0, n-1));
    return 0;
}
