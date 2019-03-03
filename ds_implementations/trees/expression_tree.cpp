#include <iostream>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

struct Node {
    char c;
    struct Node *left, *right;
    Node(char chr) {
        c = chr;
        left = NULL;
        right = NULL;
    }
};

void inorder_print(struct Node *root) {
    if(!root) return;
    inorder_print(root->left);
    cout<<root->c<<" ";
    inorder_print(root->right);
}

int evaluate(struct Node *root) {
    if(!root) return 0;
    if(!root->left && !root->right) return (int)(root->c-'0');
    switch(root->c) {
        case '+': return evaluate(root->left)+evaluate(root->right);
        break;
        case '-': return evaluate(root->left)-evaluate(root->right);
        break;
        case '*': return evaluate(root->left)*evaluate(root->right);
        break;
        case '/': return evaluate(root->left)/evaluate(root->right);
        break;
        case '%': return evaluate(root->left)%evaluate(root->right);
        break;
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    stack <struct Node *> s;
    string line = "12+34*5*-";
    for(int i=0;i<line.length();i++) {
        if(line[i]=='+' || line[i]=='-' || line[i]=='*' || line[i]=='/' || line[i]=='%') {
            struct Node *s1 = s.top();
            s.pop();
            struct Node *s2 = s.top();
            s.pop();
            struct Node *op = new Node(line[i]);
            op->left = s2;
            op->right = s1;
            s.push(op);
        }
        else {
            s.push(new Node(line[i]));
        }
    }
    cout<<evaluate(s.top());
    return 0;
}
