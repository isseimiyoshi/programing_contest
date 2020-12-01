#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

// if('A'<=s[i] && s[i]<='Z') s[i] += 'a'-'A';

/*
string s = "abcdefg"
s.substr(4) "efg"
s.substr(0,3) "abc"
s.substr(2,4) "cdef"
*/

struct Node{
    int key;
    Node *right, *left, *parent;
};

Node *root, *NIL;

void insert(int k){
    Node *y = NIL;
    Node *x = root;
    Node *z;

    // z = malloc(sizeof(struct node));  // node構造体サイズのメモリ領域をとる
    z = (Node *)malloc(sizeof(Node));
    z->key = k;   // ポインタ変数にアクセスする時はアロー演算子
    z->left = NIL;
    z->right = NIL;
    
    while(x != NIL){
        y = x;    // 最終的なzの親を決定する
        if(z->key < x->key) x = x->left;
        else x = x->right;
    }
    z->parent = y;
    if(y == NIL){
        root = z; // 親要素が空であれば、zが根となる
    }else{
        if(z->key < y->key){
            y->left = z;
        }else{
            y->right = z;
        }
    }
}

Node *find(Node *x, int k){
    while(x != NIL){
        if(x->key == k){
            return x;     
        }else if(x->key < k){
            x = x->right;
        }else{
            x = x->left;
        }
    }
    return x;
}

/*
void delet(int k){
    Node *x = root;
    Node *y = NIL;
    while(x != NIL){
        if(x->key == k){
            if(x->left == NIL && x->right == NIL){
                x = NIL;
            }else if(x->left == NIL){
                y = x->right;
                x->right = NIL;
                x = y;
            }else if(x->right == NIL){
                y = x->left;
                x->left = NIL;
                x = y;
            }else{
                
            }
        }else if(x->key < k){
            x = x->right;
        }else{
            x = x->left;
        }
    }
}
*/

// 節uより下層の最小値を求める
Node *treeMinimum(Node *u){
    while(u->left != NIL) u = u->left;
    return u;
}

// ノードxの次節点（中間順巡回の順で次の節点）ノードを返す
Node *treeSuccessor(Node *x){
    if(x->right != NIL) return treeMinimum(x->right);
    Node *y = x->parent;
    while(y != NIL && x == y->right){
        x = y;
        y = y->parent;
    }
    return y;
}

void treeDelete(Node *z){
    Node *y;    // 削除する対象
    Node *x;    // yの子
    // 削除する節点を決める
    if(z->left == NIL || z->right == NIL) y = z;    // zが子を持たないか、子を1つ持つ場合は入力節点のzを削除する対象とする
    else y = treeSuccessor(z);              // zが子を2つ持つ場合には。zの次節点を削除する対象とする

    // yの子xを決める
    if(y->left != NIL){
        x = y->left;
    }else{
        x = y->right;
    }
    if(x != NIL) x->parent = y->parent;
    if(y->parent == NIL){
        root = x;
    }else{
        if(y == y->parent->left){
            y->parent->left = x;
        }else{
            y->parent->right = x;
        }
    }
    if(y != z) z->key = y->key;
    free(y);
}

void inorder(Node *u){
    if(u == NIL) return;
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}

void preorder(Node *u){
    if(u == NIL) return;
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

int main()
{
    int n, i, x;
    string com;
    scanf("%d", &n);

    rep(i, n){
        cin >> com;
        if(com == "insert"){
            scanf("%d", &x);
            insert(x);
        }else if(com == "print"){
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }else if(com == "find"){
            scanf("%d", &x);
            Node *t = find(root, x);
            if(t != NIL) printf("yes\n");
            else printf("no\n");
        }else if(com == "delete"){
            scanf("%d", &x);
            treeDelete(find(root, x));
        }
    }
}