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

// ある節点の深さ値を取得する
int getDepth(int u){
    int d = 0;
    while(T[u].parent != NIL){
        u = T[u].parent;
        d++;
    }
    return d;
}

// 全ての節点の深さを求める
void setDepth(int u, int p){
    D[u] = p;
    if(T[u].right != NIL){
        setDepth(T[u].right, p);
    }
    if(T[u].left != NIL){
        setDepth(T[u].left, p+1);
    }
}

void printchild(int u){
    if(T[u].left == NIL){
        printf("[]");
    }else{
        u = T[u].left;
        printf("[");
        while(true){
            if(T[u].right == NIL){
                printf("%d]", u);
                break;
            }else{
                printf("%d, ", u);
                u = T[u].right;
            }
        }
    }
}

// 各節点の情報を出力する
void print(int u){
    printf("node %d: ", u);
    if(T[u].parent == NIL) printf("parent = %d, ", -1);
    else printf("parent = %d, ", T[u].parent);
    printf("depth = %d, ", getDepth(u));
    if(T[u].parent == NIL){
        printf("root, ");
    }else if(T[u].left == NIL){
        printf("leaf, ");
    }else{
        printf("internal node, ");
    }
    printchild(u); cout << endl;
}

int main()
{
    int n; cin >> n;
    // 変数の初期化
    rep(i, n) T[i].parent = T[i].left = T[i].right = NIL;
    rep(i, n){
        int id; cin >> id;
        int k; cin >> k;
        rep(j, k){
            int l;
            int c; cin >> c;
            if(j == 0) T[id].left = c;
            else T[l].right = c;
            l = c;
            T[c].parent = id;
        }
    }
    // 根ノードを求めるための処理
    int r;
    rep(i, n) if(T[i].parent == NIL) r = i;
    setDepth(r, 0);
    rep(i, n){
        print(i);
    }
}