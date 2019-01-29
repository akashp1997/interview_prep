#include <stdio.h>

int gcd(int a, int b) {
    if(a==0) return b;
    return gcd(b%a, a);
}

void rotate(int arr[], int n, int d) {
    if(d<0) d=n+d;
    if(d==0 || d==n) return;
    for(int i=0;i<gcd(n,d);i++) {
        int temp = arr[i];
        int j = i;
        while(1) {
            int k = j+d;
            if(k>=n) k = k-n;
            if(k==i) break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

void print(int arr[], int n, int rot, int l, int r) {
    rot = rot%n;
    int i = (rot+l)%n;
    int num = r-l;
    for(int i=rot+l;i<r-l;i++) {
        printf("%d ", arr[i%n]);
    }
    printf("\n");
}


int main() {
    int arr[] = {4,5,6,7,8,9,10,1,2,3};
    int n=sizeof(arr)/sizeof(int);
    //+ve is left, -ve is right
    int nq = 4, rot = 0;
    for(int i=0;i<nq;i++) {
        int q;
        scanf("%d", &q);
        if(q==1) {
            int num;
            scanf("%d", &num);
            rot -= num;
        }
        else if(q==2) {
            int num;
            scanf("%d", &num);
            rot += num;
        }
        else {
            int x,y;
            scanf("%d %d", &x, &y);
            print(arr, n, rot, x, y);
        }
    }
    return 0;
}
