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

void selectSort(int A[], int N){
    int sw = 0;
    for(int i=0; i<N; i++){
        int minj = i;
        for(int j=i+1; j<N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        swap(A[i], A[minj]);
        if(i != minj) sw++;
    }
    rep(i,N){
        cout << A[i];
        if(i != N-1) cout << " ";
    }cout << endl;
    cout << sw << endl;
}

int main()
{
    int N; cin >> N;
    int A[N];
    rep(i,N){
        int Ai; cin >> Ai;
        A[i] = Ai;
    }
    selectSort(A, N);
}