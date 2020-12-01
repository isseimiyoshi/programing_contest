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

int cnt;

void insertionSort(vector<int> &A, int N, int g){
    for(int i=g; i<N; i++){
        int v = A[i];
        int j = i - g;
        while(j >= 0 && A[j] > v){
            A[j+g] = A[j];
            j -= g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void shellSort(vector<int> &A, int N){
    cnt = 0;
    vector<int> G;
    G.push_back(1);
    while(true){
        if(G[G.size()-1]*3+1 < N) G.push_back(G[G.size()-1]*3+1);
        else break;
    }
    cout << G.size() << endl;
    sort(G.begin(), G.end(), greater<int>());
    rep(i,G.size()){
        cout << G[i];
        if(i != G.size()-1) cout << " ";
    }cout << endl;
    rep(i,G.size()){
        insertionSort(A, N, G[i]);
    }
    cout << cnt << endl;
    rep(i,N){
        cout << A[i] << endl;
    }
}

int main()
{
    int N; cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    shellSort(A, N);
}