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

int main()
{
    int N, M, K; cin >> N >> M >> K;
    vector<ll> A(N), B(M);
    rep(i,N) cin >> A[i];
    rep(i,M) cin >> B[i];
    rep(i,N){
        if(i == 0) continue;
        A[i] = A[i] + A[i-1];
    }
    rep(i,M){
        if(i == 0) continue;
        B[i] = B[i] + B[i-1];
    }
    int A_up_K = -1;
    rep(i,N){
        if(A[i] <= K){
            A_up_K = i;
        }
    }
    // つまりAの本を一冊も読めない場合
    if(A_up_K == -1){
        auto itrB = upper_bound(B.begin(), B.end(), K);
        ll B_read_n = distance(B.begin(), itrB);
        cout << B_read_n << endl;
        return 0;
    }
    ll max_n = 0;
    for(int i=A_up_K; i>=0; i--){
        ll A_read_n = i+1;
        auto itrB = upper_bound(B.begin(), B.end(), (K-A[i]));
        // if(itrB == B.end()) cout << "ok" << endl;
        ll B_read_n = distance(B.begin(), itrB);
        // printf("%d %d\n", A_read_n, B_read_n);
        // cout << B[M-1] << endl;
        ll sum = A_read_n + B_read_n;
        if(max_n < sum) max_n = sum;
    }
    auto itrB = upper_bound(B.begin(), B.end(), K);
    ll B_read_n = distance(B.begin(), itrB);
    if(max_n < B_read_n) max_n = B_read_n;
    cout << max_n << endl;




    /*
    auto itrA = A.begin();
    if(A[N-1] < K) itrA = A.end();
    else itrA = upper_bound(A.begin(), A.end(), K);
    ll max_n = 0;
    for(auto itr = A.begin(); itr != itrA; ++itr){
        ll A_min = *itr;
        // cout << A_min << endl;
        ll B_min = K - A_min;
        // cout << B_min << endl;
        auto itrB = B.begin();
        if(B[N-1] <= B_min) itrB = B.end();
        else itrB = upper_bound(B.begin(), B.end(), B_min);
        ll sum = distance(A.begin(), itr) + distance(B.begin(), itrB) + 1;
        // cout << distance(A.begin(), itr) << endl;
        if(max_n < sum) max_n = sum;
    }
    cout << max_n << endl;
    */
}