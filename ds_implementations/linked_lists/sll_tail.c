#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head=NULL, *tail=NULL;

void insertBeginning(int data) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = head;
    if(head==NULL) {
        tail = newnode;
    }
    head = newnode;
}

void insertEnd(int data) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    if(tail==NULL) {
        head = newnode;
    }
    else {
        tail->next = newnode;
    }
    tail = newnode;
}

void insertPosi(int data, int pos) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    struct Node *temp = head, *prev=NULL;
    if(head==NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    if(pos==0) {
        newnode->next = head;
        if(head==NULL) {
            tail = newnode;
        }
        head = newnode;
        return;
    }
    while(pos-->0 && temp!=tail) {
        prev = temp;
        temp = temp->next;
    }
    if(temp!=tail) {
        prev->next = newnode;
        newnode->next = temp;
    }
    else {
        tail->next = newnode;
        tail = newnode;
    }
}

void deleteBeginning() {
    if(head==NULL) return;
    struct Node *temp = head;
    head = head->next;
    if(head==tail) {
        tail = NULL;
    }
    free(temp);
}

void deleteEnd() {
    if(tail==NULL) return;
    struct Node *temp = head;
    if(head==tail) {
        head = NULL;
        tail = NULL;
        return;
    }
    while(temp->next!=tail) {
        temp = temp->next;
    }
    tail = temp;
    temp = temp->next;
    tail->next = NULL;
    free(temp);
}

void deletePosi(int pos) {
    if(head==NULL) return;
    if(head==tail) {
        head = NULL;
        tail = NULL;
        return;
    }
    struct Node *temp=head,*prev=NULL;
    while(pos-->0 && temp!=tail && temp!=NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

void print() {
    struct Node *temp = head;
    if(temp==NULL) return;
    while(temp!=NULL && temp!=tail) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d\n", tail->data);
}

int main() {
    int n, val;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &val);
        insertEnd(val);
    }
    insertPosi(2,1);
    deletePosi(1);
    print();
    return 0;
}
