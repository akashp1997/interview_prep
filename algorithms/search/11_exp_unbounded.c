#include <stdio.h>

int f(int x) {
    return x*x-10*x-20;
}

int search(int low, int high){
    if(low>high) return -1;
    if(low==high) return f(low)>0;
    int mid = (low+high)/2;
    if(f(mid)>0 && f(mid-1)<=0) return mid;
    if(f(mid)<0) return search(mid+1, high);
    return search(low, mid-1);
}

int first() {
    if(f(0)>0) return 0;
    int i=1;
    while(f(i)<=0) {
        i *= 2;
    }
    return search(i/2, i);
}

int main(int argc, char const *argv[]) {
    printf("%d", first());
    return 0;
}
