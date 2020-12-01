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

int main()
{
    int N, K; cin >> N >> K;
    vector<int> DQ;
    rep(i,N){
        int Vi; cin >> Vi;
        DQ.push_back(Vi);
    }
    ll max_n = 0;
    int Sel_n;
    if(N < K){
        Sel_n = N;
    }else{
        Sel_n = K;
    }
    rep(A_B,Sel_n+1){
        int del_n = K-A_B;
        for(int A=0; A<=A_B; A++){
            int B = A_B-A;
            vector<int> Sel;
            // cout << A << B << del_n << endl;
            rep(a,A){
                Sel.push_back(DQ[a]);
            }
            rep(b,B){
                Sel.push_back(DQ[N-1-b]);
            }
            sort(Sel.begin(), Sel.end());
            if(Sel.size() > 0){
                rep(i,del_n){
                    if(Sel[i] < 0) Sel[i] = 0;  // 価値がマイナスの宝石を捨てるのと同義
                    else break;
                }
            }
            ll sum = 0;
            rep(i,Sel.size()) sum += Sel[i];
            if(max_n < sum) max_n = sum;
        }
    }
    cout << max_n << endl;
}