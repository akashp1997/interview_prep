#include <stdio.h>

int search(int arr[], int n, int ele) {
    //Fibonacci of m-1
    int fibM1 = 0;
    //Fibonacci of m-2
    int fibM2 = 1;
    //Fibonacci of m
    int fibM = fibM1+fibM2;
    while(fibM<n) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM1+fibM2;
    }
    int offset = -1;
    while(fibM>1) {
        int i = (offset+fibM2)>n?n:(offset+fibM2);
        if(arr[i]==ele) {
            return i;
        }
        else if(arr[i]>ele) {
            fibM = fibM2;
            fibM1 = fibM1-fibM2;
            fibM2 = fibM-fibM1;
        }
        else {
            fibM = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM-fibM1;
            offset = i;
        }
    }
    if(fibMMm1 && arr[offset+1]==ele)return offset+1;
    return -1;
}

int main() {
    int arr[] = {7, 17, 44, 67, 70, 70, 96, 101, 105, 120, 123, 128, 131, 135, 140, 143, 146, 156, 169, 177, 188, 189, 195, 204, 218, 219, 250, 250, 251, 252, 255, 270, 287, 305, 311, 313, 331, 337, 338, 365, 367, 368, 392, 404, 406, 408, 413, 432, 435, 443, 469, 473, 474, 485, 493, 515, 538, 542, 545, 545, 559, 562, 591, 612, 621, 627, 637, 666, 675, 722, 725, 732, 742, 797, 803, 807, 813, 814, 815, 820, 838, 841, 848, 856, 863, 868, 871, 871, 875, 875, 887, 891, 895, 901, 912, 917, 954, 963, 993, 995};
    int n = sizeof(arr)/sizeof(n);
    printf("%d\n", search(arr, n, 140));
    return 0;
}
