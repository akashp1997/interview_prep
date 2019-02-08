#include <stdio.h>

#define MAXSIZE 1000

int queue[MAXSIZE];
int front = 0;
int rear = 0;

int overflow() {
    return front==rear-1;
}

void enqueue(int data) {
    if(overflow()) return;
    queue[front] = data;
    front = (front+1)%MAXSIZE;
}

int isEmpty() {
    return front==rear;
}

int dequeue() {
    if(isEmpty()) {
        return -1;
    }
    int data = queue[rear];
    rear = (rear+1)%MAXSIZE;
    return data;
}

int top() {
    return queue[front-1];
}

int back() {
    return queue[rear];
}

int main() {
    for(int i=0;i<4;i++) {
        enqueue(i+1);
        printf("%d ", top());
    }
    printf("\n%d", dequeue());
    return 0;
}
