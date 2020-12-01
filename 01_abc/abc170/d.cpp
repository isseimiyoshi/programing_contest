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
    int A[N]; int maxA = 0;
    rep(i,N){
        cin >> A[i];
        if(maxA < A[i]) maxA = A[i];
    }
    sort(A, A+N);
    bool T[maxA+1];
    rep(i,maxA+1) T[i] = true;
    int ans = 0;
    rep(i,N){
        if(T[A[i]] == true){
            ans++;
            for(int j=1; j*A[i] <= maxA; j++){
                T[A[i]*j] = false;
            }
            if(i != N-1 && A[i] == A[i+1]){
                ans--;
            }
        }
    }
    cout << ans << endl;
}