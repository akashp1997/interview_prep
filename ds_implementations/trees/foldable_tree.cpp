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

bool isMirror(struct Node *left, struct Node *right) {
    if ((left && !right) || (!left && right)) return false;
    if (!left && !right) return true;
    return (isMirror(left->right, right->left) && isMirror(left->left, right->right));
}

bool isFoldable(struct Node *root) {
    if(!root) return true;
    return isMirror(root->left, root->right);
}

int main(int argc, char const *argv[]) {
    struct Node *root = new Node(10);
    root->left = new Node(7);
    root->left->left = new Node(9);
    root->right = new Node(15);
    root->right->right = new Node(11);
    cout<<isFoldable(root);
    cout<<endl;
    return 0;
}
