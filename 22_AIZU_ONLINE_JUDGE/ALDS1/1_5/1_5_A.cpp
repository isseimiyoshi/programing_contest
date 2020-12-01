#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

int n;
int A[50];
const int MAX_N = 22, MAX_M = 2100;
vector<int> solve_tree(MAX_N*MAX_M);


bool solve(int i, int m){
    /*
    int tree_num = solve_tree[i*MAX_M + m];
    if(tree_num != -1){
        if(tree_num) return true;
        else return false;
    }
    */
    if(m == 0) return true;
    if(i >= n) return false;
    bool res = solve(i+1, m) || solve(i+1, m-A[i]);
    /*
    if(res) solve_tree[i*MAX_M + m] = 1;
    else solve_tree[i*MAX_M + m] = 0;
    */
    return res;
}

int main()
{
    /*
    for(int i=0; i<MAX_N ; i++){
        for(int j=0; j<MAX_M; j++) solve_tree[i*MAX_M + j] = -1;
    }
    */
    cin >> n;
    for(int i=0; i<n; i++){
        int Ai; cin >> Ai;
        A[i] = Ai;
    }
    int q; cin >> q;
    for(int i=0; i<q; q++){
        int m; cin >> m;
        if(solve(0, m)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}