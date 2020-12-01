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

const ll INF = pow(10, 10);
int cnt = 0;

void merge(vector<ll> &A, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    ll L[n1 + 1], R[n2 + 1];
    rep(i, n1) L[i] = A[left + i];
    rep(i, n2) R[i] = A[mid + i];
    L[n1] = INF; R[n2] = INF;
    int i=0, j=0;   // 比較のためにそれぞれの次元引数を初期化
    for(int k=left; k<right; k++){
        cnt += 1;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i += 1;
        }else{
            A[k] = R[j];
            j += 1;
        }
    }
}

void mergeSort(vector<ll> &A, int left, int right){
    if(left+1 < right){
        int mid = (left+right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main()
{
    int n; cin >> n;
    vector<ll> A(n);
    rep(i, n){
        ll Ai; cin >> Ai;
        A[i] = Ai;
    }
    mergeSort(A, 0, n);
    rep(i, n){
        cout << A[i];
        if(i != n-1) cout << " ";
    }
    cout << endl;
    cout << cnt << endl;
}