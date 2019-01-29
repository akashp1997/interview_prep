#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

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

void print(struct Node *head) {
    struct Node *temp = head;
    while(temp!=NULL) {
        printf("%d", temp->data);
        if(temp->next!=NULL){
            printf("->");
        }
        else {
            printf("\n");
        }
        temp = temp->next;
    }
    head = NULL;
}

struct Node *removeDuplicates(struct Node *head) {
    struct Node *temp = head;
    while(temp->next!=NULL) {
        if(temp->data==temp->next->data) {
            struct Node *delnode = temp->next;
            temp->next = temp->next->next;
            free(delnode);
        }
        else {
            temp = temp->next;
        }
    }
    return head;
}

int main() {
    struct Node *head = NULL;
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        int val;
        scanf("%d", &val);
        head = insertEnd(head, val);
    }
    print(head);
    head = removeDuplicates(head);
    print(head);
    return 0;
}
