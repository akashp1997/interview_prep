#include <stdio.h>

#define MAXSIZE 1000

struct item {
    int data;
    int priority;
};

struct item pqueue[MAXSIZE];
int n = 0;

int overflow() {
    return n>=1000;
}

int isEmpty() {
    return n==0;
}

void insert(int data, int priority) {
    if(overflow()) {
        return;
    }
    pqueue[n].data = data;
    pqueue[n].priority = priority;
    n++;
}

int getHighestPriorityEle() {
    if(!isEmpty()) {
        int res = 0;
        for(int i=1;i<n;i++) {
            if(pqueue[res].priority<pqueue[i].priority) {
                res = i;
            }
        }
        return res;
    }
    return -1;
}

int getHighestPriority() {
    int ind = getHighestPriorityEle();
    if(ind==-1) return ind;
    return pqueue[ind].data;
}

int deleteHighestPriority() {
    int ind = getHighestPriorityEle();
    if(ind==-1) return -1;
    int res = pqueue[ind].data;
    for(int i=ind;i<n-1;i++) {
        pqueue[i] = pqueue[i+1];
    }
    n--;
    return res;
}

int main() {
    for(int i=1;i<12;i++) {
        insert(2*i+1, i);
    }
    printf("%d\n", deleteHighestPriority());
    printf("%d", getHighestPriority());
}
