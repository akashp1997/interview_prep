#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top_node = NULL;

void insert(int data) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = top_node;
    top_node = newnode;
}

int isEmpty() {
    return top_node==NULL;
}

int pop() {
    if(!isEmpty()) {
        int data = top_node->data;
        struct Node *temp = top_node;
        top_node = top_node->next;
        free(temp);
        return data;
    }
    return -1;
}

int top() {
    if(!isEmpty()) {
        return top_node->data;
    }
    return -1;
}

int main() {
    for(int i=0;i<4;i++) {
        insert(i+1);
        printf("%d\n", top());
    }
    printf("%d\n", pop());
    return 0;
}
