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

int cnt = 0;
const int INF = pow(10,9)+100;

void mergeSort(int A[], int n, int left, int right){
    if(left+1 < right){
        int mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

void merge(int A[], int n, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1+1], R[n2+1];
    rep(i,n1) L[i] = A[i+left];
    rep(i,n2) R[i] = A[mid+i];
    L[n1] = INF; R[n2] = INF;
    int i=0, j=0;
    for(int k=left; k<right; k++){
        cnt++;
        if(L[i] <= R[i]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
}

int main()
{
    int n; cin >> n;
    int A[n];
    rep(i,n) cin >> A[i];
    mergeSort(A, n, 0, n);
    rep(i,n){
        cout << A[i];
        if(i != n-1) cout << " ";
    }cout << endl;
}