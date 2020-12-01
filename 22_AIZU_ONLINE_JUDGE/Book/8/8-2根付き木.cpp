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

const int NIL = -1;
const int MAX_N = 100100;
struct Node{ int parent, left, right; };
Node T[MAX_N];

int getDepth(int u){
    int d = 0;
    while(T[u].parent != NIL){
        u = T[u].parent;
        d++;
    }
    return d;
}

void printChildren(int u){
    vector<int> ch;
    if(T[u].left == NIL){
        cout << "[]";
    }else{
        u = T[u].left;
        ch.push_back(u);
        while(T[u].right != NIL){
            u = T[u].right;
            ch.push_back(u);
        }
    }
    if(ch.size() != 0){
        if(ch.size() == 1){
            printf("[%d]", ch[0]);
        }else{
            rep(i, ch.size()){
                if(i == 0){
                    printf("[%d, ", ch[i]);
                }else if(i == ch.size()-1){
                    printf("%d]", ch[i]);
                }else{
                    printf("%d, ", ch[i]);
                }
            }
        }
    }
}

int main()
{
    int n; cin >> n;
    // 初期化
    rep(i,n){
        T[i].parent = NIL;
        T[i].left = NIL;
        T[i].right = NIL;
    }
    // 情報の読み込み
    rep(i,n){
        int p; cin >> p;
        int k; cin >> k;
        int ori_c = NIL;
        rep(j,k){
            int c; cin >> c;
            if(T[p].left == NIL) T[p].left = c;
            T[c].parent = p;
            if(ori_c != NIL) T[ori_c].right = c;
            ori_c = c;
        }
    }
    rep(i,n){
        printf("node %d: parent = %d, depth = %d, ", i, T[i].parent, getDepth(i));
        if(T[i].parent == -1){
            printf("root, ");
        }else{
            if(T[i].left == NIL) printf("leaf, ");
            else printf("internal node, ");
        }
        printChildren(i); cout << endl;
    }
}