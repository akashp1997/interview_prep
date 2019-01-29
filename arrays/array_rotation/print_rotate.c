#include <stdio.h>

void print(int arr[], int n, int d) {
    int i=d;
    while(1) {
        printf("%d ", arr[i%n]);
        if(i%n==d-1) {
            break;
        }
        i++;
    }
    printf("\n");
}

int main() {
    int arr[] = {4,5,6,7,8,9,10,1,2,3};
    int n=sizeof(arr)/sizeof(int);
    print(arr, n, 3);
    return 0;
}
