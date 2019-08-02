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
    if(head1==NULL && head2==NULL) return 1;
    if((head1!=NULL && head2==NULL) || (head1==NULL && head2!=NULL)) return 0;
    while(head1!=NULL) {
        struct Node *ptr1 = head1,*ptr2 = head2;
        while(ptr2!=NULL && ptr1->data!=ptr2->data) {
            ptr2 = ptr2->next;
        }
        if(ptr2!=NULL) {
            int cnt = 0;
            while(ptr1!=NULL && ptr2!=NULL) {
                if(ptr1->data!=ptr2->data) {
                    cnt = 0;
                    break;
                }
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
                cnt++;
            }
            if(cnt>1) {
                return 1;
            }
        }
        head1 = head1->next;
    }
    return 0;
}

int main() {
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    int arr1[] = {5,10,15,20,25};
    int arr2[] = {10, 15, 20};
    int n1 = sizeof(arr1)/sizeof(int);
    int n2 = sizeof(arr2)/sizeof(int);
    for(int i=0;i<n2;i++) {
        head2 = insertEnd(head2, arr2[i]);
    }
    print(head2);
    for(int i=0;i<n1;i++) {
        head1 = insertEnd(head1, arr1[i]);
    }
    print(head1);
    printf("%d", isSubList(head1, head2));
    //printf("%d\n", isSubList(head1, head2));
    return 0;
}
