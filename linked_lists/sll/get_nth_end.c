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

int get_nth(struct Node *head, int posi) {
    if(head==NULL) {
        return -1;
    }
    struct Node *temp = head;
    struct Node *res = head;
    while(posi-->0 && temp!=NULL) {
        temp = temp->next;
    }
    if(posi==0) {
        return -1;
    }
    while(temp->next!=NULL) {
        temp = temp->next;
        res = res->next;
    }
    return res->data;
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
    printf("%d\n", get_nth(head, 2));
    return 0;
}
