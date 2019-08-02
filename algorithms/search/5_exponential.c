#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int low, int high, int ele) {
    if(low<=high) {
        int mid = (low+high)/2;
        if(arr[mid]==ele) {
            return mid;
        }
        if(arr[mid]<ele) {
            return binarySearch(arr, mid+1, high, ele);
        }
        return binarySearch(arr, low, mid-1, ele);
    }
    return -1;
}

int search(int arr[], int n, int ele) {
    if(arr[0]==ele) {
        return 0;
    }
    int i=1;
    while(i<n && arr[i]<=ele) {
        i = i*2;
    }
    return binarySearch(arr, i/2, n>i?i:n, ele);
}

int main() {
    int arr[] = {7, 17, 44, 67, 70, 70, 96, 101, 105, 120, 123, 128, 131, 135, 140, 143, 146, 156, 169, 177, 188, 189, 195, 204, 218, 219, 250, 250, 251, 252, 255, 270, 287, 305, 311, 313, 331, 337, 338, 365, 367, 368, 392, 404, 406, 408, 413, 432, 435, 443, 469, 473, 474, 485, 493, 515, 538, 542, 545, 545, 559, 562, 591, 612, 621, 627, 637, 666, 675, 722, 725, 732, 742, 797, 803, 807, 813, 814, 815, 820, 838, 841, 848, 856, 863, 868, 871, 871, 875, 875, 887, 891, 895, 901, 912, 917, 954, 963, 993, 995};
    int n = sizeof(arr)/sizeof(n);
    printf("%d", search(arr, n, 140));
    return 0;
}
