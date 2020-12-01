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
    int A[N], B[N];
    rep(i,N){
        cin >> A[i] >> B[i];
    }
    sort(A, A+N);
    sort(B, B+N);
    int sum;
    if(N % 2 == 1){
        int min_x = A[N/2];
        int max_x = B[N/2];
        sum = max_x - min_x + 1;
    }else{
        int min_x = A[N/2-1] + A[N/2];
        int max_x = B[N/2-1] + B[N/2];
        sum = max_x - min_x + 1;
    }
    cout << sum << endl;
}