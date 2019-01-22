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

void insert(struct Node *prev, int val) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = val;
    if(prev==NULL) {
        return;
    }
    newnode->next = prev->next;
    prev->next = newnode;
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
}

int main() {
    struct Node *head = NULL;
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        int temp;
        scanf("%d", &temp);
        if(i==0) {
            head = insertBeginning(head, temp);
        }
        else{
            insert(head, temp);
        }
    }
    print(head);
    return 0;
}
