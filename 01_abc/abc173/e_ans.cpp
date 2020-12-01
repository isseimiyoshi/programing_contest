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

const int MOD = 1000000007;

int main()
{
    int N, K; cin >> N >> K;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    sort(A.begin(), A.end());

    ll sum = 1;
    if(K == N){
        rep(i,N){
            sum *= A[i];
            sum %= MOD;
        }
    }else{
        if(K%2 == 1 && A[N-1] <= 0){
            rep(k,K){
                sum *= A[N-k-1];
                sum %= MOD;
            }
        }else{
            vector<int> B;
            if(K%2 == 1){
                sum *= A[N-1];
                sum %= MOD;
                A.pop_back();
            }
            int As = A.size();
            for(int i=0; i<As; i+=2){
                B.push_back(A[i]*A[i+1]);
            }
            sort(B.rbegin(), B.rend());
            rep(k,K/2){
                sum *= B[k];
                sum %= MOD;
            }
        }
    }
    if(sum < 0) cout << MOD+sum << endl;
    else cout << sum << endl;
}