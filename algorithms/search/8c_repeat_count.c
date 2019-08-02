//Time: O(logn)
//Space: O(1)

#include <stdio.h>
#include <stdlib.h>

int left(int arr[], int low, int high, int ele) {
    int mid;
    while(high-low>1) {
        mid = (low+high)/2;
        if(arr[mid]>=ele) high = mid;
        else low = mid;
    }
    return high;
}

int right(int arr[], int low, int high, int ele) {
    int mid;
    while(high-low>1) {
        mid = (low+high)/2;
        if(arr[mid]<=ele) low = mid;
        else high = mid;
    }
    return low;
}

int count(int arr[], int n, int ele) {
    //Start from -1 to n-1
    int l = left(arr, -1, n-1, ele);
    //Start from 0 to n
    int r = right(arr, 0, n, ele);
    return (arr[l]==ele && arr[r]==ele)?abs(r-l)+1:0;
}

int main(int argc, char const *argv[]) {
    int arr[] = {1,1,1,1,1,1,2,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(int);
    printf("%d\n", count(arr, n, 1));
    return 0;
}
