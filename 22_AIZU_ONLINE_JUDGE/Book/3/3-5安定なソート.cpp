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

struct Card { char suit; int val;};

void bubbleSort(vector<Card> &A, int N){
    for(int i=0; i<N; i++){
        for(int j=N-1; j>i; j--){
            if(A[j].val < A[j-1].val) swap(A[j], A[j-1]);
        }
    }
    rep(i,N){
        cout << A[i].suit << A[i].val;
        if(i != N-1) cout << " ";
    }cout << endl;
}

void selectSort(vector<Card> &A, int N){
    for(int i=0; i<N; i++){
        int minj = i;
        for(int j=i+1; j<N; j++){
            if(A[minj].val > A[j].val) minj = j;
        }
        swap(A[i], A[minj]);
    }
    rep(i,N){
        cout << A[i].suit << A[i].val;
        if(i != N-1) cout << " ";
    }cout << endl;
}

bool isStable(vector<Card> A, vector<Card> B, int N){
    bool isSt = true;
    rep(i,N){
        if(A[i].val == B[i].val && A[i].suit != B[i].suit) isSt = false;
    }
    return isSt;
}

int main()
{
    int N; cin >> N;
    vector<Card> A(N), B(N);
    rep(i,N) cin >> A[i].suit >> A[i].val;
    rep(i,N) B[i] = A[i];
    bubbleSort(A, N);
    cout << "Stable" << endl;
    selectSort(B, N);
    if(isStable(A, B, N)) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
}