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

struct Node *delete(struct Node *head, int posi) {
    if(posi==0) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;
    while(temp!=NULL && posi-->0) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
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
    head = delete(head, 2);
    print(head);
    return 0;
}
