#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head=NULL;
struct Node *tail=NULL;

int isEmpty() {
    return (head==NULL && tail==NULL);
}

void enqueue(int data) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    if(isEmpty()) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

int rear() {
    if(isEmpty()) {
        return -1;
    }
    return tail->data;
}

int front() {
    if(isEmpty()) {
        return -1;
    }
    return head->data;
}

int dequeue() {
    if(isEmpty()) {
        return -1;
    }
    struct Node *temp = head;
    int data = head->data;
    head = head->next;
    free(temp);
    return data;
}

int main() {
    for(int i=0;i<4;i++) {
        enqueue(i+1);
    }
    printf("%d\n", dequeue());
    return 0;
}
