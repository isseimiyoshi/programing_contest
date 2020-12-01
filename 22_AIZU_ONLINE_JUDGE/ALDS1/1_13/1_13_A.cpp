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
static const int N = 8;
static const int FREE = 1, NOT_FREE = 0;

int row[N], col[N], dpos[2*N-1], dneg[2*N-1];

// row_nは探索する行の数字
bool solve(int row_n){
    // もしまだコマが配置されていなければ
    if(row[row_n] == FREE){
        rep(i,N){
            if(col[i]==FREE && dpos[row_n+i] == FREE && dneg[row_n-i+(N-1)] == FREE){
                col[i] = NOT_FREE; dpos[row_n+i] = NOT_FREE; dneg[row_n-i+(N-1)] = NOT_FREE;
                if(row_n == 7) return true;
                if(!solve(row_n+1)){
                    col[i] = FREE; dpos[row_n+i] = FREE; dneg[row_n-i+(N-1)] = FREE;
                }
            }
        }
        return false;
    }else{
        solve(row_n+1);
    }
}

int main()
{
    // 初期化
    rep(i,N){
        row[i]=FREE; col[i]=FREE;
    }
    rep(i,2*N-1){
        dpos[i]=FREE; dneg[i]=FREE;
    }
    // 情報の入力
    int n; cin >> n;
    rep(i,n){
        int r, c; cin >> r >> c;
        row[r] = NOT_FREE; col[c]=NOT_FREE;
        dpos[r+c]=NOT_FREE; dneg[r-c+(N-1)]=NOT_FREE;
    }
    solve(0);
    
}