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

const int MAX_N = 200100, NIL = -1;

struct Node{
    int cnt;
    int parent, left, right;
};
struct Node T[MAX_N];

vector<int> to[MAX_N];  // 入力値は隣接リスト形式で格納する
int N, Q;

void init(){
    rep(i,MAX_N){
        T[i].cnt = 0;
        T[i].parent = T[i].left = T[i].right = NIL;
    }
}

void make_tree(int u){
    // cout << u << endl;
    for(int v: to[u]){
        if(T[u].parent != v){
            T[v].parent = u;
            if(T[u].left == NIL) T[u].left = v;
            else T[T[u].left].right = v;
            make_tree(v);
        }else{
            continue;
        }
    }
}

void print_tree(int u){
    printf("key:%d, parent:%d, ", u, T[u].parent);
    if(T[u].right != NIL) printf("right:%d, ", T[u].right);
    if(T[u].left != NIL) printf("left:%d", T[u].left);
    cout << endl;
    if(T[u].right != NIL) print_tree(T[u].right);
    if(T[u].left != NIL) print_tree(T[u].left);
}

void counter(int u, int sum){
    //printf("u:%d cnt:%d sum:%d\n", u, T[u].cnt, sum);
    T[u].cnt += sum;
    //printf("u:%d cnt:%d sum:%d\n", u, T[u].cnt, sum);
    if(T[u].right != NIL) counter(T[u].right, sum);
    else if(T[u].left != NIL) counter(T[u].left, T[u].cnt);
}

int main()
{
    cin >> N >> Q;
    rep(i,N-1){
        int ai, bi; cin >> ai >> bi; --ai; --bi;
        to[ai].push_back(bi);
        to[bi].push_back(ai);
    }
    init();
    make_tree(0);
    // 根付き木がしっかり構築されているか確認する
    print_tree(0); 
    
    rep(i,Q){
        int pi, xi; cin >> pi >> xi; --pi;
        T[pi].cnt += xi;
    }
    counter(0, 0);
    rep(i,N){
        cout << T[i].cnt;
        if(i != N-1) cout << " ";
    }cout << endl;
    
}