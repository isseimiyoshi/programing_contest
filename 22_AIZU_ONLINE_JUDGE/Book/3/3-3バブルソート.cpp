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

void bubbleSort(int A[], int N){
    int sw = 0;     // 交換回数を表す変数
    int flag = 1;
    int i = 0;
    while(flag == 1){
        flag = 0;
        for(int j=N-1; j>i; j--){
            if(A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                flag = 1;
                sw++;
            }
        }
        i++;
    }
    // 出力
    rep(k,N){
        cout << A[k];
        if(k != N-1) cout << " ";
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
    bubbleSort(A, N);
}