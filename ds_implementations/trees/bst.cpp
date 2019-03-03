#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

struct Node *insert(struct Node *root, int data) {
    if(!root) return new Node(data);
    if(root->data>data) {
        root->left = insert(root->left, data);
    }
    else if(root->data<data) {
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(struct Node *root, int data) {
    if(!root) return false;
    if(root->data==data) return true;
    if(root->data>data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

void inorder_print(struct Node *root) {
    if(!root) return;
    inorder_print(root->left);
    printf("%d ", root->data);
    inorder_print(root->right);
}

struct Node *del(struct Node *root, int data) {
    if(!root) return root;
    if(root->data>data) {
        root->left = del(root->left, data);
    }
    else if(root->data<data) {
        root->right = del(root->right, data);
    }
    else {
        if(!root->left) {
            struct Node *temp = root->right;
            delete(root);
            return temp;
        }
        else if(!root->right) {
            struct Node *temp = root->left;
            delete(root);
            return temp;
        }
        struct Node *temp = root->right;
        while(!temp->left) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = del(root->right, temp->data);
    }
    return root;
}

int main(int argc, char const *argv[]) {
    struct Node *root = NULL;
    for(int i=1;i<10;i++) {
        root = insert(root, i);
    }
    cout<<search(root, 7)<<endl;
    inorder_print(root);
    cout<<endl;
    root = del(root, 6);
    inorder_print(root);
    return 0;
}
