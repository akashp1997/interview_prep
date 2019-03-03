#include <iostream>
#include <cmath>

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

bool isContinuous(struct Node *root) {
    if(root==NULL) return true;
    if(root->left==NULL && root->right==NULL) return true;
    if(root->left==NULL) return abs(root->right->data-root->data)==1 && isContinuous(root->right);
    if(root->right==NULL) return abs(root->left->data-root->data)==1 && isContinuous(root->left);
    return abs(root->left->data-root->data)==1 && abs(root->right->data-root->data)==1 && isContinuous(root->left) && isContinuous(root->right);
}

int main(int argc, char const *argv[]) {
    struct Node *root = new Node(3);
    root->left        = new Node(2);
    root->right       = new Node(4);
    root->left->left  = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(2);
    cout<<isContinuous(root);
    return 0;
}
