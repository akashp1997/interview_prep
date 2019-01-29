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

void createloop(struct Node *head) {
    struct Node *temp = head;
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = head;
}

struct Node *loop(struct Node *head) {
    struct Node *fast = head;
    struct Node *slow = head;
    if(fast==NULL) {
        return NULL;
    }
    if(fast->next==fast) {
        return fast;
    }
    do {
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow) {
            return fast;
        }
    }
    while (fast!=NULL && fast->next!=NULL && slow!=NULL);
    return NULL;
}

int loop_length(struct Node *head) {
    struct Node *node = loop(head);
    if(node==NULL) {
        return 0;
    }
    int count = 1;
    struct Node *temp = node;
    while(temp->next!=node) {
        temp = temp->next;
        count++;
    }
    return count;
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
    createloop(head);
    printf("%d\n", loop(head)->data);
    printf("%d\n", loop_length(head));
    return 0;
}
