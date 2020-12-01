#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

int cnt;

void insertionSort(vector<int> &A, int N, int g){
    for(int i=g; i<N; i++){
        int v = A[i];
        int j = i - g;
        while(j >= 0 && A[j] > v){
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void ShellSort(vector<int> &A, int N){
    int m = 0;
    vector<int> G;
    int As = A.size();
    if(As == 1){
        G.push_back(1);
        m += 1;
    }
    while(As != 1){
        if((As % 2 == 1) && As == A.size()) As -= 1;
        else As /= 2;
        G.push_back(As);
        m += 1;
    }
    for(int i=0; i<m; i++){
        // cout << "g" << i << ": " << G[i] << endl;
        insertionSort(A, N, G[i]);
    }
    cout << m << endl;
    for(int j=0; j<m; j++){
        cout << G[j];
        if(j != m-1) cout << " ";
    }
    cout << endl;
    cout << cnt << endl;
}

int main()
{
    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++){
        int Ai; cin >> Ai;
        A[i] = Ai;
    }
    ShellSort(A, N);
    for(int i=0; i<N; i++){
        cout << A[i] << endl;
    }
}