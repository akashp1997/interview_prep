#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *insertBeginning(struct Node *head, int val) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = head;
    if(head!=NULL) {
        head->prev = newnode;
    }
    head = newnode;
    return head;
}

struct Node *insertEnd(struct Node *head, int val) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = val;
    struct Node *temp = head;
    if(temp==NULL) {
        head = newnode;
        return newnode;
    }
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}

struct Node *insertBefore(struct Node *head, int val, int pos) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = val;
    struct Node *temp = head;
    if(head==NULL) {
        return newnode;
    }
    while(pos-->0 && temp->next!=NULL) {
        temp = temp->next;
    }
    if(temp->next==NULL) {
        temp->next = newnode;
        newnode->prev = temp;
        return head;
    }
    newnode->next = temp;
    newnode->prev = temp->prev;
    temp->prev = newnode;
    newnode->prev->next = newnode;
    return head;
}

struct Node *insertAfter(struct Node *head, int val, int pos) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = val;
    struct Node *temp = head;
    if(head==NULL) {
        return newnode;
    }
    while(pos-->1 && temp->next!=NULL) {
        temp = temp->next;
    }
    if(temp->next==NULL) {
        temp->next = newnode;
        newnode->prev = temp;
        return head;
    }
    newnode->next = temp;
    newnode->prev = temp->prev;
    temp->prev = newnode;
    newnode->prev->next = newnode;
    return head;
}

struct Node *deleteBeginning(struct Node *head) {
    if(head==NULL) return head;
    struct Node *temp = head;
    head = head->next;
    if(head!=NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

struct Node *deleteEnd(struct Node *head) {
    if(head==NULL) return head;
    struct Node *temp = head;
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp = temp->prev;
    free(temp->next);
    temp->next = NULL;
    return head;
}

void print(struct Node *head) {
    struct Node *temp = head;
    if(head==NULL) return;
    while(temp->next!=NULL) {
        printf("%d<->", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main() {
    struct Node *head = NULL;
    int n,val;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &val);
        head = insertEnd(head, val);
    }
    head = deleteBeginning(head);
    print(head);
    return 0;
}
