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

const int MAX_N = 10;

int main()
{
    int N, M; cin >> N >> M;
    vector<int> S[M];
    int p[M];
    rep(i,M){
        int k; cin >> k;
        rep(j,k){
            int s; cin >> s; s--;
            S[i].push_back(s);
        }
    }
    rep(i,M) cin >> p[i];
    int sum = 0;
    for(int tmp=0; tmp<(1 << N); tmp++){
        bitset<MAX_N> bit(tmp);
        bool isOK = true;
        // cout << bit << endl;
        rep(i,M){
            int on = 0;
            for(int Si: S[i]){
                if(bit.test(Si)){
                    on++;
                }
            }
            if(on%2 != p[i]){
                isOK = false;
                // break;
            }
        }
        if(isOK) sum++;
    }
    cout << sum << endl;
}