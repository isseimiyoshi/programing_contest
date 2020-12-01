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

int n;
const int MAX_N = pow(10, 7);
const int MAX_A = 20100;
vector<int> A(MAX_N);
vector<int> B(MAX_N);
vector<int> C(MAX_N);

void countingSort(vector<int> &A, vector<int> &B, int k){
    rep(i, k+1) C[i] = 0;
    for(int j=0; j<n; j++){
        C[A[j]]++;
    }
    for(int i=1; i<=k; i++){
        C[i] = C[i] + C[i-1];
    }
    for(int j=n-1; j>=0; j--){
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}

int main()
{
    cin >> n;
    int max_n = 0;
    rep(i, n){
        int Ai; cin >> Ai;
        if(max_n < Ai) max_n = Ai;
        A[i] = Ai;
    }
    countingSort(A, B, max_n);
    for(int i=1; i<=n; i++){
        cout << B[i];
        if(i != n) cout << " ";
    }
    cout << endl;
}