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
    int N; cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    sort(A.begin(), A.end(), greater<int>());

    int roop = 0; 
    ll sum = 0;
    rep(i,N){
        if(i == 0){
            sum += A[i];
            roop++;
        }else{
            sum += A[i];
            roop++;
            if(roop != N-1){
                sum += A[i];
                roop++;
            }
        }
        if(roop == N-1) break;
    }
    cout << sum << endl;
}