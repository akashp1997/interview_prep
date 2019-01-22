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

void del(struct Node *head) {
    if(head==NULL) {
        return;
    }
    struct Node *temp;
    while(head!=NULL) {
        temp = head->next;
        free(head);
        head = temp;
    }
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
    del(head);
    //print(head);
    return 0;
}
