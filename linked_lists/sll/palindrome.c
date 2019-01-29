#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node *next;
};

struct Node *insertEnd(struct Node *head, char val) {
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
        printf("%c", temp->data);
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

struct Node *reverse(struct Node * head) {
    if(head->next==NULL) {
        return head;
    }
    struct Node *rev = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rev;
}

int isPalindrome(struct Node *head) {
    struct Node *fast=head, *mid=head, *prev=NULL;
    while(fast!=NULL && fast->next!=NULL) {
        fast = fast->next->next;
        prev = mid;
        mid = mid->next;
    }
    if (fast != NULL) {
        prev->next = NULL;
    }
    mid = reverse(mid);
    while(head!=NULL || mid!=NULL) {
        if(head->data!=mid->data) {
            return 0;
        }
        head = head->next;
        mid = mid->next;
    }
    return 1;
}

int main() {
    struct Node *head = NULL;
    char arr[100];
    scanf("%s", arr);
    for(int i=0;i<strlen(arr);i++) {
        head = insertEnd(head, arr[i]);
    }
    printf("%d", isPalindrome(head));
    return 0;
}
