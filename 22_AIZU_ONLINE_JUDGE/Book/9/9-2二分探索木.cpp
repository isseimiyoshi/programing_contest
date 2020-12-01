#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

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

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/

struct Node {
    ll key;
    Node *parent, *left, *right;
};
Node *NIL, *root;

void insert(ll k){
    Node *y = NIL;   // xの親
    Node *x = root;
    Node *z;

    z = (Node *)malloc(sizeof(Node));   // Node分のポインタの容量をとる
    z->key = k; z->left = NIL; z->right = NIL;

    while(x != NIL){
        y = x;  // 親を設定
        if((z->key) < (x->key)){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    z->parent = y;
    if(y == NIL) root = z;
    else if(y->key > z->key) y->left = z;
    else y->right = z;
}

Node * treeMinimum(Node * x){
    while(x->left != NIL){
        x = x->left;
    }
    return x;
}

Node * treeSuccessor(Node *z){
    if(z->right != NIL){
        return treeMinimum(z->right);
    }

    Node *y = z->parent;
    while(y != NIL && y->right == z){
        z = y;
        y = y->parent;
    }
    return y;
}

Node * find(ll k){
    Node *x = root;
    while(x != NIL){
        if(x->key == k) break;
        if(x->key < k) x = x->right;
        else x = x->left;
    }
    return x;
}

void deleteNode(ll k){
    // 削除する対象を節点yとする
    Node *z = find(k); Node * y;
    if(z->left == NIL || z->right == NIL){
        y = z;    // zが子を持たないか、子を1つだけ持つ場合は入力節点のz
    }else{
        y = treeSuccessor(z);  // zが2つ子を持つ場合はzの次節点
    }
    // yの子xを決める
    Node * x;
    if(y->left != NIL) x = y->left;
    else x = y->right;

    if(x != NIL) x->parent = y->parent; // xの親を設定
    if(y->parent == NIL) root = x;
    else if(y->parent->left == y) y->parent->left = x;
    else y->parent->right = x;

    if(y != z) z->key = y->key; // zの次節点が削除された場合、yのデータをzにコピーする
}

void preorder(Node *n){
    if(n == NIL) return;
    printf(" %ld", n->key);
    preorder(n->left);
    preorder(n->right);
}

void inorder(Node *n){
    if(n == NIL) return;
    inorder(n->left);
    printf(" %ld", n->key);
    inorder(n->right);
}

int main()
{
    int m; cin >> m;
    rep(i,m){
        string c; cin >> c;
        if(c == "insert"){
            ll k; cin >> k;
            insert(k);
        }else if(c == "print"){
            inorder(root); cout << endl;
            preorder(root); cout << endl;
        }else if(c == "find"){
            ll k; cin >> k;
            if(find(k) != NIL) cout << "yes" << endl;
            else cout << "no" << endl;
        }
        else if(c == "delete"){
            ll k; cin >> k;
            deleteNode(k);
        }
    }
}