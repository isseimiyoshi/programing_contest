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

const int MAX = pow(10, 7);
const int NIL = -1;

struct Node { int parent, left, right; };
Node T[MAX];    // 節点のノード情報を格納する
int D[MAX];     // 節点の深さを格納する
int max_d;      // 構築するツリーの高さ
int n;          // 節点の数


int preorder(int u){
    if(u == NIL) return 0;
    printf(" %d", u);
    preorder(T[u].left);
    preorder(T[u].right);
}

int inorder(int u){
    if(u == NIL) return 0;
    inorder(T[u].left);
    printf(" %d", u);
    inorder(T[u].right);
}

int postorder(int u){
    if(u == NIL) return 0;
    postorder(T[u].left);
    postorder(T[u].right);
    printf(" %d", u);
}


int main()
{
    cin >> n;
    // 初期化
    rep(i, n) T[i].parent = T[i].left = T[i].right = NIL;
    // 各情報をセット
    rep(i, n){
        int id, l, r; cin >> id >> l >> r;
        T[id].left = l;
        T[id].right = r;
        if(l != NIL) T[l].parent = id;
        if(r != NIL) T[r].parent = id;
    }
    int r;
    rep(i, n){
        if(T[i].parent == NIL) r = i;
    }
    // Preorder
    cout << "Preorder" << endl;
    preorder(r); cout << endl;
    // Inorder
    cout << "Inorder" << endl;
    inorder(r); cout << endl;
    // Postorder
    cout << "Postorder" << endl;
    postorder(r); cout << endl;
}