#include <stdio.h>

void blockswap(int arr[], int startA, int startB, int n) {
    while(n-->0) {
        int temp = arr[startA];
        arr[startA] = arr[startB];
        arr[startB] = temp;
        startA++;
        startB++;
    }
}

void rotate(int arr[], int n, int d) {
    if(d==0 || d==n) return;
    //Block swap if arr[0..d-1]==arr[d..n-1]
    if(d==n-d) {
        blockswap(arr, 0, d, d);
        return;
    }
    if(d<n-d) {
        blockswap(arr, 0, n-d, d);
        rotate(arr, n-d, d);
    }
    else {
        blockswap(arr, 0, d, n-d);
        rotate(arr+n-d, d, 2*d-n);
    }
}

int main() {
    int n=8,d=5;
    int arr[] = {1,2,3,4,5,6,7,8};
    rotate(arr, n, d);
    for(int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
