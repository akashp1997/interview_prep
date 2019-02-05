#include <stdio.h>

#define MAXSIZE 1000

int stack[MAXSIZE];
int len=0;

int overflow() {
    return MAXSIZE<=len;
}

void insert(int data) {
    if(!overflow()) {
        stack[len++] = data;
    }
}

int isEmpty() {
    return len==0;
}

int pop() {
    if(!isEmpty()) {
        return stack[--len];
    }
    return -1;
}

int top() {
    if(!isEmpty()) {
        return stack[len-1];
    }
    return -1;
}

int main() {
    for(int i=0;i<4;i++) {
        insert(i+1);
        printf("%d\n", top());
    }
    printf("%d\n", pop());
    return 0;
}
