#include <stdio.h>

int missing(int arr[], int n) {
    int sum = 0;
    int expsum = 1;
    for(int i=0;i<n;i++) {
        expsum = expsum ^ (i+2);
        sum = sum ^ arr[i];
    }
    return expsum^sum;
}

int main() {
    int a[] = {1,2,4,5,6};
    printf("%d\n", missing(a,5));
    return 0;
}
