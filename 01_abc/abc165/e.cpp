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
    int N, M; cin >> N >> M;
    vector<int> A(N);
    for(int i=1; i<=N; i++) A[i-1] = i;
    int cnt = 0;
    int mid = N / 2;
    if(N % 2 == 0){
        rep(i,N){
            printf("%d %d\n", A[i], A[mid-1-i]);
            cnt++; if(cnt >= M) break;
            printf("%d %d\n", A[mid+1+i], A[N-1-i]);
            cnt++; if(cnt >= M) break;
        }
    }else{
        rep(i,N){
            printf("%d %d\n", A[i], A[mid-i]);
            cnt++; if(cnt >= M) break;
            printf("%d %d\n", A[mid+1+i], A[N-1-i]);
            cnt++; if(cnt >= M) break;
        }
    }
}