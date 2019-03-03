#include <iostream>
#include <cstdlib>

#define MAXSIZE 1000

using namespace std;
int minheap[MAXSIZE] = {0};
int heapsize = 0;

int getMini() {
    return minheap[0];
}

void heapify(int ind) {
    int smallest = ind;
    if(2*ind+1<heapsize && minheap[2*ind+1]<minheap[smallest]) {
        smallest = 2*ind+1;
    }
    if(2*ind+2<heapsize && minheap[2*ind+2]<minheap[smallest]) {
        smallest = 2*ind+2;
    }
    if(smallest!=ind) {
        int temp = minheap[smallest];
        minheap[smallest] = minheap[ind];
        minheap[ind] = temp;
        heapify(smallest);
    }
}

void insert(int data) {
    if(heapsize>=MAXSIZE) return;
    minheap[heapsize++] = data;
    int i=heapsize-1;
    while(i!=0 && minheap[(i-1)/2]>minheap[i]) {
        int temp = minheap[(i-1)/2];
        minheap[(i-1)/2] = minheap[i];
        minheap[i] = temp;
        i = (i-1)/2;
    }
}

int extractmin() {
    if(heapsize==0) return INT_MIN;
    int temp = minheap[0];
    minheap[0] = minheap[heapsize-1];
    minheap[heapsize--] = temp;
    heapify(0);
    return minheap[0];
}

void decreaseKey(int ind, int data) {
    minheap[ind] = data;
    while(ind!=0 && minheap[(ind-1)/2]>minheap[ind]) {
        int temp = minheap[ind];
        minheap[ind] = minheap[(ind-1)/2];
        minheap[(ind-1)/2] = temp;
        ind = (ind-1)/2;
    }
}

void del(int ind) {
    decreaseKey(ind, INT_MIN);
    extractmin();
}

void print() {
    for(int i=0;i<heapsize;i++) {
        cout<<minheap[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[]) {
    for(int i=0;i<10;i++) {
        insert(rand()%1000);
    }
    print();
    del(2);
    print();
    return 0;
}
