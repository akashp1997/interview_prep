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
    struct Node *temp;
    while(temp->next!=NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int isSubList(struct Node *head1, struct Node *head2) {
    if(head1==NULL || head2==NULL) return 0;
    struct Node *temp1=head1;
    //while(temp1!=NULL) {
        struct Node *temp2 = head2;
        while(temp2!=NULL) {
            printf("%d ", temp2->data);
            if(temp1->data!=temp2->data) {
                break;
            }
            temp2 = temp2->next;
        }
        //printf("\n");
        //if (temp2==NULL) {
        //    return 1;
        //}
        //temp1 = temp1->next;
    //}
    return 0;
}

int main() {
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    int arr1[] = {5,10,15,20,25};
    int arr2[] = {15,20,25};
    int n1 = sizeof(arr1)/sizeof(int);
    int n2 = sizeof(arr2)/sizeof(int);
    for(int i=0;i<n2;i++) {
        head2 = insertEnd(head2, arr2[i]);
    }
    print(head2);
    for(int i=0;i<n1;i++) {
        head1 = insertEnd(head1, arr1[i]);
    }
    print(head2);
    //printf("%d\n", isSubList(head1, head2));
    return 0;
}
