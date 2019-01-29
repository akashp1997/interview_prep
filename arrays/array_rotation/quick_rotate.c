#include <stdio.h>

void reverse(int arr[], int low, int high) {
    while(low<high) {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}

void rotate(int arr[], int n, int d) {
    d = d%n;
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);
}

void fun(int arr[], int n) {
    for(int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n=sizeof(arr)/sizeof(int);
    int rot[] = {1,3,4,6};
    int rotn = sizeof(rot)/sizeof(int);
    for(int i=0;i<rotn;i++) {
        rotate(arr, n, rot[i]);
        fun(arr, n);
        rotate(arr, n, n-rot[i]);
    }
    return 0;
}
