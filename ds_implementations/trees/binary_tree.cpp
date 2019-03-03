#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *root = NULL;

void inorder_print(struct Node *temp) {
    if(temp==NULL) return;
    inorder_print(temp->left);
    cout<<temp->data<<" ";
    inorder_print(temp->right);
}

void insert(int data) {
    queue <struct Node *> q;
    struct Node *newnode = new Node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    struct Node *temp = root;
    if(root==NULL) {
        root = newnode;
        return;
    }
    q.push(temp);
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        if(temp->left==NULL) {
            temp->left = newnode;
            return;
        }
        else {
            q.push(temp->left);
        }

        if(temp->right==NULL) {
            temp->right = newnode;
            return;
        }
        else {
            q.push(temp->right);
        }
    }
}

bool bfs(struct Node *node, int data) {
    if(node==NULL) return false;
    if(node->data==data) return true;
    return bfs(node->left, data) || bfs(node->right, data);
}

bool dfs(int data) {
    if(root==NULL) return false;
    queue <struct Node *> q;
    struct Node *temp = root;
    q.push(temp);
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        if(temp->data==data) {
            return true;
        }
        if(temp->left) {
            q.push(temp->left);
        }
        if(temp->right) {
            q.push(temp->right);
        }
    }
    return false;
}

void del_node(int data) {
    if(root==NULL) return;
    queue <struct Node *> q;
    //Find the deletion node
    q.push(root);
    struct Node *temp = root;
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        if(temp->data==data) {
            break;
        }
        if(temp->left) {
            q.push(temp->left);
        }
        if(temp->right) {
            q.push(temp->right);
        }
    }
    struct Node *node_del = temp;
    if(node_del==NULL) return;
    temp = root;
    struct Node *parent = NULL;
    //Traverse to the rightmost node
    while(temp->right!=NULL) {
        parent = temp;
        temp = temp->right;
    }
    if(temp->left!=NULL) {
        parent = temp;
        parent->left = NULL;
        temp = temp->left;
    }
    else {
        parent->right = NULL;
    }
    //Swap data of del node and leaf node found
    node_del->data = temp->data;
    delete(temp);
}

int main(int argc, char const *argv[]) {
    root = new Node();
    root->data = 10;
    root->left = new Node();
    root->left->data = 11;
    root->left->left = new Node();
    root->left->left->data = 7;
    root->right = new Node();
    root->right->data = 9;
    root->right->left = new Node();
    root->right->left->data = 15;
    root->right->right = new Node();
    root->right->right->data = 8;

    cout << "Inorder traversal before insertion:";
    inorder_print(root);

    int key = 12;
    insert(key);

    cout<<endl;
    cout << "Inorder traversal after insertion:";
    inorder_print(root);
    cout<<endl;
    del_node(10);
    inorder_print(root);
    cout<<endl;
    cout<<bfs(root, 5)<<endl;
    cout<<dfs(5)<<endl;
    return 0;
}
