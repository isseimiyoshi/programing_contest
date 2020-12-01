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

bool f[100005];
int c[100005];

void init(){
    rep(i,100005){
        f[i] = true;
        c[i] = 0;
    }
}

int main()
{
    init();
    f[0] = f[1] = false;
    // エラトステネスの篩にかけて素数のみをtrueとする
    for(int i=2; i<=100000; i++){
        if(f[i] == true){
            int j = i + i;
            while(j<=100000){
                f[j] = false;
                j = j + i;
            }
        }
    }
    // 2017に似た数をカウントする
    for(int i=3; i<=100000; i++){
        if(f[i] && f[(i+1)/2]) c[i] = c[i-1]+1;
        else c[i] = c[i-1];
        // cout << c[i] << endl;
    }

    // 入力値を読み込み
    
    int Q; cin >> Q;
    rep(_, Q){
        int l, r; cin >> l >> r;
        cout << c[r] - c[l-1] << endl;
    }
    
}