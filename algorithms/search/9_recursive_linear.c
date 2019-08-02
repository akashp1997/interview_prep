//Time: O(n)
//Space: O(n)

#include <stdio.h>

int search(int arr[], int low, int high, int ele) {
    if(low>high) return -1;
    if(arr[low]==ele) return low;
    return search(arr, low+1, high, ele);
}

int main(int argc, char const *argv[]) {
    int arr[] = {12, 34, 54, 2, 3}, i;
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    printf("%d\n", search(arr, 0, n, x));
    return 0;
}
