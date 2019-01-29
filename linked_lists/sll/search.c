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

int search_iter(struct Node *head, int key) {
    struct Node *temp = head;
    while(temp!=NULL) {
        if(temp->data==key) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int search_recur(struct Node *head, int key) {
    if(head==NULL) {
        return 0;
    }
    if(head->data==key) {
        return 1;
    }
    return search_recur(head->next, key);
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
    printf("%d", search_recur(head, 2));
    return 0;
}
