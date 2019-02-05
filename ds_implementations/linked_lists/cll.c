#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *insertBeginning(struct Node *last, int data) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    if(last==NULL) {
        newnode->next = newnode;
        return newnode;
    }
    newnode->next = last->next;
    last->next = newnode;
    return last;
}

struct Node *insertEnd(struct Node *last, int data) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    if(last==NULL) {
        newnode->next = newnode;
        return newnode;
    }
    newnode->next = last->next;
    last->next = newnode;
    return newnode;
}

struct Node *deleteBeginning(struct Node *last) {
    if(last==NULL) return NULL;
    if(last->next==last) {
        free(last);
        return NULL;
    }
    struct Node *temp = last->next;
    last->next = last->next->next;
    free(temp);
    return last;
}

struct Node *deleteEnd(struct Node *last) {
    if(last==NULL) return NULL;
    if(last->next==last) {
        free(last);
        return last;
    }
    struct Node *prev = last;
    while(prev->next!=last) {
        prev = prev->next;
    }
    prev->next = last->next;
    free(last);
    return prev;
}

void print(struct Node *last) {
    if(last==NULL) return;
    struct Node *temp = last->next;
    while(temp!=last) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main() {
    struct Node *last = NULL;
    for(int i=1;i<=4;i++) {
        last = insertBeginning(last, i);
    }
    last = deleteEnd(last);
    print(last);
    return 0;
}
