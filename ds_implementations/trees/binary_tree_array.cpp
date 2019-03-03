#include <iostream>
#include <queue>

#define MAXSIZE 1000

using namespace std;

int tree[MAXSIZE] = {0};

void inorder_print(int ind) {
    if(tree[ind]==0) return;
    inorder_print(2*ind+1);
    printf("%d ", tree[ind]);
    inorder_print(2*ind+2);
}

void insert(int data) {
    queue <int> q;
    q.push(0);
    int ind = 0;
    while(!q.empty()) {
        ind = q.front();
        q.pop();
        if(tree[2*ind+1]==0) {
            tree[2*ind+1] = data;
            break;
        }
        else {
            q.push(2*ind+1);
        }
        if(tree[2*ind+2]==0) {
            tree[2*ind+2] = data;
            break;
        }
        else {
            q.push(2*ind+2);
        }
    }
}

void del_node(int ind, int data) {
    if(tree[ind]==0) return;
    if(tree[ind]==data) {
        if(tree[2*ind+1]==0 && tree[2*ind+2]==0) {
            tree[ind] = 0;
            return;
        }
        int node_del = ind;
        while(tree[2*ind+2]!=0) {
            ind = 2*ind+2;
        }
        if(tree[2*ind+1]!=0) {
            ind = 2*ind+1;
        }
        tree[node_del] = tree[ind];
        tree[ind] = 0;
        return;
    }
    del_node(2*ind+1, data);
    del_node(2*ind+2, data);
}

int bfs(int ind, int data) {
    if(tree[ind]==0) return -1;
    if(tree[ind]==data) return ind;
    int left = bfs(2*ind+1, data);
    if(left!=-1) return left;
    int right = bfs(2*ind+2, data);
    if(right!=-1) return right;
    return -1;
}

int dfs(int data) {
    queue <int> q;
    q.push(0);
    int ind = 0;
    while(!q.empty()) {
        ind = q.front();
        q.pop();
        if(tree[ind]==data) {
            return ind;
        }
        if(tree[2*ind+1]!=0) {
            q.push(2*ind+1);
        }
        if(tree[2*ind+2]!=0) {
            q.push(2*ind+2);
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    tree[0] = 10;
    tree[1] = 11;
    tree[3] = 7;
    tree[2] = 9;
    tree[5] = 15;
    tree[6] = 8;
    cout << "Inorder traversal before insertion:";
    inorder_print(0);
    del_node(0, 11);
    cout<<endl<<dfs(8);
    cout<<endl;
    inorder_print(0);
    cout<<endl;
    return 0;
}
