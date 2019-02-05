#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct Node {
    int data;
    struct Node *npx;
};

struct Node *XOR(struct Node *a, struct Node *b) {
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

struct Node *insert(struct Node *head, int data) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->npx = XOR(NULL, head);
    if(head==NULL) return newnode;
    head->npx = XOR(newnode, XOR(head->npx, NULL));
    return newnode;
}

void print(struct Node *head) {
    if(head==NULL) return;
    struct Node *temp=head,*prev=NULL, *next=NULL;
    while(temp!=NULL) {
        printf("%d->", temp->data);
        next = XOR(temp->npx, prev);
        prev = temp;
        temp = next;
    }
}

int main() {
    struct Node *head=NULL;
    int n = 4;
    for(int i=1;i<=n;i++) {
        head = insert(head, i);
    }
    print(head);
    return 0;
}
