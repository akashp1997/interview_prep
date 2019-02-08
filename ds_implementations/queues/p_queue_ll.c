#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node *next;
};

struct Node *head=NULL,*tail=NULL;

int isEmpty() {
    return (head==NULL && tail==NULL);
}

void insert(int data, int priority) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->priority = priority;
    newnode->next = NULL;
    if(isEmpty()) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

struct Node *getHighestPriorityNode() {
    if(head==NULL || head->next==NULL) return head;
    struct Node *temp = head->next, *res=head;
    while(temp!=NULL) {
        if(temp->priority>res->priority) {
            res = temp;
        }
        temp = temp->next;
    }
    return res;
}

int getHighestPriority() {
    struct Node *res = getHighestPriorityNode();
    if(res==NULL) return -1;
    return res->data;
}

int deleteHighestPriority() {
    struct Node *res = getHighestPriorityNode();
    struct Node *prev = head;
    while(prev->next!=NULL && prev->next!=res) {
        prev = prev->next;
    }
    prev->next = res->next;
    int data = res->data;
    free(res);
    return data;
}

int main() {
    for(int i=1;i<12;i++) {
        insert(2*i+1, i);
    }
    printf("%d\n", deleteHighestPriority());
}
