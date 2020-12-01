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

const ll INF = pow(10,10);

void merge(vector<pair<char, ll> > &A, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    vector<pair<char, ll> > L(n1 + 1), R(n2 + 1);
    rep(i, n1) L[i] = A[left + i];
    rep(i, n2) R[i] = A[mid + i];
    L[n1] = make_pair('H', INF); R[n2] = make_pair('H', INF);
    int i=0, j=0;   // 比較のためにそれぞれの次元引数を初期化
    for(int k=left; k<right; k++){
        if(L[i].second <= R[j].second){
            A[k] = L[i];
            i += 1;
        }else{
            A[k] = R[j];
            j += 1;
        }
    }
}

void mergeSort(vector<pair<char, ll> > &A, int left, int right){
    if(left+1 < right){
        int mid = (left+right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(vector<pair<char, ll> > &A, int p, int r){
    pair<char, ll> x = A[r];   // 基準
    int i = p-1;
    for(int j=p; j<r; j++){
        if(A[j].second <= x.second){
            i += 1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

void quickSort(vector<pair<char, ll> > &A, int p, int r){
    if(p < r){
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int main()
{
    int n; cin >> n;
    vector<pair<char, ll> > A(n);
    for(int i=0; i<n; i++){
        char mark; ll Ai;
        cin >> mark >> Ai;
        A[i] = make_pair(mark, Ai);
    }
    vector<pair<char, ll> > A2 = A;
    quickSort(A, 0, n-1);
    mergeSort(A2, 0, n);
    bool isStable = true;
    rep(i, n){
        if(A[i].first != A2[i].first) isStable = false;
    }
    if(isStable) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
    rep(i, n) printf("%c %d\n", A[i].first, A[i].second);
}