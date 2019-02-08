#include <stdio.h>

#define MAXSIZE 100

int deque[MAXSIZE];
int front_ind = -1;
int rear_ind = 0;

int overflow() {
    return (front_ind==0 && rear_ind==MAXSIZE-1) || front_ind==rear_ind+1;
}

int isEmpty() {
    return front_ind==-1;
}

void enqueue_front(int data) {
    if(overflow()) return;
    if(isEmpty()) {
        front_ind = 0;
        rear_ind = 0;
    }
    else if(front_ind==0) {
        front_ind = MAXSIZE-1;
    }
    else {
        front_ind--;
    }
    deque[front_ind] = data;
}

void enqueue_rear(int data) {
    if(overflow()) return;
    if(isEmpty()) {
        front_ind = 0;
        rear_ind = 0;
    }
    else {
        rear_ind = (rear_ind+1)%MAXSIZE;
    }
    deque[rear_ind] = data;
}

int dequeue_front() {
    if(isEmpty()) return -1;
    if(front_ind==rear_ind) {
        int data = deque[front_ind];
        front_ind = -1;
        rear_ind = -1;
        return data;
    }
    else {
        int data = deque[front_ind];
        front_ind = (front_ind+1)%MAXSIZE;
        return data;
    }
}

int dequeue_rear() {
    if(isEmpty()) return -1;
    if(front_ind==rear_ind) {
        int data = deque[front_ind];
        front_ind = -1;
        rear_ind = -1;
        return data;
    }
    else {
        int data = deque[rear_ind];
        if(rear_ind==0) {
            rear_ind = MAXSIZE-1;
        }
        else {
            rear_ind--;
        }
        return data;
    }
}

int main(int argc, char const *argv[]) {
    for(int i=0;i<4;i++) {
        enqueue_front(i);
        enqueue_rear(i+10);
    }
    printf("%d %d", dequeue_front(), dequeue_rear());
    return 0;
}
