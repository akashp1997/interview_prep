#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct Node {
    int data;
    struct Node *npx;
};

struct Node *head=NULL, *tail=NULL;

struct Node *XOR(struct Node *a, struct Node *b) {
    return (struct Node *) ((uintptr_t)a ^ (uintptr_t)b);
}

int isEmpty() {
    return head==NULL&&tail==NULL;
}

void enqueue_front(int data) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->npx = XOR(NULL, head);
    if(isEmpty()) {
        head = newnode;
        tail = newnode;
        return;
    }
    head->npx = XOR(newnode, XOR(head->npx, NULL));
    head = newnode;
}

void enqueue_rear(int data) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->npx = XOR(NULL, tail);
    if(isEmpty()) {
        head = newnode;
        tail = newnode;
        return;
    }
    struct Node *prev = XOR(NULL, tail->npx);
    tail->npx = XOR(XOR(NULL, tail->npx), newnode);
    tail = newnode;
}

int dequeue_front() {
    struct Node *temp = head;
    head = XOR(head->npx, NULL);
    struct Node *next = XOR(head->npx, temp);
    head->npx = XOR(NULL, next);
    int data = temp->data;
    free(temp);
    return data;
}

int dequeue_rear() {
    struct Node *temp = tail;
    tail = XOR(tail, NULL);
    struct Node *prev = XOR(tail->npx, temp);
    tail->npx = XOR(prev, NULL);
    int data = temp->data;
    free(temp);
    return data;
}

int main(int argc, char const *argv[]) {
    for(int i=0;i<4;i++) {
        enqueue_front(i);
        enqueue_rear(i+10);
    }
    printf("%d %d", dequeue_front(), dequeue_rear());
    return 0;
}
