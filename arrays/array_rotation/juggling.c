#include <stdio.h>

int gcd(int a, int b) {
    if(a==0) {
        return b;
    }
    return gcd(b%a, a);
}

void rotate(int arr[], int n, int d) {
    if(d==0 || d==n) return;
    int g = gcd(n,d);
    for(int i=0;i<g;i++) {
        int temp = arr[i];
        int j = i;
        while(1) {
            int k = j+d;
            if(k>=n) {
                k = k-n;
            }
            if(k==i) {
                break;
            }
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

int main() {
    int n=8, d=5;
    int arr[] = {1,2,3,4,5,6,7,8};
    rotate(arr,n,d);
    for(int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
