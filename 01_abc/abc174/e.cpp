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

const int ma = 1000000000;

int N, K;

int binary_tree(vector<int> A, int left, int right){
    if(left+1 == right) return right;
    int mid = (left + right) / 2;



    int cnt = 0;
    rep(i,N){
        if(A[i] % mid == 0){
            cnt += A[i] / mid - 1;
        }else{
            cnt += A[i] / mid;
        }
    }
    if(cnt > K) return binary_tree(A, mid, right);
    // else if(cnt == K) return mid;
    else return binary_tree(A, left, mid);
}

int main()
{
    cin >> N >> K;
    vector<int> A;
    
    rep(i,N){
        int Ai; cin >> Ai;
        A.push_back(Ai);
    }
    sort(A.begin(), A.end());
    cout << binary_tree(A, 0, ma) << endl;
}