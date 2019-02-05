#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *insertBeginning(struct Node *head, int val) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
    return head;
}

struct Node *insertEnd(struct Node *head, int val) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;
    if(head==NULL) {
        head = newnode;
        return head;
    }
    struct Node *temp = head;
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

struct Node *insertPosi(struct Node *head, int val, int pos) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = val;
    struct Node *temp = head, *prev=NULL;
    if(pos==0 || head==NULL) {
        newnode->next = head;
        return newnode;
    }
    while(pos-->0 && temp->next!=NULL) {
        prev = temp;
        temp = temp->next;
    }
    if(temp->next==NULL) {
        temp->next = newnode;
        return head;
    }
    prev->next = newnode;
    newnode->next = temp;
    return head;
}

struct Node *deleteBeginning(struct Node *head) {
    if(head==NULL) return NULL;
    struct Node *newhead = head->next;
    free(head);
    return newhead;
}

struct Node *deleteEnd(struct Node *head) {
    if(head==NULL) return NULL;
    struct Node *temp=head, *prev=NULL;
    while(temp->next!=NULL) {
        prev = temp;
        temp = temp->next;
    }
    free(temp);
    prev->next = NULL;
    return head;
}

struct Node *deletePosi(struct Node *head, int pos) {
    if(head==NULL) return NULL;
    if(pos==0) return deleteBeginning(head);
    struct Node *temp = head, *prev=NULL;
    while(pos-->0 && temp->next!=NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

void print(struct Node *head) {
    struct Node *temp = head;
    if(temp==NULL) return;
    while(temp->next!=NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main() {
    struct Node *head = NULL;
    int n, val;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &val);
        head = insertEnd(head, val);
    }
    head = insertPosi(head, 2, 2);
    head = deleteEnd(head);
    print(head);
    return 0;
}
