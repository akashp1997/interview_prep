#include <stdio.h>

void reverse(int arr[], int l, int r) {
    while(l<r) {
        int temp = arr[l];
        arr[l] = arr[r-1];
        arr[r-1] = temp;
        l++;
        r--;
    }
}

void rotate(int arr[], int n, int d) {
    if(d==0 || d==n) return;
    reverse(arr, 0, d);
    reverse(arr, d, n);
    reverse(arr, 0, n);
}

int main() {
    int n=8,d=3;
    int arr[] = {1,2,3,4,5,6,7,8};
    rotate(arr, n, d);
    for(int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
