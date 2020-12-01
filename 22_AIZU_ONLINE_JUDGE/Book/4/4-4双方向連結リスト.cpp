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

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/

struct Node {
    int key;
    Node *prev, *next;
};

Node *nil;

// 初期化（番兵の概念を利用する）
void init(){
    nil = (Node *)malloc(sizeof(Node)); // 指定したサイズだけメモリから動的にメモリを確保する
    nil->next = nil;
    nil->prev = nil;
}

// 双方向リストへの要素の挿入
void insert(int k){
    Node *x = (Node *)malloc(sizeof(Node));
    // キーの値の決定
    x->key = k;
    // 前後ポインタの変更
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

// 双方向リストへの要素の探索
Node* listSearch(int k){
    Node *cur = nil->next;
    while(cur != nil && cur->key != k){
        cur = cur->next;
    }
    return cur;
}

// 双方向リストの要素の削除
void deleteNode(Node *t){
    if(t == nil) return;    // tが番兵の場合は処理しない
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}

// 先頭の要素を削除
void deleteFirst(){
    deleteNode(nil->next);
}

// 最後尾の要素を削除
void deleteLast(){
    deleteNode(nil->prev);
}

// 検索したノードを削除
void deleteKey(int k){
    deleteNode(listSearch(k));
}

// 連結リストのキーを順番に出力する
void printNode(){
    Node* cur = nil->next;
    while(cur != nil){
        cout << cur->key;
        if(cur->next != nil) cout << " ";
        cur = cur->next;
    }cout << endl;
}


int main()
{
    int n; cin >> n;
    string command;
    int x;
    init();
    rep(_,n){
        scanf("%s %d", &command, &x);
        if(command == "insert"){
            //scanf("%d", &x);
            cout << x << endl;
            insert(x);
        }else if(command == "delete"){
            scanf("%d", &x);
            deleteKey(x);
        }else if(command == "deleteFirst"){
            deleteFirst();
        }else if(command == "deleteLast"){
            deleteLast();
        }
    }
    printNode();
}