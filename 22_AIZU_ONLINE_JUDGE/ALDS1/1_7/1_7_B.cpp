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
int max_d;          // 構築するツリーの高さ

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

int printchild(int u){
    if(T[u].left == NIL){
        return 0;
    }else{
        u = T[u].left;
        while(true){
            if(T[u].right == NIL){
                return 1;
                break;
            }else{
                return 2;
            }
        }
    }
}

// 節点uの兄弟を返す
int getSibling(int u){
    if(T[u].parent == NIL) return NIL;
    if(T[T[u].parent].left != u && T[T[u].parent].left != NIL){
        return T[T[u].parent].left;
    }
    if()
}

// 各節点の情報を出力する
void print(int u){
    printf("node %d: ", u);
    if(T[u].parent == NIL){
        printf("parent = %d, ", -1);
        printf("sibling = -1, ");
    }else{
        int parent = T[u].parent;
        printf("parent = %d, ", parent);
        int left_u = T[parent].left;
        if(T[u].right != NIL){
            printf("sibling = %d, ", T[u].right);
        }else {
            if(u != left_u){
                printf("sibling = %d, ", left_u);
            }else{
                printf("sibling = %d, ", -1);
            }
        }
    }
    
    printf("degree = %d, ", printchild(u));
    printf("depth = %d, ", getDepth(u));
    printf("height = %d, ", max_d - getDepth(u));
    if(T[u].parent == NIL){
        printf("root");
    }else if(T[u].left == NIL){
        printf("leaf");
    }else{
        printf("internal node");
    }
    cout << endl;
}

int main()
{
    int n; cin >> n;
    rep(i, n) T[i].parent = T[i].left = T[i].right = NIL;
    rep(i, n){
        int id; cin >> id;
        int l, r; cin >> l >> r;
        if(i == 0 && l != NIL) T[id].left = l;
        if(l != NIL) T[l].parent = id;
        if(r != NIL) T[r].parent = id;
        if(l != NIL && r != NIL) T[l].right = r;
    }
    int r;
    rep(i, n) if(T[i].parent == NIL) r = i;
    setDepth(r, 0);
    max_d = 0;
    rep(i, n){
        if(max_d < getDepth(i)){
            max_d = getDepth(i);
        }
    }
    cout << max_d << endl;
    rep(i, n) print(i);
}